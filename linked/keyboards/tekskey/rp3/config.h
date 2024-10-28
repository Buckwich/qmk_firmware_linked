// Copyright 2023 Buckwich (@Buckwich)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define TAPPING_TOGGLE 2


// //SPLIT
// #define MATRIX_ROWS 12
// #define MATRIX_COLS 6




#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin
#define SERIAL_USART_PIN_SWAP 
#define MASTER_RIGHT
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_WATCHDOG_ENABLE

#define WS2812_PIO_USE_PIO1
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 50
#define WS2812_DI_PIN GP7
#define RGB_MATRIX_LED_COUNT 70


#define RGBLED_SPLIT { 35, 35 }
#define RGB_MATRIX_SPLIT { 35, 35 }


