#include "tim.h"

#include <driver/timer.h>

#define STEPPER_FREQ                        F_CPU / 4

const timer_group_t STEP_TIMER_GROUP        = TIMER_GROUP_0;
const timer_idx_t   STEP_TIMER_INDEX        = TIMER_0;



void IRAM_ATTR onStepperDriverTimer(void* para) {

    TIMERG0.int_clr_timers.t0 = 1;


}

void stepper_timer_init() {

    timer_config_t tim_conf;

    tim_conf.divider     = F_CPU / (F_CPU/4);
    tim_conf.counter_dir = TIMER_COUNT_UP;
    tim_conf.counter_en  = TIMER_PAUSE;
    tim_conf.alarm_en    = TIMER_ALARM_EN;
    tim_conf.intr_type   = TIMER_INTR_LEVEL;
    tim_conf.auto_reload = TIMER_AUTORELOAD_DIS;

    timer_init(STEP_TIMER_GROUP, STEP_TIMER_INDEX, &tim_conf);      // 初始化定时器配置
    timer_set_counter_value(STEP_TIMER_GROUP, STEP_TIMER_INDEX, 0x00000000ULL);     // 设置定时器计数值】
    timer_enable_intr(STEP_TIMER_GROUP, STEP_TIMER_INDEX);      // 使能定时器中断
    timer_isr_register(STEP_TIMER_GROUP, STEP_TIMER_INDEX, onStepperDriverTimer, NULL, 0, NULL);
}   