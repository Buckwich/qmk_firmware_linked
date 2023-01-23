// Copyright 2023 Buckwich (@Buckwich)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

#define MATRIX_ROWS 12
#define MATRIX_COLS 6

#define MATRIX_COL_PINS { B10, B1, B0, A3, A2, A1 }
#define MATRIX_ROW_PINS { B13, B4, B3, A15, B15, B14 }
#define MATRIX_COL_PINS_RIGHT { B10, B1, B0, A3, A2, A1 }
#define MATRIX_ROW_PINS_RIGHT { B13, B4, B3, A15, B15, B14 } 

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

//SPLIT
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin
#define MASTER_RIGHT

//RGB
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
#define RGB_DI_PIN A7
#define RGB_MATRIX_LED_COUNT 70
#define RGBLED_SPLIT { 35, 35 }
#define RGB_MATRIX_SPLIT RGBLED_SPLIT

//RGB Effects
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_BAND_SAT

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP




