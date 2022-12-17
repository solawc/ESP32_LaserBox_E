/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "./guider_fonts/guider_fonts.h"

typedef struct
{
	lv_obj_t *logo;
	bool logo_del;
	lv_obj_t *logo_img_1;	
	lv_obj_t *home;
	bool home_del;
	lv_obj_t *home_btn_tool;
	lv_obj_t *home_btn_tool_label;
	lv_obj_t *home_btn_larsepower;
	lv_obj_t *home_btn_larsepower_label;
	lv_obj_t *home_btn_about;
	lv_obj_t *home_btn_about_label;
	lv_obj_t *home_btn_setting;
	lv_obj_t *home_btn_setting_label;
	lv_obj_t *home_btn_sculpture;
	lv_obj_t *home_btn_sculpture_label;
	lv_obj_t *home_cont_1;
	lv_obj_t *home_label_m_z;
	lv_obj_t *home_cont_2;
	lv_obj_t *home_label_w_z;
	lv_obj_t *home_label_4;
	lv_obj_t *home_label_m_y;
	lv_obj_t *home_label_m_x;
	lv_obj_t *home_label_machine_coordinates_y;
	lv_obj_t *home_label_machine_coordinates_z;
	lv_obj_t *home_label_work_coordinates_z;
	lv_obj_t *home_label_work_coordinates_y;
	lv_obj_t *home_label_3;
	lv_obj_t *home_label_status;
	lv_obj_t *home_label_machine_status;
	lv_obj_t *home_label_w_x;
	lv_obj_t *home_label_w_y;
	lv_obj_t *home_label_work_coordinates_x;
	lv_obj_t *home_label_machine_coordinates_x;
	lv_obj_t *tool;
	bool tool_del;
	lv_obj_t *tool_cont_1;
	lv_obj_t *tool_ddlist_2;
	lv_obj_t *tool_label_2;
	lv_obj_t *tool_label_1;
	lv_obj_t *tool_ddlist_1;
	lv_obj_t *tool_cont_2;
	lv_obj_t *tool_label_3;
	lv_obj_t *tool_label_4;
	lv_obj_t *tool_label_5;
	lv_obj_t *tool_imgbtn_tool_return;
	lv_obj_t *tool_imgbtn_tool_return_label;
	lv_obj_t *tool_cont_3;
	lv_obj_t *tool_imgbtn_2;
	lv_obj_t *tool_imgbtn_2_label;
	lv_obj_t *tool_imgbtn_3;
	lv_obj_t *tool_imgbtn_3_label;
	lv_obj_t *tool_imgbtn_4;
	lv_obj_t *tool_imgbtn_4_label;
	lv_obj_t *tool_imgbtn_6;
	lv_obj_t *tool_imgbtn_6_label;
	lv_obj_t *tool_imgbtn_7;
	lv_obj_t *tool_imgbtn_7_label;
	lv_obj_t *tool_imgbtn_5;
	lv_obj_t *tool_imgbtn_5_label;
	lv_obj_t *tool_imgbtn_8;
	lv_obj_t *tool_imgbtn_8_label;
	lv_obj_t *tool_imgbtn_9;
	lv_obj_t *tool_imgbtn_9_label;
	lv_obj_t *tool_imgbtn_10;
	lv_obj_t *tool_imgbtn_10_label;
	lv_obj_t *tool_imgbtn_11;
	lv_obj_t *tool_imgbtn_11_label;
	lv_obj_t *larse_power;
	bool larse_power_del;
	lv_obj_t *larse_power_imgbtn_larsepower_return;
	lv_obj_t *larse_power_imgbtn_larsepower_return_label;
	lv_obj_t *larse_power_label_1;
	lv_obj_t *larse_power_sw_1;
	lv_obj_t *larse_power_img_1;
	lv_obj_t *larse_power_img_2;
	lv_obj_t *larse_power_img_3;
	lv_obj_t *larse_power_img_4;
	lv_obj_t *larse_power_cb_1;
	lv_obj_t *larse_power_cb_2;
	lv_obj_t *larse_power_cb_3;
	lv_obj_t *larse_power_cb_4;
	lv_obj_t *sculpture;
	bool sculpture_del;
	lv_obj_t *sculpture_imgbtn_sculpture_return;
	lv_obj_t *sculpture_imgbtn_sculpture_return_label;
	lv_obj_t *sculpture_animimg_1;
	lv_obj_t *setting;
	bool setting_del;
	lv_obj_t *setting_imgbtn_setting_home_return;
	lv_obj_t *setting_imgbtn_setting_home_return_label;
	lv_obj_t *setting_imgbtn_parameter;
	lv_obj_t *setting_imgbtn_parameter_label;
	lv_obj_t *setting_imgbtn_language;
	lv_obj_t *setting_imgbtn_language_label;
	lv_obj_t *setting_language;
	bool setting_language_del;
	lv_obj_t *setting_language_imgbtn_setting_language_return;
	lv_obj_t *setting_language_imgbtn_setting_language_return_label;
	lv_obj_t *setting_language_imgbtn_setting_chinese;
	lv_obj_t *setting_language_imgbtn_setting_chinese_label;
	lv_obj_t *setting_language_imgbtn_setting_english;
	lv_obj_t *setting_language_imgbtn_setting_english_label;
	lv_obj_t *setting_parameter;
	bool setting_parameter_del;
	lv_obj_t *setting_parameter_imgbtn_setting_paremeter_return;
	lv_obj_t *setting_parameter_imgbtn_setting_paremeter_return_label;
	lv_obj_t *setting_parameter_imgbtn_setting;
	lv_obj_t *setting_parameter_imgbtn_setting_label;
	lv_obj_t *about;
	bool about_del;
	lv_obj_t *about_img_info;
	lv_obj_t *about_imgbtn_about_return;
	lv_obj_t *about_imgbtn_about_return_label;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_logo(lv_ui *ui);
void setup_scr_home(lv_ui *ui);
void setup_scr_tool(lv_ui *ui);
void setup_scr_larse_power(lv_ui *ui);
void setup_scr_sculpture(lv_ui *ui);

#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(sculpture_animimg_1sculpture_file)
void setup_scr_setting(lv_ui *ui);
void setup_scr_setting_language(lv_ui *ui);
void setup_scr_setting_parameter(lv_ui *ui);
void setup_scr_about(lv_ui *ui);
LV_IMG_DECLARE(_up_alpha_50x50);
LV_IMG_DECLARE(_parameter_alpha_189x50);
LV_IMG_DECLARE(_chinese_alpha_150x50);
LV_IMG_DECLARE(_return_alpha_100x50);
LV_IMG_DECLARE(_right_alpha_50x50);
LV_IMG_DECLARE(_z_up_alpha_50x50);
LV_IMG_DECLARE(_100_power_46x47);
LV_IMG_DECLARE(_left_alpha_50x50);
LV_IMG_DECLARE(_restart_alpha_30x30);
LV_IMG_DECLARE(_parameter_alpha_220x60);
LV_IMG_DECLARE(_about_290x102);
LV_IMG_DECLARE(_return_alpha_82x42);
LV_IMG_DECLARE(_return_alpha_102x38);
LV_IMG_DECLARE(_25_power_44x44);
LV_IMG_DECLARE(_zero_alpha_30x30);
LV_IMG_DECLARE(_return_alpha_72x22);
LV_IMG_DECLARE(_half_power_44x46);
LV_IMG_DECLARE(_5_power_47x37);
LV_IMG_DECLARE(_lock_alpha_30x30);
LV_IMG_DECLARE(_down_alpha_50x50);
LV_IMG_DECLARE(_English_alpha_150x50);
LV_IMG_DECLARE(_z_down_alpha_50x50);
LV_IMG_DECLARE(_clean_alpha_30x30);
LV_IMG_DECLARE(_language_alpha_220x60);
LV_IMG_DECLARE(_MakeGologo_480x320);

#ifdef __cplusplus
}
#endif
#endif