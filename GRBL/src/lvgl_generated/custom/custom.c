// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
int gCurScr; // to record current screen.
float gWorkCoordinatesX;
float gWorkCoordinatesY;
float gWorkCoordinatesZ;
float gMachineCoordinatesX;
float gMachineCoordinatesY;
float gMachineCoordinatesZ;
int16_t gMachineState;
int8_t gLarsePower;
/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */
lv_obj_t **get_scr_by_id(int scr_id)
{
    if(scr_id == SCR_LOGO)
        return &guider_ui.logo;
    else if(scr_id == SCR_HOME)
        return &guider_ui.home;
    else if(scr_id == SCR_TOOL)
        return &guider_ui.tool;
    else if(scr_id == SCR_LARSEPOWER)
        return &guider_ui.larse_power;
    else if(scr_id == SCR_SETTING)
        return &guider_ui.setting;
    else if(scr_id == SCR_SCULPTRUE)
        return &guider_ui.sculpture;
    else if(scr_id == SCR_ABOUT)
        return &guider_ui.about;        

    return NULL;
}

// void add_loader(void (*end_cb)(lv_anim_t *)){
//     lv_anim_t a;
//     lv_arc_set_angles(guider_ui.loader_loadarc, 270, 270);
//     lv_anim_init(&a);
//     lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) loader_anim_cb);
//     lv_anim_set_ready_cb(&a, end_cb);
//     lv_anim_set_values(&a, 0, 110);
//     lv_anim_set_time(&a, LOAD_ANIM_TIME);
//     lv_anim_set_var(&a, guider_ui.loader_loadarc);
//     lv_anim_start(&a);
// }

void guider_load_screen(int scr_id)
{
    lv_obj_t **scr = NULL;
    lv_obj_t **old_scr = NULL;

    old_scr = get_scr_by_id(gCurScr);
    lv_obj_clean(*old_scr);
    lv_obj_del(*old_scr);
    *old_scr = NULL;
    
    switch(scr_id)
    {
        case SCR_LOGO:
            if(!guider_ui.logo) {
                scr = &guider_ui.logo;
                setup_scr_logo(&guider_ui);
            }
            break;        
        case SCR_HOME:
            if(!guider_ui.home) {
                scr = &guider_ui.home;
                setup_scr_home(&guider_ui);
            }
            break;
        case SCR_TOOL:
            if(!guider_ui.tool) {
                scr = &guider_ui.tool;
                setup_scr_tool(&guider_ui);
                scr_tool_event_init();
            }
            break;
        case SCR_LARSEPOWER:
            if(!guider_ui.larse_power) {
                scr = &guider_ui.larse_power;
                setup_scr_larse_power(&guider_ui);
                scr_larsepower_event_init();
            }
            break;       
        case SCR_SCULPTRUE:
            if(!guider_ui.sculpture) {
                scr = &guider_ui.sculpture;
                setup_scr_sculpture(&guider_ui);
                scr_sculpture_event_init();
                draw_sdcard();
            }
            break; 
        case SCR_SETTING:
            if(!guider_ui.setting) {
                scr = &guider_ui.setting;
                setup_scr_setting(&guider_ui);
                scr_setting_event_init();
            }
            break; 
        case SCR_ABOUT:
            if(!guider_ui.about) {
                scr = &guider_ui.about;
                setup_scr_about(&guider_ui);
                scr_about_event_init();
            }
            break;                                                                                 
    }

    lv_scr_load(*scr);

    gCurScr = scr_id;
}

void load_logo(lv_anim_t *a)
{
    guider_load_screen(SCR_LOGO);
}

void load_home(lv_anim_t *a) {
    guider_load_screen(SCR_HOME);
}

void load_tool(lv_anim_t *a) {
    guider_load_screen(SCR_TOOL);
}

void load_larsepower(lv_anim_t *a){
    guider_load_screen(SCR_LARSEPOWER);
}

void load_sculptrue(lv_anim_t *a) {
    guider_load_screen(SCR_SCULPTRUE);
}

void load_setting(lv_anim_t *a) {
    guider_load_screen(SCR_SETTING);
}

void load_about(lv_anim_t *a){
    guider_load_screen(SCR_ABOUT);
}

void load_disbtn_home_cb(lv_event_t * event){
    lv_event_code_t code = lv_event_get_code(event);
    lv_obj_t * obj = lv_event_get_target(event);
    if (code == LV_EVENT_PRESSED) {
        guider_load_screen(SCR_HOME);
    }
}

void scr_tool_event_init(void){
    lv_obj_add_event_cb(guider_ui.tool_imgbtn_tool_return, load_disbtn_home_cb, LV_EVENT_ALL, NULL);
}

void scr_larsepower_event_init(void){
    lv_obj_add_event_cb(guider_ui.larse_power_imgbtn_larsepower_return, load_disbtn_home_cb, LV_EVENT_ALL, NULL);
}

void scr_sculpture_event_init(void){
    lv_obj_add_event_cb(guider_ui.sculpture_imgbtn_sculpture_return, load_disbtn_home_cb, LV_EVENT_ALL, NULL);
}

void scr_setting_event_init(void){
    lv_obj_add_event_cb(guider_ui.setting_imgbtn_setting_home_return, load_disbtn_home_cb, LV_EVENT_ALL, NULL);
}

void scr_about_event_init(void){
    lv_obj_add_event_cb(guider_ui.about_imgbtn_about_return, load_disbtn_home_cb, LV_EVENT_ALL, NULL);
}

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    // setup_scr_home(ui);
    gCurScr = SCR_HOME;
    ui->logo = NULL;
    ui->tool = NULL;
    ui->setting = NULL;
    ui->sculpture = NULL;
    ui->about = NULL;

    // lv_scr_load(ui->home);    
}

void src_home_set_work_coordinates(lv_ui *ui, float x, float y, float z)
{
    gWorkCoordinatesX = x;
    gWorkCoordinatesY = y;
    gWorkCoordinatesZ = z;
    lv_label_set_text_fmt(ui->home_label_w_x, "%f", gWorkCoordinatesX);
    lv_label_set_text_fmt(ui->home_label_w_y, "%f", gWorkCoordinatesY);
    lv_label_set_text_fmt(ui->home_label_w_z, "%f", gWorkCoordinatesZ);
}

void src_home_set_machine_coordinates(lv_ui *ui, float x, float y, float z)
{
    gMachineCoordinatesX = x;
    gMachineCoordinatesY = y;
    gMachineCoordinatesZ = z;
    lv_label_set_text_fmt(ui->home_label_m_x, "%f", gMachineCoordinatesX);
    lv_label_set_text_fmt(ui->home_label_m_y, "%f", gMachineCoordinatesY);
    lv_label_set_text_fmt(ui->home_label_m_z, "%f", gMachineCoordinatesZ);
}

void src_home_set_state(lv_ui *ui, int16_t state)
{
    gMachineState = state;
    lv_label_set_text_fmt(ui->home_label_status, "%d", gMachineState);
}

void src_home_init_work_coordinates(lv_ui *ui)
{
    lv_label_set_text_fmt(ui->home_label_w_x, "%f", gWorkCoordinatesX);
    lv_label_set_text_fmt(ui->home_label_w_y, "%f", gWorkCoordinatesY);
    lv_label_set_text_fmt(ui->home_label_w_z, "%f", gWorkCoordinatesZ);
}

void src_home_init_machine_coordinates(lv_ui *ui)
{
    lv_label_set_text_fmt(ui->home_label_m_x, "%f", gMachineCoordinatesX);
    lv_label_set_text_fmt(ui->home_label_m_y, "%f", gMachineCoordinatesY);
    lv_label_set_text_fmt(ui->home_label_m_z, "%f", gMachineCoordinatesZ);    
}

void src_home_init_state(lv_ui *ui)
{
    lv_label_set_text_fmt(ui->home_label_status, "%d", gMachineState);
}

void src_larse_power_set_power(lv_ui *ui, int8_t power)
{
    gLarsePower = power;
}
