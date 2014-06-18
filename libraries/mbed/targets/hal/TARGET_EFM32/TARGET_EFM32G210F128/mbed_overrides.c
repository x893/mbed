/* mbed Microcontroller Library
 */
#include "cmsis.h"

// This function is called after RAM initialization and before main.
void mbed_sdk_init() {
    // Update the SystemCoreClock variable.
    SystemCoreClockUpdate();
}
