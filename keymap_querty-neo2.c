//My own representation of an ergodox QUERTY/Z layout for optimal use with Neo 2 Autohotkey
#include <util/delay.h>
#include "bootloader.h"
#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 
     * Keymap: QWERTY Gaming Layer / Neo2 Autohotkey Layer (Layer 0)
     * 
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  | +L2  |           |  =   |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  | ESC  |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   [    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | CapsLk |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------| ~L2  |           |  \   |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | NUBS | Home |  End | Left | Rght |                                       |  Up  |  Dn  | PgUp | PgDn | Ralt |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | INS  | +L1  |       | App  | RCtr |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LAlt |       | LGUI |      |      |
     *                                 | Space| Enter|------|       |------| BkSp | Del  |
     *                                 |      |      | LCtr |       | ~L1  |      |      |
     *                                 `--------------------'       `--------------------'
     * 
	 * FN1 = While Pressed Layer 1
	 * FN2 = Toggle To Layer 1 And Back
	 * FN3 = While Pressed Layer 2
	 * FN4 = Toggle To Layer 2 And Back
 	 * FN5 = Paste Macro - SHIFT INSERT
	 * FN6 = Copy Macro - CTRL INSERT
	 * FN7 = Cut Macro - CRTL INSERT, DELETE
	 */

    KEYMAP(  // layer 0 : QWERTY Gaming / Neo2 Autohotkey
        // left hand
        GRV,    1,   2,   3,   4,   5,   FN4,
        TAB,    Q,   W,   E,   R,   T,   ESC,
        CAPS,   A,   S,   D,   F,   G,
        LSFT,   Z,   X,   C,   V,   B,   FN3,
        NUBS,HOME, END,LEFT,RGHT,
                                      INS, FN2,
                                          LALT,
                                 SPC, ENT,LCTL,
        // right hand
              EQL,   6,   7,   8,   9,   0,MINS,
             RBRC,   Y,   U,   I,   O,   P,LBRC,
                     H,   J,   K,   L,SCLN,QUOT,
             BSLS,   N,   M,COMM, DOT,SLSH,RSFT,
                         UP,DOWN,PGUP,PGDN,RALT,
         APP,RCTL,
        LGUI,
         FN1,BSPC, DEL
    ),
	
	/* 
     * Keymap: Function and Media Keys Layer (Layer 1)
     * 
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  EJCT  | MRWD | MFFD | Stop |      | SLCT | Mute |           | PrSc | WSCH |      |      | SLEP | WAKE | TEENSY |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  Help  | UNDO | AGIN | Prev | COPY | EXEC |Vol Up|           | ScLk | WBAK | WFWD | WSTP | WHOM | WREF |  WFAV  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  MENU  |      | FN5Pa| Play | PSTE | STOP |------|           |------|  F1  |  F2  |  F3  |  F4  |  F5  |   F6   |
     * |--------+------+------+------+------+------|Vol Dn|           | Paus |------+------+------+------+------+--------|
     * | LShift |      | FN6Co| Next | CUT  | FIND |      |           |      |  F7  |  F8  |  F9  | F10  | F11  |  F12   |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | MAIL |      | FN7Cu| Sel  |      |                                       | CALC | MYCM |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      | -L1  |       | APP  |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LAlt |       | LGUI |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      | LCtr |       | ~L1  |      |      |
     *                                 `--------------------'       `--------------------'
     * 
     * 
	 * FN1 = While Pressed Layer 1
	 * FN2 = Toggle To Layer 1 And Back
	 * FN3 = While Pressed Layer 2
	 * FN4 = Toggle To Layer 2 And Back
	 * FN5 = Paste Macro - SHIFT INSERT
	 * FN6 = Copy Macro - CTRL INSERT
	 * FN7 = Cut Macro - CRTL INSERT, DELETE
     */

    KEYMAP(  // layer 1 : function and media keys
        // left hand
        EJCT,MRWD,MFFD,MSTP,  NO,SLCT,MUTE,
        HELP,UNDO,AGIN,MPRV,COPY,EXEC,VOLU,
        MENU,  NO, FN5,MPLY,PSTE,STOP,
        LSFT,  NO, FN6,MNXT, CUT,FIND,VOLD,
        MAIL,  NO, FN7,MSEL,  NO,
                                        NO,TRNS,
                                           LALT,
                                   NO,  NO,LCTL,
        // right hand
            PSCR,WSCH,  NO,  NO,SLEP,WAKE, FN0,
            SLCK,WBAK,WFWD,WSTP,WHOM,WREF,WFAV,
                   F1,  F2,  F3,  F4,  F5,  F6,
            PAUS,  F7,  F8,  F9, F10, F11, F12,
                      CALC,MYCM,  NO,  NO,  NO,
         APP,  NO,
        LGUI,
        TRNS,  NO,  NO
	),
	
	/* 
     * Keymap: Numpad Layer With Mouse Functionality (Layer 2)
     * 
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        | HOME |  UP  | END  | PGUP |      | -L2  |           |      |      | NmLk | KP / | KP * | KP - |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  TAB   | LEFT | DOWN | RGHT | PGDN |      |      |           |      |      | KP 7 | KP 8 | KP 9 | KP + |  BSPC  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        | ACL0 | WH_L | MS_U | WH_R | WH_U |------|           |------|   .  | KP 4 | KP 5 | KP 6 | KP + |  DEL   |
     * |--------+------+------+------+------+------| ~L2  |           | TAB  |------+------+------+------+------+--------|
     * |        | ACL1 | MS_L | MS_D | MS_R | WH_D |      |           |      |   ,  | KP 1 | KP 2 | KP 3 |KP Ent|        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      | ACL2 | BTN4 | BTN5 | BTN3 |                                       | KP 0 |      | KP . |KP Ent|      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 | BTN1 | BTN2 |------|       |------| SPC  | ENT  |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     * 
	 * FN1 = While Pressed Layer 1
	 * FN2 = Toggle To Layer 1 And Back
	 * FN3 = While Pressed Layer 2
	 * FN4 = Toggle To Layer 2 And Back
	 * FN5 = Paste Macro - SHIFT INSERT
	 * FN6 = Copy Macro - CTRL INSERT
	 * FN7 = Cut Macro - CRTL INSERT, DELETE
     */

    KEYMAP(  // layer 2: numpad
        // left hand
          NO,HOME,  UP, END,PGUP,  NO,TRNS,
         TAB,LEFT,DOWN,RGHT,PGDN,  NO,  NO,
          NO,ACL0,WH_L,MS_U,WH_R,WH_U,
          NO,ACL1,MS_L,MS_D,MS_R,WH_D,TRNS,
          NO,ACL2,BTN4,BTN5,BTN3,
                                        NO,  NO,
                                             NO,
                                 BTN1,BTN2,  NO,
        // right hand
               NO,  NO,NLCK,PSLS,PAST,PMNS,  NO,
               NO,  NO,  P7,  P8,  P9,PPLS,BSPC,
                   DOT,  P4,  P5,  P6,PPLS, DEL,
              TAB,COMM,  P1,  P2,  P3,PENT,  NO,
                       P0,    NO,PDOT,PENT,  NO,
          NO,  NO,
          NO,
          NO, SPC, ENT
    ),

};

/* id for user defined functions & macros */
enum function_id {
    TEENSY_KEY,
};

enum macro_id {
    PASTE_MC,
	COPY_MC,
	CUT_MC,
};

/*
 * Fn action definition
 */
 
const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),		// FN0 - Teensy key
    ACTION_LAYER_MOMENTARY(1),			// FN1 = While Pressed Layer 1
	ACTION_LAYER_TOGGLE(1),				// FN2 = Toggle To Layer 1 And Back
    ACTION_LAYER_MOMENTARY(2),			// FN3 = While Pressed Layer 2
    ACTION_LAYER_TOGGLE(2),				// FN4 = Toggle To Layer 2 And Back
	ACTION_MACRO(PASTE_MC),				// FN5 = Paste Macro - SHIFT INSERT
	ACTION_MACRO(COPY_MC),				// FN6 = Copy Macro - CTRL INSERT
	ACTION_MACRO(CUT_MC),				// FN7 = Cut Macro - CRTL INSERT, DELETE
};

/*
 * Defining the Teensy Key action_function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // print("action_function called\n");
    // print("id  = "); phex(id); print("\n");
    // print("opt = "); phex(opt); print("\n");

    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
} 

/*
 * Defining Macro Key Actions
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	switch (id) {
		case PASTE_MC:
			return (record->event.pressed ?
					MACRO( D(LSHIFT), D(INS), U(INS), U(LSHIFT), END ) :	// FN5 = Paste Macro SHIFT INSERT
					MACRO_NONE );
		case COPY_MC:
			return (record->event.pressed ?
					MACRO( D(LCTL), D(INS), U(INS), U(LCTL), END ) :		// FN6 = Copy Macro CTRL INSERT
					MACRO_NONE );
		case CUT_MC:
			return (record->event.pressed ?
					MACRO( D(LCTL), D(INS), U(INS), U(LCTL), T(DEL), END ) :	// FN7 = Cut Macro CRTL INSERT, DELETE
					MACRO_NONE );
	}
	return MACRO_NONE;
}
