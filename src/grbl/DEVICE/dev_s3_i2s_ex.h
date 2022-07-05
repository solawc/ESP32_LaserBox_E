#pragma once 

#ifdef USE_ESP32_S3

#include "../../main.h"
#include <stdint.h>

#define bitnum_to_mask(n) (1 << static_cast<unsigned int>(n))

/* Assert */
#    if defined(I2S_OUT_NUM_BITS)
#        if (I2S_OUT_NUM_BITS != 16) && (I2S_OUT_NUM_BITS != 32)
#            error "I2S_OUT_NUM_BITS should be 16 or 32"
#        endif
#    else
#        define I2S_OUT_NUM_BITS 32
#    endif

#    define I2SO(n) (I2S_OUT_PIN_BASE + n)

/* 16-bit mode: 1000000 usec / ((160000000 Hz) / 10 / 2) x 16 bit/pulse x 2(stereo) = 4 usec/pulse */
/* 32-bit mode: 1000000 usec / ((160000000 Hz) /  5 / 2) x 32 bit/pulse x 2(stereo) = 4 usec/pulse */
// const int I2S_OUT_USEC_PER_PULSE = 4;
const int I2S_OUT_USEC_PER_PULSE = 4;

// const int I2S_OUT_DMABUF_COUNT = 2;
const int I2S_OUT_DMABUF_COUNT = 5;    /* number of DMA buffers to store data */
const int I2S_OUT_DMABUF_LEN = 2000; /* maximum size in bytes (4092 is DMA's limit) */
// const int I2S_OUT_DMABUF_LEN = 1000;

const int I2S_OUT_DELAY_DMABUF_MS = (I2S_OUT_DMABUF_LEN / sizeof(uint32_t) * I2S_OUT_USEC_PER_PULSE / 1000);
const int I2S_OUT_DELAY_MS        = (I2S_OUT_DELAY_DMABUF_MS * (I2S_OUT_DMABUF_COUNT + 1));

typedef void (*i2s_out_pulse_func_t)(void);

enum i2s_out_pulser_status_t {
    PASSTHROUGH = 0,  // Static I2S mode.The i2s_out_write() reflected with very little delay
    STEPPING,         // Streaming step data.
    WAITING,          // Waiting for the step DMA completion
};

typedef struct {
    /*
        I2S bitstream (32-bits): Transfers from MSB(bit31) to LSB(bit0) in sequence
        ------------------time line------------------------>
             Left Channel                    Right Channel
        ws   ________________________________~~~~...
        bck  _~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~_~...
        data vutsrqponmlkjihgfedcba9876543210
             XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
                                             ^
                                Latches the X bits when ws is switched to High
        If I2S_OUT_PIN_BASE is set to 128,
        bit0:Expanded GPIO 128, 1: Expanded GPIO 129, ..., v: Expanded GPIO 159
    */
    uint8_t ws_pin;
    uint8_t bck_pin;
    uint8_t data_pin;
    uint32_t pulse_period;  // aka step rate.
    uint32_t init_val;
} i2s_out_init_t;

#endif