/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file   wirish/boards/maple_mini/board.cpp
 * @author Marti Bolivar <mbolivar@leaflabs.com>
 * @brief  Maple Mini board file.
 */

#include <board/board.h>

#include <libmaple/gpio.h>
#include <libmaple/timer.h>

#include <wirish_debug.h>
#include <wirish_types.h>

/* Since we want the Serial Wire/JTAG pins as GPIOs, disable both SW
 * and JTAG debug support, unless configured otherwise. */
void boardInit(void) {
#ifndef CONFIG_MAPLE_MINI_NO_DISABLE_DEBUG
    disableDebugPorts();
#endif
}

extern const stm32_pin_info PIN_MAP[BOARD_NR_GPIO_PINS] = {

    /* Top header */

    {GPIOB,   NULL, NULL, 11, 0, ADCx}, /* D0/PB11 */
    {GPIOB,   NULL, NULL, 10, 0, ADCx}, /* D1/PB10 */
    {GPIOB,   NULL, NULL,  2, 0, ADCx}, /* D2/PB2 */
    {GPIOB, TIMER3, ADC1,  0, 3,    8}, /* D3/PB0 */
    {GPIOA, TIMER3, ADC1,  7, 2,    7}, /* D4/PA7 */
    {GPIOA, TIMER3, ADC1,  6, 1,    6}, /* D5/PA6 */
    {GPIOA,   NULL, ADC1,  5, 0,    5}, /* D6/PA5 */
    {GPIOA,   NULL, ADC1,  4, 0,    4}, /* D7/PA4 */
    {GPIOA, TIMER2, ADC1,  3, 4,    3}, /* D8/PA3 */
    {GPIOA, TIMER2, ADC1,  2, 3,    2}, /* D9/PA2 */
    {GPIOA, TIMER2, ADC1,  1, 2,    1}, /* D10/PA1 */
    {GPIOA, TIMER2, ADC1,  0, 1,    0}, /* D11/PA0 */
    {GPIOC,   NULL, NULL, 15, 0, ADCx}, /* D12/PC15 */
    {GPIOC,   NULL, NULL, 14, 0, ADCx}, /* D13/PC14 */
    {GPIOC,   NULL, NULL, 13, 0, ADCx}, /* D14/PC13 */

    /* Bottom header */

    {GPIOB, TIMER4, NULL,  7, 2, ADCx}, /* D15/PB7 */
    {GPIOB, TIMER4, NULL,  6, 1, ADCx}, /* D16/PB6 */
    {GPIOB,   NULL, NULL,  5, 0, ADCx}, /* D17/PB5 */
    {GPIOB,   NULL, NULL,  4, 0, ADCx}, /* D18/PB4 */
    {GPIOB,   NULL, NULL,  3, 0, ADCx}, /* D19/PB3 */
    {GPIOA,   NULL, NULL, 15, 0, ADCx}, /* D20/PA15 */
    {GPIOA,   NULL, NULL, 14, 0, ADCx}, /* D21/PA14 */
    {GPIOA,   NULL, NULL, 13, 0, ADCx}, /* D22/PA13 */
    {GPIOA,   NULL, NULL, 12, 0, ADCx}, /* D23/PA12 */
    {GPIOA, TIMER1, NULL, 11, 4, ADCx}, /* D24/PA11 */
    {GPIOA, TIMER1, NULL, 10, 3, ADCx}, /* D25/PA10 */
    {GPIOA, TIMER1, NULL,  9, 2, ADCx}, /* D26/PA9 */
    {GPIOA, TIMER1, NULL,  8, 1, ADCx}, /* D27/PA8 */
    {GPIOB,   NULL, NULL, 15, 0, ADCx}, /* D28/PB15 */
    {GPIOB,   NULL, NULL, 14, 0, ADCx}, /* D29/PB14 */
    {GPIOB,   NULL, NULL, 13, 0, ADCx}, /* D30/PB13 */
    {GPIOB,   NULL, NULL, 12, 0, ADCx}, /* D31/PB12 */
    {GPIOB, TIMER4, NULL,  8, 3, ADCx}, /* D32/PB8 */
    {GPIOB, TIMER3, ADC1,  1, 4,    9}, /* D33/PB1 */
};


extern const stm32_pin_info_fast PIN_MAP_FAST[BOARD_NR_GPIO_PINS] __FLASH__ = {
    {1U<<11, 0x4221812C}, //D0
    {1U<<10, 0x42218128}, //D1
    {1U<<2, 0x42218108}, //D2
    {1U<<0, 0x42218100}, //D3
    {1U<<7, 0x4221011C}, //D4
    {1U<<6, 0x42210118}, //D5
    {1U<<5, 0x42210114}, //D6
    {1U<<4, 0x42210110}, //D7
    {1U<<3, 0x4221010C}, //D8
    {1U<<2, 0x42210108}, //D9
    {1U<<1, 0x42210104}, //D10
    {1U<<0, 0x42210100}, //D11
    {1U<<15, 0x4222013C}, //D12
    {1U<<14, 0x42220138}, //D13
    {1U<<13, 0x42220134}, //D14
    {1U<<7, 0x4221811C}, //D15
    {1U<<6, 0x42218118}, //D16
    {1U<<5, 0x42218114}, //D17
    {1U<<4, 0x42218110}, //D18
    {1U<<3, 0x4221810C}, //D19
    {1U<<15, 0x4221013C}, //D20
    {1U<<14, 0x42210138}, //D21
    {1U<<13, 0x42210134}, //D22
    {1U<<12, 0x42210130}, //D23
    {1U<<11, 0x4221012C}, //D24
    {1U<<10, 0x42210128}, //D25
    {1U<<9, 0x42210124}, //D26
    {1U<<8, 0x42210120}, //D27
    {1U<<15, 0x4221813C}, //D28
    {1U<<14, 0x42218138}, //D29
    {1U<<13, 0x42218134}, //D30
    {1U<<12, 0x42218130}, //D31
    {1U<<8, 0x42218120}, //D32
    {1U<<1, 0x42218104}, //D33
};

extern const uint8 boardPWMPins[BOARD_NR_PWM_PINS] __FLASH__ = {
    3, 4, 5, 8, 9, 10, 11, 15, 16, 25, 26, 27
};

extern const uint8 boardADCPins[BOARD_NR_ADC_PINS] __FLASH__ = {
    3, 4, 5, 6, 7, 8, 9, 10, 11
};

#define USB_DP 23
#define USB_DM 24

extern const uint8 boardUsedPins[BOARD_NR_USED_PINS] __FLASH__ = {
    BOARD_LED_PIN, BOARD_BUTTON_PIN, USB_DP, USB_DM
};
