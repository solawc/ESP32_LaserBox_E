#include "tft_lcd.h"
#include "../lv_port/lv_port_init.h"

void IRAM_ATTR disp_flush_callback(spi_transaction_t *spi_tx) {
    ui.lvPortDispCallback();
}

void HAL_TFT_LCD::tft_init(void) {
    tft.begin();
    tft.setRotation(1);
    tft.initDMA(false, disp_flush_callback);
}

void HAL_TFT_LCD::tftBglightInit(void) {
#ifdef LCD_EN
    pinMode(LCD_EN, OUTPUT);
#endif
    tft.fillScreen(TFT_BLACK);
}

void HAL_TFT_LCD::tftBglightSetOn(void) {
#ifdef LCD_EN
    digitalWrite(LCD_EN, LOW);
#endif
}

void HAL_TFT_LCD::tftBglightSetOff(void) {
#ifdef LCD_EN
    digitalWrite(LCD_EN, HIGH);
#endif
}

void HAL_TFT_LCD::tftBglightBeginOn(void) {
    // TODO...(让屏幕渐变启动)
}

HAL_TFT_LCD tft_lcd;
