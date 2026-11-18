#include <stdint.h>
#include <lint.h>
#include <8051.h>
#include <8052.h>
#include "common.h"
#include "api.h"

void uart_callback(void)
{
    /* Do not print or write to UART from this callback. */
}

void main(void)
{
    uint8_t received_byte;

    SP = 0x20;
    EA = 1;

    /* Set a baud rate before writing an image to OTP so the UART handler
     * remains accessible. */
    wisp_api_uart_open(UART_BAUDRATE_38400);
    wisp_api_uart_write_string("\nESMT ER8200 UART Demo\n");
    wisp_api_uart_write_string(wisp_api_get_sdk_string());
    wisp_api_uart_write_byte(0x30);

    if (wisp_api_uart_read_byte(&received_byte) == 0) {
        wisp_api_uart_write_byte(received_byte);
    }
    wisp_api_uart_register_cb((UART_CALLBACK_T)uart_callback);

    while (1) {
        _nop_();
    }
}
