#include "uart.h"

ESP_UART::ESP_UART(int uart_port) : _uart_num(uart_port_t(uart_port)), _pushback(-1) {}


void ESP_UART::begin(int baud, DATA dataBits, STOP stopBits, PARITY parity) {

    uart_config_t conf = {

        .baud_rate = (int)baud,
        .data_bits = uart_word_length_t(dataBits),
        .parity = uart_parity_t(parity),
        .stop_bits = uart_stop_bits_t(stopBits),
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .rx_flow_ctrl_thresh = 0,
        .use_ref_tick = false
    };

    if(uart_param_config(_uart_num, &conf) != ESP_OK) {
        return ;
    };
    
    /***********************************************************************************
     * 注：这里使用uart+queue的方式，因此消息队列的位置使用NULL传入， 并且对列大小为0，串口
     * 的使用也不需要中断，因此最后一个参数输入为0
     * ********************************************************************************/
    uart_driver_install(_uart_num, _esp_tx_buff, _esp_rx_buff, _queue_size, NULL, 0);
}

int ESP_UART::available() {
    size_t size = 0;
    uart_get_buffered_data_len(_uart_num, &size);
    return size;
}

int ESP_UART::read(TickType_t timeout) {
    uint8_t c;
    int     res = uart_read_bytes(_uart_num, &c, 1, timeout);
    return res != 1 ? -1 : c;
}

int ESP_UART::read(void) {
    return read(0);
}

size_t ESP_UART::write(uint8_t c) {
    return uart_write_bytes(_uart_num, (char *)&c, 1);
}

size_t ESP_UART::write(const uint8_t *buff, size_t len) {
    return uart_write_bytes(_uart_num, (const char *)buff, len);
}

size_t ESP_UART::write(const char *text) {
    return uart_write_bytes(_uart_num, text, strlen(text));
}

bool ESP_UART::set_pins(int tx_pin, int rx_pin, int rts_pin, int cts_pin) {
    return (uart_set_pin(_uart_num, tx_pin, rx_pin, rts_pin, cts_pin) != ESP_OK);
}













ESP_UART UART0(0);