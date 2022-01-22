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
  KC_RUN_SPC, // H:ctrl+space T:space
 
};

// <<KEYMAP_GOES_HERE>>

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
    case KC_RUN_SPC: // H:copy T:paste
    if (record->event.pressed)
    {
      kc_cp_pst_timer = timer_read();
    }
    else
    {
      if (timer_elapsed(kc_cp_pst_timer) > TAPPING_TERM)
        { 
        tap_code16(C(KC_SPC));
      }
      else
      { 
        tap_code16(KC_SPC);
      }
    }
    break;



  }
  return true;
}
bool oled_task_user(void) {
  
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state | default_layer_state)) {
            case 0:
                oled_write_P(PSTR("Workman\n"), false);
                break;
            case 1:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case 2:
                oled_write_P(PSTR("Numbers\n"), false);
                break;
            case 3:
                oled_write_P(PSTR("Gaming\n"), false);
                break;
          
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Host Keyboard LED Status
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
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