#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define RVRS 1 // control / gui reversal
#define SYMB 2 // symbols

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |   -  |   =  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  ALT |           |   '  |   Y  |   U  |   I  |   O  |   P  |   BS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  Enter |
 * |--------+------+------+------+------+------|   ]  |           |   [  |------+------+------+------+------+--------|
 * | CtE/~L2|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | CtH/GUI|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LALT |  GUI |   *  | MODE | )/~L2|                                       | (/~L2| Left | Down |  UP  | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   ]  | HOME |       | PgUp |   [  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  END |       | PgDn |      |      |
 *                                 | Space|  GUI |------|       |------| Enter| Space|
 *                                 |/Shift|      | MODE |       | Layer| /~L2 |/Shift|
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        GUI_T(KC_ESC),  KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,
        ALT_T(KC_TAB),  KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_LALT,
        KC_LCTL,        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        LT(SYMB, KC_MHEN),KC_Z,     KC_X,       KC_C,       KC_V,       KC_B,       KC_RBRC,
        KC_LALT,        KC_LGUI,    KC_ASTR,    TG(RVRS),   LT(SYMB, KC_RPRN),
                                                            KC_RBRC,    KC_HOME,
                                                                        KC_END,
                                             SFT_T(KC_SPC), KC_LGUI,    TG(RVRS),
        // right hand
        KC_7,           KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSLS,
        KC_QUOT,        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
                        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
        KC_LBRC,        KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    GUI_T(KC_HENK),
                       LT(SYMB, KC_LPRN),    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,
        KC_PGUP,        KC_LBRC,
        KC_PGDN,
        TG(SYMB),       LT(SYMB,KC_ENT), SFT_T(KC_SPC)
),
/* Keymap 1: Control / GUI reversal
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LGUI  |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | F16/CTL|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | MODE |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | LCTL |------|       |------|      |      |
 *                                 |      |      | MODE |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RVRS] = KEYMAP(
       // left hand
       CTL_T(KC_ESC),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_LGUI,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_LCTL,KC_TRNS,
       // right hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,CTL_T(KC_HENK),
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS
),
/* Keymap 2: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | PrtScr |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   DEL  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  END |      |      |      |           |      |      |      |      |      |  UP  |        |
 * |--------+------+------+------+------+------|      |           |   `  |------+------+------+------+------+--------|
 * |        | HOME |      |      | RIGHT|      |------|           |------|  LEFT| DOWN |  UP  | RIGHT|   =  |    ~   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      | LEFT |      |           |      | DOWN |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RESET|      |      |      |   ]  |                                       |   [  | HOME | PgDn | PgUp | END |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_PSCR,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_END,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_HOME,KC_TRNS,KC_TRNS,KC_RIGHT,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_LEFT,KC_TRNS,
       RESET  ,KC_TRNS,KC_TRNS,KC_TRNS,KC_RBRC,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL,
       KC_GRV, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_UP  ,KC_TRNS,
               KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,KC_EQL,RSFT(KC_GRV),
       KC_TRNS,KC_DOWN,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_LBRC,KC_HOME,KC_PGDN,KC_PGUP,KC_END,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
