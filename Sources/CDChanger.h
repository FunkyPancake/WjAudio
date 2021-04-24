#pragma once
#define BUTTON_TIMER 10
#define BT_RST_DELAY 150

typedef struct
{
    uint8_t SeekUpTimer;
    uint8_t SeekDownTimer;
    uint8_t PlayPauseTimer;
} Btn_t;

void CDChanger_1ms(void);
void CDChanger_Polling(void);
void InitBtResetTimer(uint8_t isPor);
