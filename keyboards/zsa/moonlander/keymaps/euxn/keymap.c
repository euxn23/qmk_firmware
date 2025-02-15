#include QMK_KEYBOARD_H
#include "version.h"

const key_override_t scln_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_SCLN);
const key_override_t cln_override = ko_make_with_layers_and_negmods(0, KC_SCLN, S(KC_SCLN), ~0, MOD_MASK_SHIFT);

const key_override_t *key_overrides[] = {
    &scln_override,
    &cln_override,
};

enum layers {
    BASE,  // default layer
    META,
    GAME,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,              KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,
 LALT_T(KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    MO(META),         MO(META), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_RBRC,           KC_LBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
LT(META,KC_MHEN),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LT(META,KC_HENK),
        KC_LALT, XXXXXXX, XXXXXXX, KC_F7,   KC_RPRN,          KC_GRV,            KC_QUOT,          KC_LPRN, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
                                     LSFT_T(KC_SPC), KC_LGUI, MO(META),         MO(META), KC_SPC,  LSFT_T(KC_SPC)
    ),

    [META] = LAYOUT_moonlander(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, TO(GAME),XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,           XXXXXXX,          XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                            XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [GAME] = LAYOUT_moonlander(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,              KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    MO(META),         MO(META), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_RBRC,           KC_LBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LALT, TO(BASE),XXXXXXX, KC_F7,   KC_RPRN,          KC_GRV,            KC_QUOT,          KC_LPRN, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
                                            KC_SPC,  KC_LGUI, MO(META),         MO(META), KC_SPC,  KC_SPC
    ),
};
