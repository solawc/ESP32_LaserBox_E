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


void setup_scr_about(lv_ui *ui){

	//Write codes about
	ui->about = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->about, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_about_main_main_default
	static lv_style_t style_about_main_main_default;
	if (style_about_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_main_main_default);
	else
		lv_style_init(&style_about_main_main_default);
	lv_style_set_bg_color(&style_about_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_about_main_main_default, 255);
	lv_obj_add_style(ui->about, &style_about_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes about_img_info
	ui->about_img_info = lv_img_create(ui->about);
	lv_obj_set_pos(ui->about_img_info, 91, 72);
	lv_obj_set_size(ui->about_img_info, 290, 102);
	lv_obj_set_scrollbar_mode(ui->about_img_info, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_about_img_info_main_main_default
	static lv_style_t style_about_img_info_main_main_default;
	if (style_about_img_info_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_img_info_main_main_default);
	else
		lv_style_init(&style_about_img_info_main_main_default);
	lv_style_set_img_recolor(&style_about_img_info_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_about_img_info_main_main_default, 0);
	lv_style_set_img_opa(&style_about_img_info_main_main_default, 255);
	lv_obj_add_style(ui->about_img_info, &style_about_img_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->about_img_info, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->about_img_info,&_about_290x102);
	lv_img_set_pivot(ui->about_img_info, 0,0);
	lv_img_set_angle(ui->about_img_info, 0);

	//Write codes about_imgbtn_about_return
	ui->about_imgbtn_about_return = lv_imgbtn_create(ui->about);
	lv_obj_set_pos(ui->about_imgbtn_about_return, 26, 15);
	lv_obj_set_size(ui->about_imgbtn_about_return, 102, 38);
	lv_obj_set_scrollbar_mode(ui->about_imgbtn_about_return, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_about_imgbtn_about_return_main_main_default
	static lv_style_t style_about_imgbtn_about_return_main_main_default;
	if (style_about_imgbtn_about_return_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_about_imgbtn_about_return_main_main_default);
	else
		lv_style_init(&style_about_imgbtn_about_return_main_main_default);
	lv_style_set_text_color(&style_about_imgbtn_about_return_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_about_imgbtn_about_return_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_about_imgbtn_about_return_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_about_imgbtn_about_return_main_main_default, 0);
	lv_style_set_img_opa(&style_about_imgbtn_about_return_main_main_default, 255);
	lv_obj_add_style(ui->about_imgbtn_about_return, &style_about_imgbtn_about_return_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_about_imgbtn_about_return_main_main_pressed
	static lv_style_t style_about_imgbtn_about_return_main_main_pressed;
	if (style_about_imgbtn_about_return_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_about_imgbtn_about_return_main_main_pressed);
	else
		lv_style_init(&style_about_imgbtn_about_return_main_main_pressed);
	lv_style_set_text_color(&style_about_imgbtn_about_return_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_about_imgbtn_about_return_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_about_imgbtn_about_return_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_about_imgbtn_about_return_main_main_pressed, 0);
	lv_style_set_img_opa(&style_about_imgbtn_about_return_main_main_pressed, 255);
	lv_obj_add_style(ui->about_imgbtn_about_return, &style_about_imgbtn_about_return_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_about_imgbtn_about_return_main_main_checked
	static lv_style_t style_about_imgbtn_about_return_main_main_checked;
	if (style_about_imgbtn_about_return_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_about_imgbtn_about_return_main_main_checked);
	else
		lv_style_init(&style_about_imgbtn_about_return_main_main_checked);
	lv_style_set_text_color(&style_about_imgbtn_about_return_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_about_imgbtn_about_return_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_about_imgbtn_about_return_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_about_imgbtn_about_return_main_main_checked, 0);
	lv_style_set_img_opa(&style_about_imgbtn_about_return_main_main_checked, 255);
	lv_obj_add_style(ui->about_imgbtn_about_return, &style_about_imgbtn_about_return_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->about_imgbtn_about_return, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_102x38, NULL);
	lv_obj_add_flag(ui->about_imgbtn_about_return, LV_OBJ_FLAG_CHECKABLE);
}