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


void setup_scr_larse_power(lv_ui *ui){

	//Write codes larse_power
	ui->larse_power = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->larse_power, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_main_main_default
	static lv_style_t style_larse_power_main_main_default;
	if (style_larse_power_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_main_main_default);
	else
		lv_style_init(&style_larse_power_main_main_default);
	lv_style_set_bg_color(&style_larse_power_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_larse_power_main_main_default, 255);
	lv_obj_add_style(ui->larse_power, &style_larse_power_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes larse_power_imgbtn_larsepower_return
	ui->larse_power_imgbtn_larsepower_return = lv_imgbtn_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_imgbtn_larsepower_return, 24, 16);
	lv_obj_set_size(ui->larse_power_imgbtn_larsepower_return, 82, 42);
	lv_obj_set_scrollbar_mode(ui->larse_power_imgbtn_larsepower_return, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_imgbtn_larsepower_return_main_main_default
	static lv_style_t style_larse_power_imgbtn_larsepower_return_main_main_default;
	if (style_larse_power_imgbtn_larsepower_return_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_imgbtn_larsepower_return_main_main_default);
	else
		lv_style_init(&style_larse_power_imgbtn_larsepower_return_main_main_default);
	lv_style_set_text_color(&style_larse_power_imgbtn_larsepower_return_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_larse_power_imgbtn_larsepower_return_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_larse_power_imgbtn_larsepower_return_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_larse_power_imgbtn_larsepower_return_main_main_default, 0);
	lv_style_set_img_opa(&style_larse_power_imgbtn_larsepower_return_main_main_default, 255);
	lv_obj_add_style(ui->larse_power_imgbtn_larsepower_return, &style_larse_power_imgbtn_larsepower_return_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_larse_power_imgbtn_larsepower_return_main_main_pressed
	static lv_style_t style_larse_power_imgbtn_larsepower_return_main_main_pressed;
	if (style_larse_power_imgbtn_larsepower_return_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_larse_power_imgbtn_larsepower_return_main_main_pressed);
	else
		lv_style_init(&style_larse_power_imgbtn_larsepower_return_main_main_pressed);
	lv_style_set_text_color(&style_larse_power_imgbtn_larsepower_return_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_larse_power_imgbtn_larsepower_return_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_larse_power_imgbtn_larsepower_return_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_larse_power_imgbtn_larsepower_return_main_main_pressed, 0);
	lv_style_set_img_opa(&style_larse_power_imgbtn_larsepower_return_main_main_pressed, 255);
	lv_obj_add_style(ui->larse_power_imgbtn_larsepower_return, &style_larse_power_imgbtn_larsepower_return_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_larse_power_imgbtn_larsepower_return_main_main_checked
	static lv_style_t style_larse_power_imgbtn_larsepower_return_main_main_checked;
	if (style_larse_power_imgbtn_larsepower_return_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_larse_power_imgbtn_larsepower_return_main_main_checked);
	else
		lv_style_init(&style_larse_power_imgbtn_larsepower_return_main_main_checked);
	lv_style_set_text_color(&style_larse_power_imgbtn_larsepower_return_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_larse_power_imgbtn_larsepower_return_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_larse_power_imgbtn_larsepower_return_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_larse_power_imgbtn_larsepower_return_main_main_checked, 0);
	lv_style_set_img_opa(&style_larse_power_imgbtn_larsepower_return_main_main_checked, 255);
	lv_obj_add_style(ui->larse_power_imgbtn_larsepower_return, &style_larse_power_imgbtn_larsepower_return_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->larse_power_imgbtn_larsepower_return, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_82x42, NULL);
	lv_obj_add_flag(ui->larse_power_imgbtn_larsepower_return, LV_OBJ_FLAG_CHECKABLE);

	//Write codes larse_power_label_1
	ui->larse_power_label_1 = lv_label_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_label_1, 55, 71);
	lv_obj_set_size(ui->larse_power_label_1, 149, 29);
	lv_obj_set_scrollbar_mode(ui->larse_power_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->larse_power_label_1, "Larse Power Off");
	lv_label_set_long_mode(ui->larse_power_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_label_1_main_main_default
	static lv_style_t style_larse_power_label_1_main_main_default;
	if (style_larse_power_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_label_1_main_main_default);
	else
		lv_style_init(&style_larse_power_label_1_main_main_default);
	lv_style_set_radius(&style_larse_power_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_larse_power_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_larse_power_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_larse_power_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_larse_power_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_larse_power_label_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_larse_power_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_larse_power_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_larse_power_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_larse_power_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_larse_power_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_larse_power_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_larse_power_label_1_main_main_default, 0);
	lv_obj_add_style(ui->larse_power_label_1, &style_larse_power_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes larse_power_sw_1
	ui->larse_power_sw_1 = lv_switch_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_sw_1, 315, 65);
	lv_obj_set_size(ui->larse_power_sw_1, 40, 20);
	lv_obj_set_scrollbar_mode(ui->larse_power_sw_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_sw_1_main_main_default
	static lv_style_t style_larse_power_sw_1_main_main_default;
	if (style_larse_power_sw_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_sw_1_main_main_default);
	else
		lv_style_init(&style_larse_power_sw_1_main_main_default);
	lv_style_set_radius(&style_larse_power_sw_1_main_main_default, 100);
	lv_style_set_bg_color(&style_larse_power_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_color(&style_larse_power_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_dir(&style_larse_power_sw_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_sw_1_main_main_default, 255);
	lv_style_set_border_color(&style_larse_power_sw_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_larse_power_sw_1_main_main_default, 0);
	lv_style_set_border_opa(&style_larse_power_sw_1_main_main_default, 255);
	lv_obj_add_style(ui->larse_power_sw_1, &style_larse_power_sw_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_larse_power_sw_1_main_indicator_checked
	static lv_style_t style_larse_power_sw_1_main_indicator_checked;
	if (style_larse_power_sw_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_larse_power_sw_1_main_indicator_checked);
	else
		lv_style_init(&style_larse_power_sw_1_main_indicator_checked);
	lv_style_set_bg_color(&style_larse_power_sw_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_larse_power_sw_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_larse_power_sw_1_main_indicator_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_sw_1_main_indicator_checked, 255);
	lv_style_set_border_color(&style_larse_power_sw_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_larse_power_sw_1_main_indicator_checked, 0);
	lv_style_set_border_opa(&style_larse_power_sw_1_main_indicator_checked, 255);
	lv_obj_add_style(ui->larse_power_sw_1, &style_larse_power_sw_1_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_sw_1_main_knob_default
	static lv_style_t style_larse_power_sw_1_main_knob_default;
	if (style_larse_power_sw_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_sw_1_main_knob_default);
	else
		lv_style_init(&style_larse_power_sw_1_main_knob_default);
	lv_style_set_radius(&style_larse_power_sw_1_main_knob_default, 100);
	lv_style_set_bg_color(&style_larse_power_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_larse_power_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_larse_power_sw_1_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_sw_1_main_knob_default, 255);
	lv_style_set_border_color(&style_larse_power_sw_1_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_larse_power_sw_1_main_knob_default, 0);
	lv_style_set_border_opa(&style_larse_power_sw_1_main_knob_default, 255);
	lv_obj_add_style(ui->larse_power_sw_1, &style_larse_power_sw_1_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes larse_power_img_1
	ui->larse_power_img_1 = lv_img_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_img_1, 88, 100);
	lv_obj_set_size(ui->larse_power_img_1, 47, 37);
	lv_obj_set_scrollbar_mode(ui->larse_power_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_img_1_main_main_default
	static lv_style_t style_larse_power_img_1_main_main_default;
	if (style_larse_power_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_img_1_main_main_default);
	else
		lv_style_init(&style_larse_power_img_1_main_main_default);
	lv_style_set_img_recolor(&style_larse_power_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_larse_power_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_larse_power_img_1_main_main_default, 255);
	lv_obj_add_style(ui->larse_power_img_1, &style_larse_power_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->larse_power_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->larse_power_img_1,&_5_power_47x37);
	lv_img_set_pivot(ui->larse_power_img_1, 0,0);
	lv_img_set_angle(ui->larse_power_img_1, 0);

	//Write codes larse_power_img_2
	ui->larse_power_img_2 = lv_img_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_img_2, 90, 139);
	lv_obj_set_size(ui->larse_power_img_2, 44, 44);
	lv_obj_set_scrollbar_mode(ui->larse_power_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_img_2_main_main_default
	static lv_style_t style_larse_power_img_2_main_main_default;
	if (style_larse_power_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_img_2_main_main_default);
	else
		lv_style_init(&style_larse_power_img_2_main_main_default);
	lv_style_set_img_recolor(&style_larse_power_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_larse_power_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_larse_power_img_2_main_main_default, 255);
	lv_obj_add_style(ui->larse_power_img_2, &style_larse_power_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->larse_power_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->larse_power_img_2,&_25_power_44x44);
	lv_img_set_pivot(ui->larse_power_img_2, 0,0);
	lv_img_set_angle(ui->larse_power_img_2, 0);

	//Write codes larse_power_img_3
	ui->larse_power_img_3 = lv_img_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_img_3, 90, 185);
	lv_obj_set_size(ui->larse_power_img_3, 44, 46);
	lv_obj_set_scrollbar_mode(ui->larse_power_img_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_img_3_main_main_default
	static lv_style_t style_larse_power_img_3_main_main_default;
	if (style_larse_power_img_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_img_3_main_main_default);
	else
		lv_style_init(&style_larse_power_img_3_main_main_default);
	lv_style_set_img_recolor(&style_larse_power_img_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_larse_power_img_3_main_main_default, 0);
	lv_style_set_img_opa(&style_larse_power_img_3_main_main_default, 255);
	lv_obj_add_style(ui->larse_power_img_3, &style_larse_power_img_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->larse_power_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->larse_power_img_3,&_half_power_44x46);
	lv_img_set_pivot(ui->larse_power_img_3, 0,0);
	lv_img_set_angle(ui->larse_power_img_3, 0);

	//Write codes larse_power_img_4
	ui->larse_power_img_4 = lv_img_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_img_4, 88, 231);
	lv_obj_set_size(ui->larse_power_img_4, 46, 47);
	lv_obj_set_scrollbar_mode(ui->larse_power_img_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_img_4_main_main_default
	static lv_style_t style_larse_power_img_4_main_main_default;
	if (style_larse_power_img_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_img_4_main_main_default);
	else
		lv_style_init(&style_larse_power_img_4_main_main_default);
	lv_style_set_img_recolor(&style_larse_power_img_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_larse_power_img_4_main_main_default, 0);
	lv_style_set_img_opa(&style_larse_power_img_4_main_main_default, 255);
	lv_obj_add_style(ui->larse_power_img_4, &style_larse_power_img_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->larse_power_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->larse_power_img_4,&_100_power_46x47);
	lv_img_set_pivot(ui->larse_power_img_4, 0,0);
	lv_img_set_angle(ui->larse_power_img_4, 0);

	//Write codes larse_power_cb_1
	ui->larse_power_cb_1 = lv_checkbox_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_cb_1, 325, 110);
	lv_obj_set_scrollbar_mode(ui->larse_power_cb_1, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->larse_power_cb_1, "");

	//Write style state: LV_STATE_DEFAULT for style_larse_power_cb_1_main_main_default
	static lv_style_t style_larse_power_cb_1_main_main_default;
	if (style_larse_power_cb_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_cb_1_main_main_default);
	else
		lv_style_init(&style_larse_power_cb_1_main_main_default);
	lv_style_set_radius(&style_larse_power_cb_1_main_main_default, 6);
	lv_style_set_bg_color(&style_larse_power_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_larse_power_cb_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_larse_power_cb_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_cb_1_main_main_default, 0);
	lv_style_set_text_color(&style_larse_power_cb_1_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_letter_space(&style_larse_power_cb_1_main_main_default, 2);
	lv_obj_add_style(ui->larse_power_cb_1, &style_larse_power_cb_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_cb_1_main_indicator_default
	static lv_style_t style_larse_power_cb_1_main_indicator_default;
	if (style_larse_power_cb_1_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_cb_1_main_indicator_default);
	else
		lv_style_init(&style_larse_power_cb_1_main_indicator_default);
	lv_style_set_radius(&style_larse_power_cb_1_main_indicator_default, 6);
	lv_style_set_bg_color(&style_larse_power_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_larse_power_cb_1_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_larse_power_cb_1_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_cb_1_main_indicator_default, 255);
	lv_style_set_border_color(&style_larse_power_cb_1_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_larse_power_cb_1_main_indicator_default, 2);
	lv_style_set_border_opa(&style_larse_power_cb_1_main_indicator_default, 255);
	lv_obj_add_style(ui->larse_power_cb_1, &style_larse_power_cb_1_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes larse_power_cb_2
	ui->larse_power_cb_2 = lv_checkbox_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_cb_2, 325, 152);
	lv_obj_set_scrollbar_mode(ui->larse_power_cb_2, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->larse_power_cb_2, "");

	//Write style state: LV_STATE_DEFAULT for style_larse_power_cb_2_main_main_default
	static lv_style_t style_larse_power_cb_2_main_main_default;
	if (style_larse_power_cb_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_cb_2_main_main_default);
	else
		lv_style_init(&style_larse_power_cb_2_main_main_default);
	lv_style_set_radius(&style_larse_power_cb_2_main_main_default, 6);
	lv_style_set_bg_color(&style_larse_power_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_larse_power_cb_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_larse_power_cb_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_cb_2_main_main_default, 0);
	lv_style_set_text_color(&style_larse_power_cb_2_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_letter_space(&style_larse_power_cb_2_main_main_default, 2);
	lv_obj_add_style(ui->larse_power_cb_2, &style_larse_power_cb_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_cb_2_main_indicator_default
	static lv_style_t style_larse_power_cb_2_main_indicator_default;
	if (style_larse_power_cb_2_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_cb_2_main_indicator_default);
	else
		lv_style_init(&style_larse_power_cb_2_main_indicator_default);
	lv_style_set_radius(&style_larse_power_cb_2_main_indicator_default, 6);
	lv_style_set_bg_color(&style_larse_power_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_larse_power_cb_2_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_larse_power_cb_2_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_cb_2_main_indicator_default, 255);
	lv_style_set_border_color(&style_larse_power_cb_2_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_larse_power_cb_2_main_indicator_default, 2);
	lv_style_set_border_opa(&style_larse_power_cb_2_main_indicator_default, 255);
	lv_obj_add_style(ui->larse_power_cb_2, &style_larse_power_cb_2_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes larse_power_cb_3
	ui->larse_power_cb_3 = lv_checkbox_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_cb_3, 325, 200);
	lv_obj_set_scrollbar_mode(ui->larse_power_cb_3, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->larse_power_cb_3, "");

	//Write style state: LV_STATE_DEFAULT for style_larse_power_cb_3_main_main_default
	static lv_style_t style_larse_power_cb_3_main_main_default;
	if (style_larse_power_cb_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_cb_3_main_main_default);
	else
		lv_style_init(&style_larse_power_cb_3_main_main_default);
	lv_style_set_radius(&style_larse_power_cb_3_main_main_default, 6);
	lv_style_set_bg_color(&style_larse_power_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_larse_power_cb_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_larse_power_cb_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_cb_3_main_main_default, 0);
	lv_style_set_text_color(&style_larse_power_cb_3_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_letter_space(&style_larse_power_cb_3_main_main_default, 2);
	lv_obj_add_style(ui->larse_power_cb_3, &style_larse_power_cb_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_cb_3_main_indicator_default
	static lv_style_t style_larse_power_cb_3_main_indicator_default;
	if (style_larse_power_cb_3_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_cb_3_main_indicator_default);
	else
		lv_style_init(&style_larse_power_cb_3_main_indicator_default);
	lv_style_set_radius(&style_larse_power_cb_3_main_indicator_default, 6);
	lv_style_set_bg_color(&style_larse_power_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_larse_power_cb_3_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_larse_power_cb_3_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_cb_3_main_indicator_default, 255);
	lv_style_set_border_color(&style_larse_power_cb_3_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_larse_power_cb_3_main_indicator_default, 2);
	lv_style_set_border_opa(&style_larse_power_cb_3_main_indicator_default, 255);
	lv_obj_add_style(ui->larse_power_cb_3, &style_larse_power_cb_3_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes larse_power_cb_4
	ui->larse_power_cb_4 = lv_checkbox_create(ui->larse_power);
	lv_obj_set_pos(ui->larse_power_cb_4, 325, 246);
	lv_obj_set_scrollbar_mode(ui->larse_power_cb_4, LV_SCROLLBAR_MODE_OFF);
	lv_checkbox_set_text(ui->larse_power_cb_4, "");

	//Write style state: LV_STATE_DEFAULT for style_larse_power_cb_4_main_main_default
	static lv_style_t style_larse_power_cb_4_main_main_default;
	if (style_larse_power_cb_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_cb_4_main_main_default);
	else
		lv_style_init(&style_larse_power_cb_4_main_main_default);
	lv_style_set_radius(&style_larse_power_cb_4_main_main_default, 6);
	lv_style_set_bg_color(&style_larse_power_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_larse_power_cb_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_larse_power_cb_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_cb_4_main_main_default, 0);
	lv_style_set_text_color(&style_larse_power_cb_4_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_letter_space(&style_larse_power_cb_4_main_main_default, 2);
	lv_obj_add_style(ui->larse_power_cb_4, &style_larse_power_cb_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_larse_power_cb_4_main_indicator_default
	static lv_style_t style_larse_power_cb_4_main_indicator_default;
	if (style_larse_power_cb_4_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_larse_power_cb_4_main_indicator_default);
	else
		lv_style_init(&style_larse_power_cb_4_main_indicator_default);
	lv_style_set_radius(&style_larse_power_cb_4_main_indicator_default, 6);
	lv_style_set_bg_color(&style_larse_power_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_larse_power_cb_4_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_larse_power_cb_4_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_larse_power_cb_4_main_indicator_default, 255);
	lv_style_set_border_color(&style_larse_power_cb_4_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_larse_power_cb_4_main_indicator_default, 2);
	lv_style_set_border_opa(&style_larse_power_cb_4_main_indicator_default, 255);
	lv_obj_add_style(ui->larse_power_cb_4, &style_larse_power_cb_4_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	events_init_larse_power(ui);
}