// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/*
 * custom.h
 *
 *  Created on: July 29, 2020
 *      Author: nxf53801
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "../gui_guider.h"
#include "draw_sdcard.h"

enum SCR_ID {
    SCR_LOGO                = 0,
	SCR_HOME                = 1,
	SCR_TOOL                = 2,
	SCR_LARSEPOWER          = 3,
    SCR_SCULPTRUE           = 4,
	SCR_SETTING             = 5,
    SCR_SETTING_LANGUAGE    = 6,
    SCR_SETTING_PARAMETER   = 7,
    SCR_ABOUT               = 8,
};

extern int gCurScr;

void scr_tool_event_init(void);
void scr_larsepower_event_init(void);
void scr_sculpture_event_init(void);
void scr_setting_event_init(void);
void scr_about_event_init(void);

void custom_init(lv_ui *ui);
void guider_load_screen(int scr_id);
// void add_loader(void (*end_cb)(lv_anim_t *));
void load_logo(lv_anim_t *a);
void load_home(lv_anim_t *a);
void load_tool(lv_anim_t *a);
void load_larsepower(lv_anim_t *a);
void load_sculptrue(lv_anim_t *a);
void load_setting(lv_anim_t *a);
void load_about(lv_anim_t *a);
void load_disbtn_home_cb(lv_event_t * event); //use to all return home button.

// set home page interface
extern float gWorkCoordinatesX;
extern float gWorkCoordinatesY;
extern float gWorkCoordinatesZ;
extern float gMachineCoordinatesX;
extern float gMachineCoordinatesY;
extern float gMachineCoordinatesZ;
extern int16_t gMachineState;
void src_home_set_work_coordinates(lv_ui *ui, float x, float y, float z);
void src_home_set_machine_coordinates(lv_ui *ui, float x, float y, float z);
void src_home_set_state(lv_ui *ui, int16_t state);
void src_home_init_work_coordinates(lv_ui *ui);
void src_home_init_machine_coordinates(lv_ui *ui);
void src_home_init_state(lv_ui *ui);
// set larse power interface
extern int8_t gLarsePower;
void src_larse_power_set_power(lv_ui *ui, int8_t power);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
