#pragma once
#define RX_BUFLEN 12
#define TX_BUFLEN 12
#define US2TICKS(x) ((uint16_t)((uint32_t)(x * 790) / 1024) - 1)

typedef enum
{
    Idle,
    SOF,
    Acvtive,
    Done,
    Error
} VPW_RxStatus_t;

uint8_t J1850_Transmit(uint8_t *byteBuf, uint16_t len);
uint8_t J1850_Recieve(uint8_t *byteBuf, uint16_t *len);
void J1850Init();
