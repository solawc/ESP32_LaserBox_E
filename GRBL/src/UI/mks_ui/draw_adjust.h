#ifndef __draw_adjust_h
#define __draw_adjust_h

#include "draw_ui.h"

typedef struct {

    lv_obj_t* btnUp;                /* Y 正方向移动 */
    lv_obj_t* btnDown;              /* Y 负方向移动 */
    lv_obj_t* btnLeft;              /* X 负方向移动 */
    lv_obj_t* btnRight;             /* X 正方向移动 */
    lv_obj_t* btnZup;               /* Z 负方向移动 */
    lv_obj_t* btnZdown;             /* Z 正方向移动 */
    
    lv_obj_t* labelUp;              /* Y 正方向移动label */
    lv_obj_t* labelDown;            /* Y 负方向移动label */
    lv_obj_t* labelLeft;            /* X 负方向移动label */
    lv_obj_t* labelRight;           /* X 正方向移动label */
    lv_obj_t* labelZup;             /* Z 负方向移动 */
    lv_obj_t* labelZdown;           /* Z 正方向移动 */

    lv_obj_t* btnReturn;            /* 返回主页 */    
}ctrl_ui_t;


void draw_ctrl(void);
void clear_ctrl_page(void);

#endif