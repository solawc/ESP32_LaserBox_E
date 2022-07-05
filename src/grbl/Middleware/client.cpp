#include "client.h"


void client_init() {

    // 初始化串口配置
    UART0.set_pins(1, 3);  // Tx 1, Rx 3 - standard hardware pins
    UART0.begin(115200, ESP_UART::DATA::Bits8, ESP_UART::STOP::Bits1, ESP_UART::PARITY::None);
    UART0.write("I2S Test begin\n");

}


void client_write(const char *text) {

    UART0.write(text);
}










