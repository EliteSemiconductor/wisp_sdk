
#ifndef TONKI_SOC_H
#define TONKI_SOC_H

#include <lint.h>
#include <8051.h>
#include <8052.h>
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif


#define     __IO    volatile
#define     __I     volatile const
#define     __O     volatile

//- watchdog timer control
__sfr __at (0x9F) WDTCON ;

//- peripherals  -//
#define MTPCTL_BASE              (0x4800)
#define OTPCTL_BASE              (0x4C00)
#define SYS_CTRL_BASE            (0x8000)
#define PCRMU_BASE               (0x8400)
#define IO_CTRL_BASE             (0x8800)
#define ANA_AON_BASE             (0x8C00)
#define DMA_CTRL_BASE            (0x9000)
#define TRNG_BASE                (0x9400)
#define AES_BASE                 (0x9800)
#define MAC_BASE                 (0xA000)
#define ANCTL_BASE               (0xD000)


//- head file -//
//#include "intr.h"
//#include "sys_ctrl.h"
//#include "dma_ctrl.h"
//#include "io_ctrl.h"
//#include "aes.h"
//#include "mac.h"
//#include "an_ctl.h"
//#include "ana_aon.h"
//#include "pcrmu.h"
//#include "trng.h"
//#include "otp_ctl.h"
//#include "mtp_ctl.h"


#ifdef __cplusplus
}
#endif

#endif  /* TONKI_SOC_H */
