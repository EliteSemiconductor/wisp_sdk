#include "tonki_soc.h"
#include "common.h"
#include "an_ctl.h"
#include "intr.h"
#include "mac.h"
#include "ana_aon.h"
#include "dma_ctrl.h"
#include "pcrmu.h"
#include "transfer.h"
#include "api_translate.h"
#include "api.h"

#if (TX_CONFIG_MOD_TYPE == MODE_FSK)
uint8_t tx_block_flag = 0;

void _turnoff_fs_tpm_en(void)
{
    while (ANCTL->SX_REG.SX_CONFIG_30_b.FS_TPM_EN == 0) {
        // Wait until FS_TPM_EN is set
    }

    ANCTL->SX_REG.SX_CONFIG_30_b.FS_TPM_EN = 0;

    while (ANCTL->SX_REG.SX_CONFIG_30_b.FS_TPM_EN == 1) {
        // Wait until FS_TPM_EN is cleared
    }
}

void wisp_api_tx_init_fsk(const uint8_t *rf_tx_table, uint8_t power)
{
    _tx_init_fsk(rf_tx_table, power);
}
#else
void _band_sel(uint8_t sel)
{
    ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ZEROS_0 = 0;
    ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ONES_0 =
         (ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ONES_0 & ~(1 << 3)) | (sel << 3);
}

void wisp_api_tx_init_ook(const uint8_t *rf_tx_table, const uint8_t *rf_tx_ramp_table)
{
    wisp_api_tx_init_ook_1(rf_tx_table,  rf_tx_ramp_table);
    //fixed band sel issue
    _band_sel(rf_tx_table[TX_TIMING_BAND_SEL_IDX]);
}
#endif

void wisp_api_tx_start(uint16_t tx_len, const uint8_t *tx_data, uint8_t block_flag)
{
    wisp_api_tx_start_1(tx_len, tx_data, block_flag);
#if (TX_CONFIG_DATA_RATE <= DR_333K && TX_CONFIG_MOD_TYPE == MODE_FSK)
    tx_block_flag = block_flag;
    if (tx_block_flag == TX_NONE_BLOCKED) {
        _turnoff_fs_tpm_en();
    }
#endif
}

void wisp_api_tx_restart(void)
{
    wisp_api_tx_restart_1();
#if (TX_CONFIG_DATA_RATE <= DR_333K && TX_CONFIG_MOD_TYPE == MODE_FSK)
    if (tx_block_flag == TX_NONE_BLOCKED) {
        _turnoff_fs_tpm_en();
    }
#endif
}

#if (TX_CONFIG_MOD_TYPE == MODE_FSK)
void _tx_init_fsk(const uint8_t *rf_tx_table, uint8_t power)
{
    //- Disable Tx first
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_0_b.ANCTL_TX_EN = 0;

    //- Time setting
    ANCTL->ANCTL_REG.ANCTL_CONFIG_6_0 = 0x05;
    ANCTL->ANCTL_REG.ANCTL_FS_REG0_1 = 7;

    //- Disable TX TPM calibration
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_2_b.ANCTL_TPM_CAL_EN  = 0;

    //- Disable FS write back
    ANCTL->ANCTL_REG.ANCTL_WB_REG0_0_b.ANCTL_DIS_FS_TX_WB = 1;

    //- Switch to Analog controller
    ANCTL->ANCTL_REG.ANCTL_CONFIG_PD_REG_0 = 0xFF;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_0_0_b.ANCTL_SEL_CTL = 1;  //auto mode//

    ANCTL->SX_REG.SX_CONFIG_4_b.FS_CP_ICTRL = 7;
    ANCTL->SX_REG.SX_CONFIG_11_b.FS_LF_BW_MODE = 1;

    //- Settle time
    ANCTL->SX_REG.SX_CONFIG_1 = 0x3F;
    ANCTL->SX_REG.FS_AFC_SETTLING_CYCLE_1 = 1;
    ANCTL->SX_REG.FS_AFC_SETTLING_CYCLE_2 = 0;

    //- Setup TX Packet CFG
    MAC->MAC_TX_CFG_B0 = 0;
    MAC->MAC_TX_CFG_B1 = 0;
    MAC->MAC_TX_CFG_B2 = 0;
    MAC->MAC_CRC_REG_B2 = 0;

    if (rf_tx_table[TX_TIMING_BAND_SEL_IDX] == 0) {
        ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ONES_0 &= ~(1 << 3);
    }
    else {
        ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ONES_0 |= (1 << 3);
    }

    //- HB Frequency
    ANCTL->SX_REG.SX_CONFIG_19_b.FS_TPMCAL_DIV_INT_HB = rf_tx_table[TX_TIMING_HB_DIVINT_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_HB_0 = rf_tx_table[TX_TIMING_HB_DIVFRAC0_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_HB_1 = rf_tx_table[TX_TIMING_HB_DIVFRAC1_IDX];
    ANCTL->SX_REG.SX_CONFIG_16_b.FS_TPMCAL_DIV_FRAC_HB_2 = rf_tx_table[TX_TIMING_HB_DIVFRAC2_IDX];

    //- LB Frequency
    ANCTL->SX_REG.SX_CONFIG_20_b.FS_TPMCAL_DIV_INT_LB = rf_tx_table[TX_TIMING_LB_DIVINT_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_LB_0 = rf_tx_table[TX_TIMING_LB_DIVFRAC0_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_LB_1 = rf_tx_table[TX_TIMING_LB_DIVFRAC1_IDX];
    ANCTL->SX_REG.SX_CONFIG_19_b.FS_TPMCAL_DIV_FRAC_LB_2 = rf_tx_table[TX_TIMING_LB_DIVFRAC2_IDX];

    //- TPM
    ANCTL->SX_REG.TPM_DMI_FS_PARM_0 = rf_tx_table[TX_TIMING_FS_PARM0_IDX];
    ANCTL->SX_REG.TPM_DMI_FS_PARM_1 = rf_tx_table[TX_TIMING_FS_PARM1_IDX];
    ANCTL->SX_REG.TPM_DMI_CONFIG_3_b.TPM_DMI_FS_PARM_2 = 0;
    ANCTL->SX_REG.TPM_DMI_CONFIG_4 = 0x0A;

    //- POWER Table
    //- Enable Constant PWR
    ANCTL->ANCTL_REG.ANCTL_RAMP_NUM = 0;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_7_1_b.ANCTL_CONST_PWR_EN = 1;
    _patch_power(power);

    //- Setup TX freq/mod
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_0_b.ANCTL_TX_MOD  = ANCTL_TX_MOD_FSK;

    //- MAC init
    PCRMU->DYN_GATED_REG_b.MODEM_DYN_GATED_EN = 1;
    PCRMU->BLK_CLK_REG_b.MODEM_CLK_EN = 1;
    MCU_EnableIRQ(MAC_IRQn);
    MAC->MAC_INT_ST = 0xFF;
    MAC->MAC_INT_EN = 0x0F;

    //- Setup TX datdlv
    MAC->DATDLV_DUAL_PRD0 = rf_tx_table[TX_TIMING_FS_PARM0_IDX];
    MAC->DATDLV_DUAL_PRD1 = rf_tx_table[TX_TIMING_FS_PARM1_IDX];
}

#endif

#if defined(TX_ENHANCED_API) && (TX_CONFIG_MOD_TYPE == MODE_FSK)
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

void wisp_api_tx_manual(uint8_t len, const uint8_t *tx_data, int8_t revs_flag, int8_t rep_flag)
{
    static uint8_t pre_count = 0;

    //- Disable TX first
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_0_b.ANCTL_TX_EN = 0;

    PCRMU->BLK_CLK_REG_b.MODEM_CLK_EN = 1;

    if (rf_tx_table[TX_TIMING_BAND_SEL_IDX] == 0) {
        ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ONES_0 &= ~(1 << 3);
    }
    else {
        ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ONES_0 |= (1 << 3);
    }

    //- HB Frequency
    ANCTL->SX_REG.SX_CONFIG_19_b.FS_TPMCAL_DIV_INT_HB = rf_tx_table[TX_TIMING_HB_DIVINT_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_HB_0 = rf_tx_table[TX_TIMING_HB_DIVFRAC0_IDX];
    ANCTL->SX_REG.FS_TPMCAL_DIV_FRAC_HB_1 = rf_tx_table[TX_TIMING_HB_DIVFRAC1_IDX];
    ANCTL->SX_REG.SX_CONFIG_16_b.FS_TPMCAL_DIV_FRAC_HB_2 = rf_tx_table[TX_TIMING_HB_DIVFRAC2_IDX];

    //- LB Frequency
    ANCTL->SX_REG.SX_CONFIG_20_b.FS_TPMCAL_DIV_INT_LB = rf_tx_table[TX_TIMING_LB_DIVINT_IDX];
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
    _patch_power(power_tbl[TX_CONFIG_POWER]);
    ANCTL->ANCTL_REG.ANCTL_RAMP_NUM = 0x0F;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_7_1_b.ANCTL_CONST_PWR_EN = 1;

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

    //- Anctl control mode - auto
    ANCTL->ANCTL_REG.ANCTL_CONFIG_PD_REG_0 = 0xFF;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_0_0_b.ANCTL_SEL_CTL = 1;

    ANCTL->SX_REG.SX_CONFIG_4_b.FS_CP_ICTRL = 7;
    ANCTL->SX_REG.SX_CONFIG_11_b.FS_LF_BW_MODE = 1;

    ANCTL->ASARADC_REG.ASARADC_CONFIG_4_b.ASARADC_DAF_AVG_SHIFT_N = 8;
    ANCTL->SX_REG.SX_CONFIG_34_b.FS_VCO_STARTER_CTRL = 0;

    volatile uint8_t *ptr = (volatile uint8_t *)&ANCTL->ANCTL_REG.ANCTL_TX_DAT0_0;

    if (len > 16) {
        len = 16;
    }

    for (int i = 0; i < len; i++) {
        if (revs_flag) {
            ptr[i] = _bit_reverse8(tx_data[i]);
        }
        else {
           ptr[i] = tx_data[i];
       }
    }

    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_2_b.ANCTL_TX_REP = rep_flag ? 1 : 0;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_1_b.ANCTL_TX_LEN = (len << 3) - 1;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_0_b.ANCTL_TX_EN = 1;

    if (rep_flag == 0) {
        pre_count = ANCTL->ANCTL_REG.ANCTL_CONFIG_1_3_b.ANCTL_TX_COMPL_CNT;

        _turnoff_fs_tpm_en();

        while(pre_count == ANCTL->ANCTL_REG.ANCTL_CONFIG_1_3_b.ANCTL_TX_COMPL_CNT) {
            //wait TX done
        }

        ANCTL->ANCTL_REG.ANCTL_CONFIG_1_0_b.ANCTL_TX_EN = 0;
    }
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
    //- Power on Synth engine
    ANCTL->SX_REG.SX_CONFIG_8_b.FS_FREQSYNTH_PD = 0;

    if (rf_tx_table[TX_TIMING_BAND_SEL_IDX] == 0) {
        ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ONES_0 &= ~(1 << 3);
    }
    else {
        ANA_AON->PAD_XTAL_GPREG_REG.RW_GPREG_ONES_0 |= (1 << 3);
    }

    //- LO Frequency
    ANCTL->SX_REG.SX_CONFIG_7_b.FS_DIV_INT_0 = rf_tx_table[TX_TIMING_LO_DIVINT0_IDX];
    ANCTL->SX_REG.SX_CONFIG_8_b.FS_DIV_INT_1 = rf_tx_table[TX_TIMING_LO_DIVINT1_IDX];
    ANCTL->SX_REG.SX_CONFIG_5_b.FS_DIV_FRAC_0 = rf_tx_table[TX_TIMING_LO_DIVFRAC0_IDX];
    ANCTL->SX_REG.FS_DIV_FRAC_1 = rf_tx_table[TX_TIMING_LO_DIVFRAC1_IDX];
    ANCTL->SX_REG.SX_CONFIG_7_b.FS_DIV_FRAC_2 = rf_tx_table[TX_TIMING_LO_DIVFRAC2_IDX];

    //- PA parameter
    _patch_power(power_level);
    ANCTL->PA_REG.PA_CONFIG_0_b.PA_EN = 1;
    ANCTL->PA_REG.PA_CONFIG_0_b.PA_EN_RAMP = 0; //single tone must disable it

    ANCTL->SX_REG.SX_CONFIG_4_b.FS_CP_ICTRL = 7;// Reduce sideband noise around the main tone

    //- Anctl control mode - manual
    ANCTL->ANCTL_REG.ANCTL_CONFIG_PD_REG_0 = 0;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_0_0_b.ANCTL_SEL_CTL = 0;

    //- Enable TX IQ buffer
    ANCTL->SX_REG.SX_CONFIG_31_b.FS_TX_EN = 1;

    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_0_b.ANCTL_TX_EN = 1;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_2_b.ANCTL_TX_REP = 1;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_3_b.ANCTL_SINGLE_EN = 1;
}

void wisp_api_tx_single_tone_off(void)
{
    //- Power off Synth engine
    ANCTL->SX_REG.SX_CONFIG_8_b.FS_FREQSYNTH_PD = 1;

    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_2_b.ANCTL_TX_REP = 0;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_3_b.ANCTL_SINGLE_EN = 0;
    ANCTL->ANCTL_REG.ANCTL_CONFIG_1_0_b.ANCTL_TX_EN = 0;
}

#endif
