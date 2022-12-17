/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"

lv_ui guider_ui;

void init_scr_del_flag(lv_ui *ui){
	ui->logo_del = true;
	ui->home_del = true;
	ui->tool_del = true;
	ui->larse_power_del = true;
	ui->sculpture_del = true;
	ui->setting_del = true;
	ui->setting_language_del = true;
	ui->setting_parameter_del = true;
	ui->about_del = true;
}

void setup_ui(lv_ui *ui){
	init_scr_del_flag(ui);
	setup_scr_home(ui);
	lv_scr_load(ui->home);
}
