#include QMK_KEYBOARD_H

#include <stdint.h>

enum UnicodeMapIndex {
  THORN,
};

const uint32_t PROGMEM unicode_map[] = {
  [THORN] = 0x00de,
};

// TODO: Make a copy of HOME except the right side is a numpad.
// TODO: rename the layers!
enum Layer_name {
    HOME,
    SYMS,
    UTIL,
    OTHER,
    NUMPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer Navigation
   *
   * 1:HOME -> 2:SYMS -> 3:UTIL -> 4:OTHER
   *
   * At any time, the right side can be toggled in and out of numpad
   * mode; the left side stays transparent. Within numpad mode, there
   * is a NumLock to select between PgUp, PgDn, etc. keys and numpad
   * number keys. The main reason for this is for gaming, especially
   * things like DCS which require HEAVY usage of all these buttons. As
   * well, GTA V, for example, requires the numpad keys to be able to
   * pilot aircraft.
   */

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | To HOME|   1  |   2  |   3  |   4  |   5  |LEFT  |           | RIGHT|  6   |  7   |  8   |  9   |  0   | -      |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |  Q   |  W   |  E   |  R   |  T   |      |           |      |  Y   |  U   |  I   |  O   |  P   | \      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |BkSp/Ctl|  A   |  S   |  D   |  F   |  G   |------|           |------|  H   |  J   |  K   |  L   |; /OFF| '"     |
 * |--------+------+------+------+------+------|LCtrl |           | TO   |------+------+------+------+------+--------|
 * | LShift |  Z   |  X   |  C   |  V   |  B   |      |           | SYMS |  N   |  M   |  ,   |  .   |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |~/SYMS|LEFT  | RIGHT| LGUI |-/LAlt|                                       |   [  |   ]  |  UP  | DOWN |~HOME |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Esc  |      |       | RAlt | RCtrl  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | NUM  |       |      |  Tab   |Enter |
 *                                 | Space|Backsp|------|       |------|   /    |  /   |
 *                                 |      |ace   | -    |       | +    |  LAlt  | LCtl |
 *                                 `--------------------'       `----------------------'
 */

  [HOME] = LAYOUT(
        // left had
        // NOTE: Do not override TO(HOME) on any layer!
        TO(HOME),        KC_1,    KC_2,     KC_3,     KC_4,   KC_5, KC_LEFT,
        KC_DEL,          KC_Q,    KC_W,     KC_E,     KC_R,   KC_T, KC_NO,
        CTL_T(KC_BSPC),  KC_A,    KC_S,     KC_D,     KC_F,   KC_G,
        KC_LSFT,         KC_Z,    KC_X,     KC_C,     KC_V,   KC_B, KC_LCTL,
        LT(SYMS,KC_GRV), KC_LEFT, KC_RGHT,  KC_LGUI,  MT(MOD_LALT,  KC_MINS),
                                               KC_ESC,        KC_NO,
                                                              TG(NUMPAD),
                                               KC_SPC,KC_BSPC,KC_MINS,

        // right hand
        KC_RGHT,  KC_6, KC_7,    KC_8,    KC_9,   KC_0,              KC_MINS,
        KC_NO,    KC_Y, KC_U,    KC_I,    KC_O,   KC_P,              KC_BSLS,
                  KC_H, KC_J,    KC_K,    KC_L,   LT(UTIL, KC_SCLN), KC_QUOT,
        TO(SYMS), KC_N, KC_M,    KC_COMM, KC_DOT, CTL_T(KC_SLSH),    KC_RSFT,
                        KC_LBRC, KC_RBRC, KC_UP,  KC_DOWN,           TT(SYMS),
        KC_RALT, KC_RCTL,
        KC_NO,
        KC_EQL,  MT(MOD_LALT,KC_TAB), MT(MOD_LCTL,KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | ^       |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  !   |  @   |  {   |  }   |  |   |      |           |      |      |  7   |  8   |  9   |  *   |  F12   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  #   |  $   |  (   |  )   |  `   |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |---------+------+------+------+------+------|      |           | TO   |------+------+------+------+------+--------|
 * |         |  %   |  ^   |  [   |  ]   |  ~   |      |           | UTIL |  &   |  1   |  2   |  3   |  \   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |  0   |  =   |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright| ^    |       | Sat+ |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       | Sat- |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [SYMS] = LAYOUT(
       // left hand
       KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,    KC_TRNS,
       KC_TRNS,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR, KC_PIPE,  KC_TRNS,
       KC_TRNS,  KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN, KC_GRV,
       KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC, KC_TILD,  KC_TRNS,
                           KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
                                                          RGB_MOD,KC_TRNS,
                                                                  KC_TRNS,
                                                  RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS,  KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS,  KC_NO,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                 KC_NO,   KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       TO(UTIL), KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                          KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG,    KC_TRNS,
       RGB_SAI,
       RGB_SAD,    RGB_HUD, RGB_HUI
    ),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ^      |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | RESET  |      | INS  | HOME | PgUp |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | DEL  | END  | PgDn |      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           | TO   |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | OTHER|      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | ^    |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [UTIL] = LAYOUT(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       QK_BOOT, KC_TRNS, KC_INS,  KC_HOME, KC_PGUP, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_DEL,  KC_END,  KC_PGDN, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       TO(OTHER),KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
    ),
/* Keymap 3: Empty
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ^      |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           | To   |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | HOME |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | ^    |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [OTHER] = LAYOUT(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       TO(HOME), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
       ),

 /* New Keymap: Numpad & Arrows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ^      | ^    | ^    | ^    | ^    | ^    | ^    |           |  6   |  7   |  8   |  9   |  0   | -_   | =+     |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ^      | ^    | ^    | ^    | ^    | ^    | ^    |           | NUM  |  7   |  8   |  9   |  -   | /    |        |
 * |--------+------+------+------+------+------|      |           | LOCK |------+------+------+------+------+--------|
 * | ^      | ^    | ^    | ^    | ^    | ^    |------|           |------|  4   |  5   |  6   |  +   | *    | ENTER  |
 * |--------+------+------+------+------+------| ^    |           | TO   |------+------+------+------+------+--------|
 * | ^      | ^    | ^    | ^    | ^    | ^    |      |           | HOME |  1   |  2   |  3   |  =   |  UP  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ^    | ^    | ^    | ^    | ^    |                                       |  0   |  .   |LEFT  | DOWN | RIGHT|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | ^    | ^    |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 | ^    | ^    | ^    |       |      |  ^     | ^    |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      | ^    |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
    [NUMPAD] = LAYOUT(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
       KC_NUM,   KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PSLS, KC_TRNS,
                 KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST, KC_PENT,
       TO(HOME), KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_UP,   KC_TRNS,
                          KC_P0,   KC_PDOT, KC_LEFT, KC_DOWN, KC_RIGHT,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    )
};
