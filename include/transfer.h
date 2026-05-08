#ifndef __TRANSFER_H__
#define __TRANSFER_H__

#define IF433MHZ            0
#define IF868MHZ            1
#define IF915MHZ            2

#define MODE_FSK            0
#define MODE_OOK            1

#define DR_10K              0   //only for OOK
#define DR_12P5K            1
#define DR_50K              2   //only for OOK
#define DR_100K             3   //only for OOK
#define DR_250K             4
#define DR_333K             5
#define DR_400K             6
#define DR_500K             7

#define MODULE_IDX_0P5      1
#define MODULE_IDX_1        2
#define MODULE_IDX_2        3
#define MODULE_IDX_4        4

typedef enum {
    POWER_0DBM = 0,
    POWER_1DBM,
    POWER_3DBM,
    POWER_4DBM,
    POWER_5DBM,
    POWER_6DBM,
    POWER_7DBM,
    POWER_8DBM,
    POWER_9DBM,
    POWER_10DBM,
    POWER_MAXIMUM,
} E_POWER_LEVEL;

#define TX_NONE_BLOCKED     0
#define TX_BLOCKED          1

/*****************************************************************************
 ************************ CONFIG TRANSMIT PARAMETER **************************
 *****************************************************************************/
#define TX_CONFIG_FREQENCE      IF433MHZ
#define TX_CONFIG_MOD_TYPE      MODE_FSK
#define TX_CONFIG_DATA_RATE     DR_100K
#define TX_CONFIG_POWER         POWER_10DBM
#define TX_CONFIG_MOD_IDX       MODULE_IDX_0P5
//#define TX_ENHANCED_API

#if (TX_CONFIG_DATA_RATE == DR_333K && TX_CONFIG_MOD_IDX == MODULE_IDX_4)
#error "Unsupported combination: DR_333K + MODULE_IDX_4"
#endif

#if ((TX_CONFIG_DATA_RATE == DR_400K || TX_CONFIG_DATA_RATE == DR_500K) && \
     TX_CONFIG_MOD_IDX == MODULE_IDX_4)
#error "Unsupported combination: DR_400K/500K + MODULE_IDX_4"
#endif

#if (TX_CONFIG_MOD_TYPE == MODE_FSK) && (TX_CONFIG_DATA_RATE == DR_50K)
#error "DR_50K require MODE_OOK"
#endif

#if (TX_CONFIG_MOD_TYPE == MODE_OOK) && \
    !((TX_CONFIG_DATA_RATE == DR_10K) || (TX_CONFIG_DATA_RATE == DR_50K) || \
     (TX_CONFIG_DATA_RATE == DR_100K))
    #error "In OOK mode, only DR_10K or DR_50K or DR_100K are supported."
#endif

#if (TX_CONFIG_MOD_TYPE == MODE_OOK)
typedef enum {
    TX_TIMING_BAND_SEL_IDX = 0,
    TX_TIMING_LO_DIVINT0_IDX,
    TX_TIMING_LO_DIVINT1_IDX,
    TX_TIMING_LO_DIVFRAC0_IDX,
    TX_TIMING_LO_DIVFRAC1_IDX,
    TX_TIMING_LO_DIVFRAC2_IDX,
    TX_TIMING_FS_PARM0_IDX,
    TX_TIMING_FS_PARM1_IDX,
    TX_TIMING_RAMP_CLK_IDX,
    TX_TIMING_RAMP_NUM_IDX,
    TX_TIMING_MAXIMUNN,
} E_TX_TIMING;
#elif (TX_CONFIG_MOD_TYPE == MODE_FSK)
typedef enum {
    TX_TIMING_BAND_SEL_IDX = 0,
    TX_TIMING_LO_DIVINT0_IDX,
    TX_TIMING_LO_DIVINT1_IDX,
    TX_TIMING_LO_DIVFRAC0_IDX,
    TX_TIMING_LO_DIVFRAC1_IDX,
    TX_TIMING_LO_DIVFRAC2_IDX,
    TX_TIMING_HB_DIVINT_IDX,
    TX_TIMING_HB_DIVFRAC0_IDX,
    TX_TIMING_HB_DIVFRAC1_IDX,
    TX_TIMING_HB_DIVFRAC2_IDX,
    TX_TIMING_LB_DIVINT_IDX,
    TX_TIMING_LB_DIVFRAC0_IDX,
    TX_TIMING_LB_DIVFRAC1_IDX,
    TX_TIMING_LB_DIVFRAC2_IDX,
    TX_TIMING_FS_PARM0_IDX,
    TX_TIMING_FS_PARM1_IDX,
    TX_TIMING_MAXIMUNN,
} E_TX_TIMING;
#endif
#endif /* __TRANSFER_H__ */
