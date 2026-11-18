#include <stdint.h>
#include <lint.h>
#include <8051.h>
#include <8052.h>
#include "common.h"
#include "api.h"

void gpio_callback(E_GPIO_PIN pin)
{
    /* Handle the pin here. Do not print or write to UART in this callback. */
    (void)pin;
}

void main(void)
{
    uint8_t boot_key;
    uint8_t input_level;

    SP = 0x20;
    EA = 1;

    /* GPIO clock is initialized by ROM code. */
    wisp_api_gpio_get_boot_key(&boot_key);
    wisp_api_gpio_func_sel(GPIO6, GPIO_OUTPUT);
    wisp_api_gpio_set_output(GPIO6, GPIO_HIGH);
    wisp_api_gpio_toggle_output(GPIO6);

    wisp_api_gpio_func_sel(GPIO7, GPIO_INPUT);
    wisp_api_gpio_get_input(GPIO7, &input_level);
    wisp_api_gpio_int_enable(GPIO7, GPIO_INT_TYPE_EDGE_FALING);
    wisp_api_gpio_debs_config(10);
    wisp_api_gpio_register_cb((GPIO_CALLBACK_T)gpio_callback);

    while (1) {
        _nop_();
    }
}
