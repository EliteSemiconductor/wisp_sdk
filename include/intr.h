
#ifndef __INTR_H__
#define __INTR_H__


#define IRQn_EX0  0x01
#define IRQn_ET0  0x02
#define IRQn_EX1  0x04
#define IRQn_ET1  0x08
#define IRQn_ETS  0x10
#define IRQn_EXA  0x80

#define Timer0_IRQn    IRQn_ET0

#define Timer1_IRQn    IRQn_ET1

#define WDT_IRQn       IRQn_EX0

#define DMA_CTRL_IRQn  IRQn_EX1
#define MAC_IRQn       IRQn_EX1
#define AES_IRQn       IRQn_EX1
#define IO_CTRL_IRQn   IRQn_EX1
#define ASARADC_IRQn   IRQn_EX1
#define TRNG_IRQn      IRQn_EX1
#define OTP_IRQn       IRQn_EX1
#define MTP_IRQn       IRQn_EX1

#define UART_0_IRQn    IRQn_ETS


#define MCU_EnableIRQ(INT_MSK) \
       IE = IE | (IRQn_EXA | INT_MSK);

#define MCU_DisableIRQ(INT_MSK) \
        IE = IE & ~(INT_MSK);

#endif /* __INTR_H__ */
