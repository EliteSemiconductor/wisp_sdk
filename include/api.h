#ifndef __API_H__
#define __API_H__

#include <stdint.h>
#include "transfer.h"
#include "api_translate.h"

/**
 * void wisp_api_uart_open(uint32_t baudrate)
 * @brief Initialize UART with the specified baudrate.
 * @param UART baudrate setting.
 */
#define wisp_api_uart_open UART_OPEN_ADDR

/**
 * void wisp_api_uart_console_handler(void)
 * @brief UART console handler (same as ROM code UART download mode).
 */
#define wisp_api_uart_console_handler UART_CONSOLE_HANDLER_ADDR

/**
 * void uart_set_output_pin(E_GPIO_PIN tx, E_GPIO_PIN rx)
 * @brief Set UART TX and RX GPIO pins.
 * @param tx TX pin.
 * @param rx RX pin.
 */
#define wisp_api_uart_set_output_pin UART_SET_OUTPUT_PIN_ADDR

/**
 * void wisp_api_uart_write_byte(uint8_t byte)
 * @brief Transmit a single byte over UART.
 * @param byte Byte to transmit.
 */
#define wisp_api_uart_write_byte UART_WRITE_BYTE_ADDR

/**
 * int8_t wisp_api_uart_read_byte(uint8_t *outByte)
 * @brief Receive a byte from UART.
 * @param[out] outByte Pointer to received byte.
 * @return 0 : successful, 1 : fail.
 */
#define wisp_api_uart_read_byte UART_READ_BYTE_ADDR

/**
 * void wisp_api_uart_write_string(const uint8_t *str)
 * @brief Transmit a null-terminated string over UART.
 * @param str Pointer to the string.
 */
#define wisp_api_uart_write_string UART_WRITE_STRING_ADDR

/**
 * int wisp_api_uart_register_cb(void (*cb)(void))
 * @brief Register UART callback function.
 * @param cb Callback function pointer.
 * @return 0 : successful, 1 : fail.
 */
#define wisp_api_uart_register_cb UART_REGISTER_CB_ADDR

/**
 * @brief GPIO API
 */
/**
 * void wisp_api_gpio_get_boot_key(uint8_t *key)
 * @brief Reads which key has been pressed at boot sequence.
 * @param[out] key Pointer to store boot key status.
 */
#define wisp_api_gpio_get_boot_key GPIO_GET_BOOT_KEY_ADDR

/**
 * void wisp_api_gpio_func_sel(E_GPIO_PIN pin, E_GPIO_MODE mode)
 * @brief Select GPIO pin function.
 * @param pin GPIO pin number.
 * @param mode Function mode for the pin.
 */
#define wisp_api_gpio_func_sel GPIO_FUNC_SEL_ADDR

/**
 * void wisp_api_gpio_set_output(E_GPIO_PIN pin, E_GPIO_LEVEL out_data)
 * @brief Set GPIO output level.
 * @param pin GPIO pin number.
 * @param out_data Output level (high/low).
 */
#define wisp_api_gpio_set_output GPIO_SET_OUTPUT_ADDR

/**
 * void wisp_api_gpio_toggle_output(E_GPIO_PIN pin)
 * @brief Toggle GPIO output level.
 * @param pin GPIO pin number.
 */
#define wisp_api_gpio_toggle_output GPIO_TOGGLE_OUTPUT_ADDR

/**
 * void wisp_api_gpio_get_input(E_GPIO_PIN pin, uint8_t *in_data)
 * @brief Read input level from a GPIO pin.
 * @param pin GPIO pin number.
 * @param[out] in_data Input level.
 */
#define wisp_api_gpio_get_input GPIO_GET_INPUT_ADDR

/**
 * void wisp_api_gpio_int_enable(E_GPIO_PIN pin, E_GPIO_INT_TYPE type)
 * @brief Enable interrupt for a GPIO pin.
 * @param pin GPIO pin number.
 * @param type Interrupt trigger type.
 */
#define wisp_api_gpio_int_enable GPIO_INT_ENABLE_ADDR

/**
 * void wisp_api_gpio_int_disable(E_GPIO_PIN pin)
 * @brief Disable interrupt for a GPIO pin.
 * @param pin GPIO pin number.
 */
#define wisp_api_gpio_int_disable GPIO_INT_DISABLE_ADDR

/**
 * void wisp_api_gpio_debs_config(uint8_t debs_time)
 * @brief Configure GPIO debounce time.
 * @param debs_time Debounce time in milliseconds.
 */
#define wisp_api_gpio_debs_config GPIO_DEBS_CONFIG_ADDR

/**
 * int wisp_api_gpio_register_cb(void (*cb)(E_GPIO_PIN))
 * @brief Register GPIO interrupt callback.
 * @param cb Callback function with pin info.
 * @return 0 : successful, 1 : fail.
 */
#define wisp_api_gpio_register_cb GPIO_REGISTER_CB_ADDR

/**
 * @brief Common utility API
 */
/**
 * void wisp_api_comm_print_itoa(int32_t n)
 * @brief Print signed integer as string.
 * @param n Signed integer.
 */
#define wisp_api_comm_print_itoa PRINT_ITOA_ADDR

/**
 * void wisp_api_comm_print_xtoa(uint32_t n)
 * @brief Print unsigned integer as hexadecimal string.
 * @param n Unsigned integer.
 */
#define wisp_api_comm_print_xtoa PRINT_XTOA_ADDR

/**
 * void wisp_api_comm_delay_ms(uint16_t ms)
 * @brief Millisecond delay function.
 * @param ms Milliseconds to delay.
 */
#define wisp_api_comm_delay_ms DELAY_MS_ADDR

/**
 * void wisp_api_comm_timer_enable(void (*cb)(void), uint32_t us, uint8_t one_shout)
 * @brief Enables a timer and sets a callback function.
 * @param cb Pointer to the callback function to be called when the timer expires.
 *           The callback function should have the prototype `void cb(void)`.
 * @param us The timer period in microseconds, minimum value is 165.
 *           minimum value is 165. minimum value is 165.
 * @param one_shot If non-zero, the timer will trigger only once (one-shot).
 *                 If zero, the timer will repeat periodically.
 */
#define wisp_api_comm_timer_enable TIMER_ENABLE_ADDR

/**
 * void wisp_api_comm_timer_disable(void)
 * @brief Disables the timer.
 */
#define wisp_api_comm_timer_disable TIMER_DISABLE_ADDR

/**
 * void wisp_api_comm_wdt_enable(uint16_t timeout)
 * @brief Enables the Watchdog Timer (WDT).
 *
 * @param timeout The timeout period of the WDT in milliseconds(at least 4ms)
 */
#define wisp_api_comm_wdt_enable WDT_ENABLE_ADDR

/**
 * void wisp_api_comm_wdt_disable(void)
 * @brief Disables the Watchdog Timer (WDT).
 */
#define wisp_api_comm_wdt_disable WDT_DISABLE_ADDR

/**
 * void wisp_api_comm_wdt_clear(void)
 * @brief Clear the Watchdog Status (WDT).
 */
#define wisp_api_comm_wdt_clear WDT_CLEAR_ADDR

/**
 * void wisp_api_comm_mcu_sleep(void)
 * @brief MCU into sleep mode.
 */
#define wisp_api_comm_mcu_sleep MCP_SLEEP_ADDR

/**
 * @brief Put the system into power-down mode.
 *
 * This function shuts down system operation and woken up by a valid wake-up
 * botton.
 */
void wisp_api_system_pd(void);

/**
 * @brief DMA API
 */
/**
 * void wisp_api_dma_start(ST_DMA_PRAM_T *dma_pram)
 * @brief Start a DMA operation.
 * @param dma_pram Pointer to DMA parameter structure.
 */
#define wisp_api_dma_start DMA_START_ADDR

/**
 * void wisp_api_memcpy_dma(uint8_t *dest, uint8_t *src, uint16_t len)
 * @brief Perform memory copy using DMA.
 * @param dest Destination address.
 * @param src Source address.
 * @param len Number of bytes to copy.
 */
#define wisp_api_dma_memcpy DMA_MEMCPY_ADDR

/**
 * int wisp_api_dma_register_cb(void (*cb)(void))
 * @brief Register DMA completion callback.
 * @param cb Callback function.
 * @return 0 : successful, 1 : fail.
 */
#define wisp_api_dma_register_cb DMA_REGISTER_CB_ADDR

/**
 * @brief MTP memory API
 */
/**
 * void wisp_api_mtp_init(void)
 * @brief Initialize the MTP controller.
 */
#define wisp_api_mtp_init MTP_INIT_ADDR

/**
 * void wisp_api_mtp_read(uint8_t addr, uint8_t *buf, uint8_t len)
 * @brief Read data from MTP memory.
 * @param addr Address offset to read from.
 * @param buf Pointer to buffer to store the read data.
 * @param len Number of bytes to read.
 * @return 0 : successful, 1 : fail.
 */
#define wisp_api_mtp_read MTP_READ_ADDR

/**
 * void wisp_api_mtp_write(uint8_t addr, const uint8_t *buf, uint8_t len)
 * @brief Write data to MTP memory.
 * @param addr Address offset to write to.
 * @param buf Pointer to data to write.
 * @param len Number of bytes to write.
 * @return 0 : successful, 1 : fail.
 */
#define wisp_api_mtp_write MTP_WRITE_ADDR

 /**
  * @brief Write data to MTP memory.
  * @param addr Address offset to write to.
  * @param buf Pointer to data to write.
  * @param len Number of bytes to write.
  * @note This function does not erase the content first; the user should handle it.
  */
 void wisp_api_mtp_quick_write(uint8_t write_addr, const uint8_t *write_buf, uint8_t len);

/**
 * void wisp_api_mtp_erase(uint8_t addr)
 * @brief Erase one page(16bytes) in MTP memory.
 * @param addr to erase.
 */
#define wisp_api_mtp_erase MTP_ERASE_ADDR

/**
 * void wisp_api_mtp_chip_erase(void)
 * @brief Erase the entire MTP memory chip.
 */
#define wisp_api_mtp_chip_erase MTP_CHIP_ERASE_ADDR

/**
 * @brief OTP memory API
 */
/**
 * void wisp_api_otp_init(void)
 * @brief Initialize the OTP memory controller.
 */
#define wisp_api_otp_init OTP_INIT_ADDR

/**
 * void wisp_api_otp_read(uint16_t addr, uint8_t *buf, uint16_t len)
 * @brief Read data from OTP memory.
 * @param addr Address to read from.
 * @param buf Pointer to buffer to store the read data.
 * @param len Number of bytes to read.
 */
#define wisp_api_otp_read OTP_READ_ADDR

/**
 * void wisp_api_otp_write(uint16_t addr, const uint8_t *buf, uint16_t len)
 * @brief Write data to OTP memory.
 * @param addr Address to write to.
 * @param buf Pointer to data to write.
 * @param len Number of bytes to write.
 */
#define wisp_api_otp_write OTP_WRITE_ADDR

/**
 * @brief AES encryption API
 */
/**
 * void wisp_api_aes_init(void)
 * @brief Initialize the AES encryption engine.
 */
#define wisp_api_aes_init AES_INIT_ADDR

/**
 * void wisp_api_aes_set_mode(uint8_t mode)
 * @brief Set the AES encryption mode.
 * @param mode Mode value (typically set to 0).
 */
#define wisp_api_aes_set_mode AES_SET_MODE_ADDR

/**
 * void wisp_api_aes_set_key(const uint8_t *key)
 * @brief Set the AES encryption key(16 bytes).
 * @param key Pointer to the key buffer.
 *
 * @note ex: FIPS 197 Appendix Cipher Example
 *  Cipher Key = 2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c
 *  key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15,
 *           0x88, 0x09, 0xcf, 0x4f, 0x3c}
 */
#define wisp_api_aes_set_key AES_SET_KEY_ADDR

/**
 * void wisp_api_aes_encrypt(const uint8_t *input, uint8_t *output, uint16_t len)
 * @brief Encrypt a buffer using AES.
 * @param input Pointer to plaintext data.
 * @param output Pointer to output buffer for encrypted data.
 * @param len Length of the data to encrypt in bytes.
 */
#define wisp_api_aes_encrypt AES_ENCRYPT_ADDR

/**
 * void wisp_api_aes_decrypt(const uint8_t *input, uint8_t *output, uint16_t len)
 * @brief Decrypt a buffer using AES.
 * @param input Pointer to encrypted data.
 * @param output Pointer to output buffer for decrypted data.
 * @param len Length of the data to decrypt in bytes.
 */
#define wisp_api_aes_decrypt AES_DECRYPT_ADDR

/**
 * @brief TRNG API
 */
/**
 * void wisp_api_trng_init(void)
 * @brief Initialize the TRNG module.
 */
#define wisp_api_trng_init TRNG_INIT_ADDR

/**
 * void wisp_api_trng_set_mode(E_TRNG_ENTROPY_LENGTH len, uint16_t samples)
 * @brief Configure the entropy source and sampling count.
 * @param len Entropy inverter chain length.
 * @param samples Number of sampling iterations.
 */
#define wisp_api_trng_set_mode TRNG_SET_MODE_ADDR

/**
 * void wisp_api_trng_generate(uint8_t *data, uint16_t len)
 * @brief Generate random data.
 * @param data Pointer to buffer to store random data.
 * @param len Number of random bytes to generate.
 */
#define wisp_api_trng_generate TRNG_GENERATE_ADDR

 /**
  * void wisp_api_trng_enable(void)
  * @brief Enable the TRNG generator.
  * @note This function must be called **only once** during the system
  * lifecycle. Repeated calls may result in hardware state errors or undefined
  * behavior.
  */
#define wisp_api_trng_enable TRNG_ENABLE_ADDR

/**
 * @brief Set the preamble for WISP TX.
 *
 * This function configures the preamble pattern used in transmission.
 *
 * @param[in] len   Length of the preamble in bytes, maximum is 48.
 * @param[in] data  Preamble pattern value to be used.
 * @param[in] revs_flag  Flag to indicate whether the preamble should be reversed.
 */
#define wisp_api_tx_set_preamble MAC_SET_PREAMBLE_ADDR

/**
 * @brief Set the sync word for WISP TX.
 *
 * This function configures the synchronization word (sync word)
 * that is transmitted after the preamble and used for packet detection.
 *
 * @param[in] len   Length of the sync word in bytes, maximum is 8.
 * @param[in] data  Pointer to the buffer containing the sync word bytes.
 * @param[in] revs_flag  Flag to indicate whether the sync word should be reversed.
 */
#define wisp_api_tx_set_syncword MAC_SET_SYNCWORD_ADDR

/**
 * @brief  Enable and configure the PHR (PHY Header) for TX.
 *
 * This function enables PHR appending in MAC transmission and allows
 * configuration of the PHR length and whether CRC length is included.
 *
 * @param[in] phr_len             PHR length in bytes (e.g., 1 or 2).
 * @param[in] phr_include_crc_len 1 to include CRC length in PHR, 0 to exclude.
 */
#define wisp_api_tx_enable_phr MAC_ENABLE_PHR_ADDR

/**
 * @brief  Enable and configure the CRC for TX.
 *
 * This function enables CRC appending in MAC transmission and sets
 * the CRC length, polynomial mode, and whether PHR is included in CRC calculation.
 *
 * @param[in] crc_len         CRC length in bits (1~16). Values above 16 are clamped to 16.
 * @param[in] crc_include_phr 1 to include PHR in CRC calculation, 0 to exclude.
 */
#define wisp_api_tx_enable_crc MAC_ENABLE_CRC_ADDR

/**
 * @brief  Enable and configure bit reversal for TX.
 *
 * This function enables bit-order reversal for MAC transmission. It allows
 * independent configuration of the data payload and the protocol header to
 * meet specific PHY requirements.
 *
 * @param[in] data_revs_flag  1 to enable bit reversal for the data payload, 0 to disable.
 * @param[in] hdr_revs_flag   1 to enable bit reversal for the frame header, 0 to disable.
 */
void wisp_api_set_tx_misc_reverse(uint8_t data_revs_flag, uint8_t hdr_revs_flag);

/**
 * @brief  Configure CRC polynomial and initial seed values.
 *
 * This function sets the custom CRC polynomial and seed for the MAC
 * flexible CRC generator.
 *
 * @param[in] crc_poly CRC polynomial value (16-bit).
 * @param[in] crc_seed CRC initial seed value (16-bit).
 */
#define wisp_api_tx_crc_poly_seed MAC_CRC_POLY_SEED_ADDR

/**
 * @brief Configure CRC bit-endian behavior.
 *
 * This function controls the CRC bit-endian settings during transmission.
 * It allows configuration of input bit inversion, output bit inversion,
 * and whether the output CRC is transmitted with MSB-first or LSB-first order.
 *
 * @param[in] in_inverse   Set to 1 to invert input bits before CRC calculation;
 *                         0 to disable inversion.
 * @param[in] out_inverse  Set to 1 to invert CRC result bits before transmission;
 *                         0 to disable inversion.
 * @param[in] out_msb      Set to 1 to output CRC MSB first; 0 to output LSB first.
 *                         MSB/LSB are defined on a per-byte basis.
 *
 * @return None.
 */
#define wisp_api_tx_crc_endian MAC_CRC_ENDIAN_ADDR

/**
 * @brief Initialize the TX configuration for WISP.
 *
 * This function sets up the initial transmit configuration parameters
 * for the WISP module.
 */
#define wisp_api_tx_init_fsk_1 MAC_TX_INIT_FSK_ADDR
void wisp_api_tx_init_fsk(const uint8_t *rf_tx_table, uint8_t power);

/**
 * @brief Initialize the TX configuration for WISP.
 *
 * This function sets up the initial transmit configuration parameters
 * for the WISP module.
 */
#define wisp_api_tx_init_ook_1 MAC_TX_INIT_OOK_ADDR
void wisp_api_tx_init_ook(const uint8_t *rf_tx_table, const uint8_t *rf_tx_ramp_table);

/**
 * @brief Start a WISP transmission.
 *
 * This function starts a WISP transmission with the specified data and length.
 * It initializes the TX process, loads the data into the transmission buffer,
 * and begins sending. The transmission can optionally block until completed.
 *
 * @param[in] tx_len     Length of the data to be transmitted (in bytes).
 * @param[in] tx_data    Pointer to the data buffer to be transmitted.
 * @param[in] block_flag Transmission mode flag:
 *                       - 0: Non-blocking (return immediately)
 *                       - 1: Blocking (wait until transmission finishes)
 */
#define wisp_api_tx_start_1 MAC_TX_START_ADDR
void wisp_api_tx_start(uint16_t tx_len, const uint8_t *tx_data, uint8_t block_flag);

/**
 * @brief Restart the WISP TX (transmission).
 *
 * This function restarts the WISP transmission process.
 * It is typically called after a TX stop or error condition,
 * to reinitialize and resume the transmission operation.
 *
 * @note Make sure that the TX path is properly configured
 *       before calling this function. Should be called in mac callback
 *       function.
 */
#define wisp_api_tx_restart_1 MAC_TX_RESTART_ADDR
void wisp_api_tx_restart(void);

/**
 * int wisp_api_mac_register_cb(void (*cb)(void))
 * @brief Register MAC callback function.
 * @param cb Callback function pointer.
 * @return 0 : successful, 1 : fail.
 */
#define wisp_api_mac_register_cb MAC_REGISTER_CB_ADDR

/**
 * void wisp_api_mac_register_patch(void (*pf)(void))
 * @brief RegisterMAC patch function.
 * @param pf Patch function pointer.
 */
#define wisp_api_mac_register_patch  MAC_REGISTER_PATCH_ADDR

#ifdef TX_ENHANCED_API
/**
 * @brief Transmit a single-tone carrier signal.
 *
 * This function enables the RF transmitter to output a continuous
 * single-tone signal at the specified power level. It is typically
 * used for RF calibration or testing purposes.
 *
 * @note Do not call tx_init and tx_start when calling this function.
 *
 * @param[in] power_level  Output power level (range: 1–27).
 *
 * @return None
 */
void wisp_api_tx_single_tone(uint8_t power_level);

/**
 * @brief Transmit data manually through the RF interface.
 *
 * This function sends the specified data buffer using manual transmission mode.
 * It allows fine control over the transmission process, including optional
 * reversal of bit order or other custom behaviors depending on the hardware design.
 *
 * @note This function is only supported in FSK mode.
 * @note Do not call tx_init and tx_start when calling this function.
 *
 * @param[in] len         Length of the transmission data in bytes, maximum is 16.
 * @param[in] tx_data     Pointer to the data buffer to be transmitted.
 * @param[in] revs_flag   Set to 1 to enable bit reversal mode, or 0 to disable.
 *
 * @return None
 */
void wisp_api_tx_manual(uint8_t len, const uint8_t *tx_data, int8_t revs_flag);

/**
 * @brief Calculate CRC value in standalone mode.
 *
 * This function computes the CRC (Cyclic Redundancy Check) for the given
 * data buffer without requiring any additional transmission or reception
 * process. It can be used to verify data integrity before sending or after
 * receiving.
 *
 * @param[in]  data_len   Length of the input data buffer in bytes.
 * @param[in]  data       Pointer to the input data buffer.
 * @param[out] crc_out    Pointer to the variable that stores the calculated CRC value.
 *
 * @return None
 */
void wisp_api_crc_standalone(uint16_t data_len, const uint8_t *data, uint16_t *crc_out);

/**
 * @brief Transmit a single-tone carrier signal.
 *
 * This function enables the RF transmitter to output a continuous
 * single-tone signal at the specified power level. It is typically
 * used for RF calibration or testing purposes.
 *
 * @note Do not call tx_init and tx_start when calling this function.
 *
 * @param[in] power_level  Output power level (range: 1–27).
 *
 * @return None
 */
void wisp_api_tx_single_tone(uint8_t power_level);

/**
 * @brief Transmit data manually through the RF interface.
 *
 * This function sends the specified data buffer using manual transmission mode.
 * It allows fine control over the transmission process, including optional
 * reversal of bit order or other custom behaviors depending on the hardware design.
 *
 * @note This function is only supported in FSK mode.
 * @note Do not call tx_init and tx_start when calling this function.
 *
 * @param[in] len         Length of the transmission data in bytes, maximum is 16.
 * @param[in] tx_data     Pointer to the data buffer to be transmitted.
 * @param[in] revs_flag   Set to 1 to enable bit reversal mode, or 0 to disable.
 *
 * @return None
 */
void wisp_api_tx_manual(uint8_t len, const uint8_t *tx_data, int8_t revs_flag);
#endif

/**
 * @brief Get the SDK version encoded as a 16-bit value.
 *
 * This function retrieves the SDK version and encodes it into a 16-bit
 * unsigned integer. The version number is split into three fields:
 * - Major version: upper 3 bits (bits 15..13)
 * - Minor version: next 5 bits (bits 12..8)
 * - Patch version: lower 8 bits (bits 7..0)
 *
 * @param[out] version Pointer to a uint16_t variable where the encoded version
 *                     will be stored.
 */
void wisp_api_get_sdk_version(uint16_t *version);

/**
 * @brief Get SDK version string in format "Ver: X.Y.Z".
 *
 * @return Pointer to a constant string containing the version.
 */
const char *wisp_api_get_sdk_string(void);

#endif
