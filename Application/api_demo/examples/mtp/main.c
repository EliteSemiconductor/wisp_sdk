#include <stdint.h>
#include <lint.h>
#include <8051.h>
#include <8052.h>
#include "common.h"
#include "api.h"

uint8_t mtp_buf[16];
uint8_t mtp_readback[16];

void main(void)
{
    uint8_t i;

    SP = 0x20;
    EA = 1;

    wisp_api_uart_open(UART_BAUDRATE_38400);

    wisp_api_mtp_init();
    wisp_api_mtp_read(0x00, mtp_buf, 16);
    wisp_api_uart_write_string("\r\nMTP 0x00: ");
    for (i = 0; i < 16; ++i) {
        wisp_api_comm_print_xtoa(mtp_buf[i]);
        wisp_api_uart_write_byte(' ');
    }
    wisp_api_uart_write_string("\r\n");

    wisp_api_mtp_read(0x30, mtp_readback, 16);
    wisp_api_uart_write_string("MTP 0x30 before write: ");
    for (i = 0; i < 16; ++i) {
        wisp_api_comm_print_xtoa(mtp_readback[i]);
        wisp_api_uart_write_byte(' ');
    }
    wisp_api_uart_write_string("\r\n");

    wisp_api_mtp_write(0x30, mtp_buf, 16);
    wisp_api_mtp_read(0x30, mtp_readback, 16);
    wisp_api_uart_write_string("MTP 0x30 after write: ");
    for (i = 0; i < 16; ++i) {
        wisp_api_comm_print_xtoa(mtp_readback[i]);
        wisp_api_uart_write_byte(' ');
    }
    wisp_api_uart_write_string("\r\n");

    /* Optional erase operations are disabled. The chip erase removes all
     * 128 bytes. */
    /* wisp_api_mtp_erase(0x10); */
    /* wisp_api_mtp_chip_erase(); */

    while (1) {
        _nop_();
    }
}
