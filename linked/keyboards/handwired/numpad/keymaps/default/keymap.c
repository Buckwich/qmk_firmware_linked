#include "numpad.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	KEYMAP(
		KC_PSCR,KC_SCRL,KC_PAUS,KC_MPLY,KC_VOLD,KC_VOLU,KC_MUTE,
		KC_INS ,KC_HOME,KC_PGUP, KC_NUM,KC_PSLS,KC_PAST,KC_PMNS, 
		KC_DEL ,KC_END ,KC_PGDN, KC_P7 , KC_P8 , KC_P9 ,XXXXXXX, 
		XXXXXXX,XXXXXXX,XXXXXXX, KC_P4 , KC_P5 , KC_P6 ,KC_PPLS, 
		XXXXXXX, KC_UP ,XXXXXXX, KC_P1 , KC_P2 , KC_P3 ,KC_PENT, 
		KC_LEFT,KC_DOWN,KC_RGHT, KC_P0 ,XXXXXXX,KC_PDOT,XXXXXXX
	)
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}