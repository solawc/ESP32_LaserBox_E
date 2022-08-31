#include "draw_ready.h"
#include "stdio.h"
#include "stdlib.h"
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

		}
		else if (e->current_target == ready_page.btnSettings) {
			
		}
	}
}

void draw_ready(void) {

	// lv_ui.src1 = lv_obj_create(lv_ui.main_src);
	// lv_obj_remove_style_all(lv_ui.src1);
	// lv_obj_set_size(lv_ui.src1, 460, 120);
	// lv_obj_set_pos(lv_ui.src1, 10, 200);
	// lv_style_set_text_color(&lv_ui.src1_style, lv_color_white());
	// lv_obj_add_style(lv_ui.src1, &lv_ui.src1_style, 0);
	// lv_obj_clear_flag(lv_ui.src1, LV_OBJ_FLAG_SCROLLABLE);				/* cancle scroll style; */ 

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

	ready_page.label_wpos = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_wpos, 30, 30);

	ready_page.label_mpos = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_mpos, 30, 60);

	lv_label_set_text(ready_page.label_wpos, "Wpos:X:0.00 Y:0.00 Z:0.00");
	lv_label_set_text(ready_page.label_mpos, "Mpos:X:0.00 Y:0.00 Z:0.00");

	ready_page.ready_page_upadte = lv_timer_create(readyPageUpdateInfo, 200, NULL);
}

static void disp_power(void) {
	ready_page.labelPower = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.labelPower, 30, 90);
	lv_label_set_text(ready_page.labelPower, "Power:0");
}

static void disp_wifi(void) {
	ready_page.labelWifiState = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.labelWifiState, 30, 120);
	lv_label_set_text(ready_page.labelWifiState, "Wifi:Mode:STA State:Unconnect");
}

static void disp_btn(void) {
	ready_page.btnCtrl = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ready_page.btnCtrl, 80, 80);
	lv_obj_set_pos(ready_page.btnCtrl, 20, 210);
	lv_obj_add_event_cb(ready_page.btnCtrl, event_handler, LV_EVENT_ALL, nullptr);

	ready_page.btnPrinter = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ready_page.btnPrinter, 80, 80);
	lv_obj_set_pos(ready_page.btnPrinter, 120, 210);
	lv_obj_add_event_cb(ready_page.btnPrinter, event_handler, LV_EVENT_ALL, nullptr);

	ready_page.btnSettings = lv_btn_create(lv_ui.main_src);
	lv_obj_set_size(ready_page.btnSettings, 80, 80);
	lv_obj_set_pos(ready_page.btnSettings, 220, 210);
	lv_obj_add_event_cb(ready_page.btnSettings, event_handler, LV_EVENT_ALL, nullptr);

	ready_page.labelCtrl = lv_label_create(ready_page.btnCtrl);
	ready_page.labelPrinter = lv_label_create(ready_page.btnPrinter);
	ready_page.labelSettings = lv_label_create(ready_page.btnSettings);
	lv_obj_add_event_cb(ready_page.labelCtrl, event_handler, LV_EVENT_ALL, nullptr);

	lv_obj_set_align(ready_page.labelCtrl, LV_ALIGN_CENTER);
	lv_obj_set_align(ready_page.labelPrinter, LV_ALIGN_CENTER);
	lv_obj_set_align(ready_page.labelSettings, LV_ALIGN_CENTER);

	lv_label_set_text(ready_page.labelCtrl, "Control");
	lv_label_set_text(ready_page.labelPrinter, "Print");
	lv_label_set_text(ready_page.labelSettings, "Setting");
}

static void readyPageUpdateInfo(lv_timer_t*) {

	char pos[128];
	char s_value[5];
	float* mks_print_position;

	mks_print_position = system_get_mpos();

	sprintf(pos, "Wpos: X:%.2f Y:%.2f Z:%.2f", mks_print_position[0], mks_print_position[1], mks_print_position[2]);
	lv_label_set_text(ready_page.label_wpos, pos);

	sprintf(pos, "Mpos: X:%.2f Y:%.2f Z:%.2f", mks_print_position[0], mks_print_position[1], mks_print_position[2]);
	lv_label_set_text(ready_page.label_mpos, pos);

	sprintf(s_value, "Power:%d", sys.spindle_speed);
	lv_label_set_text(ready_page.labelPower, s_value);
}

void clear_ready_page(void) {
	lv_timer_del(ready_page.ready_page_upadte);	
	lv_obj_clean(lv_ui.main_src);				
}