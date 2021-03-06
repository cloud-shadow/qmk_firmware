#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define ADDI 3 // cshadow add (poker3 compatible)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |  L1  |           | INS  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB/L3 |   Q  |   W  |   E  |   R  |   T  | MEH  |           |Backsp|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |ace   |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------| ESC  |           |Enter |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1| LGUI |  Alt | Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |SftSpc| App  |       | Home | End    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |CtlTab|       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------| Del    |Space |
 *                                 |      |ace   |AltTab|       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,          KC_2,   KC_3,   KC_4,   KC_5,   TG(SYMB),  
        LT(ADDI,KC_TAB),KC_Q,          KC_W,   KC_E,   KC_R,   KC_T,   MEH_T(KC_NO),
        KC_LCTL,        KC_A,          KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,          KC_X,   KC_C,   KC_V,   KC_B,   KC_ESC,
        LT(SYMB,KC_GRV),KC_LGUI,KC_LALT,KC_LEFT,KC_RGHT,
                                               LSFT(KC_SPC), KC_APP,
                                                               LCTL(KC_TAB),
                                               KC_SPC,KC_BSPC,LALT(KC_TAB),


                            // right hand
                                 KC_INS,      KC_6,   KC_7,   KC_8,   KC_9,    KC_0,              KC_MINS,
                                 KC_BSPC,     KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,              KC_BSLS,
                                              KC_H,   KC_J,   KC_K,   KC_L,    LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
                                 KC_ENT ,     KC_N,   KC_M,   KC_COMM,KC_DOT,  CTL_T(KC_SLSH),    KC_RSFT,
                                                      KC_UP,  KC_DOWN,KC_LBRC, KC_RBRC,           KC_FN1,
                                 KC_HOME,  KC_END,
                                 KC_PGUP,
                                 KC_PGDN,  KC_DELT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    ~   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CAPS  |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
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
       KC_TILD,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_CAPS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |ShftF1|ShftF2|ShftF3|ShftF4|ShftF5|      |           |      |ShftF6|ShftF7|ShftF8|ShftF9|ShtF10|ShftF11 |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Lclk | MsUp | Rclk | MWUp |      |      |           |Shift | PgUp | Home |  Up  | End  |      |ShftF12 |
 * |--------+------+------+------+------+------|      |           | +F11 |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght| MWDn |      |------|           |------| PgDn | Left | Down | Right|      |  Play  |
 * |--------+------+------+------+------+------|      |           |Shift |------+------+------+------+------+--------|
 * |        |      | Mclk |      |      |      |      |           | +F12 |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |MWLeft|MWRght|                                       |SftSpc|VolUp |VolDn | Mute |      |
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
       KC_ESC , LSFT(KC_F1), LSFT(KC_F2), LSFT(KC_F3), LSFT(KC_F4), LSFT(KC_F5), KC_TRNS,
       KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_R,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  LSFT(KC_F6), LSFT(KC_F7), LSFT(KC_F8), LSFT(KC_F9), LSFT(KC_F10), LSFT(KC_F11), 
       LSFT(KC_F11), KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TRNS, LSFT(KC_F12),
                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_MPLY,
       LSFT(KC_F12), KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                         LSFT(KC_SPC), KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: cshadow add
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |CtrlF1|CtrlF2|CtrlF3|CtrlF4|CtrlF5|      |           |      |CtrlF6|CtrlF7|CtrlF8|CtflF9|CtrF10|        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | Ctrl |      |      | Home | End  | PgUp |Backspce|
 * |--------+------+------+------+------+------|      |           |  F11 |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down | Up   | Right| PgDn |Enter   |
 * |--------+------+------+------+------+------|      |           | Ctrl |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |  F12 | Del  |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | M0   |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// cshadow add (poker3 compatible)
[ADDI] = KEYMAP(
       // left hand
       KC_TRNS, LCTL(KC_F1), LCTL(KC_F2), LCTL(KC_F3), LCTL(KC_F4), LCTL(KC_F5), KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS, LCTL(KC_F6), LCTL(KC_F7), LCTL(KC_F8), LCTL(KC_F9), LCTL(KC_F10), KC_TRNS,
       LCTL(KC_F11), KC_TRNS, KC_TRNS, KC_HOME, KC_END , KC_PGUP, KC_BSPC,
                 KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGDN, KC_ENT,
       LCTL(KC_F12), KC_DELT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                 M(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN1 - Momentary Layer 1 (Symbols)
    [3] = ACTION_LAYER_TAP_TOGGLE(ADDI)                
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          // outlook junk mail 
          // register_code(KC_RSFT); // default. don't know what this mean
          return MACRO( I(100), T(APP), W(200), T(J), T(B),  END );
          // 
        } else {
          // unregister_code(KC_RSFT); // default. don't know what this mean
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
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
