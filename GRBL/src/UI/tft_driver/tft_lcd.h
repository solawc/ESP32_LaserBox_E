#ifndef __tft_lcd_h
#define __tft_lcd_h

#include "../../main.h"

#include "TFT_eSPI.h"

class HAL_TFT_LCD {

private:

public:
    TFT_eSPI tft = TFT_eSPI();
    void tft_init(void);

    void tftBglightInit(void);
    void tftBglightSetOn(void);
    void tftBglightSetOff(void);
    void tftBglightBeginOn(void);           // 待实现背光渐变启动的功能
};

extern HAL_TFT_LCD tft_lcd;

#endif
