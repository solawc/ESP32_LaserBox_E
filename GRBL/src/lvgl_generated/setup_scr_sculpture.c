/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "./custom/custom.h"

static const lv_img_dsc_t* sculpture_animimg_1_imgs[1] = {
	&sculpture_animimg_1sculpture_file
};

void setup_scr_sculpture(lv_ui *ui){

	//Write codes sculpture
	ui->sculpture = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->sculpture, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sculpture_main_main_default
	static lv_style_t style_sculpture_main_main_default;
	if (style_sculpture_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sculpture_main_main_default);
	else
		lv_style_init(&style_sculpture_main_main_default);
	lv_style_set_bg_color(&style_sculpture_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_sculpture_main_main_default, 255);
	lv_obj_add_style(ui->sculpture, &style_sculpture_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sculpture_imgbtn_sculpture_return
	ui->sculpture_imgbtn_sculpture_return = lv_imgbtn_create(ui->sculpture);
	lv_obj_set_pos(ui->sculpture_imgbtn_sculpture_return, 6, 11);
	lv_obj_set_size(ui->sculpture_imgbtn_sculpture_return, 100, 50);
	lv_obj_set_scrollbar_mode(ui->sculpture_imgbtn_sculpture_return, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_sculpture_imgbtn_sculpture_return_main_main_default
	static lv_style_t style_sculpture_imgbtn_sculpture_return_main_main_default;
	if (style_sculpture_imgbtn_sculpture_return_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_sculpture_imgbtn_sculpture_return_main_main_default);
	else
		lv_style_init(&style_sculpture_imgbtn_sculpture_return_main_main_default);
	lv_style_set_text_color(&style_sculpture_imgbtn_sculpture_return_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_sculpture_imgbtn_sculpture_return_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_sculpture_imgbtn_sculpture_return_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_sculpture_imgbtn_sculpture_return_main_main_default, 0);
	lv_style_set_img_opa(&style_sculpture_imgbtn_sculpture_return_main_main_default, 255);
	lv_obj_add_style(ui->sculpture_imgbtn_sculpture_return, &style_sculpture_imgbtn_sculpture_return_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_sculpture_imgbtn_sculpture_return_main_main_pressed
	static lv_style_t style_sculpture_imgbtn_sculpture_return_main_main_pressed;
	if (style_sculpture_imgbtn_sculpture_return_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_sculpture_imgbtn_sculpture_return_main_main_pressed);
	else
		lv_style_init(&style_sculpture_imgbtn_sculpture_return_main_main_pressed);
	lv_style_set_text_color(&style_sculpture_imgbtn_sculpture_return_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_sculpture_imgbtn_sculpture_return_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_sculpture_imgbtn_sculpture_return_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_sculpture_imgbtn_sculpture_return_main_main_pressed, 0);
	lv_style_set_img_opa(&style_sculpture_imgbtn_sculpture_return_main_main_pressed, 255);
	lv_obj_add_style(ui->sculpture_imgbtn_sculpture_return, &style_sculpture_imgbtn_sculpture_return_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_sculpture_imgbtn_sculpture_return_main_main_checked
	static lv_style_t style_sculpture_imgbtn_sculpture_return_main_main_checked;
	if (style_sculpture_imgbtn_sculpture_return_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_sculpture_imgbtn_sculpture_return_main_main_checked);
	else
		lv_style_init(&style_sculpture_imgbtn_sculpture_return_main_main_checked);
	lv_style_set_text_color(&style_sculpture_imgbtn_sculpture_return_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_sculpture_imgbtn_sculpture_return_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_sculpture_imgbtn_sculpture_return_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_sculpture_imgbtn_sculpture_return_main_main_checked, 0);
	lv_style_set_img_opa(&style_sculpture_imgbtn_sculpture_return_main_main_checked, 255);
	lv_obj_add_style(ui->sculpture_imgbtn_sculpture_return, &style_sculpture_imgbtn_sculpture_return_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->sculpture_imgbtn_sculpture_return, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_100x50, NULL);
	lv_obj_add_flag(ui->sculpture_imgbtn_sculpture_return, LV_OBJ_FLAG_CHECKABLE);

	//Write codes sculpture_animimg_1
	ui->sculpture_animimg_1 = lv_animimg_create(ui->sculpture);
	lv_obj_set_pos(ui->sculpture_animimg_1, 385, 11);
	lv_obj_set_size(ui->sculpture_animimg_1, 50, 50);
	lv_obj_set_scrollbar_mode(ui->sculpture_animimg_1, LV_SCROLLBAR_MODE_OFF);
	lv_animimg_set_src(ui->sculpture_animimg_1, (lv_img_dsc_t**) sculpture_animimg_1_imgs, 1);
	lv_animimg_set_duration(ui->sculpture_animimg_1, 30);
	lv_animimg_set_repeat_count(ui->sculpture_animimg_1, 3000);
	lv_animimg_start(ui->sculpture_animimg_1);
}