#pragma once

#define USE_I2S_OUT
#define USE_I2S_STEPS
#define DEFAULT_STEPPER             ST_I2S_STATIC
#define I2S_OUT_NUM_BITS            32

#ifdef N_AXIS
    #undef N_AXIS
#endif
#define N_AXIS 3

// Enable SDCard
// #ifdef ENABLE_SD_CARD
//     #undef ENABLE_SD_CARD
// #endif