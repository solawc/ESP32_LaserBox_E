#ifndef __pins_LaserBox_E_H
#define __pins_LaserBox_E_H

/*************************************************************************
 *                              I2S OUT
 ************************************************************************/
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

// Beep
#define BEEPER					            I2SO(7)             // Default none



/*************************************************************************
 *                              Limit
 ************************************************************************/
#define X_LIMIT_PIN                         GPIO_NUM_36
#define Y_LIMIT_PIN                         GPIO_NUM_35
#define Z_LIMIT_PIN                         GPIO_NUM_34

/*************************************************************************
 *                              Probe
 ************************************************************************/
#define PROBE_PIN                           GPIO_NUM_22 


/*************************************************************************
 *                              SDcard
 ************************************************************************/
#define GRBL_SPI_SCK 			            GPIO_NUM_14
#define GRBL_SPI_MISO 			            GPIO_NUM_12
#define GRBL_SPI_MOSI 			            GPIO_NUM_13
#define GRBL_SPI_SS 			            GPIO_NUM_15
#define SDCARD_DET_PIN 			            GPIO_NUM_39
#define GRBL_SPI_FREQ 			            4000000            // 40Mb/s = 40 / 8 = 5MB/s

/*************************************************************************
 *                              LCD
 ************************************************************************/
#define LCD_SCK				                GPIO_NUM_18
#define LCD_MISO				            GPIO_NUM_19
#define LCD_MOSI				            GPIO_NUM_23
#define LCD_RS					            GPIO_NUM_33
#define LCD_EN					            GPIO_NUM_5     
#define LCD_RST					            GPIO_NUM_27     
#define LCD_CS					            GPIO_NUM_25
#define TOUCH_CS				            GPIO_NUM_26

/*************************************************************************
 *                              Coolant
 ************************************************************************/
#define COOLANT_MIST_PIN                    GPIO_NUM_4 // IIC_SCL

/*************************************************************************
 *                              Spindle
 ************************************************************************/
#define SPINDLE_TYPE                        SpindleType::LASER // only one spindle at a time
#define LASER_OUTPUT_PIN                    GPIO_NUM_32



#endif