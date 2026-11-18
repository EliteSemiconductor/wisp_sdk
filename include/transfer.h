#ifndef __TRANSFER_H__
#define __TRANSFER_H__

#define XTL16M              0
#define XTL19_2M            1

#define IF433MHZ            0
#define IF868MHZ            1
#define IF915MHZ            2
#define IFUSER              3

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
#define DR_4_8K             8
#define DR_9_6K             9
#define DR_USER             10

#define MODULE_IDX_1        1
#define MODULE_IDX_2        2
#define MODULE_IDX_4        3

#define POWER_4DBM          0
#define POWER_10DBM         1

/*****************************************************************************
 ************************ CONFIG TRANSMIT PARAMETER **************************
 *****************************************************************************/
// TX_CONFIG_XTAL is used only for compile-time checks.
// Changing it does not alter TX parameters or TX data tables.
#define TX_CONFIG_XTAL         XTL16M
#define TX_CONFIG_FREQENCY     IF433MHZ
#define TX_CONFIG_MOD_TYPE     MODE_FSK
#define TX_CONFIG_DATA_RATE    DR_100K
#define TX_CONFIG_POWER        POWER_10DBM
#define TX_CONFIG_MOD_IDX      MODULE_IDX_1
#undef TX_ENHANCED_API

#if (TX_CONFIG_XTAL == XTL19_2M) && \
    (TX_CONFIG_DATA_RATE != DR_4_8K) && \
    (TX_CONFIG_DATA_RATE != DR_9_6K) && \
    (TX_CONFIG_DATA_RATE != DR_USER)
#error "XTL19_2M supports only DR_4_8K, DR_9_6K, or DR_USER"
#endif

#if (TX_CONFIG_XTAL == XTL16M) && \
    ((TX_CONFIG_DATA_RATE == DR_4_8K) || \
     (TX_CONFIG_DATA_RATE == DR_9_6K))
#error "DR_4_8K and DR_9_6K require XTL19_2M"
#endif

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
     (TX_CONFIG_DATA_RATE == DR_100K) || (TX_CONFIG_DATA_RATE == DR_4_8K) || \
     (TX_CONFIG_DATA_RATE == DR_9_6K) || (TX_CONFIG_DATA_RATE == DR_USER))
    #error "In OOK mode, only DR_10K, DR_50K, DR_100K, DR_4_8K, DR_9_6K, or DR_USER are supported."
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

void _tx_init_fsk(const uint8_t *rf_tx_table, uint8_t power);
void _turnoff_fs_tpm_en(void);
void _patch_power(uint8_t power);
#endif /* __TRANSFER_H__ */
