#include "serial.h"

void serial_print(const char *text) {

    client_write(text);
}

void serial_printf(const char *text, const char* format, ...) {
    char    loc_buf[128];
    char*   temp = loc_buf;
    va_list arg;
    va_list copy;
    va_start(arg, format);
    va_copy(copy, arg);
    size_t len = vsnprintf(NULL, 0, format, arg);
    va_end(copy);
    if (len >= sizeof(loc_buf)) {
        temp = new char[len + 1];
        if (temp == NULL) {
            return;
        }
    }
    len = vsnprintf(temp, len + 1, format, arg);
    client_write(temp);
    va_end(arg);
    if (temp != loc_buf) {
        delete[] temp;
    }
}

