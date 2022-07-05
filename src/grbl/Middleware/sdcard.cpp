#include "sdcard.h"





#define USE_HSPI_FOR_SD 1
#ifdef USE_HSPI_FOR_SD
SPIClass SPI_H(HSPI);
#define SD_SPI SPI_H
#else
#define SD_SPI SPI
#endif


/*
Unicode      		|        UTF-8
Hexadecimal      	|        Binary
--------------------------+---------------------------------------------
0000 0000-0000 007F | 0xxxxxxx
0000 0080-0000 07FF | 110xxxxx 10xxxxxx
0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/
void unicode_2_utf8(char *des, uint16_t *source, uint8_t Len) {
    int i = Len;
	uint8_t FileName_UTF8[30];
	memset(FileName_UTF8, 0, sizeof(FileName_UTF8));
	while(i-- > 0) {
		if(0 <= source[i] && source[i] <= 0x7F) {
			// 0xxxxxxx
			*des = (source[i] & 0x7F);
			des++;  
		}
		else if(0X80 <= source[i] && source[i] <= 0x7FF) {
			// 110xxxxx 10xxxxxx
			*(des+1) = (source[i] & 0x3F) | 0x80;  
        	*des     = ((source[i] >> 6) & 0x1F) | 0xC0;
			des 	 += 2;
		}
		else if(0X800 <= source[i] && source[i] <= 0xFFFF) {
			// 1110xxxx 10xxxxxx 10xxxxxx
			*(des+2) = (source[i] & 0x3F) | 0x80;  
        	*(des+1) = ((source[i] >>  6) & 0x3F) | 0x80;  
        	*des     = ((source[i] >> 12) & 0x0F) | 0xE0;
			des 	 += 3;
		}
		else if(0X10000 <= source[i] && source[i] <= 0x10FFFF) {
			// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			*(des+3) = (source[i] & 0x3F) | 0x80;  
			*(des+2) = ((source[i] >>  6) & 0x3F) | 0x80;  
			*(des+1) = ((source[i] >> 12) & 0x3F) | 0x80;  
			*des     = ((source[i] >> 18) & 0x07) | 0xF0; 
      		des 	 += 4;
		}
		else {
			break; //Out of range
		}
	}
}

#define MOUNT_POINT "/sdcard"

void sd_fs_init() {

	pinMode(GRBL_SPI_SS, OUTPUT);
	digitalWrite(GRBL_SPI_SS, HIGH);

	delay(2000);
	SPI.begin(GRBL_SPI_SCK, GRBL_SPI_MISO, GRBL_SPI_MOSI);

	if(SD.begin(GRBL_SPI_SS)) {
		// serial_print("FS succeed\n");
		if (SD.cardSize() > 0) {
            // sd_state = SDState::Idle;
			serial_print("FS succeed\n");
			serial_printf("SD Size:%d\n", SD.cardSize());
        }
	}else {
		serial_print("FS Error\n");
	}

	File root = SD.open("/");
	File file = root.openNextFile();
	while (file)
	{
		if (file.isDirectory())
		{
			serial_print("  DIR : ");
			serial_printf("%s\n", file.name());
			// Serial.println(file.name());
			// if (levels)
			// {
			// 	listDir(file.name(), levels - 1);
			// }
		}
		else
		{
			serial_print("  FILE: ");
			serial_printf("%s\n", file.name());
			serial_print("  SIZE: ");
			serial_printf("%s\n", file.name());
		}
		file = root.openNextFile();
	}
}