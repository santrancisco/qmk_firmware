#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _ML 2

enum hype_keycodes {
  HALFPASS = SAFE_RANGE,
  FN_COMMENTBASH,
  DYNAMIC_MACRO_RANGE,
};
#include "dynamic_macro.h"

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |FN     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |LGUI|        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_ansi(
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  MO(_FL), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_PGDN, \
  KC_LCTL, KC_LALT,KC_LGUI,                KC_SPC,                        KC_RALT,MO(_ML),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer 
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |    |Hme |Up |End|PgUp|IGN|IGN|IGN|F14|F15|PSC|Bl-|Bl+|BlTG|Del |
   * |----------------------------------------------------------------|
   * |     |Lef|Dow|Rig|PgDn|IGN|CMB|Hme|IGN|End|IGN|IGN|  CAPS  |PgUp|
   * |----------------------------------------------------------------|
   * |       |HFP|RSP|RST|RPS|IGN|IGN|MUT||VU-|VU+ |IGN|Shift|Up |PgDn|
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |Ctrl|End|Dow|Hom |
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_ansi(
  KC_GRV, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,KC_HOME, KC_UP,KC_END,KC_PGUP, KC_NO,KC_NO,KC_NO, KC_F14,KC_F15,KC_PSCR,BL_DEC,BL_INC,BL_BRTG,KC_DEL, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,KC_NO,FN_COMMENTBASH,KC_HOME,KC_NO,KC_END,KC_NO,KC_NO,KC_CAPS,KC_PGUP, \
  _______,HALFPASS,DYN_REC_STOP,DYN_REC_START1,DYN_MACRO_PLAY1,KC_NO,KC_NO,KC_MUTE,KC_VOLD,KC_VOLU,KC_NO,KC_RSFT, KC_UP, KC_PGDN, \
  _______,_______,_______,                 _______,               _______,_______,KC_RCTRL,KC_HOME,KC_DOWN, KC_END),


  /* Keymap _ML: Macro Layer - For future work ?
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |    |Hme |Up |End|PgUp|IGN|IGN|IGN|F14|F15|PSC|Bl-|Bl+|BlTG|Del |
   * |----------------------------------------------------------------|
   * |     |Lef|Dow|Rig|PgDn|IGN|CMB|Hme|IGN|End|IGN|IGN|  CAPS  |PgUp|
   * |----------------------------------------------------------------|
   * |       |HFP|RSP|RST|RPS|IGN|IGN|MUT||VU-|VU+ |IGN|Shift|Up |PgDn|
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |Ctrl|End|Dow|Hom |
   * `----------------------------------------------------------------'
   */
[_ML] = LAYOUT_ansi(
  KC_GRV, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,KC_HOME, KC_UP,KC_END,KC_PGUP, KC_NO,KC_NO,KC_NO, KC_F14,KC_F15,KC_PSCR,BL_DEC,BL_INC,BL_BRTG,KC_DEL, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,KC_NO,FN_COMMENTBASH,KC_HOME,KC_NO,KC_END,KC_NO,KC_NO,KC_CAPS,KC_PGUP, \
  _______,HALFPASS,DYN_REC_STOP,DYN_REC_START1,DYN_MACRO_PLAY1,KC_NO,KC_NO,KC_MUTE,KC_VOLD,KC_VOLU,KC_NO,KC_RSFT, KC_UP, KC_PGDN, \
  _______,_______,_______,                 _______,               _______,_______,KC_RCTRL,KC_HOME,KC_DOWN, KC_END),
};

bool shiftisheld = false;
bool leftalt   = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
       return false;
   }
  switch (keycode) {
    case KC_LSFT:
        if (record->event.pressed)
        {
          shiftisheld = true;
        }
        else {
          shiftisheld = false;
        }
      break;
    case KC_LALT:
        if (record->event.pressed)
        {
          leftalt = true;
        }
        else {
          leftalt = false;
        }
      break;
    case KC_2:
      if (record->event.pressed && leftalt == true)
      {
        SEND_STRING(SS_TAP(X_F2));
        return false;
      }
      break;
    case KC_ESC:
      if (record->event.pressed && shiftisheld == true)
      {
        SEND_STRING("~");
        return false;
      }
      if (record->event.pressed && leftalt == true)
      {
        SEND_STRING("`");
        return false;
      }
      break;
    case FN_COMMENTBASH:
      if (record->event.pressed)
      {
        SEND_STRING(SS_TAP(X_HOME) "#");
        return false;
      }
      break;
    case HALFPASS:
      if (record->event.pressed)
      {
        SEND_STRING("your_half_of_password");
      }
      return false;
      break;

    // Just a test to see how customed button and layer manipulation works.
    // case FN_SAN:
    //   if (record->event.pressed)
    //   {
    //     layer_on(_FL);
    //   }
    //   else
    //   {
    //     layer_off(_FL);
    //   }
    //   return false;
    //   break;
  }
  return true;
}
