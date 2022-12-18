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


void setup_scr_setting_parameter(lv_ui *ui){

	//Write codes setting_parameter
	ui->setting_parameter = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->setting_parameter, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_setting_parameter_main_main_default
	static lv_style_t style_setting_parameter_main_main_default;
	if (style_setting_parameter_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_setting_parameter_main_main_default);
	else
		lv_style_init(&style_setting_parameter_main_main_default);
	lv_style_set_bg_color(&style_setting_parameter_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_setting_parameter_main_main_default, 255);
	lv_obj_add_style(ui->setting_parameter, &style_setting_parameter_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setting_parameter_imgbtn_setting_paremeter_return
	ui->setting_parameter_imgbtn_setting_paremeter_return = lv_imgbtn_create(ui->setting_parameter);
	lv_obj_set_pos(ui->setting_parameter_imgbtn_setting_paremeter_return, 21, 16);
	lv_obj_set_size(ui->setting_parameter_imgbtn_setting_paremeter_return, 100, 50);
	lv_obj_set_scrollbar_mode(ui->setting_parameter_imgbtn_setting_paremeter_return, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default
	static lv_style_t style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default;
	if (style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default);
	else
		lv_style_init(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default);
	lv_style_set_text_color(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default, 0);
	lv_style_set_img_opa(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default, 255);
	lv_obj_add_style(ui->setting_parameter_imgbtn_setting_paremeter_return, &style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed
	static lv_style_t style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed;
	if (style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed);
	else
		lv_style_init(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed);
	lv_style_set_text_color(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed, 0);
	lv_style_set_img_opa(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed, 255);
	lv_obj_add_style(ui->setting_parameter_imgbtn_setting_paremeter_return, &style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked
	static lv_style_t style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked;
	if (style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked);
	else
		lv_style_init(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked);
	lv_style_set_text_color(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked, 0);
	lv_style_set_img_opa(&style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked, 255);
	lv_obj_add_style(ui->setting_parameter_imgbtn_setting_paremeter_return, &style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->setting_parameter_imgbtn_setting_paremeter_return, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_100x50, NULL);
	lv_obj_add_flag(ui->setting_parameter_imgbtn_setting_paremeter_return, LV_OBJ_FLAG_CHECKABLE);

	//Write codes setting_parameter_imgbtn_setting
	ui->setting_parameter_imgbtn_setting = lv_imgbtn_create(ui->setting_parameter);
	lv_obj_set_pos(ui->setting_parameter_imgbtn_setting, 63, 76);
	lv_obj_set_size(ui->setting_parameter_imgbtn_setting, 189, 50);
	lv_obj_set_scrollbar_mode(ui->setting_parameter_imgbtn_setting, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_setting_parameter_imgbtn_setting_main_main_default
	static lv_style_t style_setting_parameter_imgbtn_setting_main_main_default;
	if (style_setting_parameter_imgbtn_setting_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_setting_parameter_imgbtn_setting_main_main_default);
	else
		lv_style_init(&style_setting_parameter_imgbtn_setting_main_main_default);
	lv_style_set_text_color(&style_setting_parameter_imgbtn_setting_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_setting_parameter_imgbtn_setting_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_setting_parameter_imgbtn_setting_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_setting_parameter_imgbtn_setting_main_main_default, 0);
	lv_style_set_img_opa(&style_setting_parameter_imgbtn_setting_main_main_default, 255);
	lv_obj_add_style(ui->setting_parameter_imgbtn_setting, &style_setting_parameter_imgbtn_setting_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_setting_parameter_imgbtn_setting_main_main_pressed
	static lv_style_t style_setting_parameter_imgbtn_setting_main_main_pressed;
	if (style_setting_parameter_imgbtn_setting_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_setting_parameter_imgbtn_setting_main_main_pressed);
	else
		lv_style_init(&style_setting_parameter_imgbtn_setting_main_main_pressed);
	lv_style_set_text_color(&style_setting_parameter_imgbtn_setting_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_setting_parameter_imgbtn_setting_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_setting_parameter_imgbtn_setting_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_setting_parameter_imgbtn_setting_main_main_pressed, 0);
	lv_style_set_img_opa(&style_setting_parameter_imgbtn_setting_main_main_pressed, 255);
	lv_obj_add_style(ui->setting_parameter_imgbtn_setting, &style_setting_parameter_imgbtn_setting_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_setting_parameter_imgbtn_setting_main_main_checked
	static lv_style_t style_setting_parameter_imgbtn_setting_main_main_checked;
	if (style_setting_parameter_imgbtn_setting_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_setting_parameter_imgbtn_setting_main_main_checked);
	else
		lv_style_init(&style_setting_parameter_imgbtn_setting_main_main_checked);
	lv_style_set_text_color(&style_setting_parameter_imgbtn_setting_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_setting_parameter_imgbtn_setting_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_setting_parameter_imgbtn_setting_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_setting_parameter_imgbtn_setting_main_main_checked, 0);
	lv_style_set_img_opa(&style_setting_parameter_imgbtn_setting_main_main_checked, 255);
	lv_obj_add_style(ui->setting_parameter_imgbtn_setting, &style_setting_parameter_imgbtn_setting_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->setting_parameter_imgbtn_setting, LV_IMGBTN_STATE_RELEASED, NULL, &_parameter_alpha_189x50, NULL);
	lv_obj_add_flag(ui->setting_parameter_imgbtn_setting, LV_OBJ_FLAG_CHECKABLE);

	//Init events for screen
	events_init_setting_parameter(ui);
}