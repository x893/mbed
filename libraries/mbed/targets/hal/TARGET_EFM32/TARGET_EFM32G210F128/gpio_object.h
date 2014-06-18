/* mbed Microcontroller Library
 */
#ifndef MBED_GPIO_OBJECT_H
#define MBED_GPIO_OBJECT_H

#include "mbed_assert.h"
#include "cmsis.h"
#include "PortNames.h"
#include "PeripheralNames.h"
#include "PinNames.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    PinName  pin;
    uint32_t mask;
    __IO uint32_t *reg_in;
    __IO uint32_t *reg_set;
    __IO uint32_t *reg_clr;
} gpio_t;

static inline void gpio_write(gpio_t *obj, int value) {
    MBED_ASSERT(obj->pin != (PinName)NC);
    if (value) {
        *obj->reg_set = obj->mask;
    } else {
        *obj->reg_clr = obj->mask;
    }
}

static inline int gpio_read(gpio_t *obj) {
    MBED_ASSERT(obj->pin != (PinName)NC);
    return ((*obj->reg_in & obj->mask) ? 1 : 0);
}

#ifdef __cplusplus
}
#endif

#endif
