/******************************************************************************
 * WARNING: HARDWARE-SPECIFIC IMPLEMENTATION
 * * The code below performs direct hardware-level operations. Any unauthorized
 * or incorrect modifications may result in critical system failure or
 * hardware damage.
 * * DO NOT MODIFY THIS FILE.
 ******************************************************************************/

#include "tonki_soc.h"
#include "common.h"
#include "sys_ctrl.h"
#include "pcrmu.h"
#include "transfer.h"
#include "api.h"
#include "an_ctl.h"
#include "ana_aon.h"
#include "api_translate.h"
#include "mtp_ctrl.h"
#include "mac.h"

#define VERSION_MAJOR   1
#define VERSION_MINOR   4
#define VERSION_PATCH   0

#define STRINGIFY(x)       #x
#define TOSTRING(x)        STRINGIFY(x)

#define SDK_VERSION_STR    "SDK Ver: " TOSTRING(VERSION_MAJOR) "." \
                           TOSTRING(VERSION_MINOR) "." \
                           TOSTRING(VERSION_PATCH) "\n"

#define VERSION ((VERSION_MAJOR << 13) | (VERSION_MINOR << 8) | (VERSION_PATCH))

void _patch_power(uint8_t power)
{
#if (TX_CONFIG_FREQENCY == IF433MHZ)
    #if (TX_CONFIG_POWER == POWER_4DBM)
        #if (TX_CONFIG_MOD_TYPE == MODE_FSK)
            ANCTL->PA_REG.PA_CONFIG_0 = 0x06;
        #else   //OOK
            ANCTL->PA_REG.PA_CONFIG_0 = 0x02;
        #endif
            ANCTL->PA_REG.PA_CONFIG_1_b.PA_PWR = power;
            ANCTL->PA_REG.PA_CONFIG_1_b.PA_DUTY_SEL = 6;
            ANCTL->PA_REG.PA_CONFIG_2 = 0x09;
            ANCTL->SX_REG.SX_CONFIG_9 = 0;

            ANCTL->ANCTL_REG.ANCTL_CONFIG_7_1_b.ANCTL_PWR_CONST = power;
            ANCTL->ANCTL_REG.ANCTL_FS_REG0_0 = 0;
    #else   //10DBM
        #if (TX_CONFIG_MOD_TYPE == MODE_FSK)
            ANCTL->PA_REG.PA_CONFIG_0 = 0x66;
        #else   //OOK
            ANCTL->PA_REG.PA_CONFIG_0 = 0x62;
        #endif
            ANCTL->PA_REG.PA_CONFIG_1_b.PA_PWR = power;
            ANCTL->PA_REG.PA_CONFIG_1_b.PA_DUTY_SEL = 6;
            ANCTL->PA_REG.PA_CONFIG_2 = 0x27;
            ANCTL->SX_REG.SX_CONFIG_9 = 0;

            ANCTL->ANCTL_REG.ANCTL_CONFIG_7_1_b.ANCTL_PWR_CONST = power;
            ANCTL->ANCTL_REG.ANCTL_FS_REG0_0 = 0;
    #endif
#else   //IF868MHZ/IF915MHZ
    #if (TX_CONFIG_POWER == POWER_4DBM)
        #if (TX_CONFIG_MOD_TYPE == MODE_FSK)
            ANCTL->PA_REG.PA_CONFIG_0 = 0x06;
        #else   //OOK
            ANCTL->PA_REG.PA_CONFIG_0 = 0x02;
        #endif
            ANCTL->PA_REG.PA_CONFIG_1_b.PA_PWR = power;
            ANCTL->PA_REG.PA_CONFIG_1_b.PA_DUTY_SEL = 2;
            ANCTL->PA_REG.PA_CONFIG_2 = 0x42;
            ANCTL->SX_REG.SX_CONFIG_9 = 0x0C;

            ANCTL->ANCTL_REG.ANCTL_CONFIG_7_1_b.ANCTL_PWR_CONST = power;
            ANCTL->ANCTL_REG.ANCTL_FS_REG0_0 = 0x0C;
    #else   //10DBM
        #if (TX_CONFIG_MOD_TYPE == MODE_FSK)
            ANCTL->PA_REG.PA_CONFIG_0 = 0x06;
        #else   //OOK
            ANCTL->PA_REG.PA_CONFIG_0 = 0x02;
        #endif
            ANCTL->PA_REG.PA_CONFIG_1_b.PA_PWR = power;
            ANCTL->PA_REG.PA_CONFIG_1_b.PA_DUTY_SEL = 2;
            ANCTL->PA_REG.PA_CONFIG_2 = 0x42;
            ANCTL->SX_REG.SX_CONFIG_9 = 0x0C;

            ANCTL->ANCTL_REG.ANCTL_CONFIG_7_1_b.ANCTL_PWR_CONST = power;
            ANCTL->ANCTL_REG.ANCTL_FS_REG0_0 = 0x0C;
    #endif
#endif
}


void wisp_api_system_pd(void)
{
    while(1) {
        ANA_AON->BIAS_REG.BIAS_CONFIG1_b.BIAS_SYSPWR_EN = 0;
        _nop_();
    }
}

void wisp_api_get_sdk_version(uint16_t *version)
{
    *version = VERSION;
}

void wisp_api_set_tx_misc_reverse(uint8_t data_revs_flag, uint8_t hdr_revs_flag)
{
    MAC->MAC_MISC_REG_B0_b.DMA_TX_BIT_REVERSE = data_revs_flag;
    MAC->MAC_TXPHR_REG_B0_b.MAC_TX_PHRINV = hdr_revs_flag;
}

const char *wisp_api_get_sdk_string(void)
{
    return SDK_VERSION_STR;
}

#ifdef MTP_QUICK_WRITE
uint8_t *rom_mtp_buf = (uint8_t __xdata *) 0x5035;
volatile uint8_t *rom_mtp_isr_arrive = (uint8_t __xdata *)0x5018;

void _exec_mtp_cmd(uint8_t cmd)
{
    *rom_mtp_isr_arrive = 0;

    MTPCTL->MTPCTL_CMD = cmd;

    while (*rom_mtp_isr_arrive == 0);
}

void wisp_api_mtp_quick_write(uint8_t write_addr, const uint8_t *write_buf, uint8_t len)
{
    uint8_t idx = 0;
    uint8_t len1;
    uint8_t i;
    uint8_t *ptr = (uint8_t *)&MTPCTL->MTPCTL_DAT;

    if (write_addr + len > 128) {
        return;
    }

    while (len) {
        uint8_t base_addr = write_addr & 0xF0;
        uint8_t offset = write_addr & 0x0F;

        if (offset || len < 16) {
            wisp_api_mtp_read(base_addr, rom_mtp_buf, 16);

            len1 = 16 - offset;
            if (offset == 0) len1 = len;
            if (len1 > len) len1 = len;

            for (i = 0; i < len1; i++) {
                rom_mtp_buf[offset + i] = write_buf[idx + i];
            }
        }
        else {
            len1 = 16;
            for (i = 0; i < 16; i++) {
                rom_mtp_buf[i] = write_buf[idx + i];
            }
        }

        for (i = 0; i < 16; i++) {
            *(ptr+i) = rom_mtp_buf[i];
        }

        _exec_mtp_cmd(14);

        MTPCTL->MTPCTL_ADR = base_addr;
        _exec_mtp_cmd(2);

        _exec_mtp_cmd(17);

        write_addr += len1;
        idx += len1;
        len -= len1;
    }
}
#endif
