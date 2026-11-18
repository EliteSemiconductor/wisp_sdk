#include <stdint.h>
#include <lint.h>
#include <8051.h>
#include <8052.h>
#include "common.h"
#include "api.h"

uint8_t key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                   0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
uint8_t aes_in_buf[16] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
                          0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F};
uint8_t aes_out_buf[16];
uint8_t aes_decrypted_buf[16];

void main(void)
{
    uint8_t i;

    SP = 0x20;
    EA = 1;

    wisp_api_uart_open(UART_BAUDRATE_38400);

    wisp_api_aes_init();
    wisp_api_aes_set_mode(AES_MODE_PARA);
    wisp_api_aes_set_key(key);
    wisp_api_aes_encrypt(aes_in_buf, aes_out_buf, 16);
    wisp_api_aes_decrypt(aes_out_buf, aes_decrypted_buf, 16);

    wisp_api_uart_write_string("\r\nAES original: ");
    for (i = 0; i < 16; ++i) {
        wisp_api_comm_print_xtoa(aes_in_buf[i]);
        wisp_api_uart_write_byte(' ');
    }
    wisp_api_uart_write_string("\r\n");
    wisp_api_uart_write_string("AES decrypted: ");
    for (i = 0; i < 16; ++i) {
        wisp_api_comm_print_xtoa(aes_decrypted_buf[i]);
        wisp_api_uart_write_byte(' ');
    }
    wisp_api_uart_write_string("\r\n");

    while (1) {
        _nop_();
    }
}
