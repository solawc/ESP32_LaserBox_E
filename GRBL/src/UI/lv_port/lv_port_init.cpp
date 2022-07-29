#include "lv_port_init.h"
#include "../tft_driver/tft_lcd.h"

#include "../../../libraries/lvgl/examples/lv_examples.h"
#include "../../../libraries/lvgl/demos/lv_demos.h"

volatile bool disp_flush_enabled = true;

LVGL_UI ui;

lv_disp_drv_t *dispHandler;

void LVGL_UI::disp_enable_update(void)
{
    disp_flush_enabled = true;
}

void LVGL_UI::disp_disable_update(void)
{
    disp_flush_enabled = false;
}

static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{   
    dispHandler = disp_drv;

    if(disp_flush_enabled) {

        uint32_t w = (area->x2 - area->x1 + 1);
        uint32_t h = (area->y2 - area->y1 + 1);

        tft_lcd.tft.startWrite();
        tft_lcd.tft.setAddrWindow(area->x1, area->y1, w, h);
        

        tft_lcd.tft.pushColorsDMA(&color_p->full, w * h, true);

        // tft_lcd.tft.pushColors(&color_p->full, w * h, true);

        tft_lcd.tft.endWrite();
        // lv_disp_flush_ready(dispHandler);
    }
}

static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    uint16_t touchX=0, touchY=0;
    static uint16_t last_x = 0;
    static uint16_t last_y = 0;
    boolean touched = tft_lcd.tft.getTouch(&touchY, &touchX);

    if(touchX > 480) { touchX = 480; }
    if(touchY > 320) { touchY = 320; }

    touchX = 480 - touchX;
    touchY = 320 - touchY;
    
    if( touched != false ) {
        last_x = touchX;
        last_y = touchY;
        data->point.x = last_x;
        data->point.y = last_y;
        data->state = LV_INDEV_STATE_PR;
    }
    else {
        data->point.x = last_x;
        data->point.y = last_y;
        data->state = LV_INDEV_STATE_REL;
    }
}

void LVGL_UI::lv_port_disp_callback(void) {

    lv_disp_flush_ready(dispHandler);
}

#define LV_BUFF_SIZE        LCD_SIZE_HOR_RES * 10

void LVGL_UI::lv_port_disp_init(void) {

    // Use example 1
    static lv_disp_draw_buf_t draw_buf_dsc_1;
    static lv_color_t buf_1[LV_BUFF_SIZE];                          /*A buffer for 10 rows*/
    lv_disp_draw_buf_init(&draw_buf_dsc_1, buf_1, NULL, LV_BUFF_SIZE);   /*Initialize the display buffer*/

    static lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    disp_drv.hor_res = LCD_SIZE_HOR_RES;
    disp_drv.ver_res = LCD_SIZE_VER_RES;
    disp_drv.flush_cb = disp_flush;
    disp_drv.draw_buf = &draw_buf_dsc_1;
    // disp_drv.full_refresh = 1;               // 如果屏幕区域不是整屏，不能打开这个
    lv_disp_drv_register(&disp_drv);            // 回调注册
}



void LVGL_UI::lv_port_touch_init(void) {

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    indev_touchpad = lv_indev_drv_register(&indev_drv);
}


static void * my_fs_open(struct _lv_fs_drv_t * drv, const char * path, lv_fs_mode_t mode) {

    
}


void lv_port_fs_init() {

    static lv_fs_drv_t drv;          
    lv_fs_drv_init(&drv);

    drv.letter = 'M';               // 意味着是my_fs      
    drv.open_cb = my_fs_open;

}

void LVGL_UI::lvglMutexInit(void) {
    lvglMutex = xSemaphoreCreateMutex();
}

void LVGL_UI::lvglMutexLock(void) {
    xSemaphoreTake(lvglMutex, portMAX_DELAY);
}

void LVGL_UI::lvglMutexUnlock(void) {

    xSemaphoreGive(lvglMutex);
}

void lvglTask(void *parg)  {

    ui.lvglMutexInit();

    lv_init();

    tft_lcd.tft_init();             // 这个地方如果使用的TFT_eSPI， 用TS35/TS24 则已经包含触摸初始化

    ui.lv_port_disp_init();
    ui.lv_port_touch_init();

#if LV_USE_DEMO_STRESS
    lv_demo_stress();
#else 
    // lvDrawLogo();
#endif

    lvDrawLogo();

    tft_lcd.tftBglightSetOn();

    while(1) {
        ui.lvglMutexLock();
        lv_task_handler();
        ui.lvglMutexUnlock();
        vTaskDelay(5);
    }
}

void LVGL_UI::lvglTaskInit(void) {

    xTaskCreatePinnedToCore(lvglTask,     // task
                            "lvglTask",         // name for task
                            DISP_TASK_STACK,    // size of task stack
                            NULL,               // parameters
                            DISP_TASK_PRO,      // priority
                            // nullptr,
                            &lv_disp_tcb,
                            DISP_TASK_CORE      // must run the task on same core // core
    );
}


lv_obj_t *src;

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

void draw_demo(void) {

    src = lv_obj_create(NULL);
    src = lv_scr_act();

    lv_obj_t * label;

    lv_obj_t * btn1 = lv_btn_create(src);
    lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    lv_obj_t * btn2 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn2, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Toggle");
    lv_obj_center(label);
}








