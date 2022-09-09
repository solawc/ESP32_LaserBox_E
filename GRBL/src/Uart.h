#pragma once

#include <driver/uart.h>

class Uart : public Stream {
private:
    uart_port_t _uart_num;
    int         _pushback;

public:

    // for lcd change baudrate
    enum class Baudrate : unsigned long {
        Bauderate_4800   = 4800,
        Bauderate_19200  = 19200,
        Bauderate_38400  = 38400,
        Bauderate_57600  = 57600,
        Bauderate_115200 = 115200,
        Bauderate_460800 = 460800,
        Bauderate_921600 = 921600,
    };

    enum class Data : int {
        Bits5 = UART_DATA_5_BITS,
        Bits6 = UART_DATA_6_BITS,
        Bits7 = UART_DATA_7_BITS,
        Bits8 = UART_DATA_8_BITS,
    };

    enum class Stop : int {
        Bits1   = UART_STOP_BITS_1,
        Bits1_5 = UART_STOP_BITS_1_5,
        Bits2   = UART_STOP_BITS_2,
    };

    enum class Parity : int {
        None = UART_PARITY_DISABLE,
        Even = UART_PARITY_EVEN,
        Odd  = UART_PARITY_ODD,
    };

    Uart(int uart_num);
    bool          setHalfDuplex();
    bool          setPins(int tx_pin, int rx_pin, int rts_pin = -1, int cts_pin = -1);
    void          begin(unsigned long baud, Data dataBits, Stop stopBits, Parity parity);
    int           available(void) override;
    int           read(void) override;
    int           read(TickType_t timeout);
    size_t        readBytes(char* buffer, size_t length, TickType_t timeout);
    size_t        readBytes(uint8_t* buffer, size_t length, TickType_t timeout) { return readBytes((char*)buffer, length, timeout); }
    size_t        readBytes(char* buffer, size_t length) override;
    int           peek(void) override;
    size_t        write(uint8_t data);
    size_t        write(const uint8_t* buffer, size_t length);
    inline size_t write(const char* buffer, size_t size) { return write((uint8_t*)buffer, size); }
    size_t        write(const char* text);
    void          flush() { uart_flush(_uart_num); }
    bool          flushTxTimed(TickType_t ticks);
    void          changeBuad(unsigned long baudrate);
};

extern Uart Uart0;
