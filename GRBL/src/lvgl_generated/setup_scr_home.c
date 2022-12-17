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


void setup_scr_home(lv_ui *ui){

	//Write codes home
	ui->home = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->home, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_main_main_default
	static lv_style_t style_home_main_main_default;
	if (style_home_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_main_main_default);
	else
		lv_style_init(&style_home_main_main_default);
	lv_style_set_bg_color(&style_home_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_home_main_main_default, 255);
	lv_obj_add_style(ui->home, &style_home_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_btn_tool
	ui->home_btn_tool = lv_btn_create(ui->home);
	lv_obj_set_pos(ui->home_btn_tool, 18, 44);
	lv_obj_set_size(ui->home_btn_tool, 110, 32);
	lv_obj_set_scrollbar_mode(ui->home_btn_tool, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_btn_tool_main_main_default
	static lv_style_t style_home_btn_tool_main_main_default;
	if (style_home_btn_tool_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_btn_tool_main_main_default);
	else
		lv_style_init(&style_home_btn_tool_main_main_default);
	lv_style_set_radius(&style_home_btn_tool_main_main_default, 5);
	lv_style_set_bg_color(&style_home_btn_tool_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_home_btn_tool_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_btn_tool_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_btn_tool_main_main_default, 255);
	lv_style_set_border_color(&style_home_btn_tool_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_home_btn_tool_main_main_default, 0);
	lv_style_set_border_opa(&style_home_btn_tool_main_main_default, 255);
	lv_style_set_text_color(&style_home_btn_tool_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_btn_tool_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_home_btn_tool_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->home_btn_tool, &style_home_btn_tool_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->home_btn_tool_label = lv_label_create(ui->home_btn_tool);
	lv_label_set_text(ui->home_btn_tool_label, "Tool");
	lv_obj_set_style_pad_all(ui->home_btn_tool, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->home_btn_tool_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes home_btn_larsepower
	ui->home_btn_larsepower = lv_btn_create(ui->home);
	lv_obj_set_pos(ui->home_btn_larsepower, 18, 94);
	lv_obj_set_size(ui->home_btn_larsepower, 110, 32);
	lv_obj_set_scrollbar_mode(ui->home_btn_larsepower, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_btn_larsepower_main_main_default
	static lv_style_t style_home_btn_larsepower_main_main_default;
	if (style_home_btn_larsepower_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_btn_larsepower_main_main_default);
	else
		lv_style_init(&style_home_btn_larsepower_main_main_default);
	lv_style_set_radius(&style_home_btn_larsepower_main_main_default, 5);
	lv_style_set_bg_color(&style_home_btn_larsepower_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_home_btn_larsepower_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_btn_larsepower_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_btn_larsepower_main_main_default, 255);
	lv_style_set_border_color(&style_home_btn_larsepower_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_home_btn_larsepower_main_main_default, 0);
	lv_style_set_border_opa(&style_home_btn_larsepower_main_main_default, 255);
	lv_style_set_text_color(&style_home_btn_larsepower_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_btn_larsepower_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_home_btn_larsepower_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->home_btn_larsepower, &style_home_btn_larsepower_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->home_btn_larsepower_label = lv_label_create(ui->home_btn_larsepower);
	lv_label_set_text(ui->home_btn_larsepower_label, "Larse Power");
	lv_obj_set_style_pad_all(ui->home_btn_larsepower, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->home_btn_larsepower_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes home_btn_about
	ui->home_btn_about = lv_btn_create(ui->home);
	lv_obj_set_pos(ui->home_btn_about, 18, 244);
	lv_obj_set_size(ui->home_btn_about, 110, 32);
	lv_obj_set_scrollbar_mode(ui->home_btn_about, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_btn_about_main_main_default
	static lv_style_t style_home_btn_about_main_main_default;
	if (style_home_btn_about_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_btn_about_main_main_default);
	else
		lv_style_init(&style_home_btn_about_main_main_default);
	lv_style_set_radius(&style_home_btn_about_main_main_default, 5);
	lv_style_set_bg_color(&style_home_btn_about_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_home_btn_about_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_btn_about_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_btn_about_main_main_default, 255);
	lv_style_set_border_color(&style_home_btn_about_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_home_btn_about_main_main_default, 0);
	lv_style_set_border_opa(&style_home_btn_about_main_main_default, 255);
	lv_style_set_text_color(&style_home_btn_about_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_btn_about_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_home_btn_about_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->home_btn_about, &style_home_btn_about_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->home_btn_about_label = lv_label_create(ui->home_btn_about);
	lv_label_set_text(ui->home_btn_about_label, "About");
	lv_obj_set_style_pad_all(ui->home_btn_about, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->home_btn_about_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes home_btn_setting
	ui->home_btn_setting = lv_btn_create(ui->home);
	lv_obj_set_pos(ui->home_btn_setting, 18, 194);
	lv_obj_set_size(ui->home_btn_setting, 110, 32);
	lv_obj_set_scrollbar_mode(ui->home_btn_setting, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_btn_setting_main_main_default
	static lv_style_t style_home_btn_setting_main_main_default;
	if (style_home_btn_setting_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_btn_setting_main_main_default);
	else
		lv_style_init(&style_home_btn_setting_main_main_default);
	lv_style_set_radius(&style_home_btn_setting_main_main_default, 5);
	lv_style_set_bg_color(&style_home_btn_setting_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_home_btn_setting_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_btn_setting_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_btn_setting_main_main_default, 255);
	lv_style_set_border_color(&style_home_btn_setting_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_home_btn_setting_main_main_default, 0);
	lv_style_set_border_opa(&style_home_btn_setting_main_main_default, 255);
	lv_style_set_text_color(&style_home_btn_setting_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_btn_setting_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_home_btn_setting_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->home_btn_setting, &style_home_btn_setting_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->home_btn_setting_label = lv_label_create(ui->home_btn_setting);
	lv_label_set_text(ui->home_btn_setting_label, "Setting");
	lv_obj_set_style_pad_all(ui->home_btn_setting, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->home_btn_setting_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes home_btn_sculpture
	ui->home_btn_sculpture = lv_btn_create(ui->home);
	lv_obj_set_pos(ui->home_btn_sculpture, 18, 144);
	lv_obj_set_size(ui->home_btn_sculpture, 110, 32);
	lv_obj_set_scrollbar_mode(ui->home_btn_sculpture, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_btn_sculpture_main_main_default
	static lv_style_t style_home_btn_sculpture_main_main_default;
	if (style_home_btn_sculpture_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_btn_sculpture_main_main_default);
	else
		lv_style_init(&style_home_btn_sculpture_main_main_default);
	lv_style_set_radius(&style_home_btn_sculpture_main_main_default, 5);
	lv_style_set_bg_color(&style_home_btn_sculpture_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_home_btn_sculpture_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_btn_sculpture_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_btn_sculpture_main_main_default, 255);
	lv_style_set_border_color(&style_home_btn_sculpture_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_home_btn_sculpture_main_main_default, 0);
	lv_style_set_border_opa(&style_home_btn_sculpture_main_main_default, 255);
	lv_style_set_text_color(&style_home_btn_sculpture_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_btn_sculpture_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_align(&style_home_btn_sculpture_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->home_btn_sculpture, &style_home_btn_sculpture_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->home_btn_sculpture_label = lv_label_create(ui->home_btn_sculpture);
	lv_label_set_text(ui->home_btn_sculpture_label, "Sculpture");
	lv_obj_set_style_pad_all(ui->home_btn_sculpture, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->home_btn_sculpture_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes home_cont_1
	ui->home_cont_1 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->home_cont_1, 152, 50);
	lv_obj_set_size(ui->home_cont_1, 300, 171);
	lv_obj_set_scrollbar_mode(ui->home_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_cont_1_main_main_default
	static lv_style_t style_home_cont_1_main_main_default;
	if (style_home_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_cont_1_main_main_default);
	else
		lv_style_init(&style_home_cont_1_main_main_default);
	lv_style_set_radius(&style_home_cont_1_main_main_default, 0);
	lv_style_set_bg_color(&style_home_cont_1_main_main_default, lv_color_make(0xff, 0xb8, 0xc1));
	lv_style_set_bg_grad_color(&style_home_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_cont_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_home_cont_1_main_main_default, 15);
	lv_style_set_shadow_color(&style_home_cont_1_main_main_default, lv_color_make(0xbe, 0xb7, 0xb7));
	lv_style_set_shadow_opa(&style_home_cont_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_home_cont_1_main_main_default, 15);
	lv_style_set_shadow_ofs_x(&style_home_cont_1_main_main_default, 2);
	lv_style_set_shadow_ofs_y(&style_home_cont_1_main_main_default, 2);
	lv_style_set_border_color(&style_home_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_home_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_home_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_home_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_home_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_home_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->home_cont_1, &style_home_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_m_z
	ui->home_label_m_z = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_m_z, 342, 168);
	lv_obj_set_size(ui->home_label_m_z, 33, 19);
	lv_obj_set_scrollbar_mode(ui->home_label_m_z, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_m_z, "z:");
	lv_label_set_long_mode(ui->home_label_m_z, LV_LABEL_LONG_WRAP);

	//Write codes home_cont_2
	ui->home_cont_2 = lv_obj_create(ui->home);
	lv_obj_set_pos(ui->home_cont_2, 178, 69);
	lv_obj_set_size(ui->home_cont_2, 250, 133);
	lv_obj_set_scrollbar_mode(ui->home_cont_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_cont_2_main_main_default
	static lv_style_t style_home_cont_2_main_main_default;
	if (style_home_cont_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_cont_2_main_main_default);
	else
		lv_style_init(&style_home_cont_2_main_main_default);
	lv_style_set_radius(&style_home_cont_2_main_main_default, 0);
	lv_style_set_bg_color(&style_home_cont_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_cont_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_cont_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_cont_2_main_main_default, 255);
	lv_style_set_border_color(&style_home_cont_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_home_cont_2_main_main_default, 0);
	lv_style_set_border_opa(&style_home_cont_2_main_main_default, 255);
	lv_style_set_pad_left(&style_home_cont_2_main_main_default, 0);
	lv_style_set_pad_right(&style_home_cont_2_main_main_default, 0);
	lv_style_set_pad_top(&style_home_cont_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_cont_2_main_main_default, 0);
	lv_obj_add_style(ui->home_cont_2, &style_home_cont_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_w_z
	ui->home_label_w_z = lv_label_create(ui->home_cont_2);
	lv_obj_set_pos(ui->home_label_w_z, 162, 34);
	lv_obj_set_size(ui->home_label_w_z, 25, 19);
	lv_obj_set_scrollbar_mode(ui->home_label_w_z, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_w_z, "z:");
	lv_label_set_long_mode(ui->home_label_w_z, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_w_z_main_main_default
	static lv_style_t style_home_label_w_z_main_main_default;
	if (style_home_label_w_z_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_w_z_main_main_default);
	else
		lv_style_init(&style_home_label_w_z_main_main_default);
	lv_style_set_radius(&style_home_label_w_z_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_w_z_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_w_z_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_w_z_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_w_z_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_w_z_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_w_z_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_w_z_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_w_z_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_w_z_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_w_z_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_w_z_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_w_z_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_w_z_main_main_default, 0);
	lv_obj_add_style(ui->home_label_w_z, &style_home_label_w_z_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_4
	ui->home_label_4 = lv_label_create(ui->home_cont_2);
	lv_obj_set_pos(ui->home_label_4, -3, 72);
	lv_obj_set_size(ui->home_label_4, 174, 13);
	lv_obj_set_scrollbar_mode(ui->home_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_4, "Machine coordinates");
	lv_label_set_long_mode(ui->home_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_4_main_main_default
	static lv_style_t style_home_label_4_main_main_default;
	if (style_home_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_4_main_main_default);
	else
		lv_style_init(&style_home_label_4_main_main_default);
	lv_style_set_radius(&style_home_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_4_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_4_main_main_default, 0);
	lv_obj_add_style(ui->home_label_4, &style_home_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_m_y
	ui->home_label_m_y = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_m_y, 264, 168);
	lv_obj_set_size(ui->home_label_m_y, 28, 19);
	lv_obj_set_scrollbar_mode(ui->home_label_m_y, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_m_y, "y:");
	lv_label_set_long_mode(ui->home_label_m_y, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_m_y_main_main_default
	static lv_style_t style_home_label_m_y_main_main_default;
	if (style_home_label_m_y_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_m_y_main_main_default);
	else
		lv_style_init(&style_home_label_m_y_main_main_default);
	lv_style_set_radius(&style_home_label_m_y_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_m_y_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_m_y_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_m_y_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_m_y_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_m_y_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_m_y_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_m_y_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_m_y_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_m_y_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_m_y_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_m_y_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_m_y_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_m_y_main_main_default, 0);
	lv_obj_add_style(ui->home_label_m_y, &style_home_label_m_y_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_m_x
	ui->home_label_m_x = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_m_x, 188, 168);
	lv_obj_set_size(ui->home_label_m_x, 29, 13);
	lv_obj_set_scrollbar_mode(ui->home_label_m_x, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_m_x, "x:");
	lv_label_set_long_mode(ui->home_label_m_x, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_m_x_main_main_default
	static lv_style_t style_home_label_m_x_main_main_default;
	if (style_home_label_m_x_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_m_x_main_main_default);
	else
		lv_style_init(&style_home_label_m_x_main_main_default);
	lv_style_set_radius(&style_home_label_m_x_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_m_x_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_m_x_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_m_x_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_m_x_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_m_x_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_m_x_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_m_x_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_m_x_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_m_x_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_m_x_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_m_x_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_m_x_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_m_x_main_main_default, 0);
	lv_obj_add_style(ui->home_label_m_x, &style_home_label_m_x_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_m_z
	ui->home_label_m_z = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_m_z, 342, 168);
	lv_obj_set_size(ui->home_label_m_z, 33, 19);
	lv_obj_set_scrollbar_mode(ui->home_label_m_z, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_m_z, "z:");
	lv_label_set_long_mode(ui->home_label_m_z, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_m_z_main_main_default
	static lv_style_t style_home_label_m_z_main_main_default;
	if (style_home_label_m_z_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_m_z_main_main_default);
	else
		lv_style_init(&style_home_label_m_z_main_main_default);
	lv_style_set_radius(&style_home_label_m_z_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_m_z_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_m_z_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_m_z_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_m_z_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_m_z_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_m_z_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_m_z_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_m_z_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_m_z_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_m_z_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_m_z_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_m_z_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_m_z_main_main_default, 0);
	lv_obj_add_style(ui->home_label_m_z, &style_home_label_m_z_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_machine_coordinates_y
	ui->home_label_machine_coordinates_y = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_machine_coordinates_y, 281, 168);
	lv_obj_set_size(ui->home_label_machine_coordinates_y, 56, 24);
	lv_obj_set_scrollbar_mode(ui->home_label_machine_coordinates_y, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_machine_coordinates_y, "0.00");
	lv_label_set_long_mode(ui->home_label_machine_coordinates_y, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_machine_coordinates_y_main_main_default
	static lv_style_t style_home_label_machine_coordinates_y_main_main_default;
	if (style_home_label_machine_coordinates_y_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_machine_coordinates_y_main_main_default);
	else
		lv_style_init(&style_home_label_machine_coordinates_y_main_main_default);
	lv_style_set_radius(&style_home_label_machine_coordinates_y_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_machine_coordinates_y_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_machine_coordinates_y_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_machine_coordinates_y_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_machine_coordinates_y_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_machine_coordinates_y_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_machine_coordinates_y_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_machine_coordinates_y_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_machine_coordinates_y_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_machine_coordinates_y_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_machine_coordinates_y_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_machine_coordinates_y_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_machine_coordinates_y_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_machine_coordinates_y_main_main_default, 0);
	lv_obj_add_style(ui->home_label_machine_coordinates_y, &style_home_label_machine_coordinates_y_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_machine_coordinates_z
	ui->home_label_machine_coordinates_z = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_machine_coordinates_z, 360, 168);
	lv_obj_set_size(ui->home_label_machine_coordinates_z, 53, 22);
	lv_obj_set_scrollbar_mode(ui->home_label_machine_coordinates_z, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_machine_coordinates_z, "0.00");
	lv_label_set_long_mode(ui->home_label_machine_coordinates_z, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_machine_coordinates_z_main_main_default
	static lv_style_t style_home_label_machine_coordinates_z_main_main_default;
	if (style_home_label_machine_coordinates_z_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_machine_coordinates_z_main_main_default);
	else
		lv_style_init(&style_home_label_machine_coordinates_z_main_main_default);
	lv_style_set_radius(&style_home_label_machine_coordinates_z_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_machine_coordinates_z_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_machine_coordinates_z_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_machine_coordinates_z_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_machine_coordinates_z_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_machine_coordinates_z_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_machine_coordinates_z_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_machine_coordinates_z_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_machine_coordinates_z_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_machine_coordinates_z_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_machine_coordinates_z_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_machine_coordinates_z_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_machine_coordinates_z_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_machine_coordinates_z_main_main_default, 0);
	lv_obj_add_style(ui->home_label_machine_coordinates_z, &style_home_label_machine_coordinates_z_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_work_coordinates_z
	ui->home_label_work_coordinates_z = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_work_coordinates_z, 354, 104);
	lv_obj_set_size(ui->home_label_work_coordinates_z, 64, 25);
	lv_obj_set_scrollbar_mode(ui->home_label_work_coordinates_z, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_work_coordinates_z, "0.00");
	lv_label_set_long_mode(ui->home_label_work_coordinates_z, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_work_coordinates_z_main_main_default
	static lv_style_t style_home_label_work_coordinates_z_main_main_default;
	if (style_home_label_work_coordinates_z_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_work_coordinates_z_main_main_default);
	else
		lv_style_init(&style_home_label_work_coordinates_z_main_main_default);
	lv_style_set_radius(&style_home_label_work_coordinates_z_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_work_coordinates_z_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_work_coordinates_z_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_work_coordinates_z_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_work_coordinates_z_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_work_coordinates_z_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_work_coordinates_z_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_work_coordinates_z_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_work_coordinates_z_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_work_coordinates_z_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_work_coordinates_z_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_work_coordinates_z_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_work_coordinates_z_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_work_coordinates_z_main_main_default, 0);
	lv_obj_add_style(ui->home_label_work_coordinates_z, &style_home_label_work_coordinates_z_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_work_coordinates_y
	ui->home_label_work_coordinates_y = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_work_coordinates_y, 281, 104);
	lv_obj_set_size(ui->home_label_work_coordinates_y, 58, 17);
	lv_obj_set_scrollbar_mode(ui->home_label_work_coordinates_y, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_work_coordinates_y, "0.00");
	lv_label_set_long_mode(ui->home_label_work_coordinates_y, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_work_coordinates_y_main_main_default
	static lv_style_t style_home_label_work_coordinates_y_main_main_default;
	if (style_home_label_work_coordinates_y_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_work_coordinates_y_main_main_default);
	else
		lv_style_init(&style_home_label_work_coordinates_y_main_main_default);
	lv_style_set_radius(&style_home_label_work_coordinates_y_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_work_coordinates_y_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_work_coordinates_y_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_work_coordinates_y_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_work_coordinates_y_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_work_coordinates_y_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_work_coordinates_y_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_work_coordinates_y_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_work_coordinates_y_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_work_coordinates_y_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_work_coordinates_y_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_work_coordinates_y_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_work_coordinates_y_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_work_coordinates_y_main_main_default, 0);
	lv_obj_add_style(ui->home_label_work_coordinates_y, &style_home_label_work_coordinates_y_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_3
	ui->home_label_3 = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_3, 174, 74);
	lv_obj_set_size(ui->home_label_3, 151, 11);
	lv_obj_set_scrollbar_mode(ui->home_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_3, "Work coordinates");
	lv_label_set_long_mode(ui->home_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_3_main_main_default
	static lv_style_t style_home_label_3_main_main_default;
	if (style_home_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_3_main_main_default);
	else
		lv_style_init(&style_home_label_3_main_main_default);
	lv_style_set_radius(&style_home_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_3_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_3_main_main_default, 0);
	lv_obj_add_style(ui->home_label_3, &style_home_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_status
	ui->home_label_status = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_status, 152, 250);
	lv_obj_set_size(ui->home_label_status, 105, 24);
	lv_obj_set_scrollbar_mode(ui->home_label_status, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_status, "Status");
	lv_label_set_long_mode(ui->home_label_status, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_status_main_main_default
	static lv_style_t style_home_label_status_main_main_default;
	if (style_home_label_status_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_status_main_main_default);
	else
		lv_style_init(&style_home_label_status_main_main_default);
	lv_style_set_radius(&style_home_label_status_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_status_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_home_label_status_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_status_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_status_main_main_default, 255);
	lv_style_set_text_color(&style_home_label_status_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_status_main_main_default, &lv_font_Amiko_Regular_16);
	lv_style_set_text_letter_space(&style_home_label_status_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_status_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_status_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_status_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_status_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_status_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_status_main_main_default, 0);
	lv_obj_add_style(ui->home_label_status, &style_home_label_status_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_machine_status
	ui->home_label_machine_status = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_machine_status, 264, 252);
	lv_obj_set_size(ui->home_label_machine_status, 175, 22);
	lv_obj_set_scrollbar_mode(ui->home_label_machine_status, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_machine_status, "Not connected");
	lv_label_set_long_mode(ui->home_label_machine_status, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_machine_status_main_main_default
	static lv_style_t style_home_label_machine_status_main_main_default;
	if (style_home_label_machine_status_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_machine_status_main_main_default);
	else
		lv_style_init(&style_home_label_machine_status_main_main_default);
	lv_style_set_radius(&style_home_label_machine_status_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_machine_status_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_machine_status_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_machine_status_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_machine_status_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_machine_status_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_machine_status_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_home_label_machine_status_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_machine_status_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_machine_status_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_machine_status_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_machine_status_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_machine_status_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_machine_status_main_main_default, 0);
	lv_obj_add_style(ui->home_label_machine_status, &style_home_label_machine_status_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_w_x
	ui->home_label_w_x = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_w_x, 188, 104);
	lv_obj_set_size(ui->home_label_w_x, 29, 13);
	lv_obj_set_scrollbar_mode(ui->home_label_w_x, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_w_x, "x:");
	lv_label_set_long_mode(ui->home_label_w_x, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_w_x_main_main_default
	static lv_style_t style_home_label_w_x_main_main_default;
	if (style_home_label_w_x_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_w_x_main_main_default);
	else
		lv_style_init(&style_home_label_w_x_main_main_default);
	lv_style_set_radius(&style_home_label_w_x_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_w_x_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_w_x_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_w_x_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_w_x_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_w_x_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_w_x_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_w_x_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_w_x_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_w_x_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_w_x_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_w_x_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_w_x_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_w_x_main_main_default, 0);
	lv_obj_add_style(ui->home_label_w_x, &style_home_label_w_x_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_w_y
	ui->home_label_w_y = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_w_y, 269, 104);
	lv_obj_set_size(ui->home_label_w_y, 28, 19);
	lv_obj_set_scrollbar_mode(ui->home_label_w_y, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_w_y, "y:");
	lv_label_set_long_mode(ui->home_label_w_y, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_w_y_main_main_default
	static lv_style_t style_home_label_w_y_main_main_default;
	if (style_home_label_w_y_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_w_y_main_main_default);
	else
		lv_style_init(&style_home_label_w_y_main_main_default);
	lv_style_set_radius(&style_home_label_w_y_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_w_y_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_w_y_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_w_y_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_w_y_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_w_y_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_w_y_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_w_y_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_w_y_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_w_y_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_w_y_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_w_y_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_w_y_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_w_y_main_main_default, 0);
	lv_obj_add_style(ui->home_label_w_y, &style_home_label_w_y_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_work_coordinates_x
	ui->home_label_work_coordinates_x = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_work_coordinates_x, 207, 104);
	lv_obj_set_size(ui->home_label_work_coordinates_x, 57, 14);
	lv_obj_set_scrollbar_mode(ui->home_label_work_coordinates_x, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_work_coordinates_x, "0.00");
	lv_label_set_long_mode(ui->home_label_work_coordinates_x, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_work_coordinates_x_main_main_default
	static lv_style_t style_home_label_work_coordinates_x_main_main_default;
	if (style_home_label_work_coordinates_x_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_work_coordinates_x_main_main_default);
	else
		lv_style_init(&style_home_label_work_coordinates_x_main_main_default);
	lv_style_set_radius(&style_home_label_work_coordinates_x_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_work_coordinates_x_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_work_coordinates_x_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_work_coordinates_x_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_work_coordinates_x_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_work_coordinates_x_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_work_coordinates_x_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_work_coordinates_x_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_work_coordinates_x_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_work_coordinates_x_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_work_coordinates_x_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_work_coordinates_x_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_work_coordinates_x_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_work_coordinates_x_main_main_default, 0);
	lv_obj_add_style(ui->home_label_work_coordinates_x, &style_home_label_work_coordinates_x_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_machine_coordinates_x
	ui->home_label_machine_coordinates_x = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_machine_coordinates_x, 207, 168);
	lv_obj_set_size(ui->home_label_machine_coordinates_x, 55, 19);
	lv_obj_set_scrollbar_mode(ui->home_label_machine_coordinates_x, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_machine_coordinates_x, "0.00");
	lv_label_set_long_mode(ui->home_label_machine_coordinates_x, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_machine_coordinates_x_main_main_default
	static lv_style_t style_home_label_machine_coordinates_x_main_main_default;
	if (style_home_label_machine_coordinates_x_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_machine_coordinates_x_main_main_default);
	else
		lv_style_init(&style_home_label_machine_coordinates_x_main_main_default);
	lv_style_set_radius(&style_home_label_machine_coordinates_x_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_machine_coordinates_x_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_machine_coordinates_x_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_machine_coordinates_x_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_machine_coordinates_x_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_machine_coordinates_x_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_label_machine_coordinates_x_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_home_label_machine_coordinates_x_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_machine_coordinates_x_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_machine_coordinates_x_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_machine_coordinates_x_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_machine_coordinates_x_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_machine_coordinates_x_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_machine_coordinates_x_main_main_default, 0);
	lv_obj_add_style(ui->home_label_machine_coordinates_x, &style_home_label_machine_coordinates_x_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_home(ui);
}