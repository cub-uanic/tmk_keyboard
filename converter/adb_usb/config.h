/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H


#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0ADB
#define DEVICE_VER      0x0101
#define MANUFACTURER    t.m.k.
#define PRODUCT         ADB keyboard converter
#define DESCRIPTION     convert ADB keyboard to USB

/* matrix size */
#define MATRIX_ROWS 16  // keycode bit: 3-0
#define MATRIX_COLS 8   // keycode bit: 6-4

#define MATRIX_ROW(code)    ((code)>>3&0x0F)
#define MATRIX_COL(code)    ((code)&0x07)


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// Mouse Extended Report
//#define MOUSE_EXT_REPORT

// Second button in Apple Classic Mouse protocol is ignored as Mac OS9 and OSX does.
// Without this some of 2-button mouses are unusable.
// https://github.com/tmk/tmk_keyboard/issues/724
#define ADB_MOUSE_2ND_BUTTON_QUIRK


/* ADB port setting */
#define ADB_PORT        PORTD
#define ADB_PIN         PIND
#define ADB_DDR         DDRD
#define ADB_DATA_BIT    0
#define ADB_PSW_BIT     1

/* key combination for command */
#ifndef __ASSEMBLER__
#include "adb.h"
#include "matrix.h"
#define IS_COMMAND() ( \
    matrix_is_on(MATRIX_ROW(ADB_POWER), MATRIX_COL(ADB_POWER)) \
)
#endif


/* Mouse scroll by button
 *
 * Kensington Turbo Mouse 5
 *                    .--------,
 *    middle click -> |3  __  4|
 *                    |  /  \  |
 *                    |  \__/  |
 *      left click -> |1      2| <- right click
 *                    `--------'
 */
#define MOUSE_SCROLL_BUTTON     MOUSE_BTN2
#define MOUSE_SCROLL_DIV        10

#endif
