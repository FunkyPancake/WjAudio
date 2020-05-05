#pragma once
#include "PE_Types.h"

#define US2TICKS(x) ((uint16_t)((uint32_t)(x * 790) / 1024) - 1)

void J1850_Transmit(uint8_t *byteBuf, uint16_t len);
void J1850Init();
