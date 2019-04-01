//
// Created by Alexandra Zaharia on 30/03/19.
//


#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include "bit_fiddling.h"


// Returns the bit string (textual) representation of the input number.
char *int_to_binary_string(int number, char *binary_string)
{
    // 1 & number gives the value of the final bit in `number`
    // (1 & number) + '0' gives the character '0' or '1', assuming ASCII is used
    for (int i = CHAR_BIT * sizeof(int) - 1; i >= 0; i--, number >>= 1)
        binary_string[i] = (char) ((1 & number) + '0');
    binary_string[CHAR_BIT * sizeof(int)] = '\0';

    return binary_string;
}


// Inverts the last `n_bits` in `number` and returns the resulting number.
int invert_last_n_bits(int number, int n_bits)
{
    /*
     * We need a mask 0...01...1, with `n_bits` 1s. We left-shift 1 by `n_bits` positions and obtain
     * 0...010...0, where 1 is at position `n_bits` + 1. When we subtract 1 from 1 << n_bits, we get
     * a mask with 0s at the most significant positions and 1s for the `n_bits` least significant
     * positions.
     *
     * Finally, this mask is XOR-ed with the number, yielding the original number with the `n_bits`
     * least significant bits inverted.
     */
    return number ^ ((1 << n_bits) - 1);
}


// Returns the number of "on" bits (bits set to 1) in the input `number`.
unsigned int number_of_bits_set(int number)
{
    unsigned int n_bits_on = 0;

    int value = number;

    for (size_t i = 0; i < CHAR_BIT * sizeof(int); i++) {
        if ((1 & value) == 1)
            ++n_bits_on;
        value >>= 1;
    }

    return n_bits_on;
}


// Returns the value of the bit at position `bit_pos` in `number`. Bit positions start at 0.
int get_bit(int number, int bit_pos)
{
    /*
     * We need a mask 0...010...0, where 1 is at position `bit_pos`. We obtain this mask by left-
     * shifting 1 by `bit_pos` positions. This mask is then applied using the AND operator to the
     * number, which allows to determine whether the bit at position `bit_pos` is set.
     */
    return (number & (1 << bit_pos)) != 0;
}


// Clears the most significant bits in `number` up to the bit at position `bit_pos` (inclusive).
int clear_most_significant_bits_up_to_position(int number, int bit_pos)
{
    return number & ((1 << bit_pos) - 1);
}


// Clears the least significant bits in `number`, starting from the bit at position `bit_pos`.
int clear_least_significant_bits_from_position(int number, int bit_pos)
{
    /*
     * We need a mask 1...10...0 where the 0s go from `bit_pos` to 0. This mask is then applied
     * using the AND operator to the number, which allows to clear all bits starting from `bit_pos`
     * up to the least significant bit.
     *
     * In order to obtain the mask, we will negate a mask 0...01...1 where the 1s go from `bit_pos`
     * to 0. Such a mask can be obtained by left-shifting 1 by `bit_pos` + 1 positions, then
     * subtracting 1 from the mask.
     */
    return number & ~((1 << (bit_pos + 1)) - 1);
}


/*
 * Rotates the given `number` to the left by a given number of `positions`. The overflowing bits
 * (the most significant bit positions in `number`) are rotated to the right (to the least
 * significant bit positions in the new number). Rotation happens on 1, 2, 3, 4, etc. bytes,
 * depending on how many bytes `number` needs for its representation.
 */
unsigned int rotate_left(unsigned int number, unsigned int positions) {
    unsigned int precision = 0; // number of bits multiple of CHAR_BIT needed to represent `number`
    unsigned int number_of_bytes = 1; // number of bytes needed to represent `number`

    while (!precision) {
        if (number < pow(2, CHAR_BIT * number_of_bytes))
            precision = CHAR_BIT * number_of_bytes;
        ++number_of_bytes;
    }

    /*
     * Overflowing bits are the most significant ones. Shift them to the right by precision -
     * positions bits.
     */
    unsigned int overflow = number >> (precision - positions);

    /*
     * Return the number left-shifted by `positions` bits, with bits more significant than
     * `precision` zeroed out if the `precision` is less than the number of bits needed for an
     * unsigned int, and with overflowing bits at the least significant positions.
     */
    unsigned int left_shifted = number << positions;
    if (precision < CHAR_BIT * sizeof(unsigned int))
        left_shifted &= (unsigned int) ((1 << precision) - 1);
    return left_shifted | overflow;
}