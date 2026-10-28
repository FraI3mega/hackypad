// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │MUT│c+C│c+V│
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * ├───┼───┼───┤
     * │PRV│PLY│NXT│
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x3(KC_MUTE, LCTL(KC_C), LCTL(KC_V), KC_D, KC_E, KC_F,
                           KC_MPRV, KC_MPLY, KC_MNXT)};

// This block executes whenever the screen refreshes

const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = {ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("OLED_test OK"), false);

  // switch (get_highest_layer(layer_state)) {
  //     case _BASE:
  //         oled_write_P(PSTR("ASdf"), false);
  //         break;
  //     default:
  //         // Or use the write_ln shortcut over adding '\n' to the end of your
  //         string oled_write_ln_P(PSTR("Undefined"), false);
  // }

  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
  oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

  return false;
}
#endif
