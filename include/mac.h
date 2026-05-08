 /****************************************************************************
 * @file     mac.h
 * @version  V2025.02.26.11.27.22
 * @brief    TONKINESE series MAC driver and register definition header file
 *
 * @copyright (C) COPYRIGHT 2025 ESMT Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __MAC_H__
#define __MAC_H__

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
  __I  uint8_t  RESERVED1 [32];
  union {
    __IO uint8_t  MAC_TX_TOP_B0;
    struct {
      __IO uint8_t  MAC_TXEN   :  1;
      __IO uint8_t  MAC_TXENCCA:  1;
      __IO uint8_t             :  5;
      __IO uint8_t  MAC_TXSTOP :  1;
    } MAC_TX_TOP_B0_b;
  };
  union {
    __IO uint8_t  MAC_TX_TOP_B1;
    struct {
      __IO uint8_t  MAC_TXDROPCNT:  3;
      __IO uint8_t               :  1;
      __IO uint8_t  MAC_TXW4ACK  :  1;
    } MAC_TX_TOP_B1_b;
  };
  __IO uint8_t  MAC_TXLEN0;
  __IO uint8_t  MAC_TXLEN1;
  union {
    __IO uint8_t  MAC_TX_STS;
    struct {
      __IO uint8_t  MAC_TXOK              :  1;
      __IO uint8_t  MAC_TXERR             :  1;
      __IO uint8_t  MAC_TXCHBSY           :  1;
      __IO uint8_t  MAC_TXNOACK           :  1;
      __IO uint8_t  MAC_CRC_STANDALONE_ERR:  1;
    } MAC_TX_STS_b;
  };
  __I  uint8_t  RESERVED2 [3];
  union {
    __IO uint8_t  MAC_TX_CFG_B0;
    struct {
      __IO uint8_t  MAC_TX_APPENDPRE   :  1;
      __IO uint8_t  MAC_TX_APPENDSFD   :  1;
      __IO uint8_t  MAC_TX_APPENDPHR   :  1;
      __IO uint8_t  MAC_TX_APPENDFCS   :  1;
      __IO uint8_t  MAC_TX_APPENDBLECRC:  1;
      __IO uint8_t  MAC_TX_APPENDPOST  :  1;
    } MAC_TX_CFG_B0_b;
  };
  union {
    __IO uint8_t  MAC_TX_CFG_B1;
    struct {
      __IO uint8_t  MAC_TX_CRCTYP         :  1;
      __IO uint8_t  MAC_TX_CRCPAD         :  1;
      __IO uint8_t                        :  5;
      __IO uint8_t  MAC_TX_PHR_EXCLUDE_CRC:  1;
    } MAC_TX_CFG_B1_b;
  };
  union {
    __IO uint8_t  MAC_TX_CFG_B2;
    struct {
      __IO uint8_t  MAC_TX_PHR2B        :  1;
      __IO uint8_t  MAC_TX_PHRDAT       :  1;
      __IO uint8_t  MAC_TX_CON          :  1;
      __IO uint8_t                      :  1;
      __IO uint8_t  MAC_TX_BYPASS_RDY   :  1;
      __IO uint8_t  MAC_TX_DIS_EXT_RATE :  1;
      __IO uint8_t  MAC_TX_BYPASS_DATRDY:  1;
    } MAC_TX_CFG_B2_b;
  };
  union {
    __IO uint8_t  MAC_TX_CFG_B3;
    struct {
      __IO uint8_t  MAC_TX_PN9PHR  :  1;
      __IO uint8_t  MAC_TX_PN9DAT  :  1;
      __IO uint8_t  MAC_TX_PN9FCS  :  1;
      __IO uint8_t                 :  1;
      __IO uint8_t  MAC_TX_PN9INV  :  1;
      __IO uint8_t                 :  1;
      __IO uint8_t  MAC_TX_MANCH_EN:  1;
    } MAC_TX_CFG_B3_b;
  };
  union {
    __IO uint8_t  MAC_TX_CFG2_B0;
    struct {
      __IO uint8_t  MAC_TX_PRE_NUM :  4;
      __IO uint8_t  MAC_TXW4ACK_NUM:  2;
    } MAC_TX_CFG2_B0_b;
  };
  __IO uint8_t  MAC_TX_PRE_PAT;
  union {
    __IO uint8_t  MAC_TX_CFG2_B2;
    struct {
      __IO uint8_t  MAC_TXW4ACK_GAP:  4;
      __IO uint8_t  MAC_TX_PN7PHR  :  1;
      __IO uint8_t  MAC_TX_PN7DAT  :  1;
      __IO uint8_t  MAC_TX_PN7FCS  :  1;
      __IO uint8_t  MAC_TX_PN7INV  :  1;
    } MAC_TX_CFG2_B2_b;
  };
  __I  uint8_t  RESERVED3 [1];
  __IO uint8_t  DATDLV_DUAL_EN;
  __IO uint8_t  DATDLV_DUAL_PRD_S;
  __IO uint8_t  DATDLV_DUAL_PRD0;
  __IO uint8_t  DATDLV_DUAL_PRD1;
  union {
    __IO uint8_t  MAC_TX_CFG3_B0;
    struct {
      __IO uint8_t  MAC_TX_SFD_NUM:  3;
      __IO uint8_t                :  1;
      __IO uint8_t  MAC_TX_PRE1_EN:  1;
    } MAC_TX_CFG3_B0_b;
  };
  __IO uint8_t  MAC_TX_PRE1_NUM;
  __IO uint8_t  MAC_TX_PRE1_PAT;
  __IO uint8_t  MAC_TX_BPSK_PKT_FORMAT_EN;
  __IO uint8_t  MAC_TX_SFD_PAT1_B0;
  __IO uint8_t  MAC_TX_SFD_PAT1_B1;
  __IO uint8_t  MAC_TX_SFD_PAT1_B2;
  __IO uint8_t  MAC_TX_SFD_PAT1_B3;
  __IO uint8_t  MAC_TX_SFD_PAT2_B0;
  __IO uint8_t  MAC_TX_SFD_PAT2_B1;
  __IO uint8_t  MAC_TX_SFD_PAT2_B2;
  __IO uint8_t  MAC_TX_SFD_PAT2_B3;
  union {
    __IO uint8_t  MAC_CCA1_B0;
    struct {
      __IO uint8_t                :  2;
      __IO uint8_t  MAC_CCA_DETCYP:  1;
    } MAC_CCA1_B0_b;
  };
  __I  uint8_t  RESERVED4 [7];
  __I  uint8_t  MAC_RF_TX_RDY;
  __I  uint8_t  RESERVED5 [3];
  union {
    __IO uint8_t  MAC_IO_REG;
    struct {
      __IO uint8_t                :  1;
      __IO uint8_t  MAC_TX_EXT_DAT:  1;
    } MAC_IO_REG_b;
  };
  __I  uint8_t  RESERVED6 [3];
  __IO uint8_t  CSMA_MOD;
  union {
    __IO uint8_t  MAC_CSMA_B1;
    struct {
      __IO uint8_t  CSMA_MINBE:  4;
      __IO uint8_t  CSMA_MAXBE:  4;
    } MAC_CSMA_B1_b;
  };
  union {
    __IO uint8_t  MAC_CSMA_B2;
    struct {
      __IO uint8_t  CSMA_SEED  :  4;
      __IO uint8_t  CSMA_CCANUM:  2;
    } MAC_CSMA_B2_b;
  };
  __IO uint8_t  CSMA_RETRYNUM;
  __IO uint8_t  CSMA_TIM1_B0;
  __IO uint8_t  CSMA_TIM1_B1;
  __I  uint8_t  RESERVED7 [2];
  __IO uint8_t  CSMA_TIM2_B0;
  __IO uint8_t  CSMA_TIM2_B1;
  __I  uint8_t  RESERVED8 [2];
  __IO uint8_t  CSMA_TIM3_B0;
  __IO uint8_t  CSMA_TIM3_B1;
  __I  uint8_t  RESERVED9 [2];
  union {
    __IO uint8_t  MAC_INT_ST;
    struct {
      __IO uint8_t                           :  2;
      __IO uint8_t  INT_ST_TX                :  1;
      __IO uint8_t  INT_ST_TXERR             :  1;
      __IO uint8_t                           :  1;
      __IO uint8_t  INT_ST_TMREVT            :  1;
      __IO uint8_t                           :  1;
      __IO uint8_t  INT_ST_CRC_STANDALONE_ERR:  1;
    } MAC_INT_ST_b;
  };
  __I  uint8_t  RESERVED10 [3];
  union {
    __IO uint8_t  MAC_INT_EN;
    struct {
      __IO uint8_t                           :  2;
      __IO uint8_t  INT_EN_TX                :  1;
      __IO uint8_t  INT_EN_TXERR             :  1;
      __IO uint8_t                           :  1;
      __IO uint8_t  INT_EN_TMREVT            :  1;
      __IO uint8_t                           :  1;
      __IO uint8_t  INT_EN_CRC_STANDALONE_ERR:  1;
    } MAC_INT_EN_b;
  };
  __I  uint8_t  RESERVED11 [3];
  union {
    __IO uint8_t  MAC_INT;
    struct {
      __IO uint8_t                        :  2;
      __IO uint8_t  INT_TX                :  1;
      __IO uint8_t  INT_TXERR             :  1;
      __IO uint8_t                        :  1;
      __IO uint8_t  INT_TMREVT            :  1;
      __IO uint8_t                        :  1;
      __IO uint8_t  INT_CRC_STANDALONE_ERR:  1;
    } MAC_INT_b;
  };
  __I  uint8_t  RESERVED12 [7];
  __IO uint8_t  MAC_PAN_ID0;
  __IO uint8_t  MAC_PAN_ID1;
  __I  uint8_t  RESERVED13 [2];
  __IO uint8_t  MAC_SADDR0;
  __IO uint8_t  MAC_SADDR1;
  __I  uint8_t  RESERVED14 [10];
  __IO uint8_t  TMREVT_EN;
  union {
    __IO uint8_t  MAC_TMR_CTL_B1;
    struct {
      __IO uint8_t                  :  2;
      __IO uint8_t  TMREVT_TYP_TXSOF:  1;
      __IO uint8_t  TMREVT_TYP_TXEOF:  1;
    } MAC_TMR_CTL_B1_b;
  };
  __I  uint8_t  RESERVED15 [2];
  union {
    __IO uint8_t  MAC_TMR_STS;
    struct {
      __IO uint8_t           :  2;
      __IO uint8_t  MAC_TXSOF:  1;
      __IO uint8_t  MAC_TXEOF:  1;
    } MAC_TMR_STS_b;
  };
  __I  uint8_t  RESERVED16 [19];
  __I  uint8_t  TMREVT_LAT_L0;
  __I  uint8_t  TMREVT_LAT_L1;
  __I  uint8_t  TMREVT_LAT_L2;
  __I  uint8_t  TMREVT_LAT_L3;
  __I  uint8_t  RESERVED17 [16];
  __I  uint8_t  MAC_TX_CRC_OUTPUT0;
  __I  uint8_t  MAC_TX_CRC_OUTPUT1;
  __I  uint8_t  MAC_TX_CRC_OUTPUT2;
  __I  uint8_t  MAC_TX_CRC_OUTPUT3;
  union {
    __IO uint8_t  MAC_MISC_REG_B0;
    struct {
      __IO uint8_t  MAC_MANCH_TYP      :  1;
      __IO uint8_t  DMA_TX_BYTE_REVERSE:  1;
      __IO uint8_t  DMA_TX_BIT_REVERSE :  1;
      __IO uint8_t                     :  2;
      __IO uint8_t  MAC_TX_INFI        :  1;
    } MAC_MISC_REG_B0_b;
  };
  __IO uint8_t  MAC_PN9_INIT0;
  union {
    __IO uint8_t  MAC_MISC_REG_B2;
    struct {
      __IO uint8_t  MAC_PN9_INIT1:  1;
      __IO uint8_t  MAC_PN7_INIT :  7;
    } MAC_MISC_REG_B2_b;
  };
  union {
    __IO uint8_t  MAC_MISC_REG_B3;
    struct {
      __IO uint8_t  MAC_PN9_INIROD    :  1;
      __IO uint8_t  MAC_PN9_TYP       :  1;
      __IO uint8_t  MAC_PN7_INIROD    :  1;
      __IO uint8_t  MAC_TX_ADDR_INSERT:  2;
      __IO uint8_t                    :  1;
      __IO uint8_t  MAC_ADDR_2B       :  1;
    } MAC_MISC_REG_B3_b;
  };
  __IO uint8_t  MAC_CRC_POLY0;
  __IO uint8_t  MAC_CRC_POLY1;
  union {
    __IO uint8_t  MAC_CRC_REG_B2;
    struct {
      __IO uint8_t  MAC_CRC_INV        :  1;
      __IO uint8_t  MAC_CRC_ENDIAN_IN  :  1;
      __IO uint8_t  MAC_CRC_ENDIAN_OUT :  1;
      __IO uint8_t  MAC_CRC_MSB        :  1;
      __IO uint8_t  MAC_CRC_INCLUDE_PHR:  1;
    } MAC_CRC_REG_B2_b;
  };
  union {
    __IO uint8_t  MAC_CRC_REG_B3;
    struct {
      __IO uint8_t  MAC_CRC_BIT:  6;
      __IO uint8_t  MAC_CRCFLEX:  1;
    } MAC_CRC_REG_B3_b;
  };
  union {
    __IO uint8_t  MAC_TXPHR_REG_B0;
    struct {
      __IO uint8_t  MAC_TXLEN_SFT:  4;
      __IO uint8_t  MAC_TX_PHRINV:  1;
    } MAC_TXPHR_REG_B0_b;
  };
  __IO uint8_t  MAC_TXPHR_PAT0;
  __IO uint8_t  MAC_TXPHR_PAT1;
  __I  uint8_t  RESERVED18 [5];
  __IO uint8_t  MAC_CRC_POLY_FLEX0;
  __IO uint8_t  MAC_CRC_POLY_FLEX1;
  __IO uint8_t  MAC_CRC_POLY_FLEX2;
  __IO uint8_t  MAC_CRC_POLY_FLEX3;
  __I  uint8_t  RESERVED19 [4];
  __IO uint8_t  MAC_CRC_INI0;
  __IO uint8_t  MAC_CRC_INI1;
  __IO uint8_t  MAC_CRC_INI2;
  __IO uint8_t  MAC_CRC_INI3;
  union {
    __IO uint8_t  MAC_PRG_DELAY_REG0;
    struct {
      __IO uint8_t  MAC_TX_PRG_DELAY_SET:  1;
      __IO uint8_t                      :  1;
      __IO uint8_t  MAC_TX_PRG_DELAY_EN :  1;
    } MAC_PRG_DELAY_REG0_b;
  };
  __I  uint8_t  RESERVED20 [3];
  __IO uint8_t  MAC_TX_PRG_DELAY_DUR0;
  __IO uint8_t  MAC_TX_PRG_DELAY_DUR1;
  __IO uint8_t  MAC_TX_PRG_DELAY_DUR2;
  __IO uint8_t  MAC_TX_PRG_DELAY_DUR3;
  __I  uint8_t  RESERVED21 [4];
  __IO uint8_t  MAC_CRC_STANDALONE_EN;
  __IO uint8_t  MAC_TXLEN_CRC0;
  __IO uint8_t  MAC_TXLEN_CRC1;
  __IO uint8_t  MAC_TXLEN_CRC2;
  __IO uint8_t  MAC_TX_POST_NUM;
  __IO uint8_t  MAC_TX_POST_PAT;
  union {
    __IO uint8_t  MAC_TX_CFG6_B2;
    struct {
      __IO uint8_t  MAC_TX_POST1_EN :  1;
      __IO uint8_t  MAC_TX_POST1_NUM:  5;
    } MAC_TX_CFG6_B2_b;
  };
  __IO uint8_t  MAC_TX_POST1_PAT;
  __I  uint8_t  RESERVED22 [784];
  __I  uint8_t  PRODUCT_ID0;
  __I  uint8_t  PRODUCT_ID1;
  __I  uint8_t  PRODUCT_ID2;
  __I  uint8_t  PRODUCT_ID3;
  __I  uint8_t  REVISION_ID;

} MAC_T;
/**@}*/ /* end of MAC register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#ifdef __cplusplus
extern "C"
{
#endif


//#define MAC                     ((MAC_T  __xdata *) MAC_BASE         )

// define actual xdata variable for CSR
volatile __xdata MAC_T __at (MAC_BASE) MAC_CSR;

#define MAC                   ((__xdata MAC_T *) &MAC_CSR         )


/**   @addtogroup Standard_Driver Standard Driver
  @{
*/

/**   @addtogroup MAC_Driver MAC Driver
  @{
*/

/**   @addtogroup MAC_EXPORTED_CONSTANTS MAC Exported Constants
  @{
*/


/**@}*/ /* end of group MAC_EXPORTED_FUNCTIONS */
/**@}*/ /* end of group MAC_Driver */
/**@}*/ /* end of group Standard_Driver */

#define MAC_TX_BIT_RATE_2M       0x00000001
#define MAC_TX_BIT_RATE_1M       0x00000002
#define MAC_TX_BIT_RATE_500K     0x00000004
#define MAC_TX_BIT_RATE_100K     0x00000014
#define MAC_TX_BIT_RATE_600      0x00000D05
#define MAC_TX_BIT_RATE_100      0x00004E20


//- CSR - MAC_TX_CFG
#define CSR_MAC_TX_APPENDPRE_Pos        0
#define CSR_MAC_TX_APPENDPRE_Msk        (0x00000001UL << CSR_MAC_TX_APPENDPRE_Pos)

#define CSR_MAC_TX_APPENDSFD_Pos        1
#define CSR_MAC_TX_APPENDSFD_Msk        (0x00000001UL << CSR_MAC_TX_APPENDSFD_Pos)

#define CSR_MAC_TX_APPENDPHR_Pos        2
#define CSR_MAC_TX_APPENDPHR_Msk        (0x00000001UL << CSR_MAC_TX_APPENDPHR_Pos)

#define CSR_MAC_TX_APPENDFCS_Pos        3
#define CSR_MAC_TX_APPENDFCS_Msk        (0x00000001UL << CSR_MAC_TX_APPENDFCS_Pos)

#define CSR_MAC_TX_PN9PHR_Pos           24
#define CSR_MAC_TX_PN9PHR_Msk           (0x00000001UL << CSR_MAC_TX_PN9PHR_Pos)

#define CSR_MAC_TX_PN9DAT_Pos           25
#define CSR_MAC_TX_PN9DAT_Msk           (0x00000001UL << CSR_MAC_TX_PN9DAT_Pos)

#define CSR_MAC_TX_PN9FCS_Pos           26
#define CSR_MAC_TX_PN9FCS_Msk           (0x00000001UL << CSR_MAC_TX_PN9FCS_Pos)

#define CSR_MAC_TX_PN9INV_Pos           28
#define CSR_MAC_TX_PN9INV_Msk           (0x00000001UL << CSR_MAC_TX_PN9INV_Pos)

#ifdef __cplusplus
}
#endif

#endif /* __MAC_H__ */
