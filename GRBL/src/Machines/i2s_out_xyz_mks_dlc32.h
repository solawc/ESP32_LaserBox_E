#pragma once
// clang-format off

#define MACHINE_NAME                        "Custom Machine"
#define BOARD_NAME                          "Board:LG_ESP_V1.0"
#define BOARD_VERSION                       "LV_ESP_V1.0"
#define FW_NAME                             "Firmware:V1A0120220822"
#define FW_VERSION                          "V1A0120220822"

// === Default settings
// #define DEFAULT_STEP_PULSE_MICROSECONDS I2S_OUT_USEC_PER_PULSE
#define DEFAULT_STEP_PULSE_MICROSECONDS     10

#define DEFAULT_STEPPER_IDLE_LOCK_TIME      25

#define DEFAULT_STEPPING_INVERT_MASK    	0 // uint8_t
#define DEFAULT_DIRECTION_INVERT_MASK   	0 // uint8_t
#define DEFAULT_INVERT_ST_ENABLE        	1 // boolean
#define DEFAULT_INVERT_LIMIT_PINS       	1 // boolean
#define DEFAULT_INVERT_PROBE_PIN        	0 // boolean

#define DEFAULE_PORBE_ENABLE                1 // boolean

#define DEFAULT_STATUS_REPORT_MASK 			1

#define DEFAULT_JUNCTION_DEVIATION  		0.01 // mm
#define DEFAULT_ARC_TOLERANCE       		0.002 // mm
#define DEFAULT_REPORT_INCHES       		0   // false

#define DEFAULT_SOFT_LIMIT_ENABLE 			0   // false
#define DEFAULT_HARD_LIMIT_ENABLE 			1   // false

#define DEFAULT_HOMING_ENABLE           	0  // false
#define DEFAULT_HOMING_DIR_MASK         	3 // move positive dir Z,negative X,Y
#define DEFAULT_HOMING_FEED_RATE        	300.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE        	1000.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY   	250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF          	1.0 // mm

#ifdef USE_SPINDLE_RELAY
    #define DEFAULT_SPINDLE_RPM_MAX         1.0 // must be 1 so PWM duty is alway 100% to prevent relay damage
#else
    #define DEFAULT_SPINDLE_RPM_MAX         1000.0     // can be change to your spindle max
#endif
#define DEFAULT_SPINDLE_RPM_MIN             0.0         // rpm

#define DEFAULT_LASER_MODE                  1           // false

#define DEFAULT_X_STEPS_PER_MM              80.0
#define DEFAULT_Y_STEPS_PER_MM              80.0
#define DEFAULT_Z_STEPS_PER_MM              80.0

#define DEFAULT_X_MAX_RATE                  6000.0      // mm/s
#define DEFAULT_Y_MAX_RATE                  6000.0      // mm/s
#define DEFAULT_Z_MAX_RATE                  6000.0      // mm/s

#define DEFAULT_X_ACCELERATION              1000.0      // mm/sec^2
#define DEFAULT_Y_ACCELERATION              1000.0      // mm/sec^2
#define DEFAULT_Z_ACCELERATION              1000.0      // mm/sec^2

#define DEFAULT_X_MAX_TRAVEL                521.0       // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL                341.0       // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL                121.0       // mm NOTE: Must be a positive value.

#define DEFAULT_SPINDLE_FREQ                1000.0      // 1KHz
#define DEFAULT_LASER_FULL_POWER            1000
#define DEFAULT_SPINDLE_MAX_VALUE           1000    
#define DEFAULT_SPINDLE_MIN_VALUE           0

#define DEFAULT_HOMING_CYCLE_0              (bit(X_AXIS) | bit(Y_AXIS))
#define DEFAULT_HOMING_CYCLE_1              0 // bit(Z_AXIS)

#define DEFAULT_BEEP_STATUS                 1
#define DEFAULT_GYRO_STATUS                 0
#define DEFAULT_LANGUAGE_STATUS             1       // default simple chinese
#define DEFAULE_ROLLER_ENABLE               0       // default roller is close
#define DEFAULE_FLAME_ENABLE                0