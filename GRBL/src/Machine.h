#pragma once

// This file is where you choose the machine type, by including
// one or more machine definition files as described below.
/*
 * 文件目录
 * |-Machines
 *           |-Custom_MC
 *                      |-dq_dlc32.h
*/


#ifdef MB_DQ_DLC32
    #include "Machines/Custom_MC/dq_dlc32.h"
#elif defined(MB_MKS_DLC32)
    #include "Machines/common_i2s_out.h"
    #include "Machines/i2s_out_xyz_mks_dlc32.h"
#elif defined(MB_MKS_DLC32_COREXY)
    #include "Machines/common_i2s_out.h"
    #include "Machines/i2s_out_xyz_mks_dlc32.h"
#endif






/*****************************************************************************
 *                                  For custon
 * **************************************************************************/


