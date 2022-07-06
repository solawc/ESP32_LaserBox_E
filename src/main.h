#ifndef __main_h
#define __main_h

#include "Arduino.h"

#include <xtensa/core-macros.h>

#include "stdio.h"
#include <stdlib.h>
#include <string.h>

#include "grbl/HAL/uart.h"
#include "grbl/Middleware/client.h"
#include "grbl/serial.h"
#include "grbl/DEVICE/dev_i2s_ex.h"
#include "grbl/Middleware/sdcard.h"

#include <driver/timer.h>

#include "grbl/Middleware/client.h"

// WebUI

#include "grbl/WebUI/ESPResponse.h"
#include "grbl/WebUI/JSONEncoder.h"

// GRBL源码目录
#include "grbl/config.h"
#include "grbl/nuts_bolts.h"
#include "grbl/default.h"
#include "grbl/error.h"
#include "grbl/WebUI/Authentication.h"
#include "grbl/probe.h"
#include "grbl/system.h"
#include "grbl/gcode.h"
#include "grbl/settings.h"
#include "grbl/settingsdefine.h"
#include "grbl/coolant.h"
#include "grbl/limit.h"
#include "grbl/protocol.h"
#include "grbl/report.h"
#include "grbl/spindle.h"
#include "grbl/motors.h"
#include "grbl/stepper.h"
#include "grbl/exec.h"
#include "grbl/planner.h"
#include "grbl/jog.h"
#include "grbl/motion_ctrl.h"

#include "grbl/pins.h"
#include "grbl/pwm.h"
#include "grbl/laser.h"

void IRAM_ATTR delay_us(int32_t us);
void delay_ms(uint16_t ms);

#endif
