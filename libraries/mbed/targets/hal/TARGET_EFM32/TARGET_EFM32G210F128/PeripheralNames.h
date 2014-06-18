/* mbed Microcontroller Library
 */
#ifndef MBED_PERIPHERALNAMES_H
#define MBED_PERIPHERALNAMES_H

#include "cmsis.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ADC_1 = (int)ADC0_BASE
} ADCName;

typedef enum {
    UART_1 = (int)USART0_BASE,
    UART_2 = (int)USART1_BASE,
    UART_3 = (int)LEUART0_BASE
} UARTName;

#define STDIO_UART_TX  PD_4
#define STDIO_UART_RX  PD_5
#define STDIO_UART     UART_3

typedef enum {
    SPI_1 = (int)USART0_BASE,
    SPI_2 = (int)USART1_BASE
} SPIName;

typedef enum {
    I2C_1 = (int)I2C0_BASE
} I2CName;

typedef enum {
    PWM_1 = (int)TIMER0_BASE,
    PWM_2 = (int)TIMER1_BASE
} PWMName;

#ifdef __cplusplus
}
#endif

#endif
