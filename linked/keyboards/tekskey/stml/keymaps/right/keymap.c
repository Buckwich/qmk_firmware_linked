// Copyright 2023 Buckwich (@Buckwich)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        RGB_TOG ,KC_F6 ,KC_F10 , KC_F11, KC_NO, QK_BOOT,
        KC_6  ,KC_7  ,KC_8   , KC_9, KC_0  , KC_6,
        KC_J  ,KC_L  ,KC_U   , KC_Y, KC_SCLN  , KC_BSLS,
        KC_M  ,KC_N  ,KC_E   , KC_I, KC_O  , KC_QUOT,
        KC_K  ,KC_H  ,KC_COMM, KC_DOT, KC_SLSH  , KC_RSFT,
        KC_SPC,KC_ENT,KC_LBRC, KC_RBRC, KC_MINS  , KC_EQL
    ),
    [_RGB] = LAYOUT(
        RGB_TOG ,KC_F6 ,KC_F10 , KC_F11, KC_NO, QK_BOOT,
        RGB_MOD ,RGB_HUI  ,RGB_SAI   , RGB_VAI, RGB_SPI  , KC_6,
        RGB_RMOD,RGB_HUD  ,RGB_SAD   , RGB_VAD, RGB_SPD  , KC_BSLS,
        KC_M  ,KC_N  ,KC_E   , KC_I, KC_O  , KC_QUOT,
        KC_K  ,KC_H  ,KC_COMM, KC_DOT, KC_SLSH  , KC_RSFT,
        KC_SPC,KC_ENT,KC_LBRC, KC_RBRC, KC_MINS  , KC_EQL
    ),
}; 
