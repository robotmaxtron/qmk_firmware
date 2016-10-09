#include "gh60.h"
#include "action_layer.h"

#define _BL 0
#define _AL 1
#define _FL 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /*
   *  Base layer, pretty standard ANSI layout. 
   * ,-----------------------------------------------------------.
   * |FN12| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |Caps/Fn|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space             |Alt |Gui |Menu|Ctrl|
   * `-----------------------------------------------------------'
   */
	[_BL] = KEYMAP(
        FN12,1,2,3,4,5,6,7,8,9,0,MINS,EQL,BSPC, \
	TAB,Q,W,E,R,T,Y,U,I,O,P,LBRC,RBRC,BSLS, \
        FN2,A,S,D,F,G,H,J,K,L,SCLN,QUOT,NO,ENT,  \
        LSFT,NO,Z,X,C,V,B,N,M,COMM,DOT,SLSH,RSFT,FN0, \
        LCTL,LGUI,LALT,        SPC,      NO,RALT,RGUI,APP, RCTL),
   
   /*  
   * Locking arrow keys to WASD for when you need dedicated arrow keys
   * ,-----------------------------------------------------------.
   * |    |  |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |       |Left|Down|Rght|   |   |   |   |   |   |   |   |    |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
	[_AL] = KEYMAP(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,UP,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   \
        TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS,TRNS),


   /* 
   * Primary function layer, mostly the same as the traditional Pok3r layout.
   * ,-------------------------------------------------------------.
   * |`~ | F1| F2| F3| F4| F5| F6| F7| F8| F9| F10| F11| F12|DEL   |
   * |-------------------------------------------------------------|
   * |    |_AL|   |   |  |  |Calc|PgUp|Up|PgDn|Ptscn|Srlck|Pause|  |
   * |-------------------------------------------------------------|
   * |      |   |   |   |   |   |Home|Left|Down|Rght|Ins|   |      |
   * |-------------------------------------------------------------|
   * |        |   |   |   |   |   |   |    |    |    |   |     |   |
   * |-------------------------------------------------------------|
   * |    |    |    |                          |    |    |    |    |
   * `-------------------------------------------------------------'
   */
	[_FL] = KEYMAP(
        GRAVE,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12, DELETE, \
        TRNS,FN1,TRNS,TRNS,TRNS,TRNS,CALC,PGUP,UP,PGDN,PSCR,SLCK,PAUS,TRNS, \
        TRNS,MUTE,_VOLDOWN,_VOLUP,TRNS,TRNS,HOME,LEFT,DOWN,RGHT,INS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,END,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,          TRNS,               TRNS,TRNS,TRNS,TRNS,TRNS),
   
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_MOMENTARY(2),  // Momentary Fn overlay
    [1]  = ACTION_LAYER_TOGGLE(1),     // Toggle Arrow Layer overlay
    [2]  = ACTION_LAYER_TAP_KEY(2, KC_CAPS), // Tap to toggle caps lock and hold to activate function layer
    [12] = ACTION_FUNCTION(SHIFT_ESC),
};

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

void matrix_scan_user(void) {

// Layer LED indicators
// ESC led on when in function layer, WASD cluster leds enabled when on arrow cluster
    uint32_t layer = layer_state;
    if (layer & (1<<1)) {
        gh60_wasd_leds_on();
    } else {
        gh60_wasd_leds_off();
    }

    if (layer & (1<<2)) {
        gh60_esc_led_on();
    } else {
        gh60_esc_led_off();
    }
};

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
     //led operations
    static uint8_t shift_esc_shift_mask;
    // Shift + ESC = ~
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
    }
};
