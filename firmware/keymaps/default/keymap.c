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
    [0] = LAYOUT_ortho_3x3(
        KC_MUTE,LCTL(KC_C),LCTL(KC_V),
        KC_D,KC_E,KC_F,
        KC_MPRV,KC_MPLY,KC_MNXT
    )
};


// This block executes whenever the screen refreshes
bool oled_task_user(void) {
    // Print a basic welcoming header
    oled_write_ln_P(PSTR("--- My Keyboard ---"), false);


    // Display host operating system lock statuses
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("     "), false);
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false; // Return false to allow default QMK screensaver tasks
}
