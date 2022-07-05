#pragma once 

#include "Arduino.h"

#include <xtensa/core-macros.h>

#include "grbl/HAL/uart.h"
#include "grbl/Middleware/client.h"
#include "grbl/DEVICE/dev_i2s_ex.h"


void IRAM_ATTR delay_us(int32_t us);
void delay_ms(uint16_t ms);
