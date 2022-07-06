#include "client.h"


void client_init() {

    // 初始化串口配置
    UART0.set_pins(1, 3);  // Tx 1, Rx 3 - standard hardware pins
    UART0.begin(115200, ESP_UART::DATA::Bits8, ESP_UART::STOP::Bits1, ESP_UART::PARITY::None);
    UART0.write("I2S Test begin\n");

}

// Returns the number of bytes available in a client buffer.
uint8_t client_get_rx_buffer_available(uint8_t client) {
#ifdef REVERT_TO_ARDUINO_SERIAL
    return 128 - Serial.available();
#else
    return 128 - UART0.available();
#endif
    //    return client_buffer[client].availableforwrite();
}



void client_write(uint8_t client, const char* text) {
if (client == CLIENT_INPUT) {
        return;
    }
#ifdef ENABLE_BLUETOOTH
    if (WebUI::SerialBT.hasClient() && (client == CLIENT_BT || client == CLIENT_ALL)) {
        WebUI::SerialBT.print(text);
        //delay(10); // possible fix for dropped characters
    }
#endif
#if defined(ENABLE_WIFI) && defined(ENABLE_HTTP) && defined(ENABLE_SERIAL2SOCKET_OUT)
    if (client == CLIENT_WEBUI || client == CLIENT_ALL) {
        WebUI::Serial2Socket.write((const uint8_t*)text, strlen(text));
    }
#endif
#if defined(ENABLE_WIFI) && defined(ENABLE_TELNET)
    if (client == CLIENT_TELNET || client == CLIENT_ALL) {
        WebUI::telnet_server.write((const uint8_t*)text, strlen(text));
    }
#endif
    // if (client == CLIENT_SERIAL || client == CLIENT_ALL || client == CLIENT_LCD) {
    if (client == CLIENT_SERIAL || client == CLIENT_ALL) {
#ifdef REVERT_TO_ARDUINO_SERIAL
        Serial.write(text);
#else
        UART0.write(text);
#endif
    }
}


// Fetches the first byte in the client read buffer. Called by protocol loop.
int client_read(uint8_t client) {
    // vTaskEnterCritical(&myMutex);
    // int data = client_buffer[client].read();
    int data = 0;
    // vTaskExitCritical(&myMutex);
    return data;
}

void client_reset_read_buffer(uint8_t client) {
    for (uint8_t client_num = 0; client_num < CLIENT_COUNT; client_num++) {
        if (client == client_num || client == CLIENT_ALL) {
            // client_buffer[client_num].begin();
        }
    }
}



