#include "PE_Types.h"
#include "CDChanger.h"
#include "J1850VPW.h"
#include "PlayButton.h"
#include "UpButton.h"
#include "DownButton.h"
#include "BtRst.h"

void ButtonRequest(uint8_t *timer);
uint8_t EvalButton(uint8_t *timer);
void ControlButtons(void);
void PingRadio(uint8_t RespCode);
void ParseRxData(void);

static uint8_t RxBuffer[RX_BUFLEN];
static uint8_t TxBuffer[TX_BUFLEN] = {0x8D, 0x93, 0x01, 0x01, 0x80};
typedef struct
{
    uint8_t SeekUpTimer;
    uint8_t SeekDownTimer;
    uint8_t PlayPauseTimer;
} Btn_t;
static Btn_t buttons;
static uint16_t RxDataLen;
static uint8_t RstCntr =0;



void ParseRxData(void)
{
    if (J1850_Recieve(RxBuffer, &RxDataLen) == 0)
    {
        switch (RxBuffer[0])
        {
			case 0x3D:
				if (RxBuffer[1] == 0x12)
				{
					uint8_t button = RxBuffer[3];
					switch (RxBuffer[2])
					{
					case 0x81: //TUNE
						// if(button == ) FF,RW,Released
						break;
					case 0x82: //SEEK
						if (button == 0x26)
						{
							ButtonRequest(&buttons.SeekUpTimer);
						}
						if (button == 0x27)
						{
							ButtonRequest(&buttons.SeekDownTimer);
						}
						break;
					case 0x83: //DISK
						// if(button == )DISK UP DISK DOWN
						break;
					case 0x84: //RND
						if (button == 0x35)
							ButtonRequest(&buttons.PlayPauseTimer);
						break;
					default:
						break;
					}
				}
				break;
			// radio poll
			case 0x8D:
				if (RxBuffer[1] == 0x0f)
				{
					PingRadio(RxBuffer[2]);
				}
	
			default:
				break;
        }
    }
}
void PingRadio(uint8_t RespCode)
{
    	switch(RespCode)
    	{
//			case 0x21:
//				TxBuffer[1] = 0x92;
//				TxBuffer[2] = 0xc0;
//				TxBuffer[3] = 0x00;
//				TxBuffer[4] = 0x00;
//				J1850_Transmit(TxBuffer, 5);
//				break;
			case 0x24:
				TxBuffer[1] = 0x94;
				TxBuffer[2] = 0x00;
				TxBuffer[3] = 0x00;
				J1850_Transmit(TxBuffer, 4);
				break;
			default:
				TxBuffer[1] = 0x93;
				TxBuffer[2] = 0x01;
				TxBuffer[3] = 0x01;
				TxBuffer[4] = 0x80;
				J1850_Transmit(TxBuffer, 5);
				break;
    	}
}
void ButtonRequest(uint8_t *timer)
{
    *timer = BUTTON_TIMER;
}

uint8_t EvalButton(uint8_t *timer)
{
    if (*timer > 0)
    {
        *timer -= 1;
        return 1;
    }
    return 0;
}
void RstBtModule(void)
{
	uint8_t output;
	if(RstCntr < BT_RST_DELAY)
	{
		RstCntr++;
		output = 1;
	}
	else
	{
		output =0;
	}
	BtRst_PutVal(NULL,output);
}
void ControlButtons(void)
{
    PlayButton_PutVal(NULL,EvalButton(&buttons.PlayPauseTimer));
    DownButton_PutVal(NULL,EvalButton(&buttons.SeekDownTimer));
    UpButton_PutVal(NULL,EvalButton(&buttons.SeekUpTimer));
}
void CDChanger_1ms(void)
{	
    ParseRxData();
    ControlButtons();
    RstBtModule();
}
