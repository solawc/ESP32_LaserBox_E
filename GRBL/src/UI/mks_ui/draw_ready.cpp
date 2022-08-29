#include "draw_ready.h"
#include "stdio.h"
#include "stdlib.h"
ready_ui_t ready_page;

static void dispPosInfo(void);
static void disp_power(void);
static void readyPageUpdateInfo(lv_timer_t*);


static void event_handler(lv_event_t* e) {

	lv_event_code_t code = lv_event_get_code(e);  // get obj event

	if (code == LV_EVENT_RELEASED) {
		LV_LOG_USER("Click");

		if (e->current_target == ready_page.imgbtn_adj) {
			LV_LOG_USER("adj click");
			clear_ready_page();

		}
		else if (e->current_target == ready_page.imgbtn_ctrl) {
			LV_LOG_USER("ctrl click");
		}
		else {
			LV_LOG_USER("unlock click");
		}
	}
}

void draw_ready(void) {

	lv_ui.src1 = lv_obj_create(lv_ui.main_src);
	lv_obj_remove_style_all(lv_ui.src1);
	lv_obj_set_size(lv_ui.src1, 460, 120);
	lv_obj_set_pos(lv_ui.src1, 10, 200);
	lv_style_set_text_color(&lv_ui.src1_style, lv_color_white());
	lv_obj_add_style(lv_ui.src1, &lv_ui.src1_style, 0);
	lv_obj_clear_flag(lv_ui.src1, LV_OBJ_FLAG_SCROLLABLE);				// cancle scroll style;


	// disp x y z pos value
	dispPosInfo();

	// disp power value
	disp_power();
}




static void dispPosInfo(void) {

	ready_page.label_wXpos = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_wXpos, 30, 30);

	ready_page.label_wYpos = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_wYpos, 200, 30);

	ready_page.label_wZpos = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_wZpos, 370, 30);

	ready_page.label_mXpos = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_mXpos, 30, 60);

	ready_page.label_mYpos = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_mYpos, 200, 60);

	ready_page.label_mZpos = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_mZpos, 370, 60);

	lv_label_set_text(ready_page.label_wXpos, "wX:100.00");
	lv_label_set_text(ready_page.label_wYpos, "wX:100.00");
	lv_label_set_text(ready_page.label_wZpos, "wX:100.00");

	lv_label_set_text(ready_page.label_mXpos, "mX:100.00");
	lv_label_set_text(ready_page.label_mYpos, "mX:100.00");
	lv_label_set_text(ready_page.label_mZpos, "mX:100.00");

	ready_page.ready_page_upadte = lv_timer_create(readyPageUpdateInfo, 200, NULL);
}

static void disp_power(void) {

	ready_page.label_power = lv_label_create(lv_ui.main_src);
	lv_obj_set_pos(ready_page.label_power, 30, 90);
	lv_label_set_text(ready_page.label_power, "S:1000");
}

static void readyPageUpdateInfo(lv_timer_t*) {

	char wpos[3][20];
	char mpos[3][20];
	char s_value[20];
#ifdef USE_WINDOS_LIST
	static float mxpos_value[3];
	static float wxpos_value[3];

	for (int i = 0; i < 3; i++) {
		mxpos_value[i] ++;
		wxpos_value[i] ++;
	}
#endif

#ifdef USE_WINDOS_LIST
	char axis;
	for (int i = 0; i < 3; i++) {
		if (i == 0) axis = 'X';
		else if (i == 1) axis = 'Y';
		else axis = 'Z';

		sprintf(wpos[i], "w%c:%.2f", axis, wxpos_value[i]);
		sprintf(mpos[i], "m%c:%.2f", axis, mxpos_value[i]);
	}

	lv_label_set_text(ready_page.label_wXpos, wpos[0]);
	lv_label_set_text(ready_page.label_wYpos, wpos[1]);
	lv_label_set_text(ready_page.label_wZpos, wpos[2]);

	lv_label_set_text(ready_page.label_mXpos, mpos[0]);
	lv_label_set_text(ready_page.label_mYpos, mpos[1]);
	lv_label_set_text(ready_page.label_mZpos, mpos[2]);
#else 
	char axis;
	float mks_print_position[MAX_N_AXIS];
	system_convert_array_steps_to_mpos(mks_print_position, sys_position);

	for (int i = 0; i < 3; i++) {
		if (i == 0) axis = 'X';
		else if (i == 1) axis = 'Y';
		else axis = 'Z';

		sprintf(wpos[i], "w%c:%.2f", axis, mks_print_position[i]);
		sprintf(mpos[i], "m%c:%.2f", axis, mks_print_position[i]);
	}

	sprintf(s_value, "Power:%d", sys.spindle_speed);

	lv_label_set_text(ready_page.label_wXpos, wpos[0]);
	lv_label_set_text(ready_page.label_wYpos, wpos[1]);
	lv_label_set_text(ready_page.label_wZpos, wpos[2]);

	lv_label_set_text(ready_page.label_mXpos, mpos[0]);
	lv_label_set_text(ready_page.label_mYpos, mpos[1]);
	lv_label_set_text(ready_page.label_mZpos, mpos[2]);

	lv_label_set_text(ready_page.label_power, s_value);
#endif
}

void clear_ready_page(void) {
	lv_timer_del(ready_page.ready_page_upadte);		// ���������
	lv_obj_clean(lv_ui.main_src);					// �����ҳ�Ĳ���
}