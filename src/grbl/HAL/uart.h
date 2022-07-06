#ifndef __uart_h
#define __uart_h

#include "../../main.h"


// esp32 driver file
#include <driver/uart.h>

class ESP_UART {

private:
    uart_port_t     _uart_num;
    int             _pushback; 


public:

// default size
    int             _esp_tx_buff    = 512;
    int             _esp_rx_buff    = 0; 
    int             _queue_size     = 0;

    // 数据长度
    enum class DATA : int {
        Bits5 = UART_DATA_5_BITS,
        Bits6 = UART_DATA_6_BITS,
        Bits7 = UART_DATA_7_BITS,
        Bits8 = UART_DATA_8_BITS,
    };

    // 停止位
    enum class STOP : int {
        Bits1   = UART_STOP_BITS_1,
        Bits1_5 = UART_STOP_BITS_1_5,
        Bits2   = UART_STOP_BITS_2,
    };

    // 校验位
    enum class PARITY : int {
        None = UART_PARITY_DISABLE,
        Even = UART_PARITY_EVEN,
        Odd  = UART_PARITY_ODD,
    };  

// Func 
    ESP_UART(int uart_port);        // 声明创建类型    
    void begin(int baud, DATA dataBits, STOP stopBits, PARITY parity);
    int available();
    int read(void);               
    int read(TickType_t timeout);

    size_t write(uint8_t c);
    size_t write(const uint8_t *buff, size_t len);
    size_t write(const char *text);

    bool set_pins(int tx_pin, int rx_pin, int rts_pin=-1, int cts_pin=-1);        // 初始化UART的GPIO
};

extern ESP_UART UART0;

#endif