#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define  ______ KC_TRNS

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,--------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp    |
   * |--------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \     |
   * |--------------------------------------------------------------|
   * |FN     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return    |
   * |--------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift| Up|~ `|
   * |--------------------------------------------------------------|
   * |Ctrl|Alt |LGUI|           Space          |Alt| FN|Lef|Dow|Rig |
   * `--------------------------------------------------------------'
   */
[_BL] = LAYOUT(
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,______, KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  MO(_FL), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,______,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_GRV, \
  KC_LCTL, KC_LALT,KC_LGUI,                 KC_SPC, KC_SPC,        KC_RALT,MO(_ML), KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer 
   * ,-----------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |
   * |-----------------------------------------------------------|
   * |    |Hme |Up |End|PgUp|IGN|IGN|IGN|F14|F15|RGB_M_P|RGB_HUD|RGBM|RGBT|
   * |-----------------------------------------------------------|
   * |     |Lef|Dow|Rig|PgDn|IGN|CMB|Hme|IGN|End|IGN|IGN|  CAPS  |
   * |-----------------------------------------------------------|
   * |       |HFP|RSP|RST|RPS|IGN|IGN|MUT||VU-|VU+ |IGN|Shift|Up|IGN|
   * |-----------------------------------------------------------|
   * |    |    |    |                       |   |   |End|Dow|Hom |
   * `-----------------------------------------------------------'
   */
[_FL] = LAYOUT(
  KC_GRV, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,KC_DEL ,  \
  ______,KC_HOME, KC_UP,KC_END,KC_PGUP, ______,______,______, KC_F14,KC_F15,RGB_M_P,RGB_HUD,RGB_MOD,RGB_TOG, \
  ______,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,______,FN_COMMENTBASH,KC_HOME,______,KC_END,______,______,KC_CAPS, \
  ______,______,HALFPASS,______,______,______,______,______,KC_MUTE,______,______,______,KC_RSFT, KC_UP,______, \
  ______,______,______,        ______,______,               ______,______,KC_HOME,KC_DOWN, KC_END),

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

