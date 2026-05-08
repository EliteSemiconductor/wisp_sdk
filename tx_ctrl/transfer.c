#include "tonki_soc.h"
#include "common.h"
#include "an_ctl.h"
#include "mac.h"
#include "ana_aon.h"
#include "dma_ctrl.h"
#include "pcrmu.h"
#include "transfer.h"
#include "api_translate.h"

#ifdef TX_ENHANCED_API
extern const uint8_t rf_tx_table[];
extern const uint8_t power_tbl[];
extern const uint8_t rf_tx_bit_rate_table[];

ST_DMA_PRAM_T dma_comm;

uint8_t _bit_reverse8(uint8_t v)
{
    v = (v >> 4) | (v << 4);
    v = ((v & 0xCC) >> 2) | ((v & 0x33) << 2);
    v = ((v & 0xAA) >> 1) | ((v & 0x55) << 1);

    return v;
}

void _tx_sx_config(void)
{
    // - Power on modules
    ANCTL->SX_REG.SX_CONFIG_8_b.FS_FREQSYNTH_PD = 0;
    ANCTL->SX_REG.SX_CONFIG_34_b.FS_VCO_LDO_PD = 0;
    ANCTL->SX_REG.SX_CONFIG_9_b.FS_HF_LDO_PD = 0;
    ANCTL->SX_REG.SX_CONFIG_4_b.FS_ANG_LDO_PD = 0;
    ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ONES_0 = 0xF7;
}

extern void patch_4dBm(void);
extern void patch_10dBm(void);
void wisp_api_tx_manual(uint8_t len, const uint8_t *tx_data, int8_t revs_flag)
{
    PCRMU->BLK_CLK_REG_b.MODEM_CLK_EN = 1;

    _tx_sx_config();

    //- Anctl Setup
    ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ZEROS_0 = rf_tx_table[TX_TIMING_BAND_SEL_IDX];

    //- HB Frequency
    ANCTL->SX_REG.SX_CONFIG_19_b.FS_TPMCAL_DIV_INT_HB = rf_tx_table[TX_TIMING_HB_DIVINT_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_HB_0 = rf_tx_table[TX_TIMING_HB_DIVFRAC0_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_HB_1 = rf_tx_table[TX_TIMING_HB_DIVFRAC1_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_HB_2 = rf_tx_table[TX_TIMING_HB_DIVFRAC2_IDX];

    //- LB Frequency
    ANCTL->SX_REG.FS_TPMCAL_DIV_INT_LB = rf_tx_table[TX_TIMING_LB_DIVINT_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_LB_0 = rf_tx_table[TX_TIMING_LB_DIVFRAC0_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_LB_1 = rf_tx_table[TX_TIMING_LB_DIVFRAC1_IDX];
    ANCTL->SX_REG.SX_CONFIG_19_b.FS_TPMCAL_DIV_FRAC_LB_2 = rf_tx_table[TX_TIMING_LB_DIVFRAC2_IDX];

    // - Enable TX IQ buffer
    ANCTL->SX_REG.SX_CONFIG_31_b.FS_TX_EN = 1;

    //- Time setting
    ANCTL->ANCTL_REG.ANCTL_CONFIG_6_0 = 0x05;

    ANCTL->ANCTL_REG.ANCTL_FS_REG0_1 = 7;

    //- TPM
    ANCTL->SX_REG.TPM_DMI_FS_PARM_0 = rf_tx_table[TX_TIMING_FS_PARM0_IDX];
    ANCTL->SX_REG.TPM_DMI_FS_PARM_1 = rf_tx_table[TX_TIMING_FS_PARM1_IDX];
    ANCTL->SX_REG.TPM_DMI_CONFIG_3_b.TPM_DMI_FS_PARM_2 = 0;

    //- Settle time
    ANCTL->SX_REG.SX_CONFIG_1 = 0x3F;
    ANCTL->SX_REG.FS_AFC_SETTLING_CYCLE_1 = 1;
    ANCTL->SX_REG.FS_AFC_SETTLING_CYCLE_2 = 0;

    //- PA parameter
    ANCTL->PA_REG.PA_CONFIG_0 = 0x03;
    ANCTL->PA_REG.PA_CONFIG_1_b.PA_PWR = power_tbl[TX_CONFIG_POWER];
    ANCTL->PA_REG.PA_CONFIG_1_b.PA_DUTY_SEL = 6;
    ANCTL->PA_REG.PA_CONFIG_2 = 0x4E;

    //- Patch dB function by 4dB or 10dB
    patch_4dBm();
    //patch_10dBm();

    ANCTL->ANCTL_REG.ANCTL_TX_BIT_RATE_0 = rf_tx_bit_rate_table[0];
    ANCTL->ANCTL_REG.ANCTL_TX_BIT_RATE_1 = rf_tx_bit_rate_table[1];
    ANCTL->ANCTL_REG.ANCTL_TX_BIT_RATE_2 = rf_tx_bit_rate_table[2];

    //- Setup TX freq/mod
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_0_b.ANCTL_TX_MOD  = ANCTL_TX_MOD_FSK;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_2_b.ANCTL_TPM_CAL_EN  = 0;

    //- Disable FS write back
    ANCTL->ANCTL_REG.ANCTL_WB_REG0_0_b.ANCTL_DIS_FS_TX_WB = 1;

    //- TX default value
    ANCTL->ANCTL_REG.ANCTL_CONFIG_3_1_b.ANCTL_TX_RUW4DAT = 0;

    //- Manual mode
    ANCTL->ANCTL_REG.ANCTL_CONFIG_0_0_b.ANCTL_SEL_CTL = 0;

    ANCTL->SX_REG.SX_CONFIG_4_b.FS_CP_ICTRL = 7;
    ANCTL->SX_REG.SX_CONFIG_11_b.FS_LF_BW_MODE = 1;

    ANCTL->ASARADC_REG.ASARADC_CONFIG_4_b.ASARADC_DAF_AVG_SHIFT_N = 8;
    ANCTL->ASARADC_REG.ASARADC_CONFIG_3_b.ASARADC_PD = 0;
    ANCTL->SX_REG.SX_CONFIG_34_b.FS_VCO_STARTER_CTRL = 0;

    volatile uint8_t *ptr = (volatile uint8_t *)&ANCTL->ANCTL_REG.ANCTL_TX_DAT0_0;
    for (int i = 0; i < len; i++) {
        if (revs_flag) {
            ptr[i] = _bit_reverse8(tx_data[i]);
        }
        else {
           ptr[i] = tx_data[i];
       }
    }

    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_2_b.ANCTL_TX_REP = 1;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_1_b.ANCTL_TX_LEN = (len << 3) - 1;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_0_b.ANCTL_TX_EN = 1;
}

void wisp_api_crc_standalone(uint16_t data_len, const uint8_t *data, uint16_t *crc_out)
{
    MAC_INIT_ADDR();

    //- DMA Setup
    dma_comm.channel = DMA0;
    dma_comm.src_addr = (uint16_t)data;
    dma_comm.len = data_len;
    dma_comm.type = P2M;
    dma_comm.idx = IDX_MAC_TX;
    DMA_START_ADDR(&dma_comm);

    //- Enable CRC and set CRC length
    MAC->MAC_TXLEN_CRC0 = (uint8_t)(data_len >> 0 );
    MAC->MAC_TXLEN_CRC1 = (uint8_t)(data_len >> 8 );
    MAC->MAC_CRC_STANDALONE_EN = 1; //- Should be enabled after DMA configuration is completed

    //- Wait CRC finished
    while (MAC->MAC_CRC_STANDALONE_EN);

    uint16_t crc_val = MAC->MAC_TX_CRC_OUTPUT3 | (MAC->MAC_TX_CRC_OUTPUT2 << 8);
    uint8_t crc_bits = MAC->MAC_CRC_REG_B3_b.MAC_CRC_BIT;

    if (crc_bits < 16) {
        *crc_out = crc_val & ((1U << crc_bits) - 1);
    } else {
        *crc_out = crc_val;
    }
}

void wisp_api_tx_single_tone(uint8_t power_level)
{
    _tx_sx_config();

    //- Anctl Setup
    ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ZEROS_0 = rf_tx_table[TX_TIMING_BAND_SEL_IDX];

    //- LO Frequency
    ANCTL->SX_REG.SX_CONFIG_7_b.FS_DIV_INT_0 = rf_tx_table[TX_TIMING_LO_DIVINT0_IDX];
    ANCTL->SX_REG.SX_CONFIG_8_b.FS_DIV_INT_1 = rf_tx_table[TX_TIMING_LO_DIVINT1_IDX];
    ANCTL->SX_REG.SX_CONFIG_5_b.FS_DIV_FRAC_0 = rf_tx_table[TX_TIMING_LO_DIVFRAC0_IDX];
    ANCTL->SX_REG.FS_DIV_FRAC_1 = rf_tx_table[TX_TIMING_LO_DIVFRAC1_IDX];
    ANCTL->SX_REG.SX_CONFIG_7_b.FS_DIV_FRAC_2 = rf_tx_table[TX_TIMING_LO_DIVFRAC2_IDX];

    //- PA parameter
    ANCTL->PA_REG.PA_CONFIG_0 = 0x03;
    ANCTL->PA_REG.PA_CONFIG_1_b.PA_PWR = (power_level > 27)? 27 : power_level;
    ANCTL->PA_REG.PA_CONFIG_1_b.PA_DUTY_SEL = 6;
    ANCTL->PA_REG.PA_CONFIG_2 = 0x4E;

    ANCTL->SX_REG.SX_CONFIG_4_b.FS_CP_ICTRL = 7;

    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_0_b.ANCTL_TX_EN = 1;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_2_b.ANCTL_TX_REP = 1;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_3_b.ANCTL_SINGLE_EN = 1;
    ANCTL->SX_REG.SX_CONFIG_31_b.FS_TX_EN = 1;
}

#endif
