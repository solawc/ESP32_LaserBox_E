#pragma once


#ifdef N_AXIS
    #undef N_AXIS
#endif
#define N_AXIS 3

#define HTTP_UPLOAD_BUFLEN  10*1024// 1436


// Enable SDCard
#ifdef ENABLE_SD_CARD
    #undef ENABLE_SD_CARD
#endif

// Board Info
#define MACHINE_NAME                    "DQ-CNC"
#define BOARD_NAME                      "Board:MKS DLC32 V2.1"
#define BOARD_VERSION                   "MKS DLC32 V2.1"
#define FW_NAME                         "Firmware:V2.10(8M.H35.20220725)"
#define FW_VERSION                      "V2.20(8M.H35.20220725)"

// Step gpio set
#define X_DISABLE_PIN                   GPIO_NUM_5
#define X_DIRECTION_PIN                 GPIO_NUM_14
#define X_STEP_PIN                      GPIO_NUM_12

#define Y_DISABLE_PIN                   GPIO_NUM_5
#define Y_DIRECTION_PIN                 GPIO_NUM_26
#define Y_STEP_PIN                      GPIO_NUM_27
    
#define Z_DISABLE_PIN                   GPIO_NUM_5
#define Z_DIRECTION_PIN                 GPIO_NUM_25
#define Z_STEP_PIN                      GPIO_NUM_33

// Laser pin set
#define SPINDLE_TYPE                SpindleType::LASER // only one spindle at a time
#define LASER_OUTPUT_PIN            GPIO_NUM_32

// Limit pins set
#define X_LIMIT_PIN                 GPIO_NUM_35
#define Y_LIMIT_PIN                 GPIO_NUM_34
#define Z_LIMIT_PIN                 GPIO_NUM_39

// LED pin set
#define LED_PIN                     GPIO_NUM_2//  GPIO_NUM_32 

// Probe pins set
#define PROBE_PIN                   GPIO_NUM_22// GPIO_NUM_32  

//sd card spi
#define GRBL_SPI_SCK 			    GPIO_NUM_14
#define GRBL_SPI_MISO 			    GPIO_NUM_12
#define GRBL_SPI_MOSI 			    GPIO_NUM_13
#define GRBL_SPI_SS 			    GPIO_NUM_15
#define SDCARD_DET_PIN 			    GPIO_NUM_39
#define GRBL_SPI_FREQ 			    40000000            // 40Mb/s = 40 / 8 = 5MB/s


// === Default settings
// #define DEFAULT_STEP_PULSE_MICROSECONDS I2S_OUT_USEC_PER_PULSE
#define DEFAULT_STEP_PULSE_MICROSECONDS     10

#define DEFAULT_STEPPER_IDLE_LOCK_TIME      25

#define DEFAULT_STEPPING_INVERT_MASK    	0 // uint8_t
#define DEFAULT_DIRECTION_INVERT_MASK   	5 // uint8_t
#define DEFAULT_INVERT_ST_ENABLE        	0 // boolean
#define DEFAULT_INVERT_LIMIT_PINS       	1 // boolean
#define DEFAULT_INVERT_PROBE_PIN        	0 // boolean

#define DEFAULE_PORBE_ENABLE                1 // boolean

#define DEFAULT_STATUS_REPORT_MASK 			1

#define DEFAULT_JUNCTION_DEVIATION  		0.01 // mm
#define DEFAULT_ARC_TOLERANCE       		0.002 // mm
#define DEFAULT_REPORT_INCHES       		0   // false

#define DEFAULT_SOFT_LIMIT_ENABLE 			0   // false
#define DEFAULT_HARD_LIMIT_ENABLE 			0   // false

#define DEFAULT_HOMING_ENABLE           	0  // false
#define DEFAULT_HOMING_DIR_MASK         	5 // move positive dir Z,negative X,Y
#define DEFAULT_HOMING_FEED_RATE        	300.0 // mm/min
#define DEFAULT_HOMING_SEEK_RATE        	1000.0 // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY   	250 // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF          	1.0 // mm

#ifdef USE_SPINDLE_RELAY
    #define DEFAULT_SPINDLE_RPM_MAX         1.0 // must be 1 so PWM duty is alway 100% to prevent relay damage
#else
    #define DEFAULT_SPINDLE_RPM_MAX         1000.0 // can be change to your spindle max
#endif
#define DEFAULT_SPINDLE_RPM_MIN             0.0 // rpm

#define DEFAULT_LASER_MODE                  1 // false

#define DEFAULT_X_STEPS_PER_MM              80.0
#define DEFAULT_Y_STEPS_PER_MM              80.0
#define DEFAULT_Z_STEPS_PER_MM              80.0

#define DEFAULT_X_MAX_RATE                  6000.0 // mm/s
#define DEFAULT_Y_MAX_RATE                  6000.0 // mm/s
#define DEFAULT_Z_MAX_RATE                  6000.0 // mm/s

#define DEFAULT_X_ACCELERATION              500.0 // mm/sec^2
#define DEFAULT_Y_ACCELERATION              500.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION              500.0 // mm/sec^2

#define DEFAULT_X_MAX_TRAVEL                450.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL                450.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL                50.0 // mm NOTE: Must be a positive value.

#define DEFAULT_SPINDLE_FREQ                1000.0   // 1KHz
#define DEFAULT_LASER_FULL_POWER            1000
#define DEFAULT_SPINDLE_MAX_VALUE           1000    
#define DEFAULT_SPINDLE_MIN_VALUE           0

#define DEFAULT_HOMING_CYCLE_0              (bit(X_AXIS) | bit(Y_AXIS))
#define DEFAULT_HOMING_CYCLE_1              0// bit(Z_AXIS)

#define DEFAULT_BEEP_STATUS                 1
#define DEFAULT_GYRO_STATUS                 0
#define DEFAULT_LANGUAGE_STATUS             1       // default simple chinese
#define DEFAULE_ROLLER_ENABLE               0       // default roller is close
#define DEFAULE_FLAME_ENABLE                0