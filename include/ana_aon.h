 /****************************************************************************
 * @file     ana_aon.h
 * @version  V2021.04.09.09.06.24
 * @brief    Tonkinese series ANA_AON driver and register definition header file
 *
 * @copyright (C) COPYRIGHT 2021 ESMT Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __ANA_AON_H__
#define __ANA_AON_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

//-----------------------------------------------------//
typedef struct {
  union {
    __IO uint8_t  BIAS_CONFIG1;
    struct {
      __IO uint8_t  BIAS_SYSPWR_EN      :  1;
      __IO uint8_t  BGR_OTA_STARTUP_EN  :  1;
      __IO uint8_t  BGR_PD              :  1;
      __IO uint8_t  BGR_STARTER_ZEROI_EN:  1;
      __IO uint8_t  BGR_VCTATGEN_EN     :  1;
      __IO uint8_t  DIG_LDOVDD_LV       :  2;
      __IO uint8_t  DIG_LDO_ILIMIT_EN   :  1;
    } BIAS_CONFIG1_b;
  };
  union {
    __IO uint8_t  BIAS_CONFIG2;
    struct {
      __IO uint8_t  DIG_LDO_ILIMIT_SEL:  2;
      __IO uint8_t  DIG_LDO_PD        :  1;
    } BIAS_CONFIG2_b;
  };
  __I  uint8_t   RESERVED_1[126];

} BIAS_T;


//-----------------------------------------------------//
typedef struct {
  __IO uint8_t  XO_CAP_I_CTRL;
  __IO uint8_t  XO_CAP_O_CTRL;
  union {
    __IO uint8_t  XO_CONFIG_3;
    struct {
      __IO uint8_t  XO_GAIN_CTRL    :  4;
      __IO uint8_t  XO_LDOVDD_LV    :  2;
      __IO uint8_t  XO_LDO_BYPCAP_EN:  1;
      __IO uint8_t  XO_MAINCAP_I_EN :  1;
    } XO_CONFIG_3_b;
  };
  union {
    __IO uint8_t  XO_CONFIG_4;
    struct {
      __IO uint8_t  XO_MAINCAP_O_EN:  1;
      __IO uint8_t  XO_PD          :  1;
      __IO uint8_t  XO_STARTUP_EN  :  1;
      __IO uint8_t  XO_SWING_BOOST :  1;
    } XO_CONFIG_4_b;
  };
  union {
    __IO uint8_t  MISC_CONFIG_1;
    struct {
      __IO uint8_t  GPIO_DRV_LV:  2;
      __IO uint8_t  GPIO_PU_EN :  1;
      __IO uint8_t  GPIO_ST_EN :  1;
    } MISC_CONFIG_1_b;
  };
  __IO uint8_t  RW_GPREG_ZEROS_0;
  __IO uint8_t  RW_GPREG_ZEROS_1;
  __IO uint8_t  RW_GPREG_ZEROS_2;
  __IO uint8_t  RW_GPREG_ZEROS_3;
  __IO uint8_t  RW_GPREG_ONES_0;
  __IO uint8_t  RW_GPREG_ONES_1;
  __IO uint8_t  RW_GPREG_ONES_2;
  __IO uint8_t  RW_GPREG_ONES_3;
  __I  uint8_t  RO_GPREG_0;
  __I  uint8_t  RO_GPREG_1;
  __I  uint8_t  RO_GPREG_2;
  __I  uint8_t  RO_GPREG_3;
  __I  uint8_t   RESERVED_1[111];

} PAD_XTAL_GPREG_T;


//-----------------------------------------------------//
typedef struct {
  __IO BIAS_T             BIAS_REG;
  __IO PAD_XTAL_GPREG_T   PAD_XTAL_GPREG_REG;
} ANA_AON_T;
/**@}*/ /* end of ANA_AON register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#ifdef __cplusplus
extern "C"
{
#endif


// define actual xdata variable for CSR
volatile __xdata ANA_AON_T __at (ANA_AON_BASE) ANA_AON_CSR;

#define ANA_AON                  ((__xdata ANA_AON_T *) &ANA_AON_CSR          )




#ifdef __cplusplus
}
#endif

#endif /* __ANA_AON_H__ */
