#include "draw_sdcard.h"
#include "../../SDCard.h"

sd_page_t sd_page;

static void disp_btn(void);
static void disp_label(void);

static void event_handler(lv_event_t* e) {

    lv_event_code_t code = lv_event_get_code(e); 

    if (code == LV_EVENT_RELEASED) {

        if(e->current_target == sd_page.btnReturn) {
            clear_sd_page();
            draw_ready();
        }
    }
}

void draw_sdcard(void) {
    disp_btn();
    disp_label();
}

static void disp_btn(void) {
    sd_page.btnReturn = lv_btn_create(lv_ui.main_src);
    lv_obj_set_size(sd_page.btnReturn, 100, 50);
	lv_obj_set_pos(sd_page.btnReturn, 1, 1);
	lv_obj_add_event_cb(sd_page.btnReturn, event_handler, LV_EVENT_ALL, nullptr);

    sd_page.btnSDCard = lv_btn_create(lv_ui.main_src);
    lv_obj_set_size(sd_page.btnSDCard, 100, 150);
	lv_obj_set_pos(sd_page.btnSDCard, 10, 100);
	lv_obj_add_event_cb(sd_page.btnSDCard, event_handler, LV_EVENT_ALL, nullptr);

}

static void disp_label(void) {

    sd_page.labelSDcardSize = lv_label_create(lv_ui.main_src);
    lv_obj_set_pos(sd_page.labelSDcardSize, 130, 100);
    lv_label_set_text_fmt(sd_page.labelSDcardSize, "Sdcard:6.4MB/%lluMB", mysdcard.get_sd_size());
}

void clear_sd_page(void) {
	lv_obj_clean(lv_ui.main_src);				
}




