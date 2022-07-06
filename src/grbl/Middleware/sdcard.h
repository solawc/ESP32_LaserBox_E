#ifndef __sdcard_h
#define __sdcard_h

#include "../../main.h"



#include <FS.h>
#include <SD.h>
#include <SPI.h>                    // 如果SD卡使用SPI，就包含这个头文件


#define GRBL_SPI_SCK 			    GPIO_NUM_14
#define GRBL_SPI_MISO 			    GPIO_NUM_12
#define GRBL_SPI_MOSI 			    GPIO_NUM_13
#define GRBL_SPI_SS 			    GPIO_NUM_15
#define SDCARD_DET_PIN 			    GPIO_NUM_39
#define GRBL_SPI_FREQ 			    4000000
// #define GRBL_SPI_FREQ 			    40000000


void sd_fs_init();

#endif
