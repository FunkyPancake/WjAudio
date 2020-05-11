/*PlayPong[] ={
    HEADER,
    PONG_PLAY(0x94),
    playTimeMin,
    playTimeSec
};
PlayEnablePong{0x8d,0xe1,0x01,0x10}
->potrzebne tylko to IdlePong(0x8d,0x93,actualdisc,actualtrack,message)*/
#include "PE_Types.h"
#include "CDChanger.h"
#include "J1850VPW.h"
uint8_t RxBuffer[RX_BUFLEN];
uint8_t TxBuffer[TX_BUFLEN] = {0x8D, 0x93, 0x01, 0x01, 0x70};
uint8_t PingCntr;
uint16_t RxDataLen;

void ParseRxData()
{
    if (J1850_Recieve(RxBuffer, &RxDataLen) == 0)
    {
        switch (RxBuffer[0])
        {
        //Buttons data frame
        case 0x3D:
            switch (RxBuffer[3])
            {
            case 0x26: //seek up
                break;
            case 0x27: //seek down
                break;
            case 0x28:
            	break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void PingRadio()
{
    if (PingCntr == PING_PERIOD_MS)
    {
        J1850_Transmit(TxBuffer, 5);
        PingCntr = 0;
        return;
    }
    PingCntr++;
}
void ControlDio(void)
{
}
void CDChanger_1ms(void)
{

    //PingRadio();
    ParseRxData();
    //ControlDio();
}
