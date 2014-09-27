static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  |  ESC |           |   =  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Home   |   Q  |   W  |   E  |   R  |   T  |   {  |           |   }  |   Y  |   U  |   I  |   O  |   P  |  PGUP  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | End    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   /  |  PGDN  |
     * |--------+------+------+------+------+------|   ,  |           |   .  |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   '  |   ;  |  UP  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Mute |   [  |   <  |  \	 |  FN0 |                                       |   ]  |  >   | LEFT | DOWN | RIGHT|
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | VOL- | LGUI |       | RGUI | VOL+ |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LCTRL|       | RALT |      |      |
     *                                 | BkSp |  TAB |------|       |------| Enter| Space|
     *                                 |      |      | LALT |       | RCTRL|      |      |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(  // layout: layer 0: default
        // left hand
        GRV,    1,      2,      3,      4,      5,      ESC,
        HOME,   Q,      W,      E,      R,      T,      FN1,
        END,    A,      S,      D,      F,      G,
        LSFT,   Z,      X,      C,      V,      B,      COMM,
        MUTE,   LBRC,   FN2,    BSLS,   FN0,
                                                        VOLD,   LGUI,
                                                                LCTL,
                                                BSPC,   TAB,    LALT,
        // right hand
                EQL,    6,      7,      8,      9,      0,      MINS,
                FN3,    Y,      U,      I,      O,      P,      PGUP,
                        H,      J,      K,      L,      SLSH,   PGDN,
                DOT,    N,      M,      QUOT,   SCLN,   UP,     RSFT,
                                RBRC,   FN4,    LEFT,   DOWN,   RGHT,
        RGUI,   VOLU,
        RALT,
        RCTL,   ENT,    SPC
    ),

    /* Keymap 1: Function/Keypad/Mouse/Debug
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   FN5  |  F13 |  F14 |  F15 |  F16 |  F17 | TRNS |           |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   F7   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TRNS  | WH_L | MS_U | WL_R | WL_U | BTN4 |  Tab |           | SPACE|  F12 |  KP7 |  KP8 |  KP9 |   -  |  TRNS  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  TRNS  | MS_L | MS_D | MS_R | WL_D | BTN5 |------|           |------|   /  |  KP4 |  KP7 |  KP6 |   +  |  TRNS  |
     * |--------+------+------+------+------+------| BkSp |           | ENTER|------+------+------+------+------+--------|
     * |  TRNS  | BTN1 | BTN3 | BTN2 | BTN1 |  F18 |      |           |      |   *  |  KP1 |  KP2 |  KP3 | TRNS |  TRNS  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | TRNS | PRTSC| PAUSE|  NO  | TRNS |                                       |  KP0 |  PDOT| TRNS | TRNS | TRNS |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | TRNS | TRNS |       | TRNS | TRNS |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 |  F8  |  F10 |------|       |------|  F9  |  F11 |
     *                                 |      |      | TRNS |       | TRNS |      |      |
     *                                 `--------------------'       `--------------------'
     */ 
    
    KEYMAP(  // layout: layer 1: F-keys instead of numbers
        // left hand
        FN5,    F13,    F14,    F15,    F16,    F17,    TRNS,
        TRNS,   WH_L,   MS_U,   WH_R,   WH_U,   BTN4,   TAB,
        TRNS,   MS_L,   MS_D,   MS_R,   WH_D,   BTN5,
        TRNS,   BTN1,   BTN3,   BTN2,   BTN1,   F18,    BSPC,
        TRNS,   PSCR,   PAUS,   NO,     TRNS,
                                                        TRNS,   TRNS,
                                                                TRNS,
                                                F8,     F10,    TRNS,
        // right hand
                F1,     F2,     F3,     F4,     F5,     F6,     F7,
                SPC,    F12,    P7,     P8,     P9,     PMNS,   TRNS,
                        PSLS,   P4,     P5,     P6,     PPLS,   TRNS,
                ENT,    PAST,   P1,     P2,     P3,     TRNS,   TRNS,
                                P0,     PDOT,   TRNS,   TRNS,   TRNS,
        TRNS,   TRNS,
        TRNS,
        TRNS,   F9,     F11
    ),

/*
    KEYMAP(  // layout: layer N: transparent on edges, all others are empty
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,  
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,  
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    KEYMAP(  // layout: layer N: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

#define TAPPING_TOGGLE 2

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_LAYER_TAP_TOGGLE(1),                      // FN0 - push/toggle Layer1
    
    ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),             // FN1 - shifted to {
    ACTION_MODS_KEY(MOD_LSFT, KC_COMM),             // FN2 - shifted to <
    ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),             // FN3 - shifted to }
    ACTION_MODS_KEY(MOD_LSFT, KC_DOT),              // FN4 - shifted to >
    
    //**************************************************************************
    
    ACTION_FUNCTION(TEENSY_KEY),                    // FN5 - Teensy key
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}

