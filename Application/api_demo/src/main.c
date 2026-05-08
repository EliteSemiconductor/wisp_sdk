#include <stdint.h>
#include <lint.h>
#include <8051.h>
#include <8052.h>
#include "common.h"
#include "api.h"

uint8_t key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
uint8_t aes_in_buf[16] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F};
uint8_t aes_out_buf[16];
uint8_t mtp_buf[16];
uint8_t trng_seed[16];
uint8_t dma_src[16], dma_dest[16];

void gpio_callback(E_GPIO_PIN pin)
{
    //do something here
    //note : do not print or write to UART in callback function
}

void uart_callback(void)
{
    //do something here
    //note : do not print or write to UART in callback function
}

void timer_callback(void)
{
    //do something here
    //note : do not print or write to UART in callback function
}

//=============================================================
//- This code inside the function is for example purposes only.
//  You may extract parts of it for implementation,
//  but it is not recommended to compile and run it directly.
//=============================================================
void main (void)
{
	//-Initial stack
	SP = 0x20;
	
    //- Global interrupt enable must be present
    EA = 1;

    //------------------------------------------------
    //--------------------- UART ---------------------
    //------------------------------------------------
    //- Set UART baud rate
    // NOTE: This must be present when writing the image to OTP;
    // otherwise, the UART handler cannot be controlled again.
    wisp_api_uart_open(UART_BAUDRATE_38400);

    //- Show Message
    wisp_api_uart_write_string("\nESMT ER8200 API TX Demo\n");
    wisp_api_uart_write_string(wisp_api_get_sdk_string());

    //- Write data to UART TX
    wisp_api_uart_write_byte(0x30);

    //- Read data from UART RX
    uint8_t rbyte;
    int ret = wisp_api_uart_read_byte(&rbyte);
    if (ret == 0) {
        //Read successful
    }

    //- Register UART interrupt callback function
    wisp_api_uart_register_cb((UART_CALLBACK_T)uart_callback);

    //------------------------------------------------
    //--------------------- GPIO ---------------------
    //------------------------------------------------
    //- GPIO clock initialization in ROM code

    //- Get pressed boot key
    uint8_t boot_key;
    wisp_api_gpio_get_boot_key(&boot_key);

    //- Set output type
    wisp_api_gpio_func_sel(GPIO6, GPIO_OUTPUT);

    //- Set output high
    wisp_api_gpio_set_output(GPIO6, GPIO_HIGH);

    //- Set output toggle
    wisp_api_gpio_toggle_output(GPIO6);

    //- Set output type
    wisp_api_gpio_func_sel(GPIO7, GPIO_INPUT);

    //- Get input status
    wisp_api_gpio_get_input(GPIO7, GPIO_INPUT);

    //- Set interrupt type
    wisp_api_gpio_int_enable(GPIO7, GPIO_INT_TYPE_EDGE_FALING);

    //- Set debounce time
    wisp_api_gpio_debs_config(10);

    //- Register interrupt callback function
    wisp_api_gpio_register_cb((GPIO_CALLBACK_T)gpio_callback);

    //------------------------------------------------
    //--------------------- MTP ----------------------
    //------------------------------------------------
    //- Initialize MTP clock
    wisp_api_mtp_init();

    //- Read 16-byte from MTP offset 0    
    wisp_api_mtp_read(0x00, mtp_buf, 16);

    //- Write 16-byte to MTP offset 0x30
    wisp_api_mtp_write(0x30, mtp_buf, 16);

    //- Erase one page(16-byte) at offset 0x10
    wisp_api_mtp_erase(0x10);

    //- Erase whole chip(128-byte)
    wisp_api_mtp_chip_erase();

    //------------------------------------------------
    //--------------------- OTP ----------------------
    //------------------------------------------------
    //- The OTP feature will not be demonstrated here,
    //  since once written it cannot be modified.

    //------------------------------------------------
    //--------------------- COMM ----------------------
    //------------------------------------------------
    //- Print decimal value
    wisp_api_comm_print_itoa(1234);

    //- Print hexadecimal value
    wisp_api_comm_print_xtoa(5678);

    //- Delay 100ms
    wisp_api_comm_delay_ms(100);

    //- Enable periodic timer (500 ms)
    wisp_api_comm_timer_enable(timer_callback, 500, 0);

    //- Enable one-shot (1000 ms)
    wisp_api_comm_timer_enable(timer_callback, 1000, 1);

    //- Enable Watchdog (2000 ms)
    wisp_api_comm_wdt_enable(2000);

    //- In the main loop, call the function to clear the watchdog flag every
    //  2000 ms to prevent a system reset
    //wisp_api_comm_wdt_clear();

    //------------------------------------------------
    //--------------------- AES ----------------------
    //------------------------------------------------
    //- Initialize AES clock
    wisp_api_aes_init();

    //- Set AES mode, do not change the mode value
    wisp_api_aes_set_mode(AES_MODE_PARA);

    //- Set 16-bytes of AES key    
    wisp_api_aes_set_key(key);

    //- AES encryption 16-byte    
    wisp_api_aes_encrypt(aes_in_buf, aes_out_buf, 16);

    //- AES decryption 16-byte
    wisp_api_aes_decrypt(aes_in_buf, aes_out_buf, 16);

    //------------------------------------------------
    //--------------------- TRNG ---------------------
    //------------------------------------------------
    //- Initialize TRNG clock
    wisp_api_trng_init();

    //- Set TRNG mode, sample number must not be less than 100
    wisp_api_trng_set_mode(TRNG_ENTROPY_SHORTEST_INVERTER, 100);

    //- Enable TRNG engine
    wisp_api_trng_enable();

    //- Get 16-byte TRNG seed and print    
    wisp_api_trng_generate(trng_seed, 16);

    //- Continue getting 16-byte TRNG seed and print
    wisp_api_trng_generate(trng_seed, 16);

    while (1) {
        _nop_();
    }
}
