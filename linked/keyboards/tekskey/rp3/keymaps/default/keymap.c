// Copyright 2023 Buckwich (@Buckwich)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS
][MATRIX_COLS
] = {
    [0]= LAYOUT(
        KC_ESC,KC_1,KC_2,KC_NO, KC_3, KC_4,          KC_F5, KC_F6, KC_VOLD ,KC_VOLU,KC_NO  , KC_F12,
        KC_GRV ,KC_1 ,KC_2 , KC_3, KC_4, KC_5,              KC_6  ,KC_7  ,KC_8   , KC_9, KC_0   , KC_6,
        KC_TAB ,KC_Q ,KC_W , KC_F, KC_P, KC_B,              KC_J  ,KC_L  ,KC_U   , KC_Y, KC_SCLN, KC_BSLS,
        KC_BSPC,KC_A ,KC_R , KC_S, KC_T, KC_G,              KC_M  ,KC_N  ,KC_E   , KC_I, KC_O   , KC_QUOT,
        KC_LSFT,KC_Z ,KC_X , KC_C, KC_D, KC_V,              KC_K  ,KC_H  ,KC_COMM,KC_DOT,KC_SLSH, KC_RSFT,
        KC_LCTL,KC_LGUI,KC_LALT,TT(1), KC_ENT,KC_SPC,     KC_SPC,KC_ENT,KC_LBRC,KC_RBRC,KC_MINS,KC_EQL
    )
};

#define AZURE   {132, 102, 255}
#define BLACK   {  0,   0,   0}
#define BLUE_   {170, 255, 255}
#define CHART   { 64, 255, 255}
#define CORAL   { 11, 176, 255}
#define CYAN_   {128, 255, 255}
#define GOLD_   { 36, 255, 255}
#define GREEN   { 85, 255, 255}
#define MAGEN   {213, 255, 255}
#define ORNGE   { 21, 255, 255}
#define PINK_   {234, 128, 255}
#define PRPLE   {191, 255, 255}
#define RED__   {  0, 255, 255}
#define SPGRN   {106, 255, 255}
#define TEAL_   {128, 255, 255}
#define TURQU   {123,  90, 112}
#define WHITE   {  0,   0, 255}
#define YELLW   { 43, 255, 255}
#define OFF__   {  0,   0,   0}
#define _____   {  0,   0,   0}

const uint8_t PROGMEM rgb_matrix_led_map[][RGB_MATRIX_LED_COUNT][4] = {
    [1] = {
    //LEFT
    _____,_____,   _____,_____,RED__, //REV
    _____,PRPLE,TEAL_,MAGEN,_____,_____, 
    _____,_____,_____,_____,_____,_____,//REV
    _____,_____,_____,_____,_____,_____, 
    _____,_____,_____,_____,_____,_____,//REV
    _____,_____,_____,_____,_____,_____, 

    //RIGHT
    _____,_____,   _____,_____,_____, //REV
    _____,_____,RED__,MAGEN,MAGEN,MAGEN, 
    MAGEN,TEAL_,TEAL_,TEAL_,_____,_____, //REV
    _____,_____,TEAL_,TEAL_,TEAL_,MAGEN, 
    MAGEN,TEAL_,TEAL_,TEAL_,PRPLE,_____, //REV
    PRPLE,PRPLE,PRPLE,TEAL_,TEAL_,MAGEN,
  }
};

void set_layer_color(int layer)
{
  for (uint8_t i_row = 0; i_row < MATRIX_ROWS; i_row++)
  {
    for (uint8_t i_col = 0; i_col < MATRIX_COLS; i_col++)
    {
      if (g_led_config.matrix_co[i_row][i_col] == NO_LED)
      { // skip as target key doesn't have an led position
        continue;
      }

      uint8_t i = g_led_config.matrix_co[i_row][i_col];
      HSV hsv = {
          .h = pgm_read_byte(&rgb_matrix_led_map[layer][i][0]),
          .s = pgm_read_byte(&rgb_matrix_led_map[layer][i][1]),
          .v = pgm_read_byte(&rgb_matrix_led_map[layer][i][2]),
      };
      if (!hsv.h && !hsv.s && !hsv.v)
      {
        rgb_matrix_set_color(i, 0, 0, 0);
      }
      else
      {
        RGB rgb = hsv_to_rgb(hsv);
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
      }
    }
  }
}

bool rgb_matrix_indicators_user(void)
{
  switch (biton32(layer_state))
  {
  // case 0:
  //   set_layer_color(0);
  //   break;
  case 1:
    set_layer_color(1);
    break;
    // case 2:
    //   set_layer_color(2);
    //   break;
    // case 3:
    //   set_layer_color(3);
    //   break;
  default:
    // if (rgb_matrix_get_flags() == LED_FLAG_NONE)
    //   rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return false;
}
