/*
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>

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

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "action_layer.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "ergodox.h"
#include "i2cmaster.h"
#ifdef DEBUG_MATRIX_SCAN_RATE
#include  "timer.h"
#endif

// This configures how many matrix scans a key must have settled before the
// next state change is accepted. The matrix is scanned about every 3ms, so
// this gives us roughly 12ms.
#ifndef DEBOUNCE
#   define DEBOUNCE 4
#endif

#if DEBOUNCE < 1
#   error "DEBOUNCE must be larger or equal 1"
#endif


/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];

// matrix_debouncing is used to implement debouncing. If a bit is set, the key
// has recently changed and needs to calm down first, so the change is ignored.
static matrix_row_t matrix_debouncing[DEBOUNCE][MATRIX_ROWS];

static void advance_debouncing_matrix(void);

static matrix_row_t read_cols(uint8_t row);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);

static uint8_t mcp23018_reset_loop;

#ifdef DEBUG_MATRIX_SCAN_RATE
uint32_t matrix_timer;
uint32_t matrix_scan_count;
#endif

inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // initialize row and col
    init_ergodox();
    mcp23018_status = init_mcp23018();
    ergodox_blink_all_leds();
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }

    // initialize debouncing shadow copies
    for (uint8_t d = 0; d < DEBOUNCE; d++) {
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            matrix_debouncing[d][i] = 0;
        }
    }

#ifdef DEBUG_MATRIX_SCAN_RATE
    matrix_timer = timer_read32();
    matrix_scan_count = 0;
#endif
}

inline static void advance_debouncing_matrix()
{
#if DEBOUNCE > 1
    // advance debouncing shadow copies
    for (uint8_t d = 0; d < DEBOUNCE-1; d++) {
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            matrix_debouncing[d][row] = matrix_debouncing[d+1][row];
        }
    }
#endif

    // clear last debouncing matrix
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix_debouncing[DEBOUNCE-1][i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    if (mcp23018_status) { // if there was an error
        if (++mcp23018_reset_loop == 0) {
            // since mcp23018_reset_loop is 8 bit - we'll try to reset once in 255 matrix scans
            // this will be approx bit more frequent than once per second
            print("trying to reset mcp23018\n");
            mcp23018_status = init_mcp23018();
            if (mcp23018_status) {
                print("left side not responding\n");
            } else {
                print("left side attached\n");
                ergodox_blink_all_leds();
            }
        }
    }

#ifdef DEBUG_MATRIX_SCAN_RATE
    matrix_scan_count++;

    uint32_t timer_now = timer_read32();
    if (TIMER_DIFF_32(timer_now, matrix_timer)>1000) {
        print("matrix scan frequency: ");
        pdec(matrix_scan_count);
        print("\n");

        matrix_timer = timer_now;
        matrix_scan_count = 0;
    }
#endif

#ifdef KEYMAP_CUB
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_left_led_1_off();
    ergodox_left_led_2_off();
    ergodox_left_led_3_off();
    switch (layer) {
        case 1:
            // all
            ergodox_left_led_1_on();
            ergodox_left_led_2_on();
            ergodox_left_led_3_on();
            break;
        case 2:
            // blue
            ergodox_left_led_2_on();
            break;
        case 8:
            // blue and green
            ergodox_left_led_2_on();
            // break missed intentionally
        case 3:
            // green
            ergodox_left_led_3_on();
            break;
        case 6:
            ergodox_board_led_on();
            // break missed intentionally
        case 4:
        case 5:
        case 7:
            // white
            ergodox_left_led_1_on();
            break;
        case 9:
            // white+green
            ergodox_left_led_1_on();
            ergodox_left_led_3_on();
            break;
        default:
            // none
            break;
    }

    mcp23018_status = ergodox_left_leds_update();
#endif

    matrix_row_t changes, mask;
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        // read cols for current row
        select_row(row);
        matrix_row_t cols = read_cols(row);

        // read changed keys in current row
        changes = matrix[row] ^ cols;

        // compute mask for debouncing for current row
        mask = ~matrix_debouncing[0][row];

#ifdef DEBUG_BOUNCING
        if (changes > 0 && (changes & mask) == 0) {
            print("masked changes in row ");
            print_hex8(row);
            print(": ");
            print_hex8(changes);
            print(", demasked: ");
            print_hex8(changes & mask);
            print("\n");
        }
#endif

        // mask out keys that have changed recently, the bits are set it
        // matrix_debouncing.
        changes &= mask;

        if (changes > 0) {
            // apply changes to matrix
            matrix[row] ^= changes;

            // set bits in shadow matrixes
            for (uint8_t d = 0; d < DEBOUNCE; d++) {
                matrix_debouncing[d][row] |= changes;
            }
        }

        unselect_rows();
    }

    advance_debouncing_matrix();

    return 1;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

/* Column pin configuration
 *
 * Teensy
 * col: 0   1   2   3   4   5
 * pin: F0  F1  F4  F5  F6  F7
 *
 * MCP23018
 * col: 0   1   2   3   4   5
 * pin: B5  B4  B3  B2  B1  B0
 */
static void  init_cols(void)
{
    // init on mcp23018
    // not needed, already done as part of init_mcp23018()

    // init on teensy
    // Input with pull-up(DDR:0, PORT:1)
    DDRF  &= ~(1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<1 | 1<<0);
    PORTF |=  (1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<1 | 1<<0);
}

static matrix_row_t read_cols(uint8_t row)
{
    if (row < 7) {
        if (mcp23018_status) { // if there was an error
            return 0;
        } else {
            uint8_t data = 0;
            mcp23018_status = i2c_start(I2C_ADDR_WRITE);    if (mcp23018_status) goto out;
            mcp23018_status = i2c_write(GPIOB);             if (mcp23018_status) goto out;
            mcp23018_status = i2c_start(I2C_ADDR_READ);     if (mcp23018_status) goto out;
            data = i2c_readNak();
            data = ~data;
        out:
            i2c_stop();
            return data;
        }
    } else {
        _delay_us(30);  // without this wait read unstable value.
        // read from teensy
        return
            (PINF&(1<<0) ? 0 : (1<<0)) |
            (PINF&(1<<1) ? 0 : (1<<1)) |
            (PINF&(1<<4) ? 0 : (1<<2)) |
            (PINF&(1<<5) ? 0 : (1<<3)) |
            (PINF&(1<<6) ? 0 : (1<<4)) |
            (PINF&(1<<7) ? 0 : (1<<5)) ;
    }
}

/* Row pin configuration
 *
 * Teensy
 * row: 7   8   9   10  11  12  13
 * pin: B0  B1  B2  B3  D2  D3  C6
 *
 * MCP23018
 * row: 0   1   2   3   4   5   6
 * pin: A0  A1  A2  A3  A4  A5  A6
 */
static void unselect_rows(void)
{
    // unselect on mcp23018
    if (mcp23018_status) { // if there was an error
        // do nothing
    } else {
        // set all rows hi-Z : 1
        mcp23018_status = i2c_start(I2C_ADDR_WRITE);    if (mcp23018_status) goto out;
        mcp23018_status = i2c_write(GPIOA);             if (mcp23018_status) goto out;
        mcp23018_status = i2c_write( 0xFF
                              & ~(ergodox_left_led_3<<LEFT_LED_3_SHIFT)
                          );                            if (mcp23018_status) goto out;
    out:
        i2c_stop();
    }

    // unselect on teensy
    // Hi-Z(DDR:0, PORT:0) to unselect
    DDRB  &= ~(1<<0 | 1<<1 | 1<<2 | 1<<3);
    PORTB &= ~(1<<0 | 1<<1 | 1<<2 | 1<<3);
    DDRD  &= ~(1<<2 | 1<<3);
    PORTD &= ~(1<<2 | 1<<3);
    DDRC  &= ~(1<<6);
    PORTC &= ~(1<<6);
}

static void select_row(uint8_t row)
{
    if (row < 7) {
        // select on mcp23018
        if (mcp23018_status) { // if there was an error
            // do nothing
        } else {
            // set active row low  : 0
            // set other rows hi-Z : 1
            mcp23018_status = i2c_start(I2C_ADDR_WRITE);        if (mcp23018_status) goto out;
            mcp23018_status = i2c_write(GPIOA);                 if (mcp23018_status) goto out;
            mcp23018_status = i2c_write( 0xFF & ~(1<<row)
                                  & ~(ergodox_left_led_3<<LEFT_LED_3_SHIFT)
                              );                                if (mcp23018_status) goto out;
        out:
            i2c_stop();
        }
    } else {
        // select on teensy
        // Output low(DDR:1, PORT:0) to select
        switch (row) {
            case 7:
                DDRB  |= (1<<0);
                PORTB &= ~(1<<0);
                break;
            case 8:
                DDRB  |= (1<<1);
                PORTB &= ~(1<<1);
                break;
            case 9:
                DDRB  |= (1<<2);
                PORTB &= ~(1<<2);
                break;
            case 10:
                DDRB  |= (1<<3);
                PORTB &= ~(1<<3);
                break;
            case 11:
                DDRD  |= (1<<2);
                PORTD &= ~(1<<3);
                break;
            case 12:
                DDRD  |= (1<<3);
                PORTD &= ~(1<<3);
                break;
            case 13:
                DDRC  |= (1<<6);
                PORTC &= ~(1<<6);
                break;
        }
    }
}
