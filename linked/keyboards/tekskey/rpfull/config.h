// Copyright 2023 Buckwich (@Buckwich)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

#define MATRIX_ROWS 12
#define MATRIX_COLS 6

#define MATRIX_COL_PINS { GP6 , GP7 , GP8 , GP9 , GP10, GP11}
#define MATRIX_ROW_PINS { GP0 , GP5 , GP4 , GP3 , GP2 , GP1,     GP16, GP21, GP20, GP19, GP18, GP17 }

#define TAPPING_TOGGLE 2
/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

