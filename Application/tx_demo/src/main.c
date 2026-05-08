#include <stdint.h>
#include <lint.h>
#include <8051.h>
#include <8052.h>
#include "api.h"
#include "common.h"

#define TX_DATA_LEN         0x10
uint8_t tx_data_buf[TX_DATA_LEN];

#if TX_CONFIG_MOD_TYPE == MODE_OOK
extern const uint8_t rf_tx_table[];
extern const uint8_t rf_tx_ramp_table[];
#else
extern const uint8_t rf_tx_table[];
extern const uint8_t power_tbl[];
extern const uint8_t rf_tx_bit_rate_table[];
#endif

extern void patch_4dBm(void);
extern void patch_10dBm(void);

void mac_tx_callback(void)
{
    wisp_api_tx_restart();
}

//=============================================================
//- This function initializes the core logic. Please refer to
//- transfer.h for the definitions of various TX data used
//- throughout the process.
//=============================================================
void main (void)
{
    //- Initial stack
    SP = 0x20;

    //- Global interrupt enable must be present
    EA = 1;

    //- Set UART baud rate
    wisp_api_uart_open(UART_BAUDRATE_38400);

    //- Show Message
    // NOTE: Do not print anything when running in release mode
    wisp_api_uart_write_string("\nESMT ER8200 RF TX Demo\n");
    wisp_api_uart_write_string(wisp_api_get_sdk_string());

    //- [Option], MTP read transmit data from MTP offset 0x00
    wisp_api_mtp_init();
    wisp_api_mtp_read(0, tx_data_buf, TX_DATA_LEN);

#if TX_CONFIG_MOD_TYPE == MODE_OOK
    // NOTE: Currently supports only 4dBm and 10dBm patch functions
    //       Must be called before the init function
    wisp_api_mac_register_patch((MAC_TX_PATCH_T)patch_10dBm);

    //- Initial TX setting
    wisp_api_tx_init_ook(rf_tx_table, rf_tx_ramp_table);
#else
    // NOTE: Currently supports only 4dBm and 10dBm patch functions
    //       Must be called before the init function
    wisp_api_mac_register_patch((MAC_TX_PATCH_T)patch_10dBm);

    //- Initial TX setting
    wisp_api_tx_init_fsk(rf_tx_table, power_tbl[TX_CONFIG_POWER]);
#endif

    //- Set preamble with bit reverse
    wisp_api_tx_set_preamble(2, 0xAA, 1);

    //- Set syncword with bit reverse
    uint8_t sw_data[] = {0x8e, 0x89, 0xbe, 0xd6};
    wisp_api_tx_set_syncword(4, sw_data, 1);

    //- [Option], Enable packet header 2 byte length, include CRC length
    wisp_api_tx_enable_phr(2, 1);

    //- [Option], Enable CRC 16bits, CRC exclude header
    wisp_api_tx_enable_crc(16, 0);

    //- Register callback function to mac tx finished
    wisp_api_mac_register_cb(mac_tx_callback);

    //- Tx Start
    wisp_api_tx_start(TX_DATA_LEN, tx_data_buf, TX_NONE_BLOCKED);

    while (1) {
        _nop_();
    }
}
