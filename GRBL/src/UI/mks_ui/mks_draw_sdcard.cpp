#include "mks_draw_sdcard.h"
#include "../../SDCard.h"

sd_page_t mks_sd_page;

static void disp_btn(void);
static void disp_label(void);

static void event_handler(lv_event_t* e) {

    lv_event_code_t code = lv_event_get_code(e); 

    if (code == LV_EVENT_RELEASED) {

        if(e->current_target == mks_sd_page.btnReturn) {
            mks_clear_sd_page();
            draw_ready();
        }
    }
}

void mks_draw_sdcard(void) {
    disp_btn();
    disp_label();
}

static void disp_btn(void) {
    mks_sd_page.btnReturn = lv_btn_create(mks_lv_ui.main_src);
    lv_obj_set_size(mks_sd_page.btnReturn, 100, 50);
	lv_obj_set_pos(mks_sd_page.btnReturn, 1, 1);
	lv_obj_add_event_cb(mks_sd_page.btnReturn, event_handler, LV_EVENT_ALL, nullptr);

    mks_sd_page.btnSDCard = lv_btn_create(mks_lv_ui.main_src);
    lv_obj_set_size(mks_sd_page.btnSDCard, 100, 150);
	lv_obj_set_pos(mks_sd_page.btnSDCard, 10, 100);
	lv_obj_add_event_cb(mks_sd_page.btnSDCard, event_handler, LV_EVENT_ALL, nullptr);

}

static void disp_label(void) {

    mks_sd_page.labelSDcardSize = lv_label_create(mks_lv_ui.main_src);
    lv_obj_set_pos(mks_sd_page.labelSDcardSize, 130, 100);
    lv_label_set_text_fmt(mks_sd_page.labelSDcardSize, "Sdcard:6.4MB/%lluMB", mysdcard.get_sd_size());
}

void mks_clear_sd_page(void) {
	lv_obj_clean(mks_lv_ui.main_src);				
}




