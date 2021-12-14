/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers
{
  _BASE = 0,
  _NAV,
  _SYM,
  _FUNCTION,
  _ADJUST
};

enum custom_keycodes
{
  TD_TAB_ESC = SAFE_RANGE,
  TD_CP_PST,
  TDC_A,
  TDC_B,
  TDC_C,
  TDC_D,
  TDC_E,
  TDC_F,
  TDC_G,
  TDC_H,
  TDC_I,
  TDC_J,
  TDC_K,
  TDC_L,
  TDC_M,
  TDC_N,
  TDC_O,
  TDC_P,
  TDC_Q,
  TDC_R,
  TDC_S,
  TDC_T,
  TDC_U,
  TDC_V,
  TDC_W,
  TDC_X,
  TDC_Y,
  TDC_Z
};

// Aliases for readability

#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)
#define ADJUST MO(_ADJUST)

#define CTL_BSP MT(MOD_LCTL, KC_BSPC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: COLMAK
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |Tab/Esc |   Q  |   W  |   F  |   P  |   B  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Bsp|   A  |   R  |   S  |   T  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
     TD_TAB_ESC ,TDC_Q ,  TDC_W   ,  TDC_F  ,   TDC_P ,   TDC_B , TDC_J   , TDC_L   ,  TDC_U  ,   TDC_Y ,KC_SCLN, KC_BSPC,
     CTL_BSP , TDC_A ,  TDC_R   ,  TDC_S  ,   TDC_T ,   TDC_G ,                                     TDC_M   , TDC_N   ,  TDC_E  ,   TDC_I , TDC_O  , CTL_QUOT,
     KC_LSFT , TDC_Z ,  TDC_X   ,  TDC_C  ,   TDC_D ,   TDC_V , _______, TD_CP_PST, _______, _______, TDC_K   , TDC_H   , KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                _______, _______, KC_SPC , _______, _______, _______, _______, _______, KC_UP  , KC_DOWN
    ), 
    /*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    // [_BASE] = LAYOUT(
    //  KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,  KC_VOLD, KC_VOLU,   KC_PGDN, KC_PGUP, KC_J,   KC_L ,  KC_U ,   KC_Y ,  KC_SCLN , KC_BSPC,
    //  CTL_ESC , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,                                        KC_M,   KC_N ,  KC_E ,   KC_I , KC_O, CTL_QUOT,
    //  KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
    //                             ADJUST , KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
    // ),


/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______,  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SLCK, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,------+-------------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   | \ |  | [ {  |      |  |      |  ] } |  # ~ |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 , KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_NUBS, KC_LBRC, _______, _______, KC_RBRC, KC_NUHS, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `--------+------+------+--------------------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                     RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


};
// clang-format on

uint16_t td_tab_esc_timer;
uint16_t td_cp_pst_timer;
uint16_t tdc_a_timer;
uint16_t tdc_b_timer;
uint16_t tdc_c_timer;
uint16_t tdc_d_timer;
uint16_t tdc_e_timer;
uint16_t tdc_f_timer;
uint16_t tdc_g_timer;
uint16_t tdc_h_timer;
uint16_t tdc_i_timer;
uint16_t tdc_j_timer;
uint16_t tdc_k_timer;
uint16_t tdc_l_timer;
uint16_t tdc_m_timer;
uint16_t tdc_n_timer;
uint16_t tdc_o_timer;
uint16_t tdc_p_timer;
uint16_t tdc_q_timer;
uint16_t tdc_r_timer;
uint16_t tdc_s_timer;
uint16_t tdc_t_timer;
uint16_t tdc_u_timer;
uint16_t tdc_v_timer;
uint16_t tdc_w_timer;
uint16_t tdc_x_timer;
uint16_t tdc_y_timer;
uint16_t tdc_z_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {

  case TD_TAB_ESC: // One key copy/paste
    if (record->event.pressed)
    {
      td_tab_esc_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(td_tab_esc_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_V));
      }
      else
      { // Tap, paste
        tap_code16(C(KC_V));
      }
    }
    break;

  case TD_CP_PST: // One key copy/paste
    if (record->event.pressed)
    {
      td_cp_pst_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(td_cp_pst_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(KC_ESC);
      }
      else
      { // Tap, paste
        tap_code16(KC_TAB);
      }
    }
    break;

  case TDC_A: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_a_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_a_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_A));
      }
      else
      { // Tap, paste
        tap_code16(KC_A);
      }
    }
    break;

  case TDC_B: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_b_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_b_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_B));
      }
      else
      { // Tap, paste
        tap_code16(KC_B);
      }
    }
    break;

  case TDC_C: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_c_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_c_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_C));
      }
      else
      { // Tap, paste
        tap_code16(KC_C);
      }
    }
    break;

  case TDC_D: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_d_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_d_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_D));
      }
      else
      { // Tap, paste
        tap_code16(KC_D);
      }
    }
    break;

  case TDC_E: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_e_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_e_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_E));
      }
      else
      { // Tap, paste
        tap_code16(KC_E);
      }
    }
    break;

  case TDC_F: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_f_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_f_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_F));
      }
      else
      { // Tap, paste
        tap_code16(KC_F);
      }
    }
    break;

  case TDC_G: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_g_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_g_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_G));
      }
      else
      { // Tap, paste
        tap_code16(KC_G);
      }
    }
    break;

  case TDC_H: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_h_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_h_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_H));
      }
      else
      { // Tap, paste
        tap_code16(KC_H);
      }
    }
    break;

  case TDC_I: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_i_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_i_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_I));
      }
      else
      { // Tap, paste
        tap_code16(KC_I);
      }
    }
    break;

  case TDC_J: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_j_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_j_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_J));
      }
      else
      { // Tap, paste
        tap_code16(KC_J);
      }
    }
    break;

  case TDC_K: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_k_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_k_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_K));
      }
      else
      { // Tap, paste
        tap_code16(KC_K);
      }
    }
    break;

  case TDC_L: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_l_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_l_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_L));
      }
      else
      { // Tap, paste
        tap_code16(KC_L);
      }
    }
    break;

  case TDC_M: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_m_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_m_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_M));
      }
      else
      { // Tap, paste
        tap_code16(KC_M);
      }
    }
    break;

  case TDC_N: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_n_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_n_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_N));
      }
      else
      { // Tap, paste
        tap_code16(KC_N);
      }
    }
    break;

  case TDC_O: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_o_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_o_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_O));
      }
      else
      { // Tap, paste
        tap_code16(KC_O);
      }
    }
    break;

  case TDC_P: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_p_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_p_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_P));
      }
      else
      { // Tap, paste
        tap_code16(KC_P);
      }
    }
    break;

  case TDC_Q: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_q_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_q_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_Q));
      }
      else
      { // Tap, paste
        tap_code16(KC_Q);
      }
    }
    break;

  case TDC_R: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_r_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_r_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_R));
      }
      else
      { // Tap, paste
        tap_code16(KC_R);
      }
    }
    break;

  case TDC_S: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_s_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_s_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_S));
      }
      else
      { // Tap, paste
        tap_code16(KC_S);
      }
    }
    break;

  case TDC_T: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_t_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_t_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_T));
      }
      else
      { // Tap, paste
        tap_code16(KC_T);
      }
    }
    break;

  case TDC_U: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_u_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_u_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_U));
      }
      else
      { // Tap, paste
        tap_code16(KC_U);
      }
    }
    break;

  case TDC_V: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_v_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_v_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_V));
      }
      else
      { // Tap, paste
        tap_code16(KC_V);
      }
    }
    break;

  case TDC_W: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_w_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_w_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_W));
      }
      else
      { // Tap, paste
        tap_code16(KC_W);
      }
    }
    break;

  case TDC_X: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_x_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_x_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_X));
      }
      else
      { // Tap, paste
        tap_code16(KC_X);
      }
    }
    break;

  case TDC_Y: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_y_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_y_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_Y));
      }
      else
      { // Tap, paste
        tap_code16(KC_Y);
      }
    }
    break;

  case TDC_Z: // One key copy/paste
    if (record->event.pressed)
    {
      tdc_z_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(tdc_z_timer) > TAPPING_TERM)
      { // Hold, copy
        tap_code16(C(KC_Z));
      }
      else
      { // Tap, paste
        tap_code16(KC_Z);
      }
    }
    break;
  }
  return true;
}
