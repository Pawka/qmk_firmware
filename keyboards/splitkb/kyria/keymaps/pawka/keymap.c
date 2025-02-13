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
#include "g/keymap_combo.h"

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
    _NUM,
    _MOUSE,
    _LOCALE,
    _MEDIA,
};

// Tap Dance declarations
enum {
    TD_MPP, // Mute, play/pause
};

// Aliases for readability
#define LOCALE   MO(_LOCALE)
#define NUM      MO(_NUM)
#define MOUSE    MO(_MOUSE)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_TAB  MT(MOD_LCTL, KC_TAB)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Layers
#define LT_ENT   LT(_NUM, KC_ENT)
#define LT_BSPC  LT(_SYM, KC_BSPC)
#define LT_DEL   LT(_LOCALE, KC_DEL)
#define LT_TAB   LT(_MOUSE, KC_TAB)
#define LT_SPC   LT(_NAV, KC_SPC)
#define LT_G     LT(_MOUSE, KC_G)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#define UNDO  LCTL(KC_Z)
#define REDO  LCTL(LSFT(KC_Z))
#define CUT   LCTL(KC_X)
#define COPY  LCTL(KC_C)
#define PASTE LCTL(KC_V)

// Navigation shortcuts
#define PREV_TAB LCTL(KC_PGUP)
#define NEXT_TAB LCTL(KC_PGDN)
#define NEW_TAB LCTL(KC_T)
#define CLOSE_TAB LCTL(KC_W)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
     KC_ESC , KC_Q  , KC_W  , KC_E   , KC_R   , KC_T  ,                                         KC_Y   , KC_U   , KC_I   , KC_O  , KC_P ,    KC_BSLASH,
     KC_LSFT, KC_A  , HOME_S, HOME_D , HOME_F , LT_G  ,                                         KC_H   , HOME_J , HOME_K , HOME_L, KC_SCLN , CTL_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C   , KC_V   , KC_B  , KC_LBRC, TG(_MOUSE),  _______, KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,
                              TD(TD_MPP), _______, KC_LGUI, LT_SPC , CTL_TAB, LT_ENT , LT_BSPC, LT_DEL , NUM    , _______),

    [_LOCALE] = LAYOUT(
      _______, RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5),    RALT(KC_6), RALT(KC_7), RALT(KC_8), RALT(KC_9), RALT(KC_0), RALT(KC_EQL),
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, KC_TRNS, _______
    ),
    [_NAV] = LAYOUT(
      _______, _______, PREV_TAB,NEW_TAB, NEXT_TAB,_______,                                     REDO,    PASTE,   COPY,    CUT,     UNDO, _______,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______,
      _______, _______, _______, CLOSE_TAB,_______, _______, _______, _______, _______, _______,KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
     _______ , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                     KC_PIPE, KC_UNDS, KC_PLUS, KC_ASTR, _______, _______,
     _______ , _______, KC_DLR,  KC_CIRC, KC_PIPE, KC_GRAVE,                                    KC_AMPR, KC_EQL , KC_MINS, KC_SLSH, _______, _______,
     _______ , _______, _______, _______, _______, KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     REDO, KC_PASTE, KC_MS_U, KC_CUT, KC_UNDO, RESET,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
                                 _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, _______, _______
    ),

    [_NUM] = LAYOUT(
      _______,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                                      KC_6  ,  KC_7  ,  KC_8  ,  KC_9  , KC_0   , KC_MINS,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                                      KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_F11,  KC_F12, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Scroll up/down
        if (clockwise) {
            tap_code(KC_WH_D);
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
            tap_code(KC_WH_U);
        }
    }
    return false;
}
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Win
        case HOME_A:
        case HOME_SCLN:
            return TAPPING_TERM + 250;
        // Alt
        case HOME_S:
        case HOME_L:
            return TAPPING_TERM + 50;
        // Ctrl
        case HOME_D:
        case HOME_K:
        case CTL_TAB:
            return TAPPING_TERM - 30;
        // Shift
        case HOME_F:
        case HOME_J:
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}

// Tap dance actions should be registereg here.
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for mute, twice for play/pause
    [TD_MPP] = ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MPLY),
};
