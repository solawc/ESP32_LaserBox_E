#include "draw_ui.h"
#include "../tft_driver/tft_lcd.h"
lv_ui_t mks_lv_ui;

void allStyleInit(void) {

	lv_style_init(&mks_lv_ui.main_style);
	lv_style_set_bg_color(&mks_lv_ui.main_style, lv_color_hex(MAIN_BG_COLOR));
	lv_style_set_bg_opa(&mks_lv_ui.main_style, LV_OPA_COVER);
	lv_style_set_text_color(&mks_lv_ui.main_style, lv_color_white());
	lv_obj_add_style(mks_lv_ui.main_src, &mks_lv_ui.main_style, 0);

	lv_style_init(&mks_lv_ui.src1_style);
	lv_style_set_bg_color(&mks_lv_ui.src1_style, lv_color_hex(SRC1_BG_COLOR));
	lv_style_set_bg_opa(&mks_lv_ui.src1_style, LV_OPA_COVER);
	lv_style_set_border_width(&mks_lv_ui.src1_style, 0);
	lv_style_set_radius(&mks_lv_ui.src1_style, 17);
}

void drawLogoTaskCb(lv_timer_t*) {
	tft_lcd.tftBglightSetOn();
	delay(1000);
	lv_obj_del(mks_lv_ui.mks_logo);
	draw_ready();
	lv_timer_del(mks_lv_ui.timer_logo);
}

void lvDrawLogo(void) {

	mks_lv_ui.main_src = lv_obj_create(NULL);
	mks_lv_ui.main_src = lv_scr_act();
	lv_obj_clear_flag(mks_lv_ui.main_src, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(mks_lv_ui.main_src, 480, 320);
	lv_obj_remove_style_all(mks_lv_ui.main_src);

	/* Creat logo */
	mks_lv_ui.mks_logo = lv_img_create(mks_lv_ui.main_src);
	// lv_img_set_src(mks_lv_ui.mks_logo, "M:/mks_logo.bin");

	/* Init all style */
	allStyleInit();

	/* Tick 2000ms */
	mks_lv_ui.timer_logo = lv_timer_create(drawLogoTaskCb, 2000, NULL);
}

#ifdef USE_WINDOS_LIST
void runMksUiDemo(void) {
	lvDrawLogo();
}
#endif
