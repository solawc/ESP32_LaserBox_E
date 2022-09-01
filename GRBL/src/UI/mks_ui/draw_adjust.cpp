#include "draw_adjust.h"

ctrl_ui_t ctrl_page;


static void dispMoveBtn(void);
static void dispLabel(void);

static void event_handler(lv_event_t* e) {

    lv_event_code_t code = lv_event_get_code(e);  /* get obj event */ 
    char str[96];

    if (code == LV_EVENT_RELEASED) {

        if(e->current_target == ctrl_page.btnReturn) {
            clear_ctrl_page();
            draw_ready();
        }
        else if( e->current_target == ctrl_page.btnLeft) {
            sprintf(str, "$J=G91X-%.3fF%d\n", ctrl_page.stepLen, ctrl_page.stepSpeed);
            GRBL_CMD_SEND(str);
        }
        else if( e->current_target == ctrl_page.btnRight) {
            sprintf(str, "$J=G91X%.3fF%d\n", ctrl_page.stepLen, ctrl_page.stepSpeed);
            GRBL_CMD_SEND(str);
        }
        else if( e->current_target == ctrl_page.btnUp) {
            sprintf(str, "$J=G91Y%.3fF%d\n", ctrl_page.stepLen, ctrl_page.stepSpeed);
            GRBL_CMD_SEND(str);
        }
        else if( e->current_target == ctrl_page.btnDown) {
            sprintf(str, "$J=G91Y-%.3fF%d\n", ctrl_page.stepLen, ctrl_page.stepSpeed);
            GRBL_CMD_SEND(str);
        }
    }
}


void draw_ctrl(void) {

    /* Init parg  TODO..*/
    ctrl_page.stepLen = 10;
    ctrl_page.stepSpeed = 3000;

    /* disp all btn */
    dispMoveBtn();

    /* disp all label */
    dispLabel();
}

/**
 * 使用指令控制轴移动
 * axis - 移动的轴
 * stepLen - 移动距离
 * stepSpeed - 移动速度
 */
void setStepMove(char axis, float stepLen, uint32_t stepSpeed) {


}

static void dispMoveBtn(void) {
    ctrl_page.btnReturn = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ctrl_page.btnReturn, 100, 50);
	lv_obj_set_pos(ctrl_page.btnReturn, 1, 1);
    lv_obj_add_event_cb(ctrl_page.btnReturn, event_handler, LV_EVENT_ALL, nullptr);

    ctrl_page.btnUp = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ctrl_page.btnUp, 50, 50);
	lv_obj_set_pos(ctrl_page.btnUp, 60, 100);
    lv_obj_add_event_cb(ctrl_page.btnUp, event_handler, LV_EVENT_ALL, nullptr);

    ctrl_page.btnDown = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ctrl_page.btnDown, 50, 50);
	lv_obj_set_pos(ctrl_page.btnDown, 60, 200);
    lv_obj_add_event_cb(ctrl_page.btnDown, event_handler, LV_EVENT_ALL, nullptr);

    ctrl_page.btnLeft = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ctrl_page.btnLeft, 50, 50);
	lv_obj_set_pos(ctrl_page.btnLeft, 10, 150);
    lv_obj_add_event_cb(ctrl_page.btnLeft, event_handler, LV_EVENT_ALL, nullptr);

    ctrl_page.btnRight = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ctrl_page.btnRight, 50, 50);
	lv_obj_set_pos(ctrl_page.btnRight, 110, 150);
    lv_obj_add_event_cb(ctrl_page.btnRight, event_handler, LV_EVENT_ALL, nullptr);

    ctrl_page.btnZup = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ctrl_page.btnZup, 50, 50);
	lv_obj_set_pos(ctrl_page.btnZup, 10, 260);
    lv_obj_add_event_cb(ctrl_page.btnZup, event_handler, LV_EVENT_ALL, nullptr);

    ctrl_page.btnZdown = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ctrl_page.btnZdown, 50, 50);
	lv_obj_set_pos(ctrl_page.btnZdown, 110, 260);
    lv_obj_add_event_cb(ctrl_page.btnZdown, event_handler, LV_EVENT_ALL, nullptr);
}

static void dispLabel(void) {

    ctrl_page.labelUp = lv_label_create(ctrl_page.btnUp);
    ctrl_page.labelDown = lv_label_create(ctrl_page.btnDown);
    ctrl_page.labelLeft = lv_label_create(ctrl_page.btnLeft);
    ctrl_page.labelRight = lv_label_create(ctrl_page.btnRight);
    ctrl_page.labelZup = lv_label_create(ctrl_page.btnZup);
    ctrl_page.labelZdown = lv_label_create(ctrl_page.btnZdown);
    ctrl_page.labelReturn = lv_label_create(ctrl_page.btnReturn);

    lv_obj_set_align(ctrl_page.labelUp, LV_ALIGN_CENTER);
	lv_obj_set_align(ctrl_page.labelDown, LV_ALIGN_CENTER);
	lv_obj_set_align(ctrl_page.labelLeft, LV_ALIGN_CENTER);
	lv_obj_set_align(ctrl_page.labelRight, LV_ALIGN_CENTER);
    lv_obj_set_align(ctrl_page.labelReturn, LV_ALIGN_CENTER);
    lv_obj_set_align(ctrl_page.labelZup, LV_ALIGN_CENTER);
    lv_obj_set_align(ctrl_page.labelZdown, LV_ALIGN_CENTER);

    lv_label_set_text(ctrl_page.labelUp, "U");
    lv_label_set_text(ctrl_page.labelDown, "D");
    lv_label_set_text(ctrl_page.labelLeft, "L");
    lv_label_set_text(ctrl_page.labelRight, "R");
    lv_label_set_text(ctrl_page.labelZup, "Z-U");
    lv_label_set_text(ctrl_page.labelZdown, "Z-D");   
    lv_label_set_text(ctrl_page.labelReturn, "Return");
}


void clear_ctrl_page(void) {
	lv_obj_clean(lv_ui.main_src);				
}

