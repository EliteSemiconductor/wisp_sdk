#include <stdint.h>
#include <lint.h>
#include <8051.h>
#include <8052.h>
#include "common.h"
#include "api.h"

void main(void)
{
    SP = 0x20;
    EA = 1;

    wisp_api_uart_open(UART_BAUDRATE_38400);
    wisp_api_uart_write_string("\nESMT ER8200 WDT Demo\n");

    /* The watchdog resets the MCU if it is not cleared within 2000 ms. */
    wisp_api_comm_wdt_enable(2000);

    while (1) {
        wisp_api_comm_delay_ms(1000);
        wisp_api_comm_wdt_clear();
        wisp_api_uart_write_string("\nSystem is alive\n");
        /* Comment out the clear call above to observe a watchdog reset. */
    }
}
