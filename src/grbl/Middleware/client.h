#ifndef __client_h
#define __client_h

#include "../../main.h"


#define CLIENT_SERIAL 0
#define CLIENT_BT 1
#define CLIENT_WEBUI 2
#define CLIENT_TELNET 3
#define CLIENT_INPUT 4

#define CLIENT_ALL 0xFF
#define CLIENT_COUNT 5  // total number of client types regardless if they are used








void client_init();
void client_write(uint8_t client, const char* text);
int client_read(uint8_t client);
uint8_t client_get_rx_buffer_available(uint8_t client);
void client_reset_read_buffer(uint8_t client);

#endif
