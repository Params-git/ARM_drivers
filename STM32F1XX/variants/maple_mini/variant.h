#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

// From SAM implementation #define digitalPinToBitMask(P)     ( g_APinDescription[P].ulPin )


#warning "TO DO. IMPLEMENT digitalPinToBitMask in variant.h"
// Its likely that this function has no meaning with reference to the STM32 GPIO
// But its required by some libraries. 


//typedef struct stm32_pin_info {
//    gpio_dev *gpio_device;      /**< Maple pin's GPIO device */
//    timer_dev *timer_device;    /**< Pin's timer device, if any. */
//    const adc_dev *adc_device;  /**< ADC device, if any. */
//    uint8 gpio_bit;             /**< Pin's GPIO port bit. */
//    uint8 timer_channel;        /**< Timer channel, or 0 if none. */
//    uint8 adc_channel;          /**< Pin ADC channel, or ADCx if none. */
//	uint8 pinMode; 				/**< mode specific by pinMode call (Roger Clark added to optimize compatibility with Arduino API*/
//} stm32_pin_info;

#define digitalPinToBitMask(P)     ( 1 << PIN_MAP[P].gpio_bit )
#define digitalPinToPort(P)        ( PIN_MAP[P].gpio_device->regs->CRL )
#define portOutputRegister(port)   ( &(PIN_MAP[P].gpio_device->regs->ODR) )
#define portInputRegister(port)    ( &(PIN_MAP[P].gpio_device->regs->IDR )
#define digitalPinHasPWM(P)        ( PIN_MAP[P].hasPWM)

#endif /* _VARIANT_ARDUINO_STM32_ */