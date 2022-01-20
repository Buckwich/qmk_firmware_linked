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


enum custom_keycodes
{
  KC_ESC_TAB = SAFE_RANGE, // H:esc T:tab
  KC_CP_PST, // H:copy T:paste
 
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0:
 * ┌──────────┬─────┬─────┬─────┬─────┬─────┐                                    ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │TD_TAB_ESC│  Q  │  W  │  F  │  P  │  B  │                                    │  J  │  L  │  U  │  Y  │  ;  │  \  │
 * ├──────────┼─────┼─────┼─────┼─────┼─────┤                                    ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │    ⌫     │  A  │  R  │  S  │  T  │  G  │                                    │  M  │  N  │  E  │  I  │  O  │  '  │
 * ├──────────┼─────┼─────┼─────┼─────┼─────┼─────────────┬─────────┬─────┬──────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │    `     │  Z  │  X  │  C  │  D  │  V  │            │TD_CP_PST│    │     │  K  │  H  │  ,  │  .  │  /  │    │
 * └──────────┴─────┴─────┼─────┼─────┼─────┼─────────────┼─────────┼─────┼──────┼─────┼─────┼─────┼─────┴─────┴─────┘
 *                        │ Alt │Ctrl │  ␣  │OSM(MOD_LSFT)│        │    │OSL(1)│  ⏎  │  ↑  │  ↓  │
 *                        └─────┴─────┴─────┴─────────────┴─────────┴─────┴──────┴─────┴─────┴─────┘
 */
  [0] = LAYOUT(
    KC_ESC_TAB,KC_Q ,KC_W , KC_F  , KC_P  , KC_B ,                                      KC_J ,KC_L , KC_U  , KC_Y ,KC_SCLN,KC_BSLS,
     KC_BSPC  ,KC_A ,KC_R , KC_S  , KC_T  , KC_G ,                                      KC_M ,KC_N , KC_E  , KC_I , KC_O  ,KC_QUOT,
      KC_GRV  ,KC_Z ,KC_X , KC_C  , KC_D  , KC_V ,    EEPROM_RESET    ,KC_CP_PST,KC_NO,KC_NO , KC_K ,KC_H ,KC_COMM,KC_DOT,KC_SLSH, KC_NO ,
                           KC_LALT,KC_LCTL,KC_SPC,OSM(MOD_LSFT),  KC_NO  ,KC_NO,OSL(1),KC_ENT,KC_UP,KC_DOWN
  ),

/* Layer 1:
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐                       ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  !  │  @  │  #  │  $  │  %  │                       │  ^  │  [  │  ]  │    │    │    │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  *  │  &  │  +  │  =  │  >  │                       │    │  {  │  }  │    │    │    │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┬─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │  ~  │  /  │  |  │  -  │  _  │    │    │    │    │    │    │  (  │  )  │  <  │  >  │    │
 * └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
 *                   │    │    │    │    │    │    │     │    │    │    │
 *                   └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
  [1] = LAYOUT(
    KC_TRNS,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                          KC_CIRC,KC_LBRC,KC_RBRC,KC_NO,KC_NO,KC_NO,
    KC_TRNS,KC_ASTR,KC_AMPR,KC_PLUS,KC_EQL , KC_GT ,                           KC_NO ,KC_LCBR,KC_RCBR,KC_NO,KC_NO,KC_NO,
    KC_TILD,KC_SLSH,KC_PIPE,KC_MINS,KC_UNDS, KC_NO ,KC_NO,KC_NO,KC_NO, KC_NO , KC_NO ,KC_LPRN,KC_RPRN,KC_LT,KC_GT,KC_NO,
                             KC_NO , KC_NO , KC_NO ,KC_NO,KC_NO,KC_NO,KC_TRNS, KC_NO , KC_NO , KC_NO 
  ),

/* Layer 2:
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐                       ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │    │    │    │    │    │    │                       │    │  7  │  8  │  9  │    │    │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
 * │    │    │    │    │    │    │                       │    │  4  │  5  │  6  │    │    │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┬─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │    │    │    │    │    │    │    │    │    │    │    │  1  │  2  │  3  │    │    │
 * └─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┴─────┘
 *                   │    │    │    │    │    │    │    │    │    │    │
 *                   └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
  [2] = LAYOUT(
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                        KC_NO,KC_P7,KC_P8,KC_P9,KC_NO,KC_NO,
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                        KC_NO,KC_P4,KC_P5,KC_P6,KC_NO,KC_NO,
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_P1,KC_P2,KC_P3,KC_NO,KC_NO,
                      KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO
  ),

};
// clang-format on

uint16_t kc_esc_tab_timer;
uint16_t kc_cp_pst_timer;


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {

  case KC_ESC_TAB: // H:esc T:tab
    if (record->event.pressed)
    {
      kc_esc_tab_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(kc_esc_tab_timer) > TAPPING_TERM)
       { 
        tap_code16(KC_ESC);
      }
      else
      { 
        tap_code16(KC_TAB);
      }
   
    }
    break;

  case KC_CP_PST: // H:copy T:paste
    if (record->event.pressed)
    {
      kc_cp_pst_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(kc_cp_pst_timer) > TAPPING_TERM)
        { 
        tap_code16(C(KC_C));
      }
      else
      { 
        tap_code16(C(KC_V));
      }
    }
    break;


  }
  return true;
}

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_YELLOW);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
rgblight_set_effect_range(0, 20);
rgblight_set_clipping_range(0,20);
  sethsv(HSV_BLUE, (LED_TYPE *)&led[0]); // led 0
sethsv(HSV_RED,   (LED_TYPE *)&led[1]); // led 1
sethsv(HSV_GREEN, (LED_TYPE *)&led[2]); // led 2

  sethsv(HSV_BLUE, (LED_TYPE *)&led[6]); // led 0
sethsv(HSV_RED,   (LED_TYPE *)&led[7]); // led 1
sethsv(HSV_GREEN, (LED_TYPE *)&led[8]); // led 2
rgblight_set(); 
}
// // Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
// const rgblight_segment_t PROGMEM layer0[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 26, HSV_OFF}
// );
// // Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
// const rgblight_segment_t PROGMEM layer1[] = RGBLIGHT_LAYER_SEGMENTS(
//   //   {1,1,HSV_AZURE},
//   // {2,1,HSV_BLACK},
//   // {3,1,HSV_BLUE},
//   // {4,1,HSV_CHARTREUSE},
//   // {5,1,HSV_CORAL},
//   // {6,1,HSV_CYAN},
//   // {7,1,HSV_GOLD},
//   // {8,1,HSV_GOLDENROD},
//   // {9,1,HSV_GREEN},
//   // {10,1,HSV_MAGENTA},
//   // {11,1,HSV_ORANGE},
//   // {12,1,HSV_PINK},
//   // {13,1,HSV_PURPLE},
//   // {14,1,HSV_RED},
//   // {15,1,HSV_SPRINGGREEN},
//   // {16,1,HSV_TEAL},
//   // {17,1,HSV_TURQUOISE},
//   // {18,1,HSV_WHITE},
//   // {19,1,HSV_YELLOW}
//   {0,7,HSV_YELLOW},
//   {7,1,HSV_WHITE},
//     {8,1,HSV_RED},
//   {9,1,HSV_BLUE},
//   {10,1,HSV_GREEN}
//   // {4,1,HSV_RED},
//   // {5,1,HSV_BLUE},
//   // {6,1,HSV_GREEN},
//   // {7,1,HSV_GREEN},
//   // {8,1,HSV_BLUE},
//   // {9,1,HSV_GREEN},
//   // {10,1,HSV_MAGENTA},
//   // {11,1,HSV_MAGENTA},
//   // {12,1,HSV_MAGENTA},
//   // {13,1,HSV_PURPLE},
//   // {14,1,HSV_PURPLE},
//   // {15,1,HSV_PURPLE},
//   // {16,1,HSV_PURPLE},
//   // {17,1,HSV_YELLOW},
//   // {18,1,HSV_YELLOW},
//   // {19,1,HSV_YELLOW}
// );

// Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     layer0,layer1
//     // my_layer1_layer,    // Overrides caps lock layer
//     // my_layer2_layer,    // Overrides other layers
//     // my_layer3_layer     // Overrides other layers
// );

// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     // rgblight_layers = my_rgb_layers;
// }
layer_state_t default_layer_state_set_user(layer_state_t state) {
    // rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    // rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}


// static void render_status(void) {
    // QMK Logo and version information
    
    //oled_write_P(PSTR("┌ j l u y i o \n"),false);
    // static const char PROGMEM kyria_logo[] = {
    // 0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    // 0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    // 0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    // 0x01,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0b,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,0x12,0x13,0x14,
    // 0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,0x20,0x21,0x22,0x23,0x24,
    // 0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,0x50,0x51,0x52,0x53,0x54,
    // 0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,

//  0x78,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0


    // };
  //  oled_write_P(kyria_logo, false);
// oled_write_P(PSTR("│  J  │  L  │  U  │  Y  │  ;  │  █  │\n"),false);
// oled_write_P(PSTR("├─────┼─────┼─────┼─────┼─────┼─────┤\n"),false);
// oled_write_P(PSTR("│  M  │  N  │  E  │  I  │  O  │  █  │\n"),false);
// oled_write_P(PSTR("┼─────┼─────┼─────┼─────┼─────┼─────┤\n"),false);
// oled_write_P(PSTR("│  K  │  H  │  ,  │  .  │  /  │  █  │\n"),false);
// oled_write_P(PSTR("┼─────┼─────┼─────┼─────┴─────┴─────┘\n"), false);

    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer: "), false);
  
    

    // Host Keyboard LED Status
    // uint8_t led_usb_state = host_keyboard_leds();
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
// }

// void oled_task_user(void) {
 
//         render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  
// }
#endif