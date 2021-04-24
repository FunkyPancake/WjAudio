#pragma once
#define RX_BUFLEN   12
#define TX_BUFLEN   12
#define US2TICKS(x) ((uint16_t)((uint32_t)(x * 790) / 1024) - 1)

/*timing thresholds for symbols*/
#define RX_SHORT_MIN US2TICKS(34)
#define RX_SHORT_MAX US2TICKS(96)
#define RX_LONG_MIN  US2TICKS(96)
#define RX_LONG_MAX  US2TICKS(163)
#define RX_SOF_MIN   US2TICKS(163)
#define RX_SOF_MAX   US2TICKS(239)
#define RX_EOF_MIN   US2TICKS(239)
#define SOF_US       200
#define LONG_US      128
#define SHORT_US     64
#define EOF_US       200

#define LONG_IDX  0
#define SHORT_IDX 1
#define SOF_IDX   2
#define EOF_IDX   3


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
