#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // Arrows/Numpad
#define MDIA 2 // Mouse controls

#define EPRM M(1) // Macro 1: Reset EEPROM

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,----------------------------------------------------.           ,----------------------------------------------------.
 * |   ~`     |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |Backspace |
 * |----------+------+------+------+------+-------------|           |------+------+------+------+------+------+----------|
 * | Tab      |   Q  |   W  |   E  |   R  |   T  |  {[  |           |  }]  |   Y  |   U  |   I  |   O  |   P  |   \|     |
 * |----------+------+------+------+------+------|      |           |      |------+------+------+------+------+----------|
 * | Caps     |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;     |'"        |
 * |----------+------+------+------+------+------| L1   |           | L1   |------+------+------+------+------+----------|
 * | LShift   |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |/?    | RShift   |
 * `--------+------+------+------+------+---------------'           `-------------+------+------+------+------+----------'
 *   |LCtrl |LSuper|LAlt  | L2   |  L3  |                                       | -_   | +=   |RAlt |RSuper |RCtrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ESC  |Insert|       |  Up  | Down |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Home |       | PgUp |       |      |
 *                                 | Enter|Shift |------|       |------|Backspa|Space |
 *                                 |      |      | End  |       | PgDn |ce     |      |
 *                                 `--------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,       KC_1,        KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TAB,       KC_Q,        KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
        KC_CAPS,      KC_A,        KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,      KC_Z,        KC_X,   KC_C,   KC_V,   KC_B,   KC_FN1,
        KC_LCTL,      KC_LGUI,     KC_LALT,KC_FN2, KC_FN3,
                                                       KC_ESC,KC_INS,
                                                              KC_HOME,
                                               KC_ENT,KC_LSFT,KC_END,
        // right hand
             KC_RGHT,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,      KC_BSPC,
             KC_RBRC,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,      KC_BSLS,
                        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,   KC_QUOT,
             KC_FN1,    KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,
                                KC_MINS,KC_EQL, KC_RALT,KC_RGUI,   KC_RCTL,
             KC_UP,KC_DOWN,
             KC_PGUP,
             KC_PGDN,KC_BSPC, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |      |      |      |      |      |      |           |      |      |      |      |      |      |   DEL  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |Prtscn|      |           |      | Num  |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |SPACE |ENTER |------|       |------|DEL   |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       M(0),   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_PSCR,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                                 KC_SPC,KC_ENT,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
       KC_TRNS, KC_NLCK, KC_P7,  KC_P8,   KC_P9,   KC_PAST, KC_TRNS,
                KC_TRNS, KC_P4,  KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P1,  KC_P2,   KC_P3,   KC_PSLS, KC_TRNS,
                         KC_P0,  KC_P0,   KC_DOT,  KC_PEQL, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_DEL, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   |  F5  |      |           |      | F6   | F7   | F8   | F9   | F10  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | UP   |      |      |      |      |           |      |      |Lclk  | MsUp | Rclk |      |  F11   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | LEFT | DOWN | RIGHT|      |      |------|           |------|      |MsLeft|MsDown|MsRght|      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_LEFT, KC_DOWN, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_F11,
                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_F12,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(SYMB),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TOGGLE(SYMB),
    [3] = ACTION_LAYER_TOGGLE(MDIA),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
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
    switch (layer) {
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
void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // Turn capslock on
        ergodox_right_led_3_on();
    } else{
        // Turn capslock off
        ergodox_right_led_3_off();
	  }
	
};
