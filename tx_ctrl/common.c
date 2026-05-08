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

#define VERSION_MAJOR   1
#define VERSION_MINOR   2
#define VERSION_PATCH   0

#define VERSION ((VERSION_MAJOR << 13) | (VERSION_MINOR << 8) | (VERSION_PATCH))

void patch_4dBm(void)
{
    ANCTL->PA_REG.PA_CONFIG_0 = 0x03;
    ANCTL->PA_REG.PA_CONFIG_1 = 0xCA;
    ANCTL->PA_REG.PA_CONFIG_2 = 0x09;
    ANCTL->PA_REG.PA_TX_SUBG_RESERVED = 0;
    ANCTL->SX_REG.SX_CONFIG_9 = 0;

    ANCTL->ANCTL_REG.ANCTL_CONFIG_7_1_b.ANCTL_PWR_CONST = 10;
    ANCTL->ANCTL_REG.ANCTL_FS_REG0_0 = 0;
}

void patch_10dBm(void)
{
    ANCTL->PA_REG.PA_CONFIG_0 = 0x63;
    ANCTL->PA_REG.PA_CONFIG_1 = 0xD1;
    ANCTL->PA_REG.PA_CONFIG_2 = 0x27;
    ANCTL->PA_REG.PA_TX_SUBG_RESERVED = 0;
    ANCTL->SX_REG.SX_CONFIG_9 = 0;

    ANCTL->ANCTL_REG.ANCTL_CONFIG_7_1_b.ANCTL_PWR_CONST = 17;
    ANCTL->ANCTL_REG.ANCTL_FS_REG0_0 = 0;
}

void wisp_api_system_pd(void)
{
    ANA_AON->BIAS_REG.BIAS_CONFIG1_b.BIAS_SYSPWR_EN = 0;
}

void wisp_api_get_sdk_version(uint16_t *version)
{
    *version = VERSION;
}

const char *wisp_api_get_sdk_string(void)
{
    return "SDK Ver: 1.2.0\n";
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
