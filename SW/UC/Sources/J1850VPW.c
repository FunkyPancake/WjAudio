#include "J1850VPW.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#define RX_BUFLEN 10
#define TX_BUFLEN 10

#define SOF_US 200
#define LONG_US 128
#define SHORT_US 64
#define EOF_US 200
const uint32_t VPW_Symbols[] = { 
		US2TICKS(LONG_US),
		US2TICKS(SHORT_US),
		US2TICKS(SOF_US),
		US2TICKS(EOF_US) 
};
volatile uint16_t VPW_RxBuf[(RX_BUFLEN + 1) * 8];
volatile uint16_t VPW_TxBuf[(TX_BUFLEN + 1) * 8];
volatile uint16_t VPW_RxBufPtr;
volatile uint16_t VPW_TxBufPtr;
volatile uint8_t TxInProgress;
volatile uint8_t RxInProgress;
volatile uint16_t prevVal;
const uint8_t crctable[256] = { 0x00, 0x1D, 0x3A, 0x27, 0x74, 0x69, 0x4E, 0x53,
		0xE8, 0xF5, 0xD2, 0xCF, 0x9C, 0x81, 0xA6, 0xBB, 0xCD, 0xD0, 0xF7, 0xEA,
		0xB9, 0xA4, 0x83, 0x9E, 0x25, 0x38, 0x1F, 0x02, 0x51, 0x4C, 0x6B, 0x76,
		0x87, 0x9A, 0xBD, 0xA0, 0xF3, 0xEE, 0xC9, 0xD4, 0x6F, 0x72, 0x55, 0x48,
		0x1B, 0x06, 0x21, 0x3C, 0x4A, 0x57, 0x70, 0x6D, 0x3E, 0x23, 0x04, 0x19,
		0xA2, 0xBF, 0x98, 0x85, 0xD6, 0xCB, 0xEC, 0xF1, 0x13, 0x0E, 0x29, 0x34,
		0x67, 0x7A, 0x5D, 0x40, 0xFB, 0xE6, 0xC1, 0xDC, 0x8F, 0x92, 0xB5, 0xA8,
		0xDE, 0xC3, 0xE4, 0xF9, 0xAA, 0xB7, 0x90, 0x8D, 0x36, 0x2B, 0x0C, 0x11,
		0x42, 0x5F, 0x78, 0x65, 0x94, 0x89, 0xAE, 0xB3, 0xE0, 0xFD, 0xDA, 0xC7,
		0x7C, 0x61, 0x46, 0x5B, 0x08, 0x15, 0x32, 0x2F, 0x59, 0x44, 0x63, 0x7E,
		0x2D, 0x30, 0x17, 0x0A, 0xB1, 0xAC, 0x8B, 0x96, 0xC5, 0xD8, 0xFF, 0xE2,
		0x26, 0x3B, 0x1C, 0x01, 0x52, 0x4F, 0x68, 0x75, 0xCE, 0xD3, 0xF4, 0xE9,
		0xBA, 0xA7, 0x80, 0x9D, 0xEB, 0xF6, 0xD1, 0xCC, 0x9F, 0x82, 0xA5, 0xB8,
		0x03, 0x1E, 0x39, 0x24, 0x77, 0x6A, 0x4D, 0x50, 0xA1, 0xBC, 0x9B, 0x86,
		0xD5, 0xC8, 0xEF, 0xF2, 0x49, 0x54, 0x73, 0x6E, 0x3D, 0x20, 0x07, 0x1A,
		0x6C, 0x71, 0x56, 0x4B, 0x18, 0x05, 0x22, 0x3F, 0x84, 0x99, 0xBE, 0xA3,
		0xF0, 0xED, 0xCA, 0xD7, 0x35, 0x28, 0x0F, 0x12, 0x41, 0x5C, 0x7B, 0x66,
		0xDD, 0xC0, 0xE7, 0xFA, 0xA9, 0xB4, 0x93, 0x8E, 0xF8, 0xE5, 0xC2, 0xDF,
		0x8C, 0x91, 0xB6, 0xAB, 0x10, 0x0D, 0x2A, 0x37, 0x64, 0x79, 0x5E, 0x43,
		0xB2, 0xAF, 0x88, 0x95, 0xC6, 0xDB, 0xFC, 0xE1, 0x5A, 0x47, 0x60, 0x7D,
		0x2E, 0x33, 0x14, 0x09, 0x7F, 0x62, 0x45, 0x58, 0x0B, 0x16, 0x31, 0x2C,
		0x97, 0x8A, 0xAD, 0xB0, 0xE3, 0xFE, 0xD9, 0xC4 };

uint8_t J1850VPW_CalcCRC(uint8_t *data, uint8_t size);
uint16_t J1850VPW_ByteToBits(uint8_t *byteBuf, uint16_t len);

uint16_t J1850VPW_ByteToBits(uint8_t *byteBuf, uint16_t len) {
	int i, j, idx, pSymIdx;
	uint8_t cBit, pBit;
	VPW_TxBuf[0] = VPW_Symbols[2];
	idx = 1;
	pBit = 1;
	pSymIdx = 1;
	for (i = 0; i < len; i++) {
		for (j = 7; j >= 0; j--) {
			cBit = (byteBuf[i] & (1 << j)) && 1;
			if (cBit == pBit) {
				pSymIdx ^= 1;
				VPW_TxBuf[idx] = VPW_Symbols[pSymIdx];
			} else
				VPW_TxBuf[idx] = VPW_Symbols[pSymIdx];
			pBit = cBit;
			idx++;
		}
	}
	uint8_t crc = J1850VPW_CalcCRC(byteBuf, len);
	for (j = 7; j >= 0; j--) {
		cBit = (crc & (1 << j)) && 1;
		if (cBit == pBit) {
			pSymIdx ^= 1;
			VPW_TxBuf[idx] = VPW_Symbols[pSymIdx];
		} else
			VPW_TxBuf[idx] = VPW_Symbols[pSymIdx];
		pBit = cBit;
		idx++;
	}
	return idx;
}
uint8_t J1850VPW_CalcCRC(uint8_t *data, uint8_t size) {
	uint8_t crc = 0xff;
	uint16_t idx;
	for (idx = 0; idx < size; idx++) {
		/* XOR-in next input byte */
		uint8_t byte = (data[idx] ^ crc);
		/* get current CRC value = remainder */
		crc = (crctable[byte]);
	}
	crc ^= 0xff;
	return crc;
}
void J1850_Transmit(uint8_t *byteBuf, uint16_t len) {
	uint16_t curVal;
	if (TxInProgress == 0) {
		J1850VPW_ByteToBits(byteBuf, len);
		VPW_TxBufPtr = 0;
		curVal = FTM2_CNT;
		SetTimerAlarm(&FTM2_C1V,curVal + 10);
		TxInProgress = 1;
	}
}
inline void SetTimerAlarm(uint32_t* counterRegister, uint16_t value);
inline void SetTimerAlarm(uint32_t* counterRegister, uint16_t value) {
	value &= 0x7fff;
	*counterRegister = value;
}
 inline uint16_t GetPulseWidth(uint16_t a,uint16_t b){
	
	if(b < a){
		return b +0x8000 - a;
	}
	return b-a;
}
void J1850Init(){
	TxInProgress =0;
	RxInProgress = 0;
	//Sof starts from rising edge
	FTM2_C1SC &=~( FTM_CnSC_ELSB_MASK);
}
PE_ISR(FTM_Isr) {

	uint32_t nextVal;
	uint32_t curVal = FTM2_CNT;
	if ((FTM2_STATUS & FTM_STATUS_CH1F_MASK) == FTM_STATUS_CH1F_MASK) {
		FTM2_STATUS &= ~(FTM_STATUS_CH1F_MASK);
		nextVal = VPW_TxBuf[VPW_TxBufPtr];
		if (VPW_TxBuf[VPW_TxBufPtr] == 0) {
			FTM2_C1V = -1;
			TxInProgress = 0;
		}
		else
		{
			SetTimerAlarm(&FTM2_C1V,curVal + nextVal);
		}
		VPW_TxBufPtr++;
	}
	if ((FTM2_STATUS & FTM_STATUS_CH0F_MASK) == FTM_STATUS_CH0F_MASK) {
		FTM2_STATUS &= ~(FTM_STATUS_CH0F_MASK);
		if(RxInProgress ==0){
			RxInProgress = 1;
			VPW_RxBufPtr = 0;
			FTM2_C0SC |=( FTM_CnSC_ELSB_MASK);
		}
		else if(RxInProgress ==1){
			
				VPW_RxBuf[VPW_RxBufPtr] = GetPulseWidth(prevVal,curVal) ;
				VPW_RxBufPtr++;
				SetTimerAlarm(&FTM2_C2V,curVal + 150);
		}
		 prevVal = curVal;


	}
	if ((FTM2_STATUS & FTM_STATUS_CH2F_MASK) == FTM_STATUS_CH2F_MASK) {
		FTM2_STATUS &= ~(FTM_STATUS_CH2F_MASK);
		RxInProgress = 2;
	}
	/*
	 else if ((FTM2_STATUS & FTM_STATUS_CH0F_MASK) == FTM_STATUS_CH0F_MASK){
	 FTM2_STATUS &= ~(FTM_STATUS_CH0F_MASK);
	 if(curVal - prevVal > VPW_Symbols[2])
	 SOF =1;
	 else 
	 SOF = 0;
	 prevVal = curVal;
	 SetTimerAlarm(&FTM2_C2V,curVal + VPW_TxBuf[3]);
	 }
	 else if ((FTM2_STATUS & FTM_STATUS_CH2F_MASK) == FTM_STATUS_CH2F_MASK){
	 FTM2_STATUS &= ~(FTM_STATUS_CH2F_MASK);
	 FTM2_C2V = -1;
	 EOF = 1;
	 }*/

}
