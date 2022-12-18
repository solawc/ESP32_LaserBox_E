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

void setup_scr_logo(lv_ui *ui){

	//Write codes logo
	ui->logo = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->logo, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_logo_main_main_default
	static lv_style_t style_logo_main_main_default;
	if (style_logo_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_logo_main_main_default);
	else
		lv_style_init(&style_logo_main_main_default);
	lv_style_set_bg_color(&style_logo_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_logo_main_main_default, 0);
	lv_obj_add_style(ui->logo, &style_logo_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes logo_img_1
	ui->logo_img_1 = lv_img_create(ui->logo);
	lv_obj_set_pos(ui->logo_img_1, 0, 0);
	lv_obj_set_size(ui->logo_img_1, 480, 320);
	lv_obj_set_scrollbar_mode(ui->logo_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_logo_img_1_main_main_default
	static lv_style_t style_logo_img_1_main_main_default;
	if (style_logo_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_logo_img_1_main_main_default);
	else
		lv_style_init(&style_logo_img_1_main_main_default);
	lv_style_set_img_recolor(&style_logo_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_logo_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_logo_img_1_main_main_default, 255);
	lv_obj_add_style(ui->logo_img_1, &style_logo_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->logo_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->logo_img_1,&_MakeGologo_480x320);
	lv_img_set_pivot(ui->logo_img_1, 0,0);
	lv_img_set_angle(ui->logo_img_1, 0);
}