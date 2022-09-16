#include "lv_port_init.h"
#include "../tft_driver/tft_lcd.h"
#include "../../../libraries/lvgl/examples/lv_examples.h"
#include "../../../libraries/lvgl/demos/lv_demos.h"
#include "../../WebUI/fs_api.h"

volatile bool disp_flush_enabled = true;

LVGL_UI ui;

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
    ui.dispHandler = disp_drv;

    if(disp_flush_enabled) {

        uint32_t w = (area->x2 - area->x1 + 1);
        uint32_t h = (area->y2 - area->y1 + 1);

        tft_lcd.tft.startWrite();

        tft_lcd.tft.setAddrWindow(area->x1, area->y1, w, h);
        
        tft_lcd.tft.pushColorsDMA(&color_p->full, w * h, true);

        tft_lcd.tft.endWrite();
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

void LVGL_UI::lvPortDispCallback(void) {

    lv_disp_flush_ready(dispHandler);
}

void LVGL_UI::lvPortDispInit(void) {

    static lv_disp_draw_buf_t draw_buf_dsc_1;

    DispBuff = static_cast<lv_color_t*>(malloc(LV_BUFF_SIZE * sizeof(lv_color_t)));
    if (DispBuff == nullptr)
        LV_LOG_WARN("lv_port_disp_init malloc failed!\n");
    
    lv_disp_draw_buf_init(&draw_buf_dsc_1, DispBuff, NULL, LV_BUFF_SIZE);       /* Initialize the display buffer */

    static lv_disp_drv_t disp_drv;                                              /* Descriptor of a display driver */
    lv_disp_drv_init(&disp_drv);                                                /* Basic initialization */

    disp_drv.hor_res = LCD_SIZE_HOR_RES;
    disp_drv.ver_res = LCD_SIZE_VER_RES;
    disp_drv.flush_cb = disp_flush;
    disp_drv.draw_buf = &draw_buf_dsc_1;
    // disp_drv.full_refresh = 1;                                               /* 如果屏幕区域不是整屏，不能打开这个 */ 
    lv_disp_drv_register(&disp_drv);                                            /* 回调注册 */ 
}

void LVGL_UI::lvPortTouchInit(void) {
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    indev_touchpad = lv_indev_drv_register(&indev_drv);
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
    tft_lcd.tft_init();                               
    ui.lvPortDispInit();
    ui.lvPortTouchInit();
    ui.lvPortFsInit();

#if LV_USE_DEMO_STRESS
    lv_demo_stress();
#else 
    lvDrawLogo();
#endif

    // tft_lcd.tftBglightSetOn();

    while(1) {
        ui.lvglMutexLock();
        lv_task_handler();
        ui.lvglMutexUnlock();
        vTaskDelay(1);                  /* 这里必须大于等于5ms */
    }
}

void LVGL_UI::lvglTaskInit(void) {

    xTaskCreatePinnedToCore(lvglTask,     // task
                            "lvglTask",         // name for task
                            DISP_TASK_STACK,    // size of task stack
                            NULL,               // parameters
                            DISP_TASK_PRO,      // priority
                            &lv_disp_tcb,
                            DISP_TASK_CORE      // must run the task on same core // core
    );
}









