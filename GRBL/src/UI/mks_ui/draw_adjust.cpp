#include "draw_adjust.h"

ctrl_ui_t ctrl_page;


static void disp_move_btn(void);

static void event_handler(lv_event_t* e) {

    lv_event_code_t code = lv_event_get_code(e);  /* get obj event */ 

    if (code == LV_EVENT_RELEASED) {

        if(e->current_target == ctrl_page.btnReturn) {
            clear_ctrl_page();
            draw_ready();
        }
    }
}


void draw_ctrl(void) {

    /* disp all btn */
    disp_move_btn();


}

static void disp_move_btn(void) {

    ctrl_page.btnReturn = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ctrl_page.btnReturn, 50, 50);
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
}


void clear_ctrl_page(void) {
	lv_obj_clean(lv_ui.main_src);				
}

