 /****************************************************************************
 * @file     anctl.h
 * @version  V2021.04.09.09.06.24
 * @brief    XS9000 series ANCTL driver and register definition header file
 *
 * @copyright (C) COPYRIGHT 2021 ESMT Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __ANCTL_H__
#define __ANCTL_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

//-----------------------------------------------------//
typedef struct {
  union {
    __IO uint8_t  ANCTL_CONFIG_0_0;
    struct {
      __IO uint8_t   ANCTL_SEL_CTL    :  1;
    } ANCTL_CONFIG_0_0_b;
  };
  __I  uint8_t  RESERVED_1[3];
  union {
    __IO uint8_t   ANCTL_CONFIG_1_0;
    struct {
      __IO uint8_t   ANCTL_TX_EN       :  1;
      __IO uint8_t   ANCTL_TX_RESERVED0:  3;
      __IO uint8_t   ANCTL_TX_FREQ     :  1;
      __IO uint8_t   ANCTL_TX_MOD      :  3;
    } ANCTL_CONFIG_1_0_b;
  };
  union {
    __IO uint8_t   ANCTL_CONFIG_1_1;
    struct {
      __IO uint8_t   ANCTL_TX_LEN      :  7;
    } ANCTL_CONFIG_1_1_b;
  };
  union {
    __IO uint8_t   ANCTL_CONFIG_1_2;
    struct {
      __IO uint8_t                   :  4;
      __IO uint8_t   ANCTL_TX_INV    :  1;
      __IO uint8_t                   :  1;
      __IO uint8_t   ANCTL_TX_REP    :  1;
      __IO uint8_t   ANCTL_TPM_CAL_EN:  1;
    } ANCTL_CONFIG_1_2_b;
  };
  union {
    __IO uint8_t   ANCTL_CONFIG_1_3;
    struct {
      __IO uint8_t   ANCTL_SINGLE_EN   :  1;
      __IO uint8_t                     :  3;
      __I  uint8_t   ANCTL_TX_COMPL_CNT:  2;
    } ANCTL_CONFIG_1_3_b;
  };
  __IO uint8_t   ANCTL_TX_BIT_RATE_0;
  __IO uint8_t   ANCTL_TX_BIT_RATE_1;
  __IO uint8_t   ANCTL_TX_BIT_RATE_2;
  __I  uint8_t  RESERVED_2;
  union {
    __IO uint8_t   ANCTL_CONFIG_3_0;
    struct {
      __IO uint8_t   ANCTL_TX_MAP_00:  2;
      __IO uint8_t   ANCTL_TX_MAP_01:  2;
      __IO uint8_t   ANCTL_TX_MAP_10:  2;
      __IO uint8_t   ANCTL_TX_MAP_11:  2;
    } ANCTL_CONFIG_3_0_b;
  };
  union {
    __IO uint8_t   ANCTL_CONFIG_3_1;
    struct {
      __IO uint8_t                   :  7;
      __IO uint8_t   ANCTL_TX_RUW4DAT:  1;
    } ANCTL_CONFIG_3_1_b;
  };
  union {
    __IO uint8_t   ANCTL_CONFIG_3_2;
    struct {
      __IO uint8_t   ANCTL_TX_REP_IDX;
    } ANCTL_CONFIG_3_2_b;
  };
  union {
    __IO uint8_t   ANCTL_CONFIG_3_3;
    struct {
      __IO uint8_t   ANCTL_TX_D4VAL   :  1;
      __IO uint8_t   ANCTL_TX_STRWPROD:  3;
      __IO uint8_t   ANCTL_TX_ENDWPROD:  3;
    } ANCTL_CONFIG_3_3_b;
  };
  __I  uint8_t  RESERVED_3[8];
  union {
    __IO uint8_t   ANCTL_CONFIG_6_0;
    struct {
      __IO uint8_t   ANCTL_PA_TIM_ENIQ:  3;
      __IO uint8_t   ANCTL_TIM_FS_TX  :  2;
      __IO uint8_t   ANCTL_TIM_FS_RST :  3;
    } ANCTL_CONFIG_6_0_b;
  };
  union {
    __IO uint8_t   ANCTL_CONFIG_6_1;
    struct {
      __IO uint8_t   ANCTL_TIM_FS_PLL;
    } ANCTL_CONFIG_6_1_b;
  };
  __I  uint8_t  RESERVED_4[2];
  union {
    __IO uint8_t   ANCTL_CONFIG_7_0;
    struct {
      __IO uint8_t   ANCTL_TX_DAT_RD_DIS :  1;
      __IO uint8_t                       :  1;
      __IO uint8_t   ANCTL_TX_DAT_TOG_DIS:  1;
    } ANCTL_CONFIG_7_0_b;
  };
  union {
    __IO uint8_t   ANCTL_CONFIG_7_1;
    struct {
      __IO uint8_t   ANCTL_PWR_CONST   :  5;
      __IO uint8_t                     :  2;
      __IO uint8_t   ANCTL_CONST_PWR_EN:  1;
    } ANCTL_CONFIG_7_1_b;
  };
  __I  uint8_t  RESERVED_5[2];
  __IO uint8_t   ANCTL_RAMP_CLK_0;
  __IO uint8_t   ANCTL_RAMP_CLK_1;
  __IO uint8_t   ANCTL_RAMP_CLK_2;
  __IO uint8_t   ANCTL_RAMP_NUM;
  union {
    __IO uint8_t   ANCTL_CONFIG_9_0;
    struct {
      __IO uint8_t   ANCTL_PLL_LOCK_BYPASS:  1;
      __IO uint8_t   ANCTL_DUP_PLL_BYPASS :  1;
      __IO uint8_t                        :  2;
      __IO uint8_t   ANCTL_VDDDET_LOC     :  1;
    } ANCTL_CONFIG_9_0_b;
  };
  __I  uint8_t  RESERVED_6[3];
  __IO uint8_t   ANCTL_TX_PKTMOD_GAP_0;
  __IO uint8_t   ANCTL_TX_PKTMOD_GAP_1;
  __IO uint8_t   ANCTL_TX_PKTMOD_NUM;
  __IO uint8_t   ANCTL_TX_PKTMOD_PDEN;
  union {
    __IO uint8_t   ANCTL_CONFIG_VOL_DET_0;
    struct {
      __IO uint8_t   ANCTL_VOL_DET_EN      :  1;
      __IO uint8_t   ANCTL_VOL_DET_PD_EN   :  1;
      __IO uint8_t   ANCTL_VOL_DET_RST_N_EN:  1;
      __IO uint8_t   ANCTL_VOL_DET_BUF_EN  :  1;
      __IO uint8_t   ANCTL_VOL_DET_AAF_EN  :  1;
      __IO uint8_t   ANCTL_VOL_DET_EDGE_R  :  1;
    } ANCTL_CONFIG_VOL_DET_0_b;
  };
  __IO uint8_t   ANCTL_VOL_DET_VIN_MUX_SEL;
  __IO uint8_t   ANCTL_VOL_DET_CUR_0;
  __IO uint8_t   ANCTL_VOL_DET_CUR_1;
  union {
    __IO uint8_t   ANCTL_CONFIG_PD_REG_0;
    struct {
      __IO uint8_t   ANCTL_FS_FREQSYNTH_SEL           :  1;
      __IO uint8_t   ANCTL_FS_FREQSYNTH_PD_TX_EN      :  1;
      __IO uint8_t   ANCTL_FS_FREQSYNTH_RST_N_TX_EN   :  1;
      __IO uint8_t   ANCTL_TPM_DMI_EN_TX_EN           :  1;
      __IO uint8_t                                    :  1;
      __IO uint8_t                                    :  1;
      __IO uint8_t   ANCTL_FS_IREFGEN_STARTUP_EN_TX_EN:  1;
    } ANCTL_CONFIG_PD_REG_0_b;
  };
  union {
    __IO uint8_t   ANCTL_CONFIG_PD_REG_1;
    struct {
      __IO uint8_t                         :  4;
      __IO uint8_t   ANCTL_ASARADC_PD_SEL  :  1;
      __IO uint8_t   ANCTL_ASARADC_PD_EN   :  1;
      __IO uint8_t   ANCTL_ASARADC_RST_N_EN:  1;
    } ANCTL_CONFIG_PD_REG_1_b;
  };
  __I  uint8_t  RESERVED_7;
  union {
    __IO uint8_t   ANCTL_CONFIG_PD_REG_3;
    struct {
      __IO uint8_t   ANCTL_TPM_DMI_EN_RX_EN    :  1;
      __IO uint8_t   ANCTL_FS_AFC_EN_FS_OPT_EN :  1;
      __IO uint8_t   ANCTL_FS_AFC_EN_TPM_OPT_EN:  1;
    } ANCTL_CONFIG_PD_REG_3_b;
  };
  __I  uint8_t  RESERVED_8[12];
  __IO uint8_t   ANCTL_TX_DAT0_0;
  __IO uint8_t   ANCTL_TX_DAT0_1;
  __IO uint8_t   ANCTL_TX_DAT0_2;
  __IO uint8_t   ANCTL_TX_DAT0_3;
  __IO uint8_t   ANCTL_TX_DAT1_0;
  __IO uint8_t   ANCTL_TX_DAT1_1;
  __IO uint8_t   ANCTL_TX_DAT1_2;
  __IO uint8_t   ANCTL_TX_DAT1_3;
  __IO uint8_t   ANCTL_TX_DAT2_0;
  __IO uint8_t   ANCTL_TX_DAT2_1;
  __IO uint8_t   ANCTL_TX_DAT2_2;
  __IO uint8_t   ANCTL_TX_DAT2_3;
  __IO uint8_t   ANCTL_TX_DAT3_0;
  __IO uint8_t   ANCTL_TX_DAT3_1;
  __IO uint8_t   ANCTL_TX_DAT3_2;
  __IO uint8_t   ANCTL_TX_DAT3_3;
  __I  uint8_t  RESERVED_9[16];
  union {
    __IO uint8_t   ANCTL_PA1G_REG0_0_0;
    struct {
      __IO uint8_t   ANCTL_RF_LDO_SEL_RX:  2;
      __IO uint8_t   ANCTL_RF_LDO_SEL_TX:  2;
    } ANCTL_PA1G_REG0_0_0_b;
  };
  __I  uint8_t  RESERVED_10;
  union {
    __IO uint8_t   ANCTL_PA1G_REG0_0_2;
    struct {
      __IO uint8_t   ANCTL_PA_PWRDLY_PROD;
    } ANCTL_PA1G_REG0_0_2_b;
  };
  __I  uint8_t  RESERVED_11;
  union {
    __IO uint8_t   ANCTL_FS_REG0_0;
    struct {
      __IO uint8_t   ANCTL_FS_IQBUF_ICTRL_RX:  3;
      __IO uint8_t                          :  1;
      __IO uint8_t   ANCTL_FS_IQBUF_ICTRL_TX:  3;
    } ANCTL_FS_REG0_0_b;
  };
  union {
    __IO uint8_t   ANCTL_FS_REG0_1;
    struct {
      __IO uint8_t   ANCTL_FS_CP_ICTRL_TXSET;
    } ANCTL_FS_REG0_1_b;
  };
  __I  uint8_t  RESERVED_12[2];
  union {
    __IO uint8_t   ANCTL_FS_REG1;
    struct {
      __IO uint8_t   ANCTL_DIS_FS_IOBUF_ICTRL:  1;
      __IO uint8_t   ANCTL_DIS_FS_CP_ICTRL   :  1;
    } ANCTL_FS_REG1_b;
  };
  __I  uint8_t  RESERVED_13[7];
  union {
    __IO uint8_t   ANCTL_WB_REG0_0;
    struct {
      __IO uint8_t                              :  1;
      __IO uint8_t   ANCTL_DIS_FS_TX_WB         :  1;
      __IO uint8_t                              :  2;
      __IO uint8_t   ANCTL_DIS_ASARADC_CFG_WB   :  1;
      __IO uint8_t   ANCTL_DIS_ASARADC_PDRSTN_WB:  1;
    } ANCTL_WB_REG0_0_b;
  };
  __I  uint8_t  RESERVED_14[2];
  union {
      __IO uint8_t ANCTL_WB_REG0_3;
      struct {
          __IO uint8_t ANCTL_DIS_TPM_CAL_EN_WB    : 1;
          __IO uint8_t                            : 1;
          __IO uint8_t ANCTL_DIS_TPM_TEST_MODE_WB : 1;
          __IO uint8_t                            : 5;
      } ANCTL_WB_REG0_3_b;
  };
  __I uint8_t RESERVED_15[12];
  union {
      __IO uint8_t ANCTL_ANA_LAT_REG0;
      struct {
          __IO uint8_t ANCTL_ANA_LAT_SRC : 4;
          __IO uint8_t                   : 4;
      } ANCTL_ANA_LAT_REG0_b;
  };
  __I uint8_t RESERVED_16[3];
  union {
      __O uint8_t ANCTL_ANA_LAT_REG1;
      struct {
          __O uint8_t W1T_ANA_LAT : 1;
          __O uint8_t             : 7;
      } ANCTL_ANA_LAT_REG1_b;
  };
  __I uint8_t RESERVED_17[3];
  __I uint8_t ANCTL_CUR_ANA_LAT_0;
  __I uint8_t ANCTL_CUR_ANA_LAT_1;
  __I uint8_t ANCTL_CUR_ANA_LAT_2;
  __I uint8_t ANCTL_CUR_ANA_LAT_3;
  __I uint8_t RESERVED_18[112];
  __I  uint8_t   ANCTL_CUR_ST;
  __I  uint8_t   RESERVED_19[3];
  __IO uint8_t   ANCTL_PWR01;
  __IO uint8_t   ANCTL_PWR02;
  __IO uint8_t   ANCTL_PWR03;
  __IO uint8_t   ANCTL_PWR04;
  __IO uint8_t   ANCTL_PWR05;
  __IO uint8_t   ANCTL_PWR06;
  __IO uint8_t   ANCTL_PWR07;
  __IO uint8_t   ANCTL_PWR08;
  __IO uint8_t   ANCTL_PWR09;
  __IO uint8_t   ANCTL_PWR10;
  __IO uint8_t   ANCTL_PWR11;
  __IO uint8_t   ANCTL_PWR12;
  __IO uint8_t   ANCTL_PWR13;
  __IO uint8_t   ANCTL_PWR14;
  __IO uint8_t   ANCTL_PWR15;
  __IO uint8_t   ANCTL_PWR16;
  __IO uint8_t   ANCTL_PWR17;
  __IO uint8_t   ANCTL_PWR18;
  __IO uint8_t   ANCTL_PWR19;
  __IO uint8_t   ANCTL_PWR20;
  __IO uint8_t   ANCTL_PWR21;
  __IO uint8_t   ANCTL_PWR22;
  __IO uint8_t   ANCTL_PWR23;
  __IO uint8_t   ANCTL_PWR24;
  __IO uint8_t   ANCTL_PWR25;
  __IO uint8_t   ANCTL_PWR26;
  __IO uint8_t   ANCTL_PWR27;
  __IO uint8_t   ANCTL_PWR28;
  __IO uint8_t   ANCTL_PWR29;
  __IO uint8_t   ANCTL_PWR30;
  __IO uint8_t   ANCTL_PWR31;
  __IO uint8_t   ANCTL_PWR32;
  __IO uint8_t   ANCTL_PWR33;
  __IO uint8_t   ANCTL_PWR34;
  __IO uint8_t   ANCTL_PWR35;
  __IO uint8_t   ANCTL_PWR36;
  __IO uint8_t   ANCTL_PWR37;
  __IO uint8_t   ANCTL_PWR38;
  __IO uint8_t   ANCTL_PWR39;
  __IO uint8_t   ANCTL_PWR40;
  __IO uint8_t   ANCTL_PWR41;
  __IO uint8_t   ANCTL_PWR42;
  __IO uint8_t   ANCTL_PWR43;
  __IO uint8_t   ANCTL_PWR44;
  __IO uint8_t   ANCTL_PWR45;
  __IO uint8_t   ANCTL_PWR46;
  __IO uint8_t   ANCTL_PWR47;
  __IO uint8_t   ANCTL_PWR48;
  __IO uint8_t   ANCTL_PWR49;
  __IO uint8_t   ANCTL_PWR50;
  __IO uint8_t   ANCTL_PWR51;
  __IO uint8_t   ANCTL_PWR52;
  __IO uint8_t   ANCTL_PWR53;
  __IO uint8_t   ANCTL_PWR54;
  __IO uint8_t   ANCTL_PWR55;
  __IO uint8_t   ANCTL_PWR56;
  __IO uint8_t   ANCTL_PWR57;
  __IO uint8_t   ANCTL_PWR58;
  __IO uint8_t   ANCTL_PWR59;
  __IO uint8_t   ANCTL_PWR60;
  __IO uint8_t   ANCTL_PWR61;
  __IO uint8_t   ANCTL_PWR62;
  __IO uint8_t   ANCTL_PWR63;
  __IO uint8_t   ANCTL_PWR64;
  __I  uint8_t   RESERVED_20[64];

} ANCTLD_T;


//-----------------------------------------------------//
typedef struct {
  union {
    __IO uint8_t   PA_CONFIG_0;
    struct {
      __IO uint8_t   PA_EN                :  1;
      __IO uint8_t   PA_DUTY_EN           :  1;
      __IO uint8_t   PA_EN_RAMP           :  1;
      __IO uint8_t   PA_SEL_RAMP          :  2;
      __IO uint8_t   PA_VB2_SEL           :  2;
      __IO uint8_t   PA_PA1G_VB_DRIVER_SEL:  1;
    } PA_CONFIG_0_b;
  };
  __I  uint8_t   RESERVED_1[3];
  union {
    __IO uint8_t   PA_CONFIG_1;
    struct {
      __IO uint8_t   PA_PWR     :  5;
      __IO uint8_t   PA_DUTY_SEL:  3;
    } PA_CONFIG_1_b;
  };
  union {
    __IO uint8_t   PA_CONFIG_2;
    struct {
      __IO uint8_t   PA_LDO_SEL :  2;
      __IO uint8_t   PA_IREF_SEL:  3;
      __IO uint8_t   PA_D2S_ISEL:  2;
    } PA_CONFIG_2_b;
  };
  __IO uint8_t   PA_TX_SUBG_RESERVED;
  __I  uint8_t   RESERVED_2[121];

} PA_T;


//-----------------------------------------------------//
typedef struct {
  union {
    __IO uint8_t   ASARADC_CONFIG_1;
    struct {
      __IO uint8_t   ASARADC_AAF_BW         :  2;
      __IO uint8_t   ASARADC_AAF_EN         :  1;
      __IO uint8_t   ASARADC_ASYNC_CLK_PULWD:  3;
      __IO uint8_t   ASARADC_BUF_EN         :  1;
      __IO uint8_t   ASARADC_BUF_LDOVDD_EN  :  1;
    } ASARADC_CONFIG_1_b;
  };
  union {
    __IO uint8_t   ASARADC_CONFIG_2;
    struct {
      __IO uint8_t   ASARADC_CKS_PULSEMODE_EN:  1;
      __IO uint8_t   ASARADC_CKS_PULWD       :  3;
      __IO uint8_t   ASARADC_LDOVDD_LV       :  2;
      __IO uint8_t   ASARADC_LDO_BYPCAP_EN   :  1;
      __IO uint8_t   ASARADC_LDO_BYP_EN      :  1;
    } ASARADC_CONFIG_2_b;
  };
  union {
    __IO uint8_t   ASARADC_CONFIG_3;
    struct {
      __IO uint8_t   ASARADC_PD             :  1;
      __IO uint8_t   ASARADC_RST_N          :  1;
      __IO uint8_t   ASARADC_STARTUP_EN     :  1;
      __IO uint8_t   ASARADC_VDDDET_EN      :  1;
      __IO uint8_t   ASARADC_VDDDET_VSLV_SEL:  3;
      __IO uint8_t   ASARADC_VIN_MUX_EN     :  1;
    } ASARADC_CONFIG_3_b;
  };
  union {
    __IO uint8_t   ASARADC_CONFIG_4;
    struct {
      __IO uint8_t   ASARADC_VIN_MUX_SEL    :  3;
      __IO uint8_t   ASARADC_DAF_AVG_SHIFT_N:  4;
      __IO uint8_t                          :  1;
    } ASARADC_CONFIG_4_b;
  };
  union {
    __IO uint8_t   ASARADC_CONFIG_5;
    struct {
      __IO uint8_t   ASARADC_DAF_EN        :  1;
      __IO uint8_t   ASARADC_DAF_AUTORST_EN:  1;
      __IO uint8_t                         :  6;
    } ASARADC_CONFIG_5_b;
  };
  union {
    __I uint8_t   ASARADC_CONFIG_6;
    struct {
      __I uint8_t   ASARADC_TIMING_GOOD:  1;
      __I uint8_t   ASARADC_DOUT_0     :  7;
    } ASARADC_CONFIG_6_b;
  };
  union {
    __I uint8_t   ASARADC_CONFIG_7;
    struct {
      __I uint8_t   ASARADC_DOUT_1    :  5;
      __I uint8_t   ASARADC_HR_RDOUT_0:  3;
    } ASARADC_CONFIG_7_b;
  };
  __I uint8_t   ASARADC_HR_RDOUT_1;
  __I uint8_t   ASARADC_HR_RDOUT_2;
  __I uint8_t   ASARADC_HR_RDOUT_3;
  __I uint8_t   RESERVED_1[38];
  union {
    __IO uint8_t   ASARADC_CONFIG_13;
    struct {
      __IO uint8_t   ASARADC_START:  1;
      __I  uint8_t   ASARADC_READY:  1;
      __I  uint8_t                :  6;
    } ASARADC_CONFIG_13_b;
  };
  __I uint8_t   RESERVED_2[3];
  __I uint8_t   ASARADC_DATA_0;
  union {
    __I uint8_t   ASARADC_DATA_1;
    struct {
      __I uint8_t   ASARADC_DATA_1_VALUE:  4;
      __I uint8_t                       :  4;
    } ASARADC_CONFIG_14_1_b;
  };
  __I uint8_t   RESERVED_3[2];
  __I uint8_t   ASARADC_HR_DATA_0;
  __I uint8_t   ASARADC_HR_DATA_1;
  __I uint8_t   ASARADC_HR_DATA_2;
  union {
    __I uint8_t   ASARADC_HR_DATA_3;
    struct {
      __I uint8_t   ASARADC_HR_DATA_3_VALUE:  3;
      __I uint8_t                          :  5;
    } ASARADC_CONFIG_15_3_b;
  };
  union {
    __IO uint8_t   ASARADC_CONFIG_16;
    struct {
      __IO uint8_t   ASARADC_VIN_MUX_SEL_SET:  4;
      __IO uint8_t                          :  4;
    } ASARADC_CONFIG_16_b;
  };
  __I uint8_t   RESERVED_4[3];
  union {
    __IO uint8_t   ASARADC_INT_ST;
    struct {
      __IO uint8_t   INT_ST_READY:  1;
      __IO uint8_t               :  7;
    } ASARADC_INT_ST_b;
  };
  __I uint8_t   RESERVED_5[3];
  union {
    __IO uint8_t   ASARADC_INT_EN;
    struct {
      __IO uint8_t   INT_EN_READY:  1;
      __IO uint8_t               :  7;
    } ASARADC_INT_EN_b;
  };
  __I uint8_t   RESERVED_6[3];
  union {
    __I uint8_t   ASARADC_INT;
    struct {
      __I uint8_t   INT_READY:  1;
      __I uint8_t            :  7;
    } ASARADC_INT_b;
  };
  __I uint8_t   RESERVED_7[7];
  union {
    __IO uint8_t   ASARADC_CONFIG_17;
    struct {
      __IO uint8_t   FETCH_MODE  :  1;
      __IO uint8_t   TIMER_MODE_1:  2;
      __IO uint8_t   TIMER_MODE_2:  2;
      __IO uint8_t               :  3;
    } ASARADC_CONFIG_17_b;
  };
  __I uint8_t   RESERVED_8[47];
} ASARADC_T;

//-----------------------------------------------------//
typedef struct {
  union {
    __IO uint8_t   SX_CONFIG_1;
    struct {
      __IO uint8_t   FS_AFC_EN              :  1;
      __IO uint8_t   FS_AFC_INIT_BSMODE_EN  :  1;
      __IO uint8_t   FS_AFC_SETTLING_CYCLE_0:  6;
    } SX_CONFIG_1_b;
  };
  __IO uint8_t   FS_AFC_SETTLING_CYCLE_1;
  __IO uint8_t   FS_AFC_SETTLING_CYCLE_2;
  union {
    __IO uint8_t   SX_CONFIG_4;
    struct {
      __IO uint8_t   FS_ANG_LDO_BYP_EN:  1;
      __IO uint8_t   FS_ANG_LDO_PD    :  1;
      __IO uint8_t   FS_AUTOLBW_EN    :  1;
      __IO uint8_t   FS_CP_ICTRL      :  3;
      __IO uint8_t   RESERVED         :  2;
    } SX_CONFIG_4_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_5;
    struct {
      __IO uint8_t   FS_CP_OTA_PD_CTRL:  3;
      __IO uint8_t   FS_DIV_FRAC_0    :  5;
    } SX_CONFIG_5_b;
  };
  __IO uint8_t   FS_DIV_FRAC_1;
  union {
    __IO uint8_t   SX_CONFIG_7;
    struct {
      __IO uint8_t   FS_DIV_FRAC_2:  5;
      __IO uint8_t   FS_DIV_INT_0 :  3;
    } SX_CONFIG_7_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_8;
    struct {
      __IO uint8_t   FS_DIV_INT_1               :  2;
      __IO uint8_t   FS_DSM_DITHERING           :  1;
      __IO uint8_t   FS_DSM_DITHERING_BIT_DVALUE:  1;
      __IO uint8_t   FS_FRACMODE_EN             :  1;
      __IO uint8_t   FS_FREF_INVMODE_EN         :  1;
      __IO uint8_t   FS_FREQSYNTH_PD            :  1;
      __IO uint8_t   FS_FREQSYNTH_RST_N         :  1;
    } SX_CONFIG_8_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_9;
    struct {
      __IO uint8_t   FS_HF_LDO_BYP_EN:  1;
      __IO uint8_t   FS_HF_LDO_PD    :  1;
      __IO uint8_t   FS_IQBUF_ICTRL  :  3;
      __IO uint8_t   RESERVED        :  3;
    } SX_CONFIG_9_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_10;
    struct {
      __IO uint8_t   FS_IQGEN_LATCH_ICTRL:  4;
      __IO uint8_t   RESERVED            :  4;
    } SX_CONFIG_10_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_11;
    struct {
      __IO uint8_t   FS_KVC_IN    :  5;
      __IO uint8_t   FS_LDO_SUPEN :  1;
      __IO uint8_t   FS_LF_BW_MODE:  1;
      __IO uint8_t   RESERVED     :  1;
    } SX_CONFIG_11_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_12;
    struct {
      __IO uint8_t   FS_OPT_VTUNE_SEL:  3;
      __IO uint8_t   FS_PFD_RST_DLY  :  2;
      __IO uint8_t   FS_PVT_CAL_EN   :  1;
      __IO uint8_t   RESERVED        :  2;
    } SX_CONFIG_12_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_13;
    struct {
      __IO uint8_t   FS_PVT_KVC_TARGET        :  5;
      __IO uint8_t   FS_TPMCAL_AVG_SAMPLES_SEL:  2;
      __IO uint8_t   RESERVED                 :  1;
    } SX_CONFIG_13_b;
  };
  __IO uint8_t   FS_TPMCAL_DIV_FRAC_HB_0;
  __IO uint8_t   FS_TPMCAL_DIV_FRAC_HB_1;
  union {
    __IO uint8_t   SX_CONFIG_16;
    struct {
      __IO uint8_t   FS_TPMCAL_DIV_FRAC_HB_2:  2;
      __IO uint8_t   RESERVED               :  6;
    } SX_CONFIG_16_b;
  };
  __IO uint8_t   FS_TPMCAL_DIV_FRAC_LB_0;
  __IO uint8_t   FS_TPMCAL_DIV_FRAC_LB_1;
  union {
    __IO uint8_t   SX_CONFIG_19;
    struct {
      __IO uint8_t   FS_TPMCAL_DIV_FRAC_LB_2:  2;
      __IO uint8_t   FS_TPMCAL_DIV_INT_HB   :  5;
      __IO uint8_t   RESERVED               :  1;
    } SX_CONFIG_19_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_20;
    struct {
      __IO uint8_t   FS_TPMCAL_DIV_INT_LB:  5;
      __IO uint8_t   RESERVED            :  3;
    } SX_CONFIG_20_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_21;
    struct {
      __IO uint8_t   FS_TPMCAL_EN                 :  1;
      __IO uint8_t   FS_TPMCAL_RST_N              :  1;
      __IO uint8_t   FS_TPMCAL_SEQUENTIAL_COUNTS_0:  6;
    } SX_CONFIG_21_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_22;
    struct {
      __IO uint8_t   FS_TPMCAL_SEQUENTIAL_COUNTS_1:  6;
      __IO uint8_t   RESERVED                     :  2;
    } SX_CONFIG_22_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_23;
    struct {
      __IO uint8_t   FS_TPMCAL_SETTLING_CYCLES:  7;
      __IO uint8_t   RESERVED                 :  1;
    } SX_CONFIG_23_b;
  };
  __IO uint8_t   FS_TPMCAL_TPM_DIN_HB_0;
  union {
    __IO uint8_t   SX_CONFIG_25;
    struct {
      __IO uint8_t   FS_TPMCAL_TPM_DIN_HB_1:  4;
      __IO uint8_t   RESERVED              :  4;
    } SX_CONFIG_25_b;
  };
  __IO uint8_t   FS_TPMCAL_TPM_DIN_LB_0;
  union {
    __IO uint8_t   SX_CONFIG_27;
    struct {
      __IO uint8_t   FS_TPMCAL_TPM_DIN_LB_1:  4;
      __IO uint8_t   FS_D2S_ICTRL          :  4;
    } SX_CONFIG_27_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_28;
    struct {
      __IO uint8_t   FS_TPM_CAPARRAY_CTRL :  3;
      __IO uint8_t   FS_TPM_CLK_INVMODE_EN:  1;
      __IO uint8_t   FS_TPM_CLK_LF_MODE   :  1;
      __IO uint8_t   RESERVED             :  3;
    } SX_CONFIG_28_b;
  };
  __IO uint8_t   FS_TPM_DIN_0;
  union {
    __IO uint8_t   SX_CONFIG_30;
    struct {
      __IO uint8_t   FS_TPM_DIN_1        :  4;
      __IO uint8_t   FS_TPM_DSM_DITHERING:  1;
      __IO uint8_t   FS_TPM_EN           :  1;
      __IO uint8_t   FS_TPM_FBSRC_DLY    :  2;
    } SX_CONFIG_30_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_31;
    struct {
      __IO uint8_t   FS_TPM_FBSRC_INVMODE_EN:  1;
      __IO uint8_t   FS_TPM_FBSRC_SEL       :  1;
      __IO uint8_t   FS_TPM_LPF_BW          :  3;
      __IO uint8_t   FS_TPM_LPF_CAP_EN      :  1;
      __IO uint8_t   FS_TPM_LPF_RES_EN      :  1;
      __IO uint8_t   FS_TX_EN               :  1;
    } SX_CONFIG_31_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_32;
    struct {
      __IO uint8_t   FS_VCO_BUF_ICTRL:  4;
      __IO uint8_t   RESERVED        :  4;
    } SX_CONFIG_32_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_33;
    struct {
      __IO uint8_t   FS_VCO_ICTRL     :  5;
      __IO uint8_t   FS_VCO_LDO_BYP_EN:  1;
      __IO uint8_t   RESERVED         :  2;
    } SX_CONFIG_33_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_34;
    struct {
      __IO uint8_t   FS_VCO_LDO_LV      :  3;
      __IO uint8_t   FS_VCO_LDO_PD      :  1;
      __IO uint8_t   FS_VCO_STARTER_CTRL:  1;
      __IO uint8_t   FS_VTUNEDET_VH     :  3;
    } SX_CONFIG_34_b;
  };
  union {
    __IO uint8_t   SX_CONFIG_35;
    struct {
      __IO uint8_t   FS_VTUNEDET_VL  :  3;
      __IO uint8_t   FS_VTUNEPROBE_EN:  1;
      __IO uint8_t   RESERVED        :  4;
    } SX_CONFIG_35_b;
  };
  union {
    __I uint8_t   SX_CONFIG_36;
    struct {
      __I uint8_t   FS_KVC_ROUT      :  5;
      __I uint8_t   FS_PLL_LOCKED_SIG:  1;
      __I uint8_t   FS_TPMCAL_DONE   :  1;
      __I uint8_t   RESERVED         :  1;
    } SX_CONFIG_36_b;
  };
  __I uint8_t   FS_TPMCAL_TPM_DIN_HB_OUT_0;
  union {
    __I uint8_t   SX_CONFIG_38;
    struct {
      __I uint8_t   FS_TPMCAL_TPM_DIN_HB_OUT_1:  4;
      __I uint8_t   FS_PVT_CAL_DONE           :  1;
      __I uint8_t   RESERVED                  :  3;
    } SX_CONFIG_38_b;
  };
  union {
    __I uint8_t   SX_CONFIG_39;
    struct {
      __I uint8_t   FS_INNER_VCO_ICTRL_ROUT:  5;
      __I uint8_t   RESERVED               :  3;
    } SX_CONFIG_39_b;
  };
  __IO uint8_t   TPM_DMI_FS_PARM_0;
  __IO uint8_t   TPM_DMI_FS_PARM_1;
  union {
    __IO uint8_t   TPM_DMI_CONFIG_3;
    struct {
      __IO uint8_t   TPM_DMI_FS_PARM_2:  4;
      __IO uint8_t   TPM_DMI_TEST_MODE:  4;
    } TPM_DMI_CONFIG_3_b;
  };
  union {
    __IO uint8_t   TPM_DMI_CONFIG_4;
    struct {
      __IO uint8_t   TPM_DMI_GSF_EN         :  1;
      __IO uint8_t   TPM_DMI_SINGLE_BIT_MODE:  1;
      __IO uint8_t   TPM_DMI_CLK_PHASE      :  1;
      __IO uint8_t   TPM_DMI_EN             :  1;
      __IO uint8_t   RESERVED               :  4;
    } TPM_DMI_CONFIG_4_b;
  };
  __IO uint8_t   FS_TPMCAL_DIV_FRAC_HB_M_0;
  __IO uint8_t   FS_TPMCAL_DIV_FRAC_HB_M_1;
  union {
    __IO uint8_t   TPM_DMI_CONFIG_7;
    struct {
      __IO uint8_t   FS_TPMCAL_DIV_FRAC_HB_M_2:  2;
      __IO uint8_t   RESERVED                 :  6;
    } TPM_DMI_CONFIG_7_b;
  };
  __IO uint8_t   FS_TPMCAL_DIV_FRAC_LB_M_0;
  __IO uint8_t   FS_TPMCAL_DIV_FRAC_LB_M_1;
  union {
    __IO uint8_t   TPM_DMI_CONFIG_10;
    struct {
      __IO uint8_t   FS_TPMCAL_DIV_FRAC_LB_M_2:  2;
      __IO uint8_t   RESERVED                 :  6;
    } TPM_DMI_CONFIG_10_b;
  };
  union {
    __IO uint8_t   TPM_DMI_CONFIG_11;
    struct {
      __IO uint8_t   FS_TPMCAL_DIV_INT_HB_M:  5;
      __IO uint8_t   RESERVED              :  3;
    } TPM_DMI_CONFIG_11_b;
  };
  union {
    __IO uint8_t   TPM_DMI_CONFIG_12;
    struct {
      __IO uint8_t   FS_TPMCAL_DIV_INT_LB_M:  5;
      __IO uint8_t   RESERVED              :  3;
    } TPM_DMI_CONFIG_12_b;
  };
  __IO uint8_t   FS_TPMCAL_TPM_DIN_HB_M_0;
  union {
    __IO uint8_t   TPM_DMI_CONFIG_14;
    struct {
      __IO uint8_t   FS_TPMCAL_TPM_DIN_HB_M_1:  4;
      __IO uint8_t   RESERVED                :  4;
    } TPM_DMI_CONFIG_14_b;
  };
  __IO uint8_t   FS_TPMCAL_TPM_DIN_LB_M_0;
  union {
    __IO uint8_t   TPM_DMI_CONFIG_16;
    struct {
      __IO uint8_t   FS_TPMCAL_TPM_DIN_LB_M_1:  4;
      __IO uint8_t   RESERVED                :  4;
    } TPM_DMI_CONFIG_16_b;
  };
  __I uint8_t RESERVED_1[73];
} SX_T;

//-----------------------------------------------------//
typedef struct {
  __IO ANCTLD_T           ANCTL_REG;
  __I  uint8_t            RESERVED1 [128];
  __IO PA_T               PA_REG;
  __IO ASARADC_T          ASARADC_REG;
  __I  uint8_t            RESERVED2 [128];
  __IO SX_T               SX_REG;
} ANCTL_T;
/**@}*/ /* end of ANCTL register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#ifdef __cplusplus
extern "C"
{
#endif


// define actual xdata variable for CSR
volatile __xdata ANCTL_T __at (ANCTL_BASE) ANCTL_CSR;

#define ANCTL                  ((__xdata ANCTL_T *) &ANCTL_CSR          )



#define ANCTL_TX_FREQ_1G         0
#define ANCTL_TX_FREQ_2G         1

#define ANCTL_TX_MOD_BPSK        0
#define ANCTL_TX_MOD_QPSK        1
#define ANCTL_TX_MOD_oQPSK       2
#define ANCTL_TX_MOD_FSK         3
#define ANCTL_TX_MOD_4FSK        4
#define ANCTL_TX_MOD_BPSK_RAMP   5
#define ANCTL_TX_MOD_OOK         6

#define ANCTL_TX_BIT_RATE_2M     0x00000008
#define ANCTL_TX_BIT_RATE_1M     0x00000010
#define ANCTL_TX_BIT_RATE_500K   0x00000020
#define ANCTL_TX_BIT_RATE_600    0x0000682A
#define ANCTL_TX_BIT_RATE_100    0x00027100

#ifdef __cplusplus
}
#endif

#endif /* __ANCTL_H__ */
