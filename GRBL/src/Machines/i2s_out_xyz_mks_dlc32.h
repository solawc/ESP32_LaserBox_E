#pragma once
// clang-format off

/*
 * 更新版本号需要修改的地方
 * 1、FW_NAME
 * 2、main ---- GRBL_VERSION_BUILD
*/

#define MACHINE_NAME                        "Custom Machine"
#define BOARD_NAME                          "Board:LG_ESP_V1.0"
#define BOARD_VERSION                       "LV_ESP_V1.0"
#define FW_NAME                             "Firmware:V1A0120220822"
#define FW_VERSION                          "V1A0120220822"

// I2S pins set
#define I2S_OUT_BCK                         GPIO_NUM_16
#define I2S_OUT_WS                          GPIO_NUM_17
#define I2S_OUT_DATA                        GPIO_NUM_21
    
// X I2S pin set    
#define X_DISABLE_PIN                       I2SO(0)
#define X_DIRECTION_PIN                     I2SO(2)
#define X_STEP_PIN                          I2SO(1)

// Y I2S pin set
#define Y_DISABLE_PIN                       I2SO(0)
#define Y_DIRECTION_PIN                     I2SO(6)
#define Y_STEP_PIN                          I2SO(5)
    
// Z I2S pin set
#define Z_DISABLE_PIN                       I2SO(0)
#define Z_DIRECTION_PIN                     I2SO(4)
#define Z_STEP_PIN                          I2SO(3)

// Laser pin set
// #define SPINDLE_TYPE                        SpindleType::LASER // only one spindle at a time
// #define LASER_OUTPUT_PIN                    GPIO_NUM_32

#define SPINDLE_TYPE                        SpindleType::PWM // only one spindle at a time
#define SPINDLE_OUTPUT_PIN                  GPIO_NUM_32

#define X_LIMIT_PIN                         GPIO_NUM_36
#define Y_LIMIT_PIN                         GPIO_NUM_35
#define Z_LIMIT_PIN                         GPIO_NUM_34

#define LED_PIN                             GPIO_NUM_2//  GPIO_NUM_32 
#define PROBE_PIN                           GPIO_NUM_22// GPIO_NUM_32  


#define LCD_SCK				                GPIO_NUM_18
#define LCD_MISO				            GPIO_NUM_19
#define LCD_MOSI				            GPIO_NUM_23
#define LCD_RS					            GPIO_NUM_33
#define LCD_EN					            GPIO_NUM_5     
#define LCD_RST					            GPIO_NUM_27     
#define LCD_CS					            GPIO_NUM_25
#define TOUCH_CS				            GPIO_NUM_26
#define BEEPER					            I2SO(7)

#define IIC_SCL                             GPIO_NUM_4
#define IIC_SDA                             GPIO_NUM_0

#define COOLANT_MIST_PIN                    GPIO_NUM_4 // IIC_SCL

//sd card spi
#define GRBL_SPI_SCK 			            GPIO_NUM_14
#define GRBL_SPI_MISO 			            GPIO_NUM_12
#define GRBL_SPI_MOSI 			            GPIO_NUM_13
#define GRBL_SPI_SS 			            GPIO_NUM_15
#define SDCARD_DET_PIN 			            GPIO_NUM_39
#define GRBL_SPI_FREQ 			            40000000            // 40Mb/s = 40 / 8 = 5MB/s

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
    #define DEFAULT_SPINDLE_RPM_MAX         10000.0     // can be change to your spindle max
#endif
#define DEFAULT_SPINDLE_RPM_MIN             0.0         // rpm

#define DEFAULT_LASER_MODE                  0           // false

#define DEFAULT_X_STEPS_PER_MM              200.0
#define DEFAULT_Y_STEPS_PER_MM              200.0
#define DEFAULT_Z_STEPS_PER_MM              200.0

#define DEFAULT_X_MAX_RATE                  1200.0      // mm/s
#define DEFAULT_Y_MAX_RATE                  1200.0      // mm/s
#define DEFAULT_Z_MAX_RATE                  1200.0      // mm/s

#define DEFAULT_X_ACCELERATION              1200.0      // mm/sec^2
#define DEFAULT_Y_ACCELERATION              1200.0      // mm/sec^2
#define DEFAULT_Z_ACCELERATION              1200.0      // mm/sec^2

#define DEFAULT_X_MAX_TRAVEL                521.0       // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL                341.0       // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL                121.0       // mm NOTE: Must be a positive value.

#define DEFAULT_SPINDLE_FREQ                8000.0   // 1KHz
#define DEFAULT_LASER_FULL_POWER            1000
#define DEFAULT_SPINDLE_MAX_VALUE           1000    
#define DEFAULT_SPINDLE_MIN_VALUE           0

#define DEFAULT_HOMING_CYCLE_0              (bit(X_AXIS) | bit(Y_AXIS))
#define DEFAULT_HOMING_CYCLE_1              bit(Z_AXIS)

#define DEFAULT_BEEP_STATUS                 1
#define DEFAULT_GYRO_STATUS                 0
#define DEFAULT_LANGUAGE_STATUS             1       // default simple chinese
#define DEFAULE_ROLLER_ENABLE               0       // default roller is close
#define DEFAULE_FLAME_ENABLE                0