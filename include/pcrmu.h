 /****************************************************************************
 * @file     pcrmu.h
 * @version  V2025.03.04.09.40.10
 * @brief    TONKINESE series PCRMU driver and register definition header file
 *
 * @copyright (C) COPYRIGHT 2025 ESMT Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __PCRMU_H__
#define __PCRMU_H__

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
  union {
    __IO uint8_t   DYN_GATED_REG;
    struct {
      __IO uint8_t   PCLKG_DYN_GATED_EN:  1;
      __IO uint8_t   MODEM_DYN_GATED_EN:  1;
      __IO uint8_t   MCU_DYN_GATED_EN  :  1;
    } DYN_GATED_REG_b;
  };
  union {
    __IO uint8_t   BLK_CLK_REG;
    struct {
      __IO uint8_t   MODEM_CLK_EN   :  1;
      __IO uint8_t   DMA_CLK_EN     :  1;
      __IO uint8_t   GPIO_INT_CLK_EN:  1;
      __IO uint8_t   SPIS_CLK_EN    :  1;
      __IO uint8_t   AES_CLK_EN     :  1;
      __IO uint8_t   TRNG_CLK_EN    :  1;
      __IO uint8_t   OTP_CLK_EN     :  1;
      __IO uint8_t   MTP_CLK_EN     :  1;
    } BLK_CLK_REG_b;
  };
  __I  uint8_t   RESERVED0_1[6];
  union {
    __IO uint8_t   RST_FLAG_REG;
    struct {
      __IO uint8_t   POR_RESET_FLAG   :  1;
      __IO uint8_t   EXTRST_RESET_FLAG:  1;
      __IO uint8_t   CHIP_RESET_FLAG  :  1;
      __IO uint8_t   WDT_RESET_FLAG   :  1;
    } RST_FLAG_REG_b;
  };
  __I  uint8_t   RESERVED0_2[8];
  union {
    __O uint8_t   CHIP_SWRST_REG;
    struct {
      __O  uint8_t   W1T_CHIP_SWRST;
    } CHIP_SWRST_REG_b;
  };
  union {
    __O uint8_t   BLK_SWRST_REG;
    struct {
      __O  uint8_t   W1T_MODEM_SWRST;
    } BLK_SWRST_REG_b;
  };
  union {
    __O uint8_t   CORE_SWRST_REG;
    struct {
      __O  uint8_t   W1T_MODEM_CORE_SWRST;
    } CORE_SWRST_REG_b;
  };
  union {
    __IO uint8_t   RST_CFG0_REG;
    struct {
      __IO uint8_t   WDT_RESET_EN      :  1;
      __IO uint8_t   WDT_RESET_CHIP_EN :  1;
      __IO uint8_t                     :  2;
      __IO uint8_t   EXTRST_DG_PERD    :  3;
      __IO uint8_t   EXTRST_DG_DIS     :  1;
    } RST_CFG0_REG_b;
  };
  __IO uint8_t   WDT_PROD_0;
  __IO uint8_t   WDT_PROD_1;
  __I  uint8_t   RESERVED1_1[25];
  __O  uint8_t   W1T_CPU_SLEP;
  __I  uint8_t   CPU_SLEP_STS;
  __I  uint8_t   RESERVED1_2[14];
  union {
    __IO uint8_t  PCRMU_INT_ST;
    struct {
      __IO uint8_t   INT_ST_RMU_WDT : 1;
    } PCRMU_INT_ST_b;
  };
  __I  uint8_t   RESERVED2[3];
  union {
    __IO uint8_t  PCRMU_INT_EN;
    struct {
      __IO uint8_t   INT_EN_RMU_WDT : 1;
    } PCRMU_INT_EN_b;
  };
  __I  uint8_t   RESERVED3[3];
  union {
    __IO uint8_t  PCRMU_INT;
    struct {
      __IO uint8_t   INT_RMU_WDT : 1;
    } PCRMU_INT_b;
  };
  __I  uint8_t   RESERVED4[903];
  __IO uint8_t   LOCK;
  __I  uint8_t   RESERVED5[15];
  __I  uint8_t   PERIPH_ID_LEN;
  __I  uint8_t   RESERVED6[15];
  __I  uint8_t   PERIPH_ID_0_0;
  __I  uint8_t   PERIPH_ID_0_1;
  __I  uint8_t   PERIPH_ID_0_2;
  __I  uint8_t   PERIPH_ID_0_3;
  __I  uint8_t   PERIPH_ID_1_0;

} PCRMU_T;
/**@}*/ /* end of PCRMU register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#ifdef __cplusplus
extern "C"
{
#endif


// define actual xdata variable for CSR
volatile __xdata PCRMU_T __at (PCRMU_BASE) PCRMU_CSR;

#define PCRMU                  ((__xdata PCRMU_T *) &PCRMU_CSR         )



#define     Pos_INT_ST_WDT                  0 

#define     Msk_INT_ST_WDT                 ( 0x01 << Pos_INT_ST_WDT       ) 



#ifdef __cplusplus
}
#endif

#endif /* __PCRMU_H__ */
