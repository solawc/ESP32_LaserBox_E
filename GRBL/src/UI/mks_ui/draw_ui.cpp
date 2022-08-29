#include "draw_ui.h"

lv_ui_t lv_ui;

void allStyleInit(void) {

	lv_style_init(&lv_ui.main_style);
	lv_style_set_bg_color(&lv_ui.main_style, lv_color_hex(MAIN_BG_COLOR));
	lv_style_set_bg_opa(&lv_ui.main_style, LV_OPA_COVER);
	lv_style_set_text_color(&lv_ui.main_style, lv_color_white());
	lv_obj_add_style(lv_ui.main_src, &lv_ui.main_style, 0);

	lv_style_init(&lv_ui.src1_style);
	lv_style_set_bg_color(&lv_ui.src1_style, lv_color_hex(SRC1_BG_COLOR));
	lv_style_set_bg_opa(&lv_ui.src1_style, LV_OPA_COVER);
	lv_style_set_border_width(&lv_ui.src1_style, 0);
	lv_style_set_radius(&lv_ui.src1_style, 17);
}

void test_timer(lv_timer_t*) {
	lv_obj_del(lv_ui.mks_logo);
	draw_ready();
	lv_timer_del(lv_ui.timer_logo);
}

void lvDrawLogo(void) {

	lv_ui.main_src = lv_obj_create(NULL);
	lv_ui.main_src = lv_scr_act();
	lv_obj_clear_flag(lv_ui.main_src, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(lv_ui.main_src, 480, 320);
	lv_obj_remove_style_all(lv_ui.main_src);

	/* Creat logo */
	lv_ui.mks_logo = lv_img_create(lv_ui.main_src);
	lv_img_set_src(lv_ui.mks_logo, &mks_logo);

	/* Init all style */
	allStyleInit();

	/* Tick 2000ms */
	lv_ui.timer_logo = lv_timer_create(test_timer, 2000, NULL);
}

#ifdef USE_WINDOS_LIST
void runMksUiDemo(void) {
	lvDrawLogo();
}
#endif






