#include <stdint.h>
#include <lint.h>
#include <8051.h>
#include <8052.h>
#include "common.h"
#include "api.h"

void timer_callback(void)
{
    /* Do not print or write to UART from this callback. */
}

void main(void)
{
    SP = 0x20;
    EA = 1;

    wisp_api_uart_open(UART_BAUDRATE_38400);
    wisp_api_comm_print_itoa(1234);
    wisp_api_comm_print_xtoa(5678);
    wisp_api_comm_delay_ms(100);

    /* Timer period is specified in microseconds. */
    wisp_api_comm_timer_enable(timer_callback, 500, 0);
    /* To use a one-shot timer instead: */
    /* wisp_api_comm_timer_enable(timer_callback, 1000, 1); */

    while (1) {
        _nop_();
    }
}
