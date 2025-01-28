// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H

#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum user_rgb_mode {
    RGB_MODE_ALL,
    RGB_MODE_NONE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5,                         KC_MPLY, KC_MPLY,           KC_6, KC_7, KC_8, KC_9, KC_0, LT(3,KC_EQL),
                 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                                      KC_Y, KC_U, KC_I, KC_O, KC_P, LT(2,KC_MINS),
                 TO(1), KC_A, KC_S, KC_D, KC_F, KC_G,                                                       KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                         KC_DOWN, KC_UP,             KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, LT(0,KC_RSFT),
                 KC_LGUI, LCTL_T(KC_ENT), LALT_T(KC_HOME),                  LT(1,KC_SPC),LT(1,KC_SPC),      RALT_T(KC_END), RCTL_T(KC_ENT), RGUI_T(KC_BSPC)),

    [1] = LAYOUT(KC_TRNS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_HOME,      KC_TRNS, KC_TRNS,               KC_HOME, KC_MPRV, KC_MPLY, KC_MFFD, KC_MUTE, KC_TRNS,
                 KC_TRNS, KC_NO, KC_NO, KC_UP, KC_NO, KC_PGUP,                                              KC_PGUP, KC_NO, KC_UP, KC_NO, KC_NO, KC_TRNS,
                 KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_TRNS,
                 LSFT_T(KC_CAPS), KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_END,   KC_COPY, KC_PSTE,           KC_END, KC_PIPE, KC_SCLN, KC_COLN, KC_BSLS, RSFT(KC_CAPS),
                 KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS),

    [2] = LAYOUT(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_NO, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_TRNS, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_TRNS, KC_TRNS, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PAST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_CUT, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_PSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [3] = LAYOUT(KC_TRNS, QK_BOOTLOADER, KC_NO, KC_NO, KC_NO, KC_NO, QK_AUTO_SHIFT_TOGGLE, QK_AUTO_SHIFT_TOGGLE, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOTLOADER, KC_TRNS, KC_NO, RGB_HUI, RGB_SAI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, BL_ON, BL_UP, KC_NO, KC_TRNS, KC_NO, RGB_HUD, RGB_SAD, RGB_SAD, RGB_VAD, RGB_SPD, BL_STEP, BL_BRTG, BL_OFF, BL_DOWN, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, AS_TOGG, AS_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [1] = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

#ifdef OLED_ENABLE
static void print_status_narrow(void) {
    // Create OLED content
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(""), false);
    oled_write_P(PSTR(" Ranzboard -58-"), false);
    oled_write_P(PSTR("\n"), false);

    // Print current layer
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("-Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("-Nav \n"), false);
            break;
        case 2:
            oled_write_P(PSTR("-Func\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("-RGB \n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("Caps- lock"), led_usb_state.caps_lock);

#ifdef AUTO_SHIFT_ENABLE

    bool autoshift = get_autoshift_state();
    oled_advance_page(true);
    oled_write_P(PSTR("Auto-Shift"), autoshift);
    oled_advance_page(true);

#endif


}

bool oled_task_user(void) {
    // Render the OLED
    print_status_narrow();
    return false;
}


#endif

#ifdef OS_DETECT_ENABLE
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            rgb_matrix_set_color_all(RGB_WHITE);
            break;
        case OS_WINDOWS:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case OS_LINUX:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case OS_UNSURE:
            rgb_matrix_set_color_all(RGB_RED);
            break;
    }

    return true;
}
#endif



bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    rgb_matrix_set_color(0, 255, 255, 255);
    return true;
}
