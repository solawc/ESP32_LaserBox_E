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


void setup_scr_tool(lv_ui *ui){

	//Write codes tool
	ui->tool = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->tool, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_main_main_default
	static lv_style_t style_tool_main_main_default;
	if (style_tool_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_main_main_default);
	else
		lv_style_init(&style_tool_main_main_default);
	lv_style_set_bg_color(&style_tool_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_tool_main_main_default, 255);
	lv_obj_add_style(ui->tool, &style_tool_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_cont_1
	ui->tool_cont_1 = lv_obj_create(ui->tool);
	lv_obj_set_pos(ui->tool_cont_1, 292, 117);
	lv_obj_set_size(ui->tool_cont_1, 171, 111);
	lv_obj_set_scrollbar_mode(ui->tool_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_cont_1_main_main_default
	static lv_style_t style_tool_cont_1_main_main_default;
	if (style_tool_cont_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_cont_1_main_main_default);
	else
		lv_style_init(&style_tool_cont_1_main_main_default);
	lv_style_set_radius(&style_tool_cont_1_main_main_default, 10);
	lv_style_set_bg_color(&style_tool_cont_1_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_tool_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_cont_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_cont_1_main_main_default, 255);
	lv_style_set_border_color(&style_tool_cont_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_tool_cont_1_main_main_default, 0);
	lv_style_set_border_opa(&style_tool_cont_1_main_main_default, 255);
	lv_style_set_pad_left(&style_tool_cont_1_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_cont_1_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_cont_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_cont_1_main_main_default, 0);
	lv_obj_add_style(ui->tool_cont_1, &style_tool_cont_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_ddlist_2
	ui->tool_ddlist_2 = lv_dropdown_create(ui->tool_cont_1);
	lv_obj_set_pos(ui->tool_ddlist_2, 73, 69);
	lv_obj_set_size(ui->tool_ddlist_2, 72, 28);
	lv_obj_set_scrollbar_mode(ui->tool_ddlist_2, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->tool_ddlist_2, "list1\nlist2\nlist3");

	//Write style state: LV_STATE_DEFAULT for style_tool_ddlist_2_main_main_default
	static lv_style_t style_tool_ddlist_2_main_main_default;
	if (style_tool_ddlist_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_ddlist_2_main_main_default);
	else
		lv_style_init(&style_tool_ddlist_2_main_main_default);
	lv_style_set_radius(&style_tool_ddlist_2_main_main_default, 3);
	lv_style_set_bg_color(&style_tool_ddlist_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_tool_ddlist_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_tool_ddlist_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_ddlist_2_main_main_default, 255);
	lv_style_set_border_color(&style_tool_ddlist_2_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_tool_ddlist_2_main_main_default, 1);
	lv_style_set_border_opa(&style_tool_ddlist_2_main_main_default, 255);
	lv_style_set_text_color(&style_tool_ddlist_2_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_tool_ddlist_2_main_main_default, &lv_font_simsun_12);
	lv_style_set_pad_left(&style_tool_ddlist_2_main_main_default, 6);
	lv_style_set_pad_right(&style_tool_ddlist_2_main_main_default, 6);
	lv_style_set_pad_top(&style_tool_ddlist_2_main_main_default, 8);
	lv_obj_add_style(ui->tool_ddlist_2, &style_tool_ddlist_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_tool_ddlist_2_extra_list_selected_checked
	static lv_style_t style_tool_ddlist_2_extra_list_selected_checked;
	if (style_tool_ddlist_2_extra_list_selected_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_ddlist_2_extra_list_selected_checked);
	else
		lv_style_init(&style_tool_ddlist_2_extra_list_selected_checked);
	lv_style_set_radius(&style_tool_ddlist_2_extra_list_selected_checked, 3);
	lv_style_set_bg_color(&style_tool_ddlist_2_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_tool_ddlist_2_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_tool_ddlist_2_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_ddlist_2_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_tool_ddlist_2_extra_list_selected_checked, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_tool_ddlist_2_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_tool_ddlist_2_extra_list_selected_checked, 255);
	lv_style_set_text_color(&style_tool_ddlist_2_extra_list_selected_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_ddlist_2_extra_list_selected_checked, &lv_font_simsun_12);
	lv_style_set_pad_left(&style_tool_ddlist_2_extra_list_selected_checked, 6);
	lv_style_set_pad_right(&style_tool_ddlist_2_extra_list_selected_checked, 6);
	lv_style_set_pad_top(&style_tool_ddlist_2_extra_list_selected_checked, 6);
	lv_style_set_pad_bottom(&style_tool_ddlist_2_extra_list_selected_checked, 6);
	lv_obj_add_style(lv_dropdown_get_list(ui->tool_ddlist_2), &style_tool_ddlist_2_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_tool_ddlist_2_extra_list_main_default
	static lv_style_t style_tool_ddlist_2_extra_list_main_default;
	if (style_tool_ddlist_2_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_ddlist_2_extra_list_main_default);
	else
		lv_style_init(&style_tool_ddlist_2_extra_list_main_default);
	lv_style_set_radius(&style_tool_ddlist_2_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_tool_ddlist_2_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_tool_ddlist_2_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_tool_ddlist_2_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_ddlist_2_extra_list_main_default, 255);
	lv_style_set_border_color(&style_tool_ddlist_2_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_tool_ddlist_2_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_tool_ddlist_2_extra_list_main_default, 255);
	lv_style_set_text_color(&style_tool_ddlist_2_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_tool_ddlist_2_extra_list_main_default, &lv_font_simsun_12);
	lv_style_set_pad_left(&style_tool_ddlist_2_extra_list_main_default, 6);
	lv_style_set_pad_right(&style_tool_ddlist_2_extra_list_main_default, 6);
	lv_style_set_pad_top(&style_tool_ddlist_2_extra_list_main_default, 6);
	lv_style_set_pad_bottom(&style_tool_ddlist_2_extra_list_main_default, 6);
	lv_style_set_max_height(&style_tool_ddlist_2_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->tool_ddlist_2), &style_tool_ddlist_2_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_tool_ddlist_2_extra_list_scrollbar_default
	static lv_style_t style_tool_ddlist_2_extra_list_scrollbar_default;
	if (style_tool_ddlist_2_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_tool_ddlist_2_extra_list_scrollbar_default);
	else
		lv_style_init(&style_tool_ddlist_2_extra_list_scrollbar_default);
	lv_style_set_radius(&style_tool_ddlist_2_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_tool_ddlist_2_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_tool_ddlist_2_extra_list_scrollbar_default, 255);
	lv_style_set_pad_left(&style_tool_ddlist_2_extra_list_scrollbar_default, 6);
	lv_style_set_pad_right(&style_tool_ddlist_2_extra_list_scrollbar_default, 6);
	lv_style_set_pad_top(&style_tool_ddlist_2_extra_list_scrollbar_default, 6);
	lv_style_set_pad_bottom(&style_tool_ddlist_2_extra_list_scrollbar_default, 6);
	lv_obj_add_style(lv_dropdown_get_list(ui->tool_ddlist_2), &style_tool_ddlist_2_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes tool_label_2
	ui->tool_label_2 = lv_label_create(ui->tool_cont_1);
	lv_obj_set_pos(ui->tool_label_2, 9, 75);
	lv_obj_set_size(ui->tool_label_2, 62, 22);
	lv_obj_set_scrollbar_mode(ui->tool_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_label_2, "Feed:");
	lv_label_set_long_mode(ui->tool_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_label_2_main_main_default
	static lv_style_t style_tool_label_2_main_main_default;
	if (style_tool_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_label_2_main_main_default);
	else
		lv_style_init(&style_tool_label_2_main_main_default);
	lv_style_set_radius(&style_tool_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_tool_label_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_tool_label_2_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_tool_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_tool_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_tool_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_label_2_main_main_default, 0);
	lv_obj_add_style(ui->tool_label_2, &style_tool_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_label_1
	ui->tool_label_1 = lv_label_create(ui->tool_cont_1);
	lv_obj_set_pos(ui->tool_label_1, 13, 23);
	lv_obj_set_size(ui->tool_label_1, 54, 25);
	lv_obj_set_scrollbar_mode(ui->tool_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_label_1, "Step:");
	lv_label_set_long_mode(ui->tool_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_label_1_main_main_default
	static lv_style_t style_tool_label_1_main_main_default;
	if (style_tool_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_label_1_main_main_default);
	else
		lv_style_init(&style_tool_label_1_main_main_default);
	lv_style_set_radius(&style_tool_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_tool_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_tool_label_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_tool_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_tool_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_tool_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_label_1_main_main_default, 0);
	lv_obj_add_style(ui->tool_label_1, &style_tool_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_ddlist_1
	ui->tool_ddlist_1 = lv_dropdown_create(ui->tool);
	lv_obj_set_pos(ui->tool_ddlist_1, 366, 133);
	lv_obj_set_size(ui->tool_ddlist_1, 66, 27);
	lv_obj_set_scrollbar_mode(ui->tool_ddlist_1, LV_SCROLLBAR_MODE_OFF);
	lv_dropdown_set_options(ui->tool_ddlist_1, "1 mm\n5 mm\n10 mm");

	//Write style state: LV_STATE_DEFAULT for style_tool_ddlist_1_main_main_default
	static lv_style_t style_tool_ddlist_1_main_main_default;
	if (style_tool_ddlist_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_ddlist_1_main_main_default);
	else
		lv_style_init(&style_tool_ddlist_1_main_main_default);
	lv_style_set_radius(&style_tool_ddlist_1_main_main_default, 3);
	lv_style_set_bg_color(&style_tool_ddlist_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_tool_ddlist_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_tool_ddlist_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_ddlist_1_main_main_default, 255);
	lv_style_set_border_color(&style_tool_ddlist_1_main_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_tool_ddlist_1_main_main_default, 1);
	lv_style_set_border_opa(&style_tool_ddlist_1_main_main_default, 255);
	lv_style_set_text_color(&style_tool_ddlist_1_main_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_tool_ddlist_1_main_main_default, &lv_font_simsun_12);
	lv_style_set_pad_left(&style_tool_ddlist_1_main_main_default, 6);
	lv_style_set_pad_right(&style_tool_ddlist_1_main_main_default, 6);
	lv_style_set_pad_top(&style_tool_ddlist_1_main_main_default, 8);
	lv_obj_add_style(ui->tool_ddlist_1, &style_tool_ddlist_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_tool_ddlist_1_extra_list_selected_checked
	static lv_style_t style_tool_ddlist_1_extra_list_selected_checked;
	if (style_tool_ddlist_1_extra_list_selected_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_ddlist_1_extra_list_selected_checked);
	else
		lv_style_init(&style_tool_ddlist_1_extra_list_selected_checked);
	lv_style_set_radius(&style_tool_ddlist_1_extra_list_selected_checked, 3);
	lv_style_set_bg_color(&style_tool_ddlist_1_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_color(&style_tool_ddlist_1_extra_list_selected_checked, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_bg_grad_dir(&style_tool_ddlist_1_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_ddlist_1_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_tool_ddlist_1_extra_list_selected_checked, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_tool_ddlist_1_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_tool_ddlist_1_extra_list_selected_checked, 255);
	lv_style_set_text_color(&style_tool_ddlist_1_extra_list_selected_checked, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_ddlist_1_extra_list_selected_checked, &lv_font_simsun_12);
	lv_style_set_pad_left(&style_tool_ddlist_1_extra_list_selected_checked, 6);
	lv_style_set_pad_right(&style_tool_ddlist_1_extra_list_selected_checked, 6);
	lv_style_set_pad_top(&style_tool_ddlist_1_extra_list_selected_checked, 6);
	lv_style_set_pad_bottom(&style_tool_ddlist_1_extra_list_selected_checked, 6);
	lv_obj_add_style(lv_dropdown_get_list(ui->tool_ddlist_1), &style_tool_ddlist_1_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_tool_ddlist_1_extra_list_main_default
	static lv_style_t style_tool_ddlist_1_extra_list_main_default;
	if (style_tool_ddlist_1_extra_list_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_ddlist_1_extra_list_main_default);
	else
		lv_style_init(&style_tool_ddlist_1_extra_list_main_default);
	lv_style_set_radius(&style_tool_ddlist_1_extra_list_main_default, 3);
	lv_style_set_bg_color(&style_tool_ddlist_1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_tool_ddlist_1_extra_list_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_tool_ddlist_1_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_tool_ddlist_1_extra_list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_tool_ddlist_1_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_tool_ddlist_1_extra_list_main_default, 255);
	lv_style_set_text_color(&style_tool_ddlist_1_extra_list_main_default, lv_color_make(0x0D, 0x30, 0x55));
	lv_style_set_text_font(&style_tool_ddlist_1_extra_list_main_default, &lv_font_simsun_12);
	lv_style_set_pad_left(&style_tool_ddlist_1_extra_list_main_default, 6);
	lv_style_set_pad_right(&style_tool_ddlist_1_extra_list_main_default, 6);
	lv_style_set_pad_top(&style_tool_ddlist_1_extra_list_main_default, 6);
	lv_style_set_pad_bottom(&style_tool_ddlist_1_extra_list_main_default, 6);
	lv_style_set_max_height(&style_tool_ddlist_1_extra_list_main_default, 90);
	lv_obj_add_style(lv_dropdown_get_list(ui->tool_ddlist_1), &style_tool_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_tool_ddlist_1_extra_list_scrollbar_default
	static lv_style_t style_tool_ddlist_1_extra_list_scrollbar_default;
	if (style_tool_ddlist_1_extra_list_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_tool_ddlist_1_extra_list_scrollbar_default);
	else
		lv_style_init(&style_tool_ddlist_1_extra_list_scrollbar_default);
	lv_style_set_radius(&style_tool_ddlist_1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_color(&style_tool_ddlist_1_extra_list_scrollbar_default, lv_color_make(0x00, 0xff, 0x00));
	lv_style_set_bg_opa(&style_tool_ddlist_1_extra_list_scrollbar_default, 255);
	lv_style_set_pad_left(&style_tool_ddlist_1_extra_list_scrollbar_default, 6);
	lv_style_set_pad_right(&style_tool_ddlist_1_extra_list_scrollbar_default, 6);
	lv_style_set_pad_top(&style_tool_ddlist_1_extra_list_scrollbar_default, 6);
	lv_style_set_pad_bottom(&style_tool_ddlist_1_extra_list_scrollbar_default, 6);
	lv_obj_add_style(lv_dropdown_get_list(ui->tool_ddlist_1), &style_tool_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes tool_cont_2
	ui->tool_cont_2 = lv_obj_create(ui->tool);
	lv_obj_set_pos(ui->tool_cont_2, 37, 56);
	lv_obj_set_size(ui->tool_cont_2, 243, 238);
	lv_obj_set_scrollbar_mode(ui->tool_cont_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_cont_2_main_main_default
	static lv_style_t style_tool_cont_2_main_main_default;
	if (style_tool_cont_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_cont_2_main_main_default);
	else
		lv_style_init(&style_tool_cont_2_main_main_default);
	lv_style_set_radius(&style_tool_cont_2_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_cont_2_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_tool_cont_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_cont_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_cont_2_main_main_default, 255);
	lv_style_set_border_color(&style_tool_cont_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_tool_cont_2_main_main_default, 0);
	lv_style_set_border_opa(&style_tool_cont_2_main_main_default, 255);
	lv_style_set_pad_left(&style_tool_cont_2_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_cont_2_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_cont_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_cont_2_main_main_default, 0);
	lv_obj_add_style(ui->tool_cont_2, &style_tool_cont_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_label_3
	ui->tool_label_3 = lv_label_create(ui->tool);
	lv_obj_set_pos(ui->tool_label_3, 280, 60);
	lv_obj_set_size(ui->tool_label_3, 37, 23);
	lv_obj_set_scrollbar_mode(ui->tool_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_label_3, "x:");
	lv_label_set_long_mode(ui->tool_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_label_3_main_main_default
	static lv_style_t style_tool_label_3_main_main_default;
	if (style_tool_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_label_3_main_main_default);
	else
		lv_style_init(&style_tool_label_3_main_main_default);
	lv_style_set_radius(&style_tool_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_tool_label_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_tool_label_3_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_tool_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_tool_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_tool_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_label_3_main_main_default, 0);
	lv_obj_add_style(ui->tool_label_3, &style_tool_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_label_4
	ui->tool_label_4 = lv_label_create(ui->tool);
	lv_obj_set_pos(ui->tool_label_4, 351, 60);
	lv_obj_set_size(ui->tool_label_4, 37, 23);
	lv_obj_set_scrollbar_mode(ui->tool_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_label_4, "y:");
	lv_label_set_long_mode(ui->tool_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_label_4_main_main_default
	static lv_style_t style_tool_label_4_main_main_default;
	if (style_tool_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_label_4_main_main_default);
	else
		lv_style_init(&style_tool_label_4_main_main_default);
	lv_style_set_radius(&style_tool_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_tool_label_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_tool_label_4_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_tool_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_tool_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_tool_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_label_4_main_main_default, 0);
	lv_obj_add_style(ui->tool_label_4, &style_tool_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_label_5
	ui->tool_label_5 = lv_label_create(ui->tool);
	lv_obj_set_pos(ui->tool_label_5, 429, 60);
	lv_obj_set_size(ui->tool_label_5, 37, 23);
	lv_obj_set_scrollbar_mode(ui->tool_label_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_label_5, "z:");
	lv_label_set_long_mode(ui->tool_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_label_5_main_main_default
	static lv_style_t style_tool_label_5_main_main_default;
	if (style_tool_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_label_5_main_main_default);
	else
		lv_style_init(&style_tool_label_5_main_main_default);
	lv_style_set_radius(&style_tool_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_tool_label_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_tool_label_5_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_tool_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_tool_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_tool_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_label_5_main_main_default, 0);
	lv_obj_add_style(ui->tool_label_5, &style_tool_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_imgbtn_tool_return
	ui->tool_imgbtn_tool_return = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_tool_return, 15, 23);
	lv_obj_set_size(ui->tool_imgbtn_tool_return, 72, 22);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_tool_return, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_tool_return_main_main_default
	static lv_style_t style_tool_imgbtn_tool_return_main_main_default;
	if (style_tool_imgbtn_tool_return_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_tool_return_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_tool_return_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_tool_return_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_tool_return_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_tool_return_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_tool_return_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_tool_return_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_tool_return, &style_tool_imgbtn_tool_return_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_tool_return_main_main_pressed
	static lv_style_t style_tool_imgbtn_tool_return_main_main_pressed;
	if (style_tool_imgbtn_tool_return_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_tool_return_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_tool_return_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_tool_return_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_tool_return_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_tool_return_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_tool_return_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_tool_return_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_tool_return, &style_tool_imgbtn_tool_return_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_tool_return_main_main_checked
	static lv_style_t style_tool_imgbtn_tool_return_main_main_checked;
	if (style_tool_imgbtn_tool_return_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_tool_return_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_tool_return_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_tool_return_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_tool_return_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_tool_return_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_tool_return_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_tool_return_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_tool_return, &style_tool_imgbtn_tool_return_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_tool_return, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_72x22, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_tool_return, LV_OBJ_FLAG_CHECKABLE);

	//Write codes tool_cont_3
	ui->tool_cont_3 = lv_obj_create(ui->tool);
	lv_obj_set_pos(ui->tool_cont_3, 292, 250);
	lv_obj_set_size(ui->tool_cont_3, 166, 48);
	lv_obj_set_scrollbar_mode(ui->tool_cont_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_cont_3_main_main_default
	static lv_style_t style_tool_cont_3_main_main_default;
	if (style_tool_cont_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_cont_3_main_main_default);
	else
		lv_style_init(&style_tool_cont_3_main_main_default);
	lv_style_set_radius(&style_tool_cont_3_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_cont_3_main_main_default, lv_color_make(0xf5, 0xf5, 0xf5));
	lv_style_set_bg_grad_color(&style_tool_cont_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_cont_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_cont_3_main_main_default, 255);
	lv_style_set_border_color(&style_tool_cont_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_tool_cont_3_main_main_default, 0);
	lv_style_set_border_opa(&style_tool_cont_3_main_main_default, 255);
	lv_style_set_pad_left(&style_tool_cont_3_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_cont_3_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_cont_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_cont_3_main_main_default, 0);
	lv_obj_add_style(ui->tool_cont_3, &style_tool_cont_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_imgbtn_2
	ui->tool_imgbtn_2 = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_2, 96, 76);
	lv_obj_set_size(ui->tool_imgbtn_2, 50, 50);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_2_main_main_default
	static lv_style_t style_tool_imgbtn_2_main_main_default;
	if (style_tool_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_2_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_2_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_2_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_2, &style_tool_imgbtn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_2_main_main_pressed
	static lv_style_t style_tool_imgbtn_2_main_main_pressed;
	if (style_tool_imgbtn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_2_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_2_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_2_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_2_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_2_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_2, &style_tool_imgbtn_2_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_2_main_main_checked
	static lv_style_t style_tool_imgbtn_2_main_main_checked;
	if (style_tool_imgbtn_2_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_2_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_2_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_2_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_2_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_2, &style_tool_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_up_alpha_50x50, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);

	//Write codes tool_imgbtn_3
	ui->tool_imgbtn_3 = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_3, 37, 148);
	lv_obj_set_size(ui->tool_imgbtn_3, 50, 50);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_3_main_main_default
	static lv_style_t style_tool_imgbtn_3_main_main_default;
	if (style_tool_imgbtn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_3_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_3_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_3_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_3_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_3, &style_tool_imgbtn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_3_main_main_pressed
	static lv_style_t style_tool_imgbtn_3_main_main_pressed;
	if (style_tool_imgbtn_3_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_3_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_3_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_3_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_3_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_3_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_3_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_3_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_3, &style_tool_imgbtn_3_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_3_main_main_checked
	static lv_style_t style_tool_imgbtn_3_main_main_checked;
	if (style_tool_imgbtn_3_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_3_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_3_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_3_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_3_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_3_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_3_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_3_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_3, &style_tool_imgbtn_3_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_left_alpha_50x50, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);

	//Write codes tool_imgbtn_4
	ui->tool_imgbtn_4 = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_4, 157, 148);
	lv_obj_set_size(ui->tool_imgbtn_4, 50, 50);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_4_main_main_default
	static lv_style_t style_tool_imgbtn_4_main_main_default;
	if (style_tool_imgbtn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_4_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_4_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_4_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_4_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_4, &style_tool_imgbtn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_4_main_main_pressed
	static lv_style_t style_tool_imgbtn_4_main_main_pressed;
	if (style_tool_imgbtn_4_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_4_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_4_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_4_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_4_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_4_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_4_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_4_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_4, &style_tool_imgbtn_4_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_4_main_main_checked
	static lv_style_t style_tool_imgbtn_4_main_main_checked;
	if (style_tool_imgbtn_4_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_4_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_4_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_4_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_4_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_4_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_4_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_4_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_4, &style_tool_imgbtn_4_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_right_alpha_50x50, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);

	//Write codes tool_imgbtn_6
	ui->tool_imgbtn_6 = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_6, 207, 83);
	lv_obj_set_size(ui->tool_imgbtn_6, 50, 50);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_6_main_main_default
	static lv_style_t style_tool_imgbtn_6_main_main_default;
	if (style_tool_imgbtn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_6_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_6_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_6_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_6_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_6, &style_tool_imgbtn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_6_main_main_pressed
	static lv_style_t style_tool_imgbtn_6_main_main_pressed;
	if (style_tool_imgbtn_6_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_6_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_6_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_6_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_6_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_6_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_6_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_6_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_6, &style_tool_imgbtn_6_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_6_main_main_checked
	static lv_style_t style_tool_imgbtn_6_main_main_checked;
	if (style_tool_imgbtn_6_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_6_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_6_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_6_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_6_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_6_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_6_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_6_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_6, &style_tool_imgbtn_6_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_6, LV_IMGBTN_STATE_RELEASED, NULL, &_z_up_alpha_50x50, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);

	//Write codes tool_imgbtn_7
	ui->tool_imgbtn_7 = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_7, 207, 212);
	lv_obj_set_size(ui->tool_imgbtn_7, 50, 50);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_7_main_main_default
	static lv_style_t style_tool_imgbtn_7_main_main_default;
	if (style_tool_imgbtn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_7_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_7_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_7_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_7_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_7, &style_tool_imgbtn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_7_main_main_pressed
	static lv_style_t style_tool_imgbtn_7_main_main_pressed;
	if (style_tool_imgbtn_7_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_7_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_7_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_7_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_7_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_7_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_7_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_7_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_7, &style_tool_imgbtn_7_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_7_main_main_checked
	static lv_style_t style_tool_imgbtn_7_main_main_checked;
	if (style_tool_imgbtn_7_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_7_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_7_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_7_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_7_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_7_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_7_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_7_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_7, &style_tool_imgbtn_7_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_7, LV_IMGBTN_STATE_RELEASED, NULL, &_z_down_alpha_50x50, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_7, LV_OBJ_FLAG_CHECKABLE);

	//Write codes tool_imgbtn_5
	ui->tool_imgbtn_5 = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_5, 87, 212);
	lv_obj_set_size(ui->tool_imgbtn_5, 50, 50);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_5_main_main_default
	static lv_style_t style_tool_imgbtn_5_main_main_default;
	if (style_tool_imgbtn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_5_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_5_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_5_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_5_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_5, &style_tool_imgbtn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_5_main_main_pressed
	static lv_style_t style_tool_imgbtn_5_main_main_pressed;
	if (style_tool_imgbtn_5_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_5_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_5_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_5_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_5_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_5_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_5_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_5_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_5, &style_tool_imgbtn_5_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_5_main_main_checked
	static lv_style_t style_tool_imgbtn_5_main_main_checked;
	if (style_tool_imgbtn_5_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_5_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_5_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_5_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_5_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_5_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_5_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_5_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_5, &style_tool_imgbtn_5_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_down_alpha_50x50, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);

	//Write codes tool_imgbtn_8
	ui->tool_imgbtn_8 = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_8, 298, 262);
	lv_obj_set_size(ui->tool_imgbtn_8, 30, 30);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_8_main_main_default
	static lv_style_t style_tool_imgbtn_8_main_main_default;
	if (style_tool_imgbtn_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_8_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_8_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_8_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_8_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_8, &style_tool_imgbtn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_8_main_main_pressed
	static lv_style_t style_tool_imgbtn_8_main_main_pressed;
	if (style_tool_imgbtn_8_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_8_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_8_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_8_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_8_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_8_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_8_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_8_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_8, &style_tool_imgbtn_8_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_8_main_main_checked
	static lv_style_t style_tool_imgbtn_8_main_main_checked;
	if (style_tool_imgbtn_8_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_8_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_8_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_8_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_8_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_8_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_8_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_8_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_8, &style_tool_imgbtn_8_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_8, LV_IMGBTN_STATE_RELEASED, NULL, &_clean_alpha_30x30, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_8, LV_OBJ_FLAG_CHECKABLE);

	//Write codes tool_imgbtn_9
	ui->tool_imgbtn_9 = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_9, 336, 262);
	lv_obj_set_size(ui->tool_imgbtn_9, 30, 30);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_9_main_main_default
	static lv_style_t style_tool_imgbtn_9_main_main_default;
	if (style_tool_imgbtn_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_9_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_9_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_9_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_9_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_9, &style_tool_imgbtn_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_9_main_main_pressed
	static lv_style_t style_tool_imgbtn_9_main_main_pressed;
	if (style_tool_imgbtn_9_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_9_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_9_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_9_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_9_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_9_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_9_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_9_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_9, &style_tool_imgbtn_9_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_9_main_main_checked
	static lv_style_t style_tool_imgbtn_9_main_main_checked;
	if (style_tool_imgbtn_9_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_9_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_9_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_9_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_9_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_9_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_9_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_9_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_9, &style_tool_imgbtn_9_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_9, LV_IMGBTN_STATE_RELEASED, NULL, &_zero_alpha_30x30, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_9, LV_OBJ_FLAG_CHECKABLE);

	//Write codes tool_imgbtn_10
	ui->tool_imgbtn_10 = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_10, 376, 262);
	lv_obj_set_size(ui->tool_imgbtn_10, 30, 30);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_10, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_10_main_main_default
	static lv_style_t style_tool_imgbtn_10_main_main_default;
	if (style_tool_imgbtn_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_10_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_10_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_10_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_10_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_10_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_10, &style_tool_imgbtn_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_10_main_main_pressed
	static lv_style_t style_tool_imgbtn_10_main_main_pressed;
	if (style_tool_imgbtn_10_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_10_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_10_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_10_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_10_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_10_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_10_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_10_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_10, &style_tool_imgbtn_10_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_10_main_main_checked
	static lv_style_t style_tool_imgbtn_10_main_main_checked;
	if (style_tool_imgbtn_10_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_10_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_10_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_10_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_10_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_10_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_10_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_10_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_10, &style_tool_imgbtn_10_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_10, LV_IMGBTN_STATE_RELEASED, NULL, &_restart_alpha_30x30, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_10, LV_OBJ_FLAG_CHECKABLE);

	//Write codes tool_imgbtn_11
	ui->tool_imgbtn_11 = lv_imgbtn_create(ui->tool);
	lv_obj_set_pos(ui->tool_imgbtn_11, 416, 262);
	lv_obj_set_size(ui->tool_imgbtn_11, 30, 30);
	lv_obj_set_scrollbar_mode(ui->tool_imgbtn_11, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_imgbtn_11_main_main_default
	static lv_style_t style_tool_imgbtn_11_main_main_default;
	if (style_tool_imgbtn_11_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_11_main_main_default);
	else
		lv_style_init(&style_tool_imgbtn_11_main_main_default);
	lv_style_set_text_color(&style_tool_imgbtn_11_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_imgbtn_11_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_11_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_11_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_11_main_main_default, 255);
	lv_obj_add_style(ui->tool_imgbtn_11, &style_tool_imgbtn_11_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_imgbtn_11_main_main_pressed
	static lv_style_t style_tool_imgbtn_11_main_main_pressed;
	if (style_tool_imgbtn_11_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_11_main_main_pressed);
	else
		lv_style_init(&style_tool_imgbtn_11_main_main_pressed);
	lv_style_set_text_color(&style_tool_imgbtn_11_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_11_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_11_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_11_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_11_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_imgbtn_11, &style_tool_imgbtn_11_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_imgbtn_11_main_main_checked
	static lv_style_t style_tool_imgbtn_11_main_main_checked;
	if (style_tool_imgbtn_11_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_imgbtn_11_main_main_checked);
	else
		lv_style_init(&style_tool_imgbtn_11_main_main_checked);
	lv_style_set_text_color(&style_tool_imgbtn_11_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_imgbtn_11_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_imgbtn_11_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_imgbtn_11_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_imgbtn_11_main_main_checked, 255);
	lv_obj_add_style(ui->tool_imgbtn_11, &style_tool_imgbtn_11_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_imgbtn_11, LV_IMGBTN_STATE_RELEASED, NULL, &_lock_alpha_30x30, NULL);
	lv_obj_add_flag(ui->tool_imgbtn_11, LV_OBJ_FLAG_CHECKABLE);
}