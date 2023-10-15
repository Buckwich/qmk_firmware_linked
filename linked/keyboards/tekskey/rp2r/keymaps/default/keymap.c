// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [0] = LAYOUT(
        KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, 
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
        KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, 
        KC_M, KC_N, KC_E, KC_I, KC_O , KC_QUOT, 
        KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
        KC_SPC, KC_ENT, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL
    )
};



