#include <stdint.h>
#include <lint.h>
#include <8051.h>
#include <8052.h>
#include "common.h"
#include "api.h"

uint8_t otp_buf[16];

void main(void)
{
    uint8_t i;

    SP = 0x20;
    EA = 1;

    wisp_api_uart_open(UART_BAUDRATE_38400);
    wisp_api_otp_init();
    wisp_api_otp_read(0x0000, otp_buf, 16);

    wisp_api_uart_write_string("\r\nOTP 0x0000: ");
    for (i = 0; i < 16; ++i) {
        wisp_api_comm_print_xtoa(otp_buf[i]);
        wisp_api_uart_write_byte(' ');
    }
    wisp_api_uart_write_string("\r\n");

    /* OTP programming is irreversible. Only enable a write after checking
     * the address and data for the target device. */
    /* wisp_api_otp_write(0x0000, otp_buf, 16); */

    while (1) {
        _nop_();
    }
}
