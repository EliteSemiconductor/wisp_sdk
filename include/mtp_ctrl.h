 /****************************************************************************
 * @file     mtpctl.h
 * @version  V2025.03.19.13.31.06
 * @brief    TONKINESE series MTPCTL driver and register definition header file
 *
 * @copyright (C) COPYRIGHT 2025 ESMT Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __MTPCTL_H__
#define __MTPCTL_H__

#include "tonki_soc.h"

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**   @addtogroup REGISTER Control Register
  @{
*/

/**
  @addtogroup {REPLACEMENT} Controller({REPLACEMENT}) Memory Mapped
  Structure for {REPLACEMENT} Controller
  @{
*/
typedef struct {
  __IO uint8_t  MTPCTL_CMD;
  __IO uint8_t  MTPCTL_ADR;
  __IO uint8_t  MTPCTL_DAT;
  __IO uint8_t  MTPCTL_DAT1;
  __IO uint8_t  MTPCTL_DAT2;
  __IO uint8_t  MTPCTL_DAT3;
  __IO uint8_t  MTPCTL_DAT4;
  __IO uint8_t  MTPCTL_DAT5;
  __IO uint8_t  MTPCTL_DAT6;
  __IO uint8_t  MTPCTL_DAT7;
  __IO uint8_t  MTPCTL_DAT8;
  __IO uint8_t  MTPCTL_DAT9;
  __IO uint8_t  MTPCTL_DAT10;
  __IO uint8_t  MTPCTL_DAT11;
  __IO uint8_t  MTPCTL_DAT12;
  __IO uint8_t  MTPCTL_DAT13;
  __IO uint8_t  MTPCTL_DAT14;
  __IO uint8_t  MTPCTL_DAT15;
 __I  uint8_t  RESERVED1 [14];
  union {
    __IO uint8_t  MTPCTL_INT_ST;
    struct {
      __IO uint8_t  INT_ST_COMPL :  1;
      __IO uint8_t  INT_ST_CMDERR:  1;
    } MTPCTL_INT_ST_b;
  };
  union {
    __IO uint8_t  MTPCTL_INT_EN;
    struct {
      __IO uint8_t  INT_EN_COMPL :  1;
      __IO uint8_t  INT_EN_CMDERR:  1;
    } MTPCTL_INT_EN_b;
  };
  union {
    __I  uint8_t  MTPCTL_INT;
    struct {
      __I  uint8_t  INT_COMPL :  1;
      __I  uint8_t  INT_CMDERR:  1;
    } MTPCTL_INT_b;
  };
  __I  uint8_t  RESERVED2 [973];
  __I  uint8_t  PERIPH_ID_LEN;
  __I  uint8_t  PERIPH_ID0;
  __I  uint8_t  PERIPH_ID1;
  __I  uint8_t  PERIPH_ID2;
  __I  uint8_t  PERIPH_ID3;
  __I  uint8_t  PERIPH_ID4;
  __I  uint8_t  PERIPH_ID5;

} MTPCTL_T;
/**@}*/ /* end of MTPCTL register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#ifdef __cplusplus
extern "C"
{
#endif

// define actual xdata variable for CSR
volatile __xdata MTPCTL_T __at (MTPCTL_BASE) MTPCTL_CSR;

#define MTPCTL              ((__xdata MTPCTL_T *) &MTPCTL_CSR         )


/**   @addtogroup Standard_Driver Standard Driver
  @{
*/

/**   @addtogroup MTPCTL_Driver MTPCTL Driver
  @{
*/

/**   @addtogroup MTPCTL_EXPORTED_CONSTANTS MTPCTL Exported Constants
  @{
*/


/**@}*/ /* end of group MTPCTL_EXPORTED_FUNCTIONS */
/**@}*/ /* end of group MTPCTL_Driver */
/**@}*/ /* end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif /* __MTPCTL_H__ */
