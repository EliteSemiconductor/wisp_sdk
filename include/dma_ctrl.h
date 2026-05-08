 /****************************************************************************
 * @file     dma_ctrl.h
 * @version  V2025.01.16.15.07.34
 * @brief    TONKINESE series DMA_CTRL driver and register definition header file
 *
 * @copyright (C) COPYRIGHT 2025 ESMT Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __DMA_CTRL_H__
#define __DMA_CTRL_H__

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
  __IO uint8_t  CH0_SWRST;
  __I  uint8_t  RESERVED_0_1 [3];
  union {
    __IO uint8_t  CH0_CONFIG_REG_0;
    struct {
      __IO uint8_t  CH0_EN  :  1;
      __IO uint8_t  CH0_M2M :  1;
    } CH0_CONFIG_REG_0_b;
  };
  union {
    __IO uint8_t  CH0_CONFIG_REG_1;
    struct {
      __IO uint8_t  CH0_M2M_SRC_TYP :  2;
      __IO uint8_t  CH0_M2M_DEST_TYP:  2;
    } CH0_CONFIG_REG_1_b;
  };
  __I  uint8_t  RESERVED_0_2;
  __IO uint8_t  CH0_PERI_REQ_IDX;
  __IO uint8_t  CH0_BUF_EN_A;
  __I  uint8_t  RESERVED_0_3[7];
  __IO uint8_t  CH0_BUF_BYTE_SIZE_0;
  __IO uint8_t  CH0_BUF_BYTE_SIZE_1;
  __I  uint8_t  RESERVED_0_4;
  union {
    __IO uint8_t  CH0_BUF_BYTE_SIZE_REG_3;
    struct {
      __IO uint8_t                     :  7;
      __IO uint8_t  CH0_BUF_END_BY_PERI:  1;
    } CH0_BUF_BYTE_SIZE_REG_3_b;
  };
  __IO uint8_t  CH0_M2M_SRC_ADDR_0;
  __IO uint8_t  CH0_M2M_SRC_ADDR_1;
  __I  uint8_t  RESERVED_0_5[2];
  __IO uint8_t  CH0_M2M_DEST_ADDR_0;
  __IO uint8_t  CH0_M2M_DEST_ADDR_1;
  __I  uint8_t  RESERVED_0_6[2];
  __IO uint8_t  CH0_M2M_LEN_0;
  __IO uint8_t  CH0_M2M_LEN_1;
  __I  uint8_t  RESERVED_0_7[2];
  __I  uint8_t  CH0_CNT_A_0;
  __I  uint8_t  CH0_CNT_A_1;
  __I  uint8_t  RESERVED_0_8[6];
  __O  uint8_t  W1T_CH0_M2M_TRIG;
  union {
    __IO uint8_t   CH0_TRIG_REG_1;
    struct {
      __IO uint8_t   CH0_M2M_EXT_RUN:  1;
      __IO uint8_t                  :  3;
      __IO uint8_t   CH0_M2M_EXT_SRC:  4;
    } CH0_TRIG_REG_1_b;
  };
  __I  uint8_t  RESERVED_0_9[6];
  __IO uint8_t  CH0_BUF_BASE_ADDR_A_0;
  __IO uint8_t  CH0_BUF_BASE_ADDR_A_1;
  __I  uint8_t  RESERVED_0_10[14];

  __IO uint8_t  CH1_SWRST;
  __I  uint8_t  RESERVED_1_1 [3];
  union {
    __IO uint8_t  CH1_CONFIG_REG_0;
    struct {
      __IO uint8_t  CH1_EN  :  1;
      __IO uint8_t  CH1_M2M :  1;
    } CH1_CONFIG_REG_0_b;
  };
  union {
    __IO uint8_t  CH1_CONFIG_REG_1;
    struct {
      __IO uint8_t  CH1_M2M_SRC_TYP :  2;
      __IO uint8_t  CH1_M2M_DEST_TYP:  2;
    } CH1_CONFIG_REG_1_b;
  };
  __I  uint8_t  RESERVED_1_2;
  __IO uint8_t  CH1_PERI_REQ_IDX;
  __IO uint8_t  CH1_BUF_EN_A;
  __I  uint8_t  RESERVED_1_3[7];
  __IO uint8_t  CH1_BUF_BYTE_SIZE_0;
  __IO uint8_t  CH1_BUF_BYTE_SIZE_1;
  __I  uint8_t  RESERVED_1_4;
  union {
    __IO uint8_t  CH1_BUF_BYTE_SIZE_REG_3;
    struct {
      __IO uint8_t                     :  7;
      __IO uint8_t  CH1_BUF_END_BY_PERI:  1;
    } CH1_BUF_BYTE_SIZE_REG_3_b;
  };
  __IO uint8_t  CH1_M2M_SRC_ADDR_0;
  __IO uint8_t  CH1_M2M_SRC_ADDR_1;
  __I  uint8_t  RESERVED_1_5[2];
  __IO uint8_t  CH1_M2M_DEST_ADDR_0;
  __IO uint8_t  CH1_M2M_DEST_ADDR_1;
  __I  uint8_t  RESERVED_1_6[2];
  __IO uint8_t  CH1_M2M_LEN_0;
  __IO uint8_t  CH1_M2M_LEN_1;
  __I  uint8_t  RESERVED_1_7[2];
  __I  uint8_t  CH1_CNT_A_0;
  __I  uint8_t  CH1_CNT_A_1;
  __I  uint8_t  RESERVED_1_8[6];
  __O  uint8_t  W1T_CH1_M2M_TRIG;
  union {
    __IO uint8_t   CH1_TRIG_REG_1;
    struct {
      __IO uint8_t   CH1_M2M_EXT_RUN:  1;
      __IO uint8_t                  :  3;
      __IO uint8_t   CH1_M2M_EXT_SRC:  4;
    } CH1_TRIG_REG_1_b;
  };
  __I  uint8_t  RESERVED_1_9[6];
  __IO uint8_t  CH1_BUF_BASE_ADDR_A_0;
  __IO uint8_t  CH1_BUF_BASE_ADDR_A_1;
  __I  uint8_t  RESERVED_1_10[14];

  __I  uint8_t  RESERVED10[384];

  union {
    __IO uint8_t  INT_ST_CH_CMPLT_A_REG;
    struct {
      __IO uint8_t  INT_ST_CH0_CMPLT_A:  1;
      __IO uint8_t  INT_ST_CH1_CMPLT_A:  1;
    } INT_ST_CH_CMPLT_A_REG_b;
  };
  __I  uint8_t  RESERVED11[7];

  union {
    __IO uint8_t  INT_ST_CH_ERR_EX_SIZE_A_REG;
    struct {
      __IO uint8_t  INT_ST_CH0_ERR_EX_SIZE_A:  1;
      __IO uint8_t  INT_ST_CH1_ERR_EX_SIZE_A:  1;
    } INT_ST_CH_ERR_EX_SIZE_A_REG_b;
  };
  __I  uint8_t  RESERVED12[7];

  union {
    __IO uint8_t  INT_ST_CH_ERR_OVRN_A_REG;
    struct {
      __IO uint8_t  INT_ST_CH0_ERR_OVRN_A:  1;
      __IO uint8_t  INT_ST_CH1_ERR_OVRN_A:  1;
    } INT_ST_CH_ERR_OVRN_A_REG_b;
  };
  __I  uint8_t  RESERVED13[7];

  union {
    __IO uint8_t  INT_ST_CH_M2M_CMPLT_REG;
    struct {
      __IO uint8_t  INT_ST_CH0_M2M_CMPLT:  1;
      __IO uint8_t  INT_ST_CH1_M2M_CMPLT:  1;
    } INT_ST_CH_M2M_CMPLT_REG_b;
  };
  __I  uint8_t  RESERVED14[39];

  union {
    __IO uint8_t  INT_EN_CH_CMPLT_A_REG;
    struct {
      __IO uint8_t  INT_EN_CH0_CMPLT_A:  1;
      __IO uint8_t  INT_EN_CH1_CMPLT_A:  1;
    } INT_EN_CH_CMPLT_A_REG_b;
  };
  __I  uint8_t  RESERVED15[7];

  union {
    __IO uint8_t  INT_EN_CH_ERR_EX_SIZE_A_REG;
    struct {
      __IO uint8_t  INT_EN_CH0_ERR_EX_SIZE_A:  1;
      __IO uint8_t  INT_EN_CH1_ERR_EX_SIZE_A:  1;
    } INT_EN_CH_ERR_EX_SIZE_A_REG_b;
  };
  __I  uint8_t  RESERVED16[7];

  union {
    __IO uint8_t  INT_EN_CH_ERR_OVRN_A_REG;
    struct {
      __IO uint8_t  INT_EN_CH0_ERR_OVRN_A:  1;
      __IO uint8_t  INT_EN_CH1_ERR_OVRN_A:  1;
    } INT_EN_CH_ERR_OVRN_A_REG_b;
  };
  __I  uint8_t  RESERVED17[7];

  union {
    __IO uint8_t  INT_EN_CH_M2M_CMPLT_REG;
    struct {
      __IO uint8_t  INT_EN_CH0_M2M_CMPLT:  1;
      __IO uint8_t  INT_EN_CH1_M2M_CMPLT:  1;
    } INT_EN_CH_M2M_CMPLT_REG_b;
  };
  __I  uint8_t  RESERVED18[39];

  union {
    __I  uint8_t  MASKED_INT_ST_CH_CMPLT_A_REG;
    struct {
      __I  uint8_t  INT_CH0_CMPLT_A:  1;
      __I  uint8_t  INT_CH1_CMPLT_A:  1;
    } MASKED_INT_ST_CH_CMPLT_A_REG_b;
  };
  __I  uint8_t  RESERVED19[7];

  union {
    __I  uint8_t  MASKED_INT_ST_CH_ERR_EX_SIZE_A_REG;
    struct {
      __I  uint8_t  INT_CH0_ERR_EX_SIZE_A:  1;
      __I  uint8_t  INT_CH1_ERR_EX_SIZE_A:  1;
    } MASKED_INT_ST_CH_ERR_EX_SIZE_A_REG_b;
  };
  __I  uint8_t  RESERVED20[7];

  union {
    __I  uint8_t  MASKED_INT_ST_CH_ERR_OVRN_A_REG;
    struct {
      __I  uint8_t  INT_CH0_ERR_OVRN_A:  1;
      __I  uint8_t  INT_CH1_ERR_OVRN_A:  1;
    } MASKED_INT_ST_CH_ERR_OVRN_A_REG_b;
  };
  __I  uint8_t  RESERVED21[7];

  union {
    __I  uint8_t  MASKED_INT_ST_CH_M2M_CMPLT_REG;
    struct {
      __I  uint8_t  INT_CH0_M2M_CMPLT:  1;
      __I  uint8_t  INT_CH1_M2M_CMPLT:  1;
    } MASKED_INT_ST_CH_M2M_CMPLT_REG_b;
  };
  __I  uint8_t  RESERVED22[327];

  __I  uint8_t  PERIPH_ID_LEN;
  __I  uint8_t  RESERVED23[15];
  __I  uint8_t  PERIPH_ID_0_0;
  __I  uint8_t  PERIPH_ID_0_1;
  __I  uint8_t  PERIPH_ID_0_2;
  __I  uint8_t  PERIPH_ID_0_3;
  __I  uint8_t  PERIPH_ID_1_0;
  __I  uint8_t  PERIPH_ID_1_1;
  __I  uint8_t  PERIPH_ID_1_2;
  __I  uint8_t  PERIPH_ID_1_3;

} DMA_CTRL_T;
/**@}*/ /* end of DMA_CTRL register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#ifdef __cplusplus
extern "C"
{
#endif


// define actual xdata variable for CSR
volatile __xdata DMA_CTRL_T __at (DMA_CTRL_BASE) DMA_CTRL_CSR;

#define DMA_CTRL                  ((__xdata DMA_CTRL_T *) &DMA_CTRL_CSR          )


// interrupts 
#define     Pos_INT_ST_CH0_CMPLT_A          0
#define     Pos_INT_ST_CH0_ERR_EX_SIZE_A    0
#define     Pos_INT_ST_CH0_ERR_OVRN_A       0
#define     Pos_INT_ST_CH0_M2M_CMPLT        0

#define     Pos_INT_ST_CH1_CMPLT_A          1
#define     Pos_INT_ST_CH1_ERR_EX_SIZE_A    1
#define     Pos_INT_ST_CH1_ERR_OVRN_A       1
#define     Pos_INT_ST_CH1_M2M_CMPLT        1

#define     Msk_INT_ST_CH0_CMPLT_A          ( 0x01 << Pos_INT_ST_CH0_CMPLT_A       ) 
#define     Msk_INT_ST_CH0_ERR_EX_SIZE_A    ( 0x01 << Pos_INT_ST_CH0_ERR_EX_SIZE_A ) 
#define     Msk_INT_ST_CH0_ERR_OVRN_A       ( 0x01 << Pos_INT_ST_CH0_ERR_OVRN_A    ) 
#define     Msk_INT_ST_CH0_M2M_CMPLT        ( 0x01 << Pos_INT_ST_CH0_M2M_CMPLT     ) 

#define     Msk_INT_ST_CH1_CMPLT_A          ( 0x01 << Pos_INT_ST_CH1_CMPLT_A       ) 
#define     Msk_INT_ST_CH1_ERR_EX_SIZE_A    ( 0x01 << Pos_INT_ST_CH1_ERR_EX_SIZE_A ) 
#define     Msk_INT_ST_CH1_ERR_OVRN_A       ( 0x01 << Pos_INT_ST_CH1_ERR_OVRN_A    ) 
#define     Msk_INT_ST_CH1_M2M_CMPLT        ( 0x01 << Pos_INT_ST_CH1_M2M_CMPLT     ) 


#define     Def_DMA_CH_M2M_TYP_INC             0
#define     Def_DMA_CH_M2M_TYP_FIXED           2


//- M2M external DMA
#define     Pos_DMA_CH_M2M_EXT_RUN          0
#define     Pos_DMA_CH_M2M_EXT_SRC          4

#define     Msk_DMA_CH_M2M_EXT_RUN          ( 0x01 << Pos_DMA_CH_M2M_EXT_RUN )
#define     Msk_DMA_CH_M2M_EXT_SRC          ( 0x0F << Pos_DMA_CH_M2M_EXT_SRC )


#define     Def_DMA_CH_M2M_EXT_SRC_OTP         0x0D


/**@}*/ /* end of group DMA_CTRL_EXPORTED_FUNCTIONS */
/**@}*/ /* end of group DMA_CTRL_Driver */
/**@}*/ /* end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif /* __DMA_CTRL_H__ */
