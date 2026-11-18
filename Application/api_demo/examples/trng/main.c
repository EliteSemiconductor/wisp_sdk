#include <stdint.h>
#include <lint.h>
#include <8051.h>
#include <8052.h>
#include "common.h"
#include "api.h"

uint8_t trng_seed[16];

void main(void)
{
    uint8_t i;

    SP = 0x20;
    EA = 1;

    wisp_api_uart_open(UART_BAUDRATE_38400);

    wisp_api_trng_init();
    /* The sample count must be at least 100. */
    wisp_api_trng_set_mode(TRNG_ENTROPY_SHORTEST_INVERTER, 100);
    wisp_api_trng_enable();
    wisp_api_trng_generate(trng_seed, 16);
    wisp_api_uart_write_string("\r\nTRNG 1: ");
    for (i = 0; i < 16; ++i) {
        wisp_api_comm_print_xtoa(trng_seed[i]);
        wisp_api_uart_write_byte(' ');
    }
    wisp_api_uart_write_string("\r\n");

    wisp_api_trng_generate(trng_seed, 16);
    wisp_api_uart_write_string("TRNG 2: ");
    for (i = 0; i < 16; ++i) {
        wisp_api_comm_print_xtoa(trng_seed[i]);
        wisp_api_uart_write_byte(' ');
    }
    wisp_api_uart_write_string("\r\n");

    while (1) {
        _nop_();
    }
}
