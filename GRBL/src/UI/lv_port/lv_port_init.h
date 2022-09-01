#ifndef __lv_port_init_h
#define __lv_port_init_h

#include "../../main.h"
#include "lvgl.h"

#include "../mks_ui/draw_ui.h"


#define LCD_SIZE_HOR_RES                480
#define LCD_SIZE_VER_RES                320

#define DISP_TASK_STACK                 4096*2
#define DISP_TASK_PRO                   2
#define DISP_TASK_CORE                  1


class LVGL_UI {

private:
    TaskHandle_t        lv_disp_tcb         = NULL;         /* LVGL任务句柄 */
    lv_indev_t*         indev_touchpad;                     /* 注册Touch句柄 */
    SemaphoreHandle_t   lvglMutex           = NULL;         /* LVGL互斥锁 */
public:
    void lvPortDispInit(void);
    void lvPortTouchInit(void);
    void lvPortFsInit(void);
    void lvglTaskInit(void);
    void lvPortDispCallback(void);

    void lvglMutexInit(void);
    void lvglMutexLock(void);
    void lvglMutexUnlock(void);

    void disp_enable_update(void);
    void disp_disable_update(void);
};
extern LVGL_UI ui;

void draw_demo(void);
#endif
