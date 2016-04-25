static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap: Default Layer in QWERTY
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ~    |   1  |   2  |   3  |   4  |   5  |   \  |           |   -  |   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  | ~L5  |           | ~L6  |   Y  |   U  |   I  |   O  |   P  |   [    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Tab/Shf|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------|  L0  |           | ~L7  |------+------+------+------+------+--------|
     * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   ]    |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~L5  | ~L2  | Caps | LAlt | LGui |                                       |  Lft |  Up  |  Dn  | Rght | ~L6  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | +L2  | Home |       | PgUp | Del  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |  End |       | PgDn |      |      |
     *                                 | BkSp |  ESC |------|       |------| Enter| Space|
     *                                 |      |      |  Spc |       | Ins  |      |      |
     *                                 `--------------------'       `--------------------'
     *
     *
     *
     ****************************************************************************************************
     *
     * Description here eventually.
     *
     ****************************************************************************************************
     */

    KEYMAP(  // Layer0: Default
        // left hand
        GRV,        1,      2,      3,      4,      5,          FN9,
        TAB,        Q,      W,      E,      R,      T,          QUOT,
        FN4,        A,      S,      D,      F,      G,
        LSFT,       Z,      X,      C,      V,      B,          MINS,
        LCTL,       LGUI,   LALT,   NO,     FN3,
                                                                NO,         NO,
                                                                            NO,
                                                    BSPC,       SPC,        FN1,
        // right hand
                FN10,       6,      7,      8,      9,      0,          DEL,
                FN15,       Y,      U,      I,      O,      P,          BSLS,
                            H,      J,      K,      L,      SCLN,       QUOT,
                EQL,        N,      M,      COMM,   DOT,   SLSH,        RSFT,
                            LEFT,   DOWN,   UP,     RGHT,   RCTL,
        NO,     NO,
        NO,
        FN2,    ENT,        ESC
    ),

    KEYMAP(  // Layer1: Symbols
        // left hand
        NO,         NO,     NO,     NO,     NO,     NO,         NO,
        NO,         NO,     NO,     NO,     NO,     NO,         NO,
        TRNS,        NO,     NO,     NO,     NO,     NO,
        TRNS,       NO,     NO,     NO,     NO,     NO,         NO,
        TRNS,       TRNS,   TRNS,   TRNS,   TRNS,
                                                                NO,     NO,
                                                                        NO,
                                                        TRNS,   TRNS,   TRNS,
        // right hand
                NO,         NO,     NO,     NO,     NO,     NO,         NO,
                NO,         NO,     7,      8,      9,      0,          NO,
                            NO,     4,      5,      6,      NO,         NO,
                NO,         NO,     1,      2,      3,      NO,         TRNS,
                            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
        NO,     NO,
        NO,
        TRNS,   ENT,     0
    ),

    KEYMAP(  // Layer2: Navigation
        // left hand
        NO,         NO,     NO,     NO,     NO,     NO,         NO,
        NO,         NO,     NO,     NO,     NO,     NO,         NO,
        TRNS,       NO,     NO,     NO,     NO,     NO,
        TRNS,       NO,     NO,     NO,     NO,     NO,         NO,
        TRNS,       TRNS,   TRNS,   TRNS,   TRNS,
                                                                NO,     NO,
                                                                        NO,
                                                        TRNS,   TRNS,   TRNS,
        // right hand
                NO,         NO,     NO,     NO,     NO,     NO,         NO,
                NO,         NO,     NO,     NO,     NO,     NO,         NO,
                            LEFT,   DOWN,   UP,     RIGHT,  NO,         NO,
                NO,         NO,     NO,     NO,     NO,     NO,         TRNS,
                            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
        NO,     NO,
        NO,
        TRNS,   TRNS,       TRNS
    ),

    KEYMAP(  // Layer3: Media
        // left hand
        NO,         NO,     NO,     NO,     NO,     NO,         NO,
        NO,         NO,     NO,     NO,     NO,     NO,         NO,
        TRNS,       NO,     NO,     NO,     NO,     NO,
        TRNS,       NO,     NO,     NO,     NO,     NO,         NO,
        TRNS,       TRNS,   TRNS,   TRNS,   TRNS,
                                                                NO,     NO,
                                                                        NO,
                                                        TRNS,   TRNS,   TRNS,
        // right hand
                NO,         NO,     NO,     NO,     NO,     NO,         NO,
                NO,         NO,     NO,     NO,     NO,     NO,         NO,
                            MPRV,   VOLD,   VOLU,   MNXT,   NO,         NO,
                NO,         NO,     NO,     NO,     NO,     NO,         TRNS,
                            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
        NO,     NO,
        NO,
        TRNS,   MPLY,       TRNS
    ),

    KEYMAP(  // Layer4: Quick symbols
        // left hand
        NO,         NO,     NO,     NO,     NO,     NO,         NO,
        NO,         NO,     NO,     NO,     NO,     NO,         NO,
        TRNS,       NO,     NO,     NO,     NO,     NO,
        TRNS,       NO,     NO,     NO,     NO,     NO,         NO,
        TRNS,       TRNS,   TRNS,   TRNS,   TRNS,
                                                                NO,     NO,
                                                                        NO,
                                                        TRNS,   TRNS,   TRNS,
        // right hand
                NO,         NO,     NO,     NO,     NO,     NO,         NO,
                NO,         NO,     FN11,   FN15,   FN12,     NO,         NO,
                            NO,     FN9,    FN13,   FN10,   NO,         NO,
                NO,         NO,     LBRC,   QUOT,   RBRC,   NO,         TRNS,
                            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
        NO,     NO,
        NO,
        TRNS,   TRNS,       TRNS
    ),

    KEYMAP(  // Layer5: F-keys instead of numbers, leftled:top/white
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,P1,  P2,  P3,  P4,  P5,  TRNS,
        TRNS,TRNS,TRNS,E,   TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F7,  F8,  F9,  F10, F11, F12, TRNS,
             TRNS,P6,  P7,  P8,  P9,  P0,  TRNS,
                  TRNS,U,   TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer6: F-keys + utils(Teensy, Workman-layer switch), leftled:top/white+onboard
        // left hand
        FN0, F1,  F2,  F3,  F4,  F5,  F6,
        TRNS,P1,  P2,  P3,  P4,  P5,  TRNS,
        TRNS,TRNS,TRNS,E,   TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        FN18,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F7,  F8,  F9,  F10, F11, F12, FN0,
             TRNS,P6,  P7,  P8,  P9,  P0,  TRNS,
                  TRNS,U,   TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    //
    // rarely used
    //

    KEYMAP(  // Layer7: F-keys only, leftled:top/white
        // left hand
        FN0, NO,  NO,  NO,  NO,  NO,  NO,
        FN1, F13, F14, F15, F16, NO,  TRNS,
        TRNS,F17, F18, F19, F20, NO,
        TRNS,F21, F22, F23, F24, NO,  TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  F1,  F2,  F3,  F4,  TRNS,
                  NO,  F5,  F6,  F7,  F8,  TRNS,
             TRNS,NO,  F9,  F10, F11, F12, TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        SLEP,TRNS,TRNS
    ),

    KEYMAP(  // Layer8: mouse and navigation, leftled:mid/blue+bot/green
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  ACL0,NO,  TRNS,
        TRNS,NO,  NO,  TRNS,ACL1,NO,
        TRNS,NO,  NO,  TRNS,ACL2,NO,  TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,

        // right hand
             F16, MPLY,MPRV,MNXT,VOLD,VOLU,MUTE,
             F14, BTN2,WH_L,WH_U,WH_D,WH_R,PGUP,
                  BTN1,MS_L,MS_U,MS_D,MS_R,PGDN,
             F15, BTN3,HOME,END, DEL, INS, NO,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // Layer9: application-specific shortcuts (mostly browser), leftled:top/white+bot/green
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  TRNS,NO,  TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  FN12,FN13,FN14,FN15,FN10,
                  FN1, FN2, FN3, FN4, FN5, FN11,
             TRNS,TRNS,FN6, FN7, FN8, FN9, FN0,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

/*
    // templates to copy from
    KEYMAP(  // Layer1: Workman layout, leftled:all
        // left hand
        NO,         NO,     NO,     NO,     NO,     NO,         NO,
        NO,         NO,     NO,     NO,     NO,     NO,         NO,
        NO,         NO,     NO,     NO,     NO,     NO,
        TRNS,       NO,     NO,     NO,     NO,     NO,         NO,
        TRNS,       TRNS,   TRNS,   TRNS,   TRNS,
                                                                NO,     NO,
                                                                        NO,
                                                        TRNS,   TRNS,   TRNS,
        // right hand
                NO,         NO,     NO,     NO,     NO,     NO,         NO,
                NO,         NO,     NO,     NO,     NO,     NO,         NO,
                            NO,     NO,     NO,     NO,     NO,         NO,
                NO,         NO,     NO,     NO,     NO,     NO,         TRNS,
                            TRNS,   TRNS,   TRNS,   TRNS,   TRNS,
        NO,     NO,
        NO,
        TRNS,   TRNS,       TRNS
    ),

*/

};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
    CUSTOM_KEY,
    L_CTRL_ALT_ENT,
    R_CTRL_ALT_ENT,
};

enum macro_id {
    XMONAD_RESET,
    PASSWORD1,
    PASSWORD2,
    PASSWORD3,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [0] =   ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

    // Layer switching
    [1] =   ACTION_LAYER_MOMENTARY(1),                      // FN1  = Momentary Layer1
    [2] =   ACTION_LAYER_MOMENTARY(2),                      // FN2  = Momentary Layer2
    [3] =   ACTION_LAYER_MOMENTARY(3),                      // FN3  = Momentary Layer3
    [4] =   ACTION_LAYER_MOMENTARY(4),                      // FN4  = Momentary Layer4
    [5] =   ACTION_LAYER_MOMENTARY(5),                      // FN5  = Momentary Layer5
    [6] =   ACTION_LAYER_MOMENTARY(6),                      // FN6  = Momentary Layer6
    [7] =   ACTION_LAYER_MOMENTARY(7),                      // FN7  = Momentary Layer7
    [8] =   ACTION_LAYER_MOMENTARY(8),                      // FN8  = Momentary Layer8

    // Shifted symbols
    [9]  =  ACTION_MODS_KEY(MOD_LSFT, KC_9),                // FN9   = Shifted (
    [10] =  ACTION_MODS_KEY(MOD_LSFT, KC_0),                // FN10  = Shifted )
    [11] =  ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),             // FN11  = Shifted {
    [12] =  ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),             // FN12  = Shifted }
    [13] =  ACTION_MODS_KEY(MOD_LSFT, KC_MINUS),            // FN13  = Shifted _
    [14] =  ACTION_MODS_KEY(MOD_LSFT, KC_SCLN),             // FN14  = Shifted :
    [15] =  ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),             // FN15  = Shifted "

    [16] =  ACTION_MODS_TAP_KEY(MOD_RCTL, KC_RBRC),         // FN16 = RCtrl  with tap ]

    [17] =  ACTION_LAYER_SET(0, ON_BOTH),                   // FN17 - set Layer0
    [18] =  ACTION_LAYER_SET(1, ON_BOTH),                   // FN18 - set Layer1, to use Workman layout at firmware level
    [19] =  ACTION_LAYER_SET(2, ON_BOTH),                   // FN19 - set Layer2, to use with Numpad keys

    [21] =  ACTION_FUNCTION_TAP(L_CTRL_ALT_ENT),            // FN21 - momentary Layer5+CTRL+ALT on Enter, to use with F* keys on top row
    [22] =  ACTION_FUNCTION_TAP(R_CTRL_ALT_ENT),            // FN22 - momentary Layer6+CTRL+ALT on Enter, to use with F* keys on top row + utils

    [28] =  ACTION_LAYER_TAP_KEY(4, KC_A),                  // FN28 = momentary Layer4 on A key, to use with unconvenient keys
    [29] =  ACTION_LAYER_TAP_KEY(3, KC_S),                  // FN29 = momentary Layer3 on S key, to use with F* keys
    [30] =  ACTION_LAYER_TAP_KEY(8, KC_D),                  // FN30 = momentary Layer8 on D key, to use with mouse and navigation keys
    [31] =  ACTION_LAYER_TAP_KEY(2, KC_F),                  // FN31 = momentary Layer2 on F key, to use with Numpad keys

    // i'd like to remove this - will try to get used to live without this and convert them to usual keys
    [20] =  ACTION_LAYER_MOMENTARY(2),                      // FN20 - momentary Layer2, to use with Numpad keys
// or
//  [20] =  ACTION_FUNCTION_TAP(CUSTOM_KEY),                // FN20 - use custom key, with tapping support

    [23] =  ACTION_LAYER_TAP_KEY(7, KC_BSLS),               // FN23 - momentary Layer7 on ' , to use with F* keys (F1-F24)

    [24] =  ACTION_LAYER_TAP_KEY(4, KC_Z),                  // FN24 = momentary Layer4 on Z key, to use with unconvenient keys
    [25] =  ACTION_LAYER_TAP_KEY(3, KC_X),                  // FN25 = momentary Layer3 on X key, to use with F* keys
    [26] =  ACTION_LAYER_TAP_KEY(8, KC_C),                  // FN26 = momentary Layer8 on C key, to use with mouse and navigation keys
    [27] =  ACTION_LAYER_TAP_KEY(9, KC_V),                  // FN27 = momentary Layer9 on V key, to use with application-specific shortcuts
};

static const uint16_t PROGMEM fn_actions_7[] = {
    [0]  =  ACTION_MACRO(XMONAD_RESET),                     // FN0  = xmonad-reanimator
    [1]  =  ACTION_MACRO(PASSWORD1),                        // FN1  = default password
    [2]  =  ACTION_MACRO(PASSWORD1),                        // FN2  = other password
    [3]  =  ACTION_MACRO(PASSWORD1),                        // FN3  = mega password
};

static const uint16_t PROGMEM fn_actions_9[] = {
    [0]  =  ACTION_MODS_KEY(MOD_LCTL,          KC_P0),      // FN0  = Ctrl+0
    [1]  =  ACTION_MODS_KEY(MOD_LALT,          KC_P1),      // FN1  = Alt+1
    [2]  =  ACTION_MODS_KEY(MOD_LALT,          KC_P2),      // FN2  = Alt+2
    [3]  =  ACTION_MODS_KEY(MOD_LALT,          KC_P3),      // FN3  = Alt+3
    [4]  =  ACTION_MODS_KEY(MOD_LALT,          KC_P4),      // FN4  = Alt+4
    [5]  =  ACTION_MODS_KEY(MOD_LALT,          KC_P5),      // FN5  = Alt+5
    [6]  =  ACTION_MODS_KEY(MOD_LALT,          KC_P6),      // FN6  = Alt+6
    [7]  =  ACTION_MODS_KEY(MOD_LALT,          KC_P7),      // FN7  = Alt+7
    [8]  =  ACTION_MODS_KEY(MOD_LALT,          KC_P8),      // FN8  = Alt+8
    [9]  =  ACTION_MODS_KEY(MOD_LALT,          KC_P9),      // FN9  = Alt+9
    [10] =  ACTION_MODS_KEY(MOD_LCTL|MOD_LSFT, KC_TAB),     // FN10 = Ctrl+Shift+Tab
    [11] =  ACTION_MODS_KEY(MOD_LCTL,          KC_TAB),     // FN11 = Ctrl+Tab
    [12] =  ACTION_MODS_KEY(MOD_LCTL|MOD_LSFT, KC_PGUP),    // FN12 = Ctrl+Shift+PgUp
    [13] =  ACTION_MODS_KEY(MOD_LCTL|MOD_LSFT, KC_PGDN),    // FN13 = Ctrl+Shift+PgDn
    [14] =  ACTION_MODS_KEY(MOD_LCTL,          KC_PMNS),    // FN14 = Ctrl+Pad Minus
    [15] =  ACTION_MODS_KEY(MOD_LCTL,          KC_PPLS),    // FN15 = Ctrl+Pad Plus
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // print("action_function called\n");
    // print("id  = "); phex(id); print("\n");
    // print("opt = "); phex(opt); print("\n");

    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(50);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }

    if (id == L_CTRL_ALT_ENT || id == R_CTRL_ALT_ENT) {
        if (record->tap.count == 0 || record->tap.interrupted) {
            uint8_t weak_mods;
            uint8_t layer;

            if (id == L_CTRL_ALT_ENT) {
                weak_mods = MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT);
                layer     = 5;
            } else {
                weak_mods = MOD_BIT(KC_RCTL) | MOD_BIT(KC_RALT);
                layer     = 6;
            }

            if (record->event.pressed) {
                layer_on(layer);
                add_weak_mods(weak_mods);
            } else {
                del_weak_mods(weak_mods);
                layer_off(layer);
            }
        } else {
            if (record->event.pressed) {
                add_key(KC_ENT);
                send_keyboard_report();
            } else {
                del_key(KC_ENT);
                send_keyboard_report();
            }
        }
    }


/*
 * just an example of custom key implementation
 * not really needed with custom keymap_fn_to_action(),
 * because it will allow you to have 32 FN** keys on EACH layer
 */

/*
    keyevent_t event = record->event;

    if (id == CUSTOM_KEY) {
        uint8_t layer = biton32(layer_state);
        uint8_t col = event.key.col;
        uint8_t row = event.key.row;
        uint8_t handled = 0;

        if (event.pressed) {
            if (layer == XXX && col == XXX && row == XXX) {
                    action_macro_play(
                        MACRO(
                            ...........
                        END)
                    );
                    handled++;
                }
            }
        }

        if (!handled) {
            print("custom key not handled");
            print(": layer "); pdec(layer);
            print(", col "); pdec(col);
            print(", row "); pdec(row);
            print("\n");
        }
    }
*/

}

#include "keymap_passwords.h"
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
            case XMONAD_RESET:  return MACRO_XMONAD_RESET;
            case PASSWORD1:     return MACRO_PASSWORD1;
        }
    }
    return MACRO_NONE;
}

#define FN_ACTIONS_SIZE     (sizeof(fn_actions)   / sizeof(fn_actions[0]))
#define FN_ACTIONS_4_SIZE   (sizeof(fn_actions_4) / sizeof(fn_actions_4[0]))
#define FN_ACTIONS_7_SIZE   (sizeof(fn_actions_7) / sizeof(fn_actions_7[0]))
#define FN_ACTIONS_9_SIZE   (sizeof(fn_actions_9) / sizeof(fn_actions_9[0]))

/*
 * translates Fn keycode to action
 * for some layers, use different translation table
 */
action_t keymap_fn_to_action(uint8_t keycode)
{
    uint8_t layer = biton32(layer_state);

    action_t action;
    action.code = ACTION_NO;

    if (layer == 7 && FN_INDEX(keycode) < FN_ACTIONS_7_SIZE) {
        action.code = pgm_read_word(&fn_actions_7[FN_INDEX(keycode)]);
    }

    if (layer == 9 && FN_INDEX(keycode) < FN_ACTIONS_9_SIZE) {
        action.code = pgm_read_word(&fn_actions_9[FN_INDEX(keycode)]);
    }

    // by default, use fn_actions from default layer 0
    // this is needed to get mapping for same key, that was used switch to some layer,
    // to have possibility to switch layers back
    if (action.code == ACTION_NO && FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    }

    return action;
}

