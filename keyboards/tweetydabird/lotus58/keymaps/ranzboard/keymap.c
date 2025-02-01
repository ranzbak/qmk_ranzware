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
    [0] = LAYOUT(QK_GESC,        KC_1,    KC_2, KC_3, KC_4, KC_5,                      KC_MPLY, KC_MPLY,           KC_6, KC_7, KC_8,    KC_9,   KC_0,    LT(3,KC_EQL),
                 LT(2, KC_TAB),  KC_Q,    KC_W, KC_E, KC_R, KC_T,                                                  KC_Y, KC_U, KC_I,    KC_O,   KC_P,    LT(2,KC_MINS),
                 LT(1, KC_CAPS), KC_A,    KC_S, KC_D, KC_F, KC_G,                                                  KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
                 KC_LSFT,        KC_Z,    KC_X, KC_C, KC_V, KC_B,                      KC_DOWN, KC_UP,             KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                 KC_LCTL, KC_LGUI, KC_LALT,                       LT(1,KC_SPC),LT(1,KC_SPC),       KC_RALT,    KC_RGUI, KC_RCTL
                 ),

    [1] = LAYOUT(KC_TRNS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_HOME,      KC_TRNS, KC_TRNS,               KC_HOME, KC_MPRV, KC_MPLY, KC_MFFD, KC_MUTE, KC_BSPC,
                 KC_TRNS, KC_NO, KC_NO, KC_UP, KC_NO, KC_PGUP,                                              KC_PGUP, KC_NO, KC_UP, KC_LBRC, KC_RBRC, KC_BSLS,
                 KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_ENT,
                 LSFT_T(KC_CAPS), KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_END,   KC_COPY, KC_PSTE,           KC_END, KC_PIPE, KC_SCLN, KC_COLN, KC_BSLS, RSFT(KC_CAPS),
                 KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
                 ),

    [2] = LAYOUT(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                    KC_TRNS, KC_TRNS,           KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_DEL,
                 KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                                               KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_TRNS,
                 KC_TRNS, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,                                           KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PAST, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR,          KC_CUT, KC_TRNS,            KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_PSLS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
                 ),
    [3] = LAYOUT(KC_TRNS, QK_BOOTLOADER, KC_NO, KC_NO, KC_NO, KC_NO,    QK_AUTO_SHIFT_TOGGLE, QK_AUTO_SHIFT_TOGGLE,     KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOTLOADER, KC_TRNS,
                 KC_NO, RGB_HUI, RGB_SAI, RGB_SAI, RGB_VAI, RGB_SPI,                                                    RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_TRNS,
                 KC_NO, RGB_HUD, RGB_SAD, RGB_SAD, RGB_VAD, RGB_SPD,                                                    RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, KC_NO, KC_TRNS,
                 QK_AUTO_SHIFT_TOGGLE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       RGB_TOG, RGB_TOG,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_AUTO_SHIFT_TOGGLE,
                 KC_TRNS, KC_TRNS, KC_TRNS,                                     RGB_RMOD, RGB_MOD,                      KC_TRNS, KC_TRNS, KC_TRNS
                 )
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
    oled_write_P(PSTR(" Ranzboard"), false);
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
    // oled_write_ln_P(PSTR("Caps- lock"), led_usb_state.caps_lock);
    oled_write_P(PSTR("CL"), led_usb_state.caps_lock);
    oled_write_P(" ", false);

#ifdef AUTO_SHIFT_ENABLE

    bool autoshift = get_autoshift_state();
    // oled_advance_page(true);
    // oled_write_P(PSTR("Auto-Shift"), autoshift);
    oled_write_P(PSTR("AS"), autoshift);
    oled_advance_page(true);

#endif

#ifdef RGB_MATRIX_ENABLE
    uint8_t mode = rgb_matrix_get_mode();

    // Mode unint8_t to string
    char mode_str[6];
    // itoa(mode, mode_str, 10);
    snprintf(mode_str, sizeof(mode_str), "MT%.2d", mode);
    oled_write_P(PSTR(mode_str), rgb_matrix_is_enabled());
}
#endif

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

    // LED numbering
    // {  5,  4,  3,  2,  1,  0 },   {  0,  1,  2,  3,  4,  5 },
    // {  6,  7,  8,  9, 10, 11 },   { 11, 10,  9,  8,  7,  6 },
    // { 17, 16, 15, 14, 13, 12 },   { 12, 13, 14, 15, 16, 17 },
    // { 18, 19, 20, 21, 22, 23 },   { 23, 22, 21, 20, 19, 18 },
    // {NO_LED, 28, 27, 26, 25, 24}, { 24, 25, 26, 27, 28, NO_LED },

    switch (get_highest_layer(layer_state)) {
        case 0:
            rgb_matrix_set_color(13,  0, 0, 255);
            break;
        case 1:
            rgb_matrix_set_color_all(0, 0, 0);
            // Arrow
            rgb_matrix_set_color(9,  255, 0, 0);
            rgb_matrix_set_color(15, 255, 0, 0);
            rgb_matrix_set_color(14, 255, 0, 0);
            rgb_matrix_set_color(13, 255, 0, 0);
            // Page up/down home/end
            rgb_matrix_set_color(0,  0, 255, 0);
            rgb_matrix_set_color(11, 0, 255, 0);
            rgb_matrix_set_color(12, 0, 255, 0);
            rgb_matrix_set_color(23, 0, 255, 0);
            // Media keys
            rgb_matrix_set_color(1, 0, 0, 255);
            rgb_matrix_set_color(2, 0, 0, 255);
            rgb_matrix_set_color(3, 0, 0, 255);
            rgb_matrix_set_color(4, 0, 0, 255);

            break;
        case 2:
            int f_key_array[] = {
            4, 3, 2, 1, 0,
            7,8,9, 10,11,
            16,15,14,13,12
            };
            int numpad_array[] ={
                1  , 2  ,  3,
                10  , 9  ,  8,
                13 , 14 , 15,
                         21,

            };
            int numops_array[] = {
                4, 7, 16, 19, 20
            };
            if (is_keyboard_left()) {
                for (int i = 0; i < (sizeof(f_key_array)/sizeof(int)); i++) {
                    rgb_matrix_set_color(f_key_array[i], 255, 0, 0);
                }
            } else {
                // Highlight numpad numbers
                for (int i = 0; i < (sizeof(numpad_array)/sizeof(int)); i++) {
                    rgb_matrix_set_color(numpad_array[i], 0, 255, 0);
                }
                // Highlight number operations
                for (int i = 0; i < (sizeof(numops_array)/sizeof(int)); i++) {
                    rgb_matrix_set_color(numops_array[i], 0, 0, 255);
                }
            }
            break;
        case 3:
            // Two flash keys red
            rgb_matrix_set_color(4, 255, 0, 0);
            break;
        default:
            rgb_matrix_set_color_all(0, 0, 0);
            break;
    }

    // Indicate left and right half

    return true;
}
