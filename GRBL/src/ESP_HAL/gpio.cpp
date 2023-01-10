#include "gpio.h"
#include <driver/gpio.h>

/************************************************
 * 注:
 * 当前文件是对ESP32 GPIO的控制做二次封装，抛弃原
 * 先Arduino的接口，提升可以很好提升GPIO的执行效率
 ************************************************/

void hal_gpio_write(uint8_t pin, bool val) {
    gpio_set_level((gpio_num_t)pin, val);
}

bool hal_gpio_read(uint8_t pin) {
    return gpio_get_level((gpio_num_t)pin);
}

void hal_gpio_set_interrupt_type (uint8_t pin, gpio_int_type_t type) {

    gpio_set_intr_type((gpio_num_t)pin, type);
}

void hal_gpio_add_interrupt(uint8_t pin, gpio_int_type_t type, void (*callback)(void*), void* arg) {


}