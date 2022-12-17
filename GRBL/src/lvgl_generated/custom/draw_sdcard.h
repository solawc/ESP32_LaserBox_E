#pragma once

#include "../gui_guider.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {

    lv_obj_t* btnSDCard;                /* 按下后进入文件列表 */
    lv_obj_t* btnReturn;                /* 返回按键 */

    lv_obj_t* labelSDcardSize;          /* 显示SDcard总容量 */

    lv_obj_t* labelSDcardPath;          /* 当前浏览路径*/
    lv_obj_t* brower_area;             /*  文件列表显示区域 */
    lv_obj_t* file_list;

}my_sd_page_t;

void draw_sdcard(void);
void clear_sd_page(void);

#ifdef __cplusplus
}
#endif
