#pragma once 

#include "../../main.h"

#undef CONFIG_FATFS_CODEPAGE
#define CONFIG_FATFS_CODEPAGE 936

#include <ff.h>
#include <esp_vfs_fat.h>

// #include <FS.h>
#include <SD.h>

// 如果SD卡使用SPI，就包含这个头文件
#include <SPI.h>

