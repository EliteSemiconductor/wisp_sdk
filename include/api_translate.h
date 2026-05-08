#ifndef __API_TRANSLATE_H__
#define __API_TRANSLATE_H__

#include <stdint.h>

// ====================== UART ======================
#define UART_OPEN_ADDR              ((void (*)(uint32_t))0x23F0)
#define UART_WRITE_BYTE_ADDR        ((void (*)(uint8_t))0x2535)
#define UART_READ_BYTE_ADDR         ((int8_t (*)(uint8_t *))0x2544)
#define UART_WRITE_STRING_ADDR      ((void (*)(const uint8_t *))0x257F)
#define UART_SET_OUTPUT_PIN_ADDR    ((void (*)(E_GPIO_PIN, E_GPIO_PIN))0x2499)
#define UART_REGISTER_CB_ADDR       ((void (*)(void (*)(void)))0x25FE)
#define UART_CONSOLE_HANDLER_ADDR   ((void (*)(void))0x2CB8)

// ====================== GPIO ======================
#define GPIO_GET_BOOT_KEY_ADDR      ((void (*)(uint8_t *))0x0744)
#define GPIO_FUNC_SEL_ADDR          ((void (*)(E_GPIO_PIN, E_GPIO_MODE))0x0FDA)
#define GPIO_SET_OUTPUT_ADDR        ((void (*)(E_GPIO_PIN, E_GPIO_LEVEL))0x0EAA)
#define GPIO_TOGGLE_OUTPUT_ADDR     ((void (*)(E_GPIO_PIN))0x1012)
#define GPIO_GET_INPUT_ADDR         ((void (*)(E_GPIO_PIN, uint8_t *))0x0F1A)
#define GPIO_INT_ENABLE_ADDR        ((void (*)(E_GPIO_PIN, E_GPIO_INT_TYPE))0x104F)
#define GPIO_INT_DISABLE_ADDR       ((void (*)(E_GPIO_PIN, E_GPIO_INT_TYPE))0x10E3)
#define GPIO_DEBS_CONFIG_ADDR       ((void (*)(uint8_t))0x1100)
#define GPIO_REGISTER_CB_ADDR       ((void (*)(void (*)(E_GPIO_PIN)))0x2618)

// ====================== COMM ======================
#define PRINT_ITOA_ADDR             ((void (*)(int32_t))0x053D)
#define PRINT_XTOA_ADDR             ((void (*)(uint32_t))0x0600)
#define DELAY_MS_ADDR               ((void (*)(uint16_t))0x2007)
#define SET_UART_MODE_ADDR          ((void (*)(uint8_t))0x073C)
#define TIMER_ENABLE_ADDR           ((void (*)(void (*)(void), uint32_t, uint8_t))0x206E)
#define TIMER_DISABLE_ADDR          ((void (*)(void))0x20F4)
#define WDT_ENABLE_ADDR             ((void (*)(uint16_t))0x25AA)
#define WDT_DISABLE_ADDR            ((void (*)(void))0x25F3)
#define WDT_CLEAR_ADDR              ((void (*)(void))0x25F7)
#define MCP_SLEEP_ADDR              ((void (*)(void))0x0757)

// ====================== DMA ======================
#define DMA_START_ADDR              ((void (*)(ST_DMA_PRAM_T *))0x0765)
#define DMA_MEMCPY_ADDR             ((void (*)(uint8_t *, uint8_t *, uint16_t))0x0B87)
#define DMA_REGISTER_CB_ADDR        ((void (*)(void (*)(void)))0x260B)

// ====================== MTP ======================
#define MTP_INIT_ADDR               ((void (*)(void))0x1BED)
#define MTP_READ_ADDR               ((void (*)(uint8_t, uint8_t *, uint8_t))0x1952)
#define MTP_WRITE_ADDR              ((void (*)(uint8_t, const uint8_t *, uint8_t))0x19ED)
#define MTP_ERASE_ADDR              ((void (*)(uint8_t))0x18C3)
#define MTP_CHIP_ERASE_ADDR         ((void (*)(void))0x18F8)

// ====================== OTP ======================
#define OTP_INIT_ADDR               ((void (*)(void))0x1D71)
#define OTP_READ_ADDR               ((void (*)(uint16_t, uint8_t *, uint16_t))0x1C3D)
#define OTP_WRITE_ADDR              ((void (*)(uint16_t, const uint8_t *, uint16_t))0x1CD6)

// ====================== AES ======================
#define AES_INIT_ADDR               ((void (*)(void))0x035E)
#define AES_START_ADDR              ((void (*)(void))0x037D)
#define AES_SET_MODE_ADDR           ((void (*)(uint8_t))0x041D)
#define AES_SET_KEY_ADDR            ((void (*)(const uint8_t *))0x0425)
#define AES_ENCRYPT_ADDR            ((void (*)(const uint8_t *, uint8_t *, uint16_t))0x04C9)
#define AES_DECRYPT_ADDR            ((void (*)(const uint8_t *, uint8_t *, uint16_t))0x0503)

// ====================== TRNG ======================
#define TRNG_INIT_ADDR              ((void (*)(void))0x2147)
#define TRNG_SET_MODE_ADDR          ((void (*)(E_TRNG_ENTROPY_LENGTH, uint16_t))0x2167)
#define TRNG_GENERATE_ADDR          ((void (*)(uint8_t *, uint16_t))0x2226)
#define TRNG_ENABLE_ADDR            ((void (*)(void))0x2309)
#define TRNG_DISABLE_ADDR           ((void (*)(void))0x2341)

// ====================== MAC ======================
#define MAC_INIT_ADDR               ((void (*)(void))0x1175)
#define MAC_TX_INIT_FSK_ADDR        ((void (*)(const uint8_t *, uint8_t))0x14F8)
#define MAC_TX_INIT_OOK_ADDR        ((void (*)(const uint8_t *, const uint8_t *))0x16F0)
#define MAC_TX_START_ADDR           ((void (*)(uint16_t, const uint8_t *, uint8_t))0x1193)
#define MAC_TX_RESTART_ADDR         ((void (*)(void))0x120D)
#define MAC_SET_PREAMBLE_ADDR       ((void (*)(uint8_t, uint8_t, int8_t))0x1220)
#define MAC_SET_SYNCWORD_ADDR       ((void (*)(uint8_t, const uint8_t *, int8_t))0x12B3)
#define MAC_ENABLE_PHR_ADDR         ((void (*)(uint8_t, uint8_t))0x137E)
#define MAC_ENABLE_CRC_ADDR         ((void (*)(uint8_t, uint8_t))0x13AF)
#define MAC_CRC_POLY_SEED_ADDR      ((void (*)(uint16_t, uint16_t))0x13EB)
#define MAC_CRC_ENDIAN_ADDR         ((void (*)(uint8_t, uint8_t, uint8_t))0x141E)
#define MAC_SET_TX_ISR_FLAG_ADDR    ((void (*)(uint8_t))0x1166)
#define MAC_WAIT_TX_FINISH_ADDR     ((void (*)(void))0x116E)
#define MAC_REGISTER_CB_ADDR        ((void (*)(void (*)(void)))0x2625)
#define MAC_REGISTER_PATCH_ADDR     ((void (*)(void (*)(void)))0x2632)

#endif
