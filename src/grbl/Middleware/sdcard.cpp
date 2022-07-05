#include "sdcard.h"


typedef FRESULT FS_RES_t;


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

uint32_t fs_read_fatfs_id() {
    return FF_DEFINED;
}

FS_RES_t fs_f_open(FIL* fp, TCHAR* path, BYTE mode) {
   return f_open(fp, path, mode);
}

FS_RES_t fs_f_read(FIL* fp, void* buff, UINT btr, UINT* br) {
   return f_read(fp, buff, btr, br);
}



