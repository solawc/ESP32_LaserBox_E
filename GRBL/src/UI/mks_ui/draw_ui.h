#ifndef __draw_ui_h
#define __draw_ui_h

#ifndef ESP32
#define USE_WINDOS_LIST
#endif

#include "../../main.h"
#include "../lv_port/lv_port_init.h"

/* Write cmd to ringbuffer */
#define GRBL_CMD_SEND(A)            	SerialWriteIntoBuffer((uint8_t *)A)  



/* Theme Color */
#define MAIN_BG_COLOR           		0x13121A
#define SRC1_BG_COLOR          		 	0x1F2333


#include "draw_ready.h"
#include "draw_adjust.h"
#include "draw_sdcard.h"

extern "C" {
	LV_IMG_DECLARE(mks_logo);
}

typedef struct {
	lv_obj_t* 	mks_logo;
	lv_obj_t* 	main_src;
	lv_obj_t* 	src1;
	lv_obj_t* 	src2;

	lv_style_t  main_style;
	lv_style_t  src1_style;
	lv_style_t  src2_style;

	lv_timer_t* timer_logo;             // a timer to jump to draw_read()

}lv_ui_t;
extern lv_ui_t lv_ui;

void lvDrawLogo(void);

#ifdef USE_WINDOS_LIST
void runMksUiDemo(void);
#endif

#endif
