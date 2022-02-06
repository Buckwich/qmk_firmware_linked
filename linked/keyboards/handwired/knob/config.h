#pragma once

#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x1337
#define DEVICE_VER      0x0001
#define MANUFACTURER    Buckwich
#define PRODUCT         Knob


#define MATRIX_ROWS 1
#define MATRIX_COLS 1

// pin 6
#define DIRECT_PINS {   \
    { D7} \
}


#define UNUSED_PINS

#define ENCODERS_PAD_A { D4}  // pin 3
#define ENCODERS_PAD_B { D0}  // pin 4
#define ENCODER_RESOLUTION 4