/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "./custom/custom.h"

void events_init(lv_ui *ui)
{
}

static void home_btn_tool_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		guider_load_screen(SCR_TOOL);
	}
		break;
	default:
		break;
	}
}

static void home_btn_larsepower_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		guider_load_screen(SCR_LARSEPOWER);
	}
		break;
	default:
		break;
	}
}

static void home_btn_about_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		guider_load_screen(SCR_ABOUT);
	}
		break;
	default:
		break;
	}
}

static void home_btn_setting_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		guider_load_screen(SCR_SETTING);
	}
		break;
	default:
		break;
	}
}

static void home_btn_sculpture_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		guider_load_screen(SCR_SCULPTRUE);
	}
		break;
	default:
		break;
	}
}

void events_init_home(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->home_btn_tool, home_btn_tool_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_btn_larsepower, home_btn_larsepower_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_btn_about, home_btn_about_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_btn_setting, home_btn_setting_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_btn_sculpture, home_btn_sculpture_event_handler, LV_EVENT_ALL, NULL);
}

static void larse_power_cb_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj =  lv_event_get_target(e);
	lv_ui* handle = (lv_ui*)lv_event_get_user_data(e);
	lv_state_t state = lv_obj_get_state(obj);

	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{	
		if (state == (LV_STATE_CHECKED|LV_STATE_FOCUSED))
		{
			lv_obj_add_state(handle->larse_power_cb_2, LV_STATE_DISABLED);		
			lv_obj_add_state(handle->larse_power_cb_3, LV_STATE_DISABLED);
			lv_obj_add_state(handle->larse_power_cb_4, LV_STATE_DISABLED);
		}
		else
		{
			lv_obj_clear_state(handle->larse_power_cb_2, LV_STATE_DISABLED);
			lv_obj_clear_state(handle->larse_power_cb_3, LV_STATE_DISABLED);
			lv_obj_clear_state(handle->larse_power_cb_4, LV_STATE_DISABLED);
		}
	}
		break;
	default:
		break;
	}
}

static void larse_power_cb_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj =  lv_event_get_target(e);
	lv_ui* handle = (lv_ui*)lv_event_get_user_data(e);
	lv_state_t state = lv_obj_get_state(obj);

	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{	
		if (state == (LV_STATE_CHECKED|LV_STATE_FOCUSED))
		{
			lv_obj_add_state(handle->larse_power_cb_1, LV_STATE_DISABLED);		
			lv_obj_add_state(handle->larse_power_cb_3, LV_STATE_DISABLED);
			lv_obj_add_state(handle->larse_power_cb_4, LV_STATE_DISABLED);
		}
		else
		{
			lv_obj_clear_state(handle->larse_power_cb_1, LV_STATE_DISABLED);
			lv_obj_clear_state(handle->larse_power_cb_3, LV_STATE_DISABLED);
			lv_obj_clear_state(handle->larse_power_cb_4, LV_STATE_DISABLED);
		}
	}
		break;
	default:
		break;
	}
}

static void larse_power_cb_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj =  lv_event_get_target(e);
	lv_ui* handle = (lv_ui*)lv_event_get_user_data(e);
	lv_state_t state = lv_obj_get_state(obj);

	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{	
		if (state == (LV_STATE_CHECKED|LV_STATE_FOCUSED))
		{
			lv_obj_add_state(handle->larse_power_cb_1, LV_STATE_DISABLED);		
			lv_obj_add_state(handle->larse_power_cb_2, LV_STATE_DISABLED);
			lv_obj_add_state(handle->larse_power_cb_4, LV_STATE_DISABLED);
		}
		else
		{
			lv_obj_clear_state(handle->larse_power_cb_1, LV_STATE_DISABLED);
			lv_obj_clear_state(handle->larse_power_cb_2, LV_STATE_DISABLED);
			lv_obj_clear_state(handle->larse_power_cb_4, LV_STATE_DISABLED);
		}
	}
		break;
	default:
		break;
	}
}

static void larse_power_cb_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t* obj =  lv_event_get_target(e);
	lv_ui* handle = (lv_ui*)lv_event_get_user_data(e);
	lv_state_t state = lv_obj_get_state(obj);

	switch (code)
	{
	case LV_EVENT_VALUE_CHANGED:
	{	
		if (state == (LV_STATE_CHECKED|LV_STATE_FOCUSED))
		{
			lv_obj_add_state(handle->larse_power_cb_1, LV_STATE_DISABLED);		
			lv_obj_add_state(handle->larse_power_cb_2, LV_STATE_DISABLED);
			lv_obj_add_state(handle->larse_power_cb_3, LV_STATE_DISABLED);			
		}
		else
		{
			lv_obj_clear_state(handle->larse_power_cb_1, LV_STATE_DISABLED);
			lv_obj_clear_state(handle->larse_power_cb_2, LV_STATE_DISABLED);
			lv_obj_clear_state(handle->larse_power_cb_3, LV_STATE_DISABLED);
		}
	}
		break;
	default:
		break;
	}
}

void events_init_larse_power(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->larse_power_cb_1, larse_power_cb_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->larse_power_cb_2, larse_power_cb_2_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->larse_power_cb_3, larse_power_cb_3_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->larse_power_cb_4, larse_power_cb_4_event_handler, LV_EVENT_ALL, ui);
}

static void setting_language_imgbtn_setting_language_return_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		guider_load_screen(SCR_HOME);
	}
		break;
	default:
		break;
	}
}

void events_init_setting_language(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->setting_language_imgbtn_setting_language_return, setting_language_imgbtn_setting_language_return_event_handler, LV_EVENT_ALL, NULL);
}

static void setting_parameter_imgbtn_setting_paremeter_return_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		guider_load_screen(SCR_HOME);
	}
		break;
	default:
		break;
	}
}

void events_init_setting_parameter(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->setting_parameter_imgbtn_setting_paremeter_return, setting_parameter_imgbtn_setting_paremeter_return_event_handler, LV_EVENT_ALL, NULL);
}
