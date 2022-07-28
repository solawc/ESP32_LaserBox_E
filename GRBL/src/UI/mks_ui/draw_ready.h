#ifndef __draw_ready_h
#define __draw_ready_h

#include "draw_ui.h"

typedef struct {

	lv_obj_t* imgbtn_adj;
	lv_obj_t* imgbtn_ctrl;
	lv_obj_t* imgbtn_sculpture;
	lv_obj_t* imgbtn_tool;

	lv_obj_t* label_adj;
	lv_obj_t* label_ctrl;
	lv_obj_t* label_sculpture;
	lv_obj_t* label_tool;

	lv_obj_t* label_wXpos;
	lv_obj_t* label_wYpos;
	lv_obj_t* label_wZpos;
	lv_obj_t* label_mXpos;
	lv_obj_t* label_mYpos;
	lv_obj_t* label_mZpos;
	lv_obj_t* label_power;

	lv_style_t imgbtn_style;

	lv_timer_t* ready_page_upadte;

}ready_ui_t;
extern ready_ui_t ready_page;



void draw_ready(void);
void clear_ready_page(void);

#endif
