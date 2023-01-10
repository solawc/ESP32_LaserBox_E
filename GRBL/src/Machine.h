#pragma once

/*
 * File list:
 * |-Machines
 *  |-common_i2s_out.h
 *   -i2c_out_corexy_mks_dlc32.h
 *   -i2c_out_xyz_mks_dlc32.h
 * |-BoardMap
 *  |-pins_LaserBox_E_V1.0.h
*/

#ifdef MB_LaserBox_E
    #include "Machines/common_i2s_out.h"
    #include "Machines/i2s_out_xyz_mks_dlc32.h"         // Setting GRBL default config.
    #include "BoardMap/pins_LaserBox_E_V1.0.h"          // Setting board pins.
#elif defined(MB_LaserBox_E_COREXY)
    #include "Machines/common_i2s_out.h"
    #include "Machines/i2s_out_xyz_mks_dlc32.h"         // Setting GRBL default config.
    #include "BoardMap/pins_LaserBox_E_V1.0.h"          // Setting board pins.
#endif


/*****************************************************************************
 *                                  For custon
 * **************************************************************************/
