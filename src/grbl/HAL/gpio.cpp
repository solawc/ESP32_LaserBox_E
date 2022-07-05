#include "gpio.h"


void hal_gpio_reset() {


}



void IRAM_ATTR isr_limit_switches() {


}


void limit_gpio_init() {

// 初始化为输入引脚
    pinMode(LIMIT_X_PIN, INPUT);
    pinMode(LIMIT_Y_PIN, INPUT);
    pinMode(LIMIT_Z_PIN, INPUT);

// 设置为跳变沿，链接到isr_limit_switches， 三个公用一个中断服务函数
    attachInterrupt(LIMIT_X_PIN, isr_limit_switches, CHANGE);
    attachInterrupt(LIMIT_Y_PIN, isr_limit_switches, CHANGE);
    attachInterrupt(LIMIT_Z_PIN, isr_limit_switches, CHANGE);
}












