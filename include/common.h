#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>

//#define MTP_QUICK_WRITE

#define _nop_()                 __asm nop __endasm

#define AES_ENCRYPT             (0  << 0)
#define AES_DECRYPT             (1  << 0)

#define AES_KEY_SIZE_128B       (0 << 1)
#define AES_MODE_ECB            (0 << 3)
#define AES_KEY_SRC_CSR         (1 << 6)
#define AES_MODE_PARA           (AES_KEY_SIZE_128B | AES_MODE_ECB | AES_KEY_SRC_CSR)


/**
 * @brief Enumeration for GPIO modes.
 *        GPIO can be configured as input or output.
 */
typedef enum {
    GPIO_INPUT = 0,
    GPIO_OUTPUT
} E_GPIO_MODE;

/**
 * @brief Enumeration for GPIO output levels.
 *        Used to set or read logical level on a GPIO pin.
 */
typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH
} E_GPIO_LEVEL;

/**
 * @brief Enumeration for GPIO interrupt types.
 *        Describes the trigger condition for GPIO interrupts.
 */
typedef enum {
    GPIO_INT_TYPE_LEVEL_LOW = 0,
    GPIO_INT_TYPE_LEVEL_HIGH,
    GPIO_INT_TYPE_LEVEL_BOTH,
    GPIO_INT_TYPE_EDGE_FALING,
    GPIO_INT_TYPE_EDGE_RISING,
    GPIO_INT_TYPE_EDGE_BOTH
} E_GPIO_INT_TYPE;

/**
 * @brief Enumeration for GPIO pins.
 *        List of all available GPIO pin identifiers.
 */
typedef enum {
    GPIO0 = 0,
    GPIO1,
    GPIO2,
    GPIO3,
    GPIO4,
    GPIO5,
    GPIO6,
    GPIO7
} E_GPIO_PIN;

/**
 * @brief Enumeration for TRNG entropy source configuration.
 *        Different inverter chain lengths to control entropy quality.
 */
typedef enum {
    TRNG_ENTROPY_SHORTEST_INVERTER = 0,
    TRNG_ENTROPY_SHORT_INVERTER,
    TRNG_ENTROPY_LONG_INVERTER,
    TRNG_ENTROPY_LONGEST_INVERTER
} E_TRNG_ENTROPY_LENGTH;

/**
 * @brief Enumeration for UART baud rate settings.
 *        Used to configure the speed of UART communication.
 */
typedef enum {
    UART_BAUDRATE_9600 = 9600,
    UART_BAUDRATE_19200 = 19200,
    UART_BAUDRATE_38400 = 38400
} E_UART_BAUDRATE;

/**
 * @brief Enumeration for available hardware timers.
 */
typedef enum {
    TIMER0 = 0,
    TIMER1
} E_TIMER_T;

/**
 * @brief Enumeration for DMA channels.
 */
typedef enum {
    DMA0 = 0,
    DMA1
} E_DMA_CHAN_T;

/**
 * @brief Enumeration for DMA transfer types.
 *        Specifies the type of DMA transaction.
 */
typedef enum {
    M2M = 0,
    EXM2M,
    P2M
} E_DMA_TYPE_T;

/**
 * @brief Enumeration for DMA peripheral index.
 *        Indicates the source/destination peripheral of the DMA.
 */
typedef enum {
    IDX_MAC_TX = 0,
    IDX_MAC_RX,
    IDX_AES_IN,
    IDX_AES_OUT,
    IDX_AES_AUTH_IN,
    IDX_SHA_IN,
    IDX_NONE     /**< No peripheral (general purpose memory transfer) */
} E_DMA_PERI_IDX_T;

/**
 * @brief Structure for DMA parameters.
 *        Defines all necessary settings for a DMA transfer.
 */
typedef struct {
    E_DMA_CHAN_T channel;
    E_DMA_TYPE_T type;
    E_DMA_PERI_IDX_T idx;
    uint16_t src_addr;
    uint16_t dest_addr;
    uint16_t len;
} ST_DMA_PRAM_T;

typedef void (*UART_CALLBACK_T)(void);
typedef void (*DMA_CALLBACK_T)(void);
typedef void (*GPIO_CALLBACK_T)(E_GPIO_PIN pin);
typedef void (*MAC_TX_CALLBACK_T)(void);
typedef void (*MAC_TX_PATCH_T)(void);
#endif
