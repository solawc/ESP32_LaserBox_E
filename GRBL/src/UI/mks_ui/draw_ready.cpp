#include "draw_ready.h"
#include "stdio.h"
#include "stdlib.h"
#include "Esp.h"

ready_ui_t ready_page;

static void dispPosInfo(void);
static void disp_power(void);
static void disp_wifi(void);
static void disp_btn(void);
static void readyPageUpdateInfo(lv_timer_t*);

static void event_handler(lv_event_t* e) {

	lv_event_code_t code = lv_event_get_code(e);  /* get obj event */ 

	if (code == LV_EVENT_RELEASED) {

		if (e->current_target == ready_page.btnCtrl) {
			clear_ready_page();
			draw_ctrl();
		}
		else if (e->current_target == ready_page.btnPrinter) {
			clear_ready_page();
			draw_sdcard();
		}
		else if (e->current_target == ready_page.btnSettings) {
			
		}
		else if (e->current_target == ready_page.btnUnlock) {
			GRBL_CMD_SEND("$X\n");
		}
	}
}

void draw_ready(void) {

	/* disp x y z pos value */ 
	dispPosInfo();

	/* disp power value */ 
	disp_power();

	/* disp wifi state */
	disp_wifi();

	/* draw btn */
	disp_btn();
}

static void dispPosInfo(void) {

	ready_page.label_wpos = lv_label_create(mks_lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_wpos, 30, 30);

	ready_page.label_mpos = lv_label_create(mks_lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_mpos, 30, 60);

	ready_page.labelState = lv_label_create(mks_lv_ui.main_src);
	lv_obj_set_pos(ready_page.labelState, 30, 150);

	ready_page.labelRam = lv_label_create(mks_lv_ui.main_src);
	lv_obj_set_pos(ready_page.labelRam, 30, 180);
	

	lv_label_set_text(ready_page.label_wpos, "Wpos:X:0.00 Y:0.00 Z:0.00");
	lv_label_set_text(ready_page.label_mpos, "Mpos:X:0.00 Y:0.00 Z:0.00");
	lv_label_set_text(ready_page.labelState, "State:");
	lv_label_set_text(ready_page.labelRam, "RAM:");

	ready_page.ready_page_upadte = lv_timer_create(readyPageUpdateInfo, 200, NULL);
}

static void disp_power(void) {
	ready_page.labelPower = lv_label_create(mks_lv_ui.main_src);
	lv_obj_set_pos(ready_page.labelPower, 30, 90);
	lv_label_set_text(ready_page.labelPower, "Power:0");
}

static void disp_mc_state(void) {

	if(sys.state == State::Idle) {
		lv_label_set_text(ready_page.labelState, "State:Idle");
	}else if(sys.state == State::Alarm) {
		lv_label_set_text(ready_page.labelState, "State:Alarm");
	}else if(sys.state == State::CheckMode) {
		lv_label_set_text(ready_page.labelState, "State:CheckMode");
	}else if(sys.state == State::Homing) {
		lv_label_set_text(ready_page.labelState, "State:Homing");
	}else if(sys.state == State::Cycle) {
		lv_label_set_text(ready_page.labelState, "State:Cycle");
	}else if(sys.state == State::Hold) {
		lv_label_set_text(ready_page.labelState, "State:Hold");
	}else if(sys.state == State::Jog) {
		lv_label_set_text(ready_page.labelState, "State:Jog");
	}else if(sys.state == State::SafetyDoor) {
		lv_label_set_text(ready_page.labelState, "State:SafetyDoor");
	}else if(sys.state == State::Sleep) {
		lv_label_set_text(ready_page.labelState, "State:Sleep");
	}
}

static void disp_wifi(void) {
	ready_page.labelWifiState = lv_label_create(mks_lv_ui.main_src);
	lv_obj_set_pos(ready_page.labelWifiState, 30, 120);
	lv_label_set_text(ready_page.labelWifiState, "Wifi:Mode:STA State:Unconnect");
}

static void disp_btn(void) {

	
	ready_page.btnCtrl = lv_btn_create(mks_lv_ui.main_src);
	lv_obj_set_size(ready_page.btnCtrl, 80, 80);
	lv_obj_set_pos(ready_page.btnCtrl, 20, 210);
	lv_obj_add_event_cb(ready_page.btnCtrl, event_handler, LV_EVENT_ALL, nullptr);

	ready_page.btnPrinter = lv_btn_create(mks_lv_ui.main_src);
	lv_obj_set_size(ready_page.btnPrinter, 80, 80);
	lv_obj_set_pos(ready_page.btnPrinter, 120, 210);
	lv_obj_add_event_cb(ready_page.btnPrinter, event_handler, LV_EVENT_ALL, nullptr);

	ready_page.btnSettings = lv_btn_create(mks_lv_ui.main_src);
	lv_obj_set_size(ready_page.btnSettings, 80, 80);
	lv_obj_set_pos(ready_page.btnSettings, 220, 210);
	lv_obj_add_event_cb(ready_page.btnSettings, event_handler, LV_EVENT_ALL, nullptr);

	ready_page.btnUnlock = lv_btn_create(mks_lv_ui.main_src);
	lv_obj_set_size(ready_page.btnUnlock, 80, 80);
	lv_obj_set_pos(ready_page.btnUnlock, 320, 210);
	lv_obj_add_event_cb(ready_page.btnUnlock, event_handler, LV_EVENT_ALL, nullptr);

	ready_page.labelCtrl = lv_label_create(ready_page.btnCtrl);
	ready_page.labelPrinter = lv_label_create(ready_page.btnPrinter);
	ready_page.labelSettings = lv_label_create(ready_page.btnSettings);
	ready_page.labelUnlock = lv_label_create(ready_page.btnUnlock);
	lv_obj_add_event_cb(ready_page.labelCtrl, event_handler, LV_EVENT_ALL, nullptr);

	lv_obj_set_align(ready_page.labelCtrl, LV_ALIGN_CENTER);
	lv_obj_set_align(ready_page.labelPrinter, LV_ALIGN_CENTER);
	lv_obj_set_align(ready_page.labelSettings, LV_ALIGN_CENTER);
	lv_obj_set_align(ready_page.labelUnlock, LV_ALIGN_CENTER);

	lv_label_set_text(ready_page.labelCtrl, "Control");
	lv_label_set_text(ready_page.labelPrinter, "Print");
	lv_label_set_text(ready_page.labelSettings, "Setting");
	lv_label_set_text(ready_page.labelUnlock, "Unlock");
}

String formate(uint64_t bytes) {
	if (bytes < 1024) {
		return String((uint16_t)bytes) + " B";
	} else if (bytes < (1024 * 1024)) {
		return String((float)(bytes / 1024.0), 2) + " KB";
	} else if (bytes < (1024 * 1024 * 1024)) {
		return String((float)(bytes / 1024.0 / 1024.0), 2) + " MB";
	} else {
		return String((float)(bytes / 1024.0 / 1024.0 / 1024.0), 2) + " GB";
	}
}

static void readyPageUpdateInfo(lv_timer_t*) {

	char pos[128];
	char s_value[10];
	float* mks_print_position;

	mks_print_position = system_get_mpos();

	sprintf(pos, "Wpos: X:%.2f Y:%.2f Z:%.2f", mks_print_position[0], mks_print_position[1], mks_print_position[2]);
	lv_label_set_text(ready_page.label_wpos, pos);

	sprintf(pos, "Mpos: X:%.2f Y:%.2f Z:%.2f", mks_print_position[0], mks_print_position[1], mks_print_position[2]);
	lv_label_set_text(ready_page.label_mpos, pos);

	sprintf(s_value, "Power:%d", sysGetSpindleSpeed());
	lv_label_set_text(ready_page.labelPower, s_value);

	lv_label_set_text(ready_page.labelRam, formate(ESP.getFreeHeap()).c_str());
	
	/* disp machine state */
	disp_mc_state();
}

void clear_ready_page(void) {
	lv_timer_del(ready_page.ready_page_upadte);	
	lv_obj_clean(mks_lv_ui.main_src);				
}