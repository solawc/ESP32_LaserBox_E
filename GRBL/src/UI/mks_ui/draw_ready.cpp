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
	lv_obj_clear_flag(lv_ui.src1, LV_OBJ_FLAG_SCROLLABLE);		// cancle scroll style;

	// set imgbtn style
	lv_style_init(&ready_page.imgbtn_style);
	lv_style_set_text_color(&ready_page.imgbtn_style, lv_color_white());
	lv_style_set_transform_width(&ready_page.imgbtn_style, 0);

	ready_page.imgbtn_adj = lv_imgbtn_create(lv_ui.src1);
	lv_obj_clear_flag(ready_page.imgbtn_adj, LV_OBJ_FLAG_SCROLLABLE);
	lv_imgbtn_set_src(ready_page.imgbtn_adj, LV_IMGBTN_STATE_RELEASED, &Adjustment, NULL, NULL);
	lv_imgbtn_set_src(ready_page.imgbtn_adj, LV_IMGBTN_STATE_PRESSED, &png_adj_pre, NULL, NULL);
	lv_obj_add_event_cb(ready_page.imgbtn_adj, event_handler, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ready_page.imgbtn_adj, 50, 10);
	lv_obj_set_size(ready_page.imgbtn_adj, 60, 60);

	ready_page.imgbtn_ctrl = lv_imgbtn_create(lv_ui.src1);
	lv_imgbtn_set_src(ready_page.imgbtn_ctrl, LV_IMGBTN_STATE_RELEASED, &Control, NULL, NULL);
	lv_imgbtn_set_src(ready_page.imgbtn_ctrl, LV_IMGBTN_STATE_PRESSED, &png_ctrl_pre, NULL, NULL);
	lv_obj_add_event_cb(ready_page.imgbtn_ctrl, event_handler, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ready_page.imgbtn_ctrl, 150, 10);
	lv_obj_set_size(ready_page.imgbtn_ctrl, 60, 60);

	ready_page.imgbtn_sculpture = lv_imgbtn_create(lv_ui.src1);
	lv_imgbtn_set_src(ready_page.imgbtn_sculpture, LV_IMGBTN_STATE_RELEASED, &Sculpture, NULL, NULL);
	lv_imgbtn_set_src(ready_page.imgbtn_sculpture, LV_IMGBTN_STATE_PRESSED, &png_file_pre, NULL, NULL);
	lv_obj_add_event_cb(ready_page.imgbtn_sculpture, event_handler, LV_EVENT_ALL, NULL);
	lv_obj_set_pos(ready_page.imgbtn_sculpture, 250, 10);
	lv_obj_set_size(ready_page.imgbtn_sculpture, 60, 60);

	ready_page.imgbtn_tool = lv_imgbtn_create(lv_ui.src1);
	lv_imgbtn_set_src(ready_page.imgbtn_tool, LV_IMGBTN_STATE_RELEASED, &Tool, NULL, NULL);
	lv_imgbtn_set_src(ready_page.imgbtn_tool, LV_IMGBTN_STATE_PRESSED, &png_tool_pre, NULL, NULL);
	lv_obj_set_pos(ready_page.imgbtn_tool, 350, 10);
	lv_obj_set_size(ready_page.imgbtn_tool, 60, 60);

	lv_obj_add_style(ready_page.imgbtn_adj, &ready_page.imgbtn_style, LV_STATE_DEFAULT);
	lv_obj_add_style(ready_page.imgbtn_adj, &ready_page.imgbtn_style, LV_STATE_PRESSED);

	lv_obj_add_style(ready_page.imgbtn_ctrl, &ready_page.imgbtn_style, LV_STATE_DEFAULT);
	lv_obj_add_style(ready_page.imgbtn_ctrl, &ready_page.imgbtn_style, LV_STATE_PRESSED);

	lv_obj_add_style(ready_page.imgbtn_sculpture, &ready_page.imgbtn_style, LV_STATE_DEFAULT);
	lv_obj_add_style(ready_page.imgbtn_sculpture, &ready_page.imgbtn_style, LV_STATE_PRESSED);

	lv_obj_add_style(ready_page.imgbtn_tool, &ready_page.imgbtn_style, LV_STATE_DEFAULT);
	lv_obj_add_style(ready_page.imgbtn_tool, &ready_page.imgbtn_style, LV_STATE_PRESSED);

	ready_page.label_adj = lv_label_create(lv_ui.src1);
	ready_page.label_ctrl = lv_label_create(lv_ui.src1);
	ready_page.label_sculpture = lv_label_create(lv_ui.src1);
	ready_page.label_tool = lv_label_create(lv_ui.src1);

	lv_label_set_text(ready_page.label_adj, "Adjustment");
	lv_label_set_text(ready_page.label_ctrl, "Control");
	lv_label_set_text(ready_page.label_sculpture, "Sculpture");
	lv_label_set_text(ready_page.label_tool, "Tool");

	lv_obj_align_to(ready_page.label_adj, ready_page.imgbtn_adj, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
	lv_obj_align_to(ready_page.label_ctrl, ready_page.imgbtn_ctrl, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
	lv_obj_align_to(ready_page.label_sculpture, ready_page.imgbtn_sculpture, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
	lv_obj_align_to(ready_page.label_tool, ready_page.imgbtn_tool, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

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
	lv_timer_del(ready_page.ready_page_upadte);		// 清除计数器
	lv_obj_clean(lv_ui.main_src);					// 清空主页的部件
}