#ifndef __draw_ready_h
#define __draw_ready_h

#include "draw_ui.h"

typedef struct {

	lv_obj_t* btnCtrl;					    	/* 进入控制界面 */
	lv_obj_t* btnPrinter;						/* 进入获取SD卡 */
	lv_obj_t* btnSettings;						/* 进入设置界面 */

	lv_obj_t* labelCtrl;						/* 显示控制界面label */					
	lv_obj_t* labelPrinter;						/* 显示获取SD卡label */
	lv_obj_t* labelSettings;					/* 显示设置界面label */	

	lv_obj_t* label_wpos;						/* 显示工作坐标 */
	lv_obj_t* label_mpos;						/* 显示机械坐标 */
	lv_obj_t* labelPower;						/* 显示主轴功率 */
	lv_obj_t* labelWifiState;					/* 显示wifi状态 */

	lv_style_t imgbtn_style;
	lv_timer_t* ready_page_upadte;

}ready_ui_t;
extern ready_ui_t ready_page;


void draw_ready(void);
void clear_ready_page(void);

#endif
