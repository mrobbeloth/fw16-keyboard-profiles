// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Custom keymap for Framework Laptop 16 RGB Macropad
// OSU theme: Scarlet (#BB0000) on Layer 0, Gray (#666666) on Layer 2 (VS Code macros)

#include QMK_KEYBOARD_H
#include "factory.h"

// OSU Colors in HSV
// Scarlet: H=0, S=255, V=187  (#BB0000)
// Gray:    H=0, S=0,   V=102  (#666666)
#define OSU_SCARLET_H 0
#define OSU_SCARLET_S 255
#define OSU_SCARLET_V 187

#define OSU_GRAY_H 0
#define OSU_GRAY_S 0
#define OSU_GRAY_V 102

// Store the RGB state before layer switch so we can restore it
static uint8_t saved_mode = 0;
static HSV     saved_hsv  = {0, 0, 0};
static bool    layer2_active = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Layer 0: Numpad (default)
     * ┌────┬────┬────┬────┐
     * │Esc │Calc│ =  │ <- │
     * ├────┼────┼────┼────┤
     * │NmLk│ /  │ *  │ -  │  NumLk = LT(2, KC_NUM): tap=NumLock, hold=Layer 2
     * ├────┼────┼────┼────┤
     * │ 7  │ 8  │ 9  │ +  │
     * ├────┼────┼────┼────┤
     * │ 4  │ 5  │ 6  │ +  │
     * ├────┼────┼────┼────┤
     * │ 1  │ 2  │ 3  │Entr│
     * ├────┼────┼────┼────┤
     * │ 0  │ 0  │ .  │Entr│
     * └────┴────┴────┴────┘
     */
    [_NUMLOCK] = LAYOUT(
        KC_ESC,        KC_CALC, KC_EQL,  KC_BSPC,
        LT(2, KC_NUM), KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,         KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,         KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,         KC_P2,   KC_P3,   KC_PENT,
        KC_P0,         KC_P0,   KC_PDOT, KC_PENT
    ),

    /*
     * Layer 1: Fn (activated when NumLock is off)
     * RGB controls + navigation
     */
    [_FN] = LAYOUT(
        RGB_TOG, RGB_SPI, RGB_HUI, RGB_SAI,
        _______, RGB_SPD, RGB_HUD, RGB_SAD,
        _______, _______, _______, RGB_MOD,
        _______, _______, _______, RGB_RMOD,
        _______, _______, _______, BL_STEP,
        _______, _______, _______, BL_STEP
    ),

    /*
     * Layer 2: VS Code Macro Grid (hold NumLock)
     * Uses MACRO(4)-MACRO(15) on numpad keys
     * +, Enter, ., 3 pass through to Layer 0
     */
    [_FACTORY] = LAYOUT(
        KC_A,    KC_B,    KC_C,    KC_D,
        KC_E,    KC_F,    KC_G,    KC_H,
        KC_I,    KC_J,    KC_K,    KC_L,
        KC_M,    KC_N,    KC_O,    KC_P,
        KC_Q,    KC_R,    KC_S,    KC_T,
        KC_U,    KC_V,    KC_W,    KC_X
    ),
};

bool led_update_user(led_t led_state) {
    if (led_state.num_lock) {
        layer_off(_FN);
    } else {
        layer_on(_FN);
    }
    return true;
}

void enable_factory_mode(bool enable) {
    if (enable)
        layer_on(_FACTORY);
    else
        layer_off(_FACTORY);
}

// Layer-based RGB switching for OSU theme
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t highest = get_highest_layer(state);

    if (highest == 2 && !layer2_active) {
        // Entering Layer 2: save current RGB state, switch to gray breathing
        saved_mode = rgb_matrix_get_mode();
        saved_hsv  = rgb_matrix_get_hsv();
        layer2_active = true;

        rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
        rgb_matrix_sethsv_noeeprom(OSU_GRAY_H, OSU_GRAY_S, OSU_GRAY_V);
    } else if (highest != 2 && layer2_active) {
        // Leaving Layer 2: restore previous RGB state
        layer2_active = false;

        rgb_matrix_mode_noeeprom(saved_mode);
        rgb_matrix_sethsv_noeeprom(saved_hsv.h, saved_hsv.s, saved_hsv.v);
    }

    return state;
}
