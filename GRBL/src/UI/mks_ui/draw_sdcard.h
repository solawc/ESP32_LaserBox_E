#ifndef __draw_sdcard_h
#define __draw_sdcard_h

#include "draw_ui.h"


typedef struct {

    lv_obj_t* btnSDCard;                /* 按下后进入文件列表 */
    lv_obj_t* btnReturn;                /* 返回按键 */

    lv_obj_t* labelSDcardSize;          /* 显示SDcard总容量 */

}sd_page_t;

void draw_sdcard(void);
void clear_sd_page(void);

#endif
