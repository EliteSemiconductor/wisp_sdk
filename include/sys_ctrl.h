 /****************************************************************************
 * @file     sys_ctrl.h
 * @version  V2025.01.23.13.47.14
 * @brief    TONKINESE series SYS_CTRL driver and register definition header file
 *
 * @copyright (C) COPYRIGHT 2025 ESMT Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __SYS_CTRL_H__
#define __SYS_CTRL_H__

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
    __I  uint8_t  INT_ST_EX0_REG;
    struct {
      __I  uint8_t  INT_ST_WDT:  1;
    } INT_ST_EX0_REG_b;
  };
  union {
    __I  uint8_t  INT_ST_EX1_REG;
    struct {
      __I  uint8_t  INT_ST_DMA     :  1;
      __I  uint8_t  INT_ST_MAC     :  1;
      __I  uint8_t  INT_ST_AES     :  1;
      __I  uint8_t  INT_ST_GPIO    :  1;
      __I  uint8_t  INT_ST_ASARADC :  1;
      __I  uint8_t  INT_ST_TRNG    :  1;
      __I  uint8_t  INT_ST_OTP     :  1;
      __I  uint8_t  INT_ST_MTP     :  1;
    } INT_ST_EX1_REG_b;
  };
  __I  uint8_t  RESERVED0[14];
  union {
    __I  uint8_t  STRAPPING_REG;
    struct {
      __I  uint8_t  STRAP_BT_0  :  1;
      __I  uint8_t  STRAP_BT_1  :  1;
      __I  uint8_t  STRAP_BT_2  :  1;
      __I  uint8_t  STRAP_BT_3  :  1;
      __I  uint8_t  STRAP_GPIO_4:  1;
      __I  uint8_t  STRAP_GPIO_5:  1;
    } STRAPPING_REG_b;
  };
  __I  uint8_t  RESERVED1[239];
  __I  uint8_t  PRODUCT_ID0;
  __I  uint8_t  PRODUCT_ID1;
  __I  uint8_t  RESERVED2[2];
  __I  uint8_t  REVISION_ID;
  __I  uint8_t  RESERVED3[251];
  __IO uint8_t  ECO_RESERVED0;
  __IO uint8_t  ECO_RESERVED1;
  __I  uint8_t  RESERVED4[2];
  union {
    __IO  uint8_t  SYS_CFG_REG;
    struct {
      __IO uint8_t  XDATA_CODE_EN  :  1;
      __IO uint8_t  XDATA_PRAM_EN  :  1;
      __IO uint8_t  CPU_LCK_EN     :  1;
    } SYS_CFG_REG_b;
  };
  __I  uint8_t  RESERVED5[475];
  __I  uint8_t  PERIPH_ID_LEN;
  __I  uint8_t  RESERVED6[15];
  __I  uint8_t  PERIPH_ID_0_0;
  __I  uint8_t  PERIPH_ID_0_1;
  __I  uint8_t  PERIPH_ID_0_2;
  __I  uint8_t  PERIPH_ID_0_3;
  __I  uint8_t  PERIPH_ID_1_0;
  __I  uint8_t  PERIPH_ID_1_1;
  __I  uint8_t  PERIPH_ID_1_2;
  __I  uint8_t  PERIPH_ID_1_3;

} SYS_CTRL_T;
/**@}*/ /* end of SYS_CTRL register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#ifdef __cplusplus
extern "C"
{
#endif


// define actual xdata variable for CSR
volatile __xdata SYS_CTRL_T __at (SYS_CTRL_BASE) SYS_CTRL_CSR;

#define SYS_CTRL                  ((__xdata SYS_CTRL_T *) &SYS_CTRL_CSR          )


#define     Pos_INT_ST_EX0_WDT              0 

#define     Pos_INT_ST_EX1_DMA              0 
#define     Pos_INT_ST_EX1_MAC              1
#define     Pos_INT_ST_EX1_AES              2 
#define     Pos_INT_ST_EX1_GPIO             3
#define     Pos_INT_ST_EX1_ASARADC          4
#define     Pos_INT_ST_EX1_TRNG             5
#define     Pos_INT_ST_EX1_OTP              6
#define     Pos_INT_ST_EX1_MTP              7


#define     Msk_INT_ST_EX0_WDT              ( 0x01 << Pos_INT_ST_EX0_WDT       ) 

#define     Msk_INT_ST_EX1_DMA              ( 0x01 << Pos_INT_ST_EX1_DMA       ) 
#define     Msk_INT_ST_EX1_MAC              ( 0x01 << Pos_INT_ST_EX1_MAC       ) 
#define     Msk_INT_ST_EX1_AES              ( 0x01 << Pos_INT_ST_EX1_AES       ) 
#define     Msk_INT_ST_EX1_GPIO             ( 0x01 << Pos_INT_ST_EX1_GPIO      ) 
#define     Msk_INT_ST_EX1_ASARADC          ( 0x01 << Pos_INT_ST_EX1_ASARADC   ) 
#define     Msk_INT_ST_EX1_TRNG             ( 0x01 << Pos_INT_ST_EX1_TRNG      ) 
#define     Msk_INT_ST_EX1_OTP              ( 0x01 << Pos_INT_ST_EX1_OTP       ) 
#define     Msk_INT_ST_EX1_MTP              ( 0x01 << Pos_INT_ST_EX1_MTP       ) 


#ifdef __cplusplus
}
#endif

#endif /* __SYS_CTRL_H__ */
