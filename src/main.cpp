#include "main.h"

extern uint32_t g_ticks_per_us_pro;  // For CPU 0 - typically 240 MHz
extern uint32_t g_ticks_per_us_app;  // For CPU 1 - typically 240 MHz

inline int32_t IRAM_ATTR getCpuTicks() {
    return XTHAL_GET_CCOUNT();
}

inline int32_t IRAM_ATTR usToCpuTicks(int32_t us) {
    return us * g_ticks_per_us_pro;
}

inline void IRAM_ATTR spinUntil(int32_t endTicks) {
    while ((getCpuTicks() - endTicks) < 0) {
#ifdef ESP32
    asm volatile("nop");
#endif
    }
}

inline int32_t IRAM_ATTR usToEndTicks(int32_t us) {
    return getCpuTicks() + usToCpuTicks(us);
}

void IRAM_ATTR delay_us(int32_t us) {
    spinUntil(usToEndTicks(us));
}

void delay_ms(uint16_t ms) {
    vTaskDelay(ms / portTICK_PERIOD_MS);
}

const int I2S_OUT_PIN_BASE = 128;
#define I2SO(n)                     (I2S_OUT_PIN_BASE + n)
#define BEEPER					    I2SO(7)

void IRAM_ATTR i2s_digitalWrite(uint8_t pin, uint8_t val) {

    i2s_out_write(pin - I2S_OUT_PIN_BASE, val);
}

void setup() {

    client_init();

    i2s_out_init();

    sd_fs_init();
}

void loop() {
    // i2s_digitalWrite(BEEPER, LOW);
    delay(500);
    // i2s_digitalWrite(BEEPER, HIGH);
    delay(500);
}