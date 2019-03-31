//
// Created by Alexandra Zaharia on 30/03/19.
//


#include <stdio.h>
#include <limits.h>
#include <string.h>
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
    return ((1 << n_bits) - 1) ^ number;
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
     * shifting 1 by `bit_pos` positions. Then this mask is applied with the AND operator to the
     * number, which allows to determine whether the bit at position `bit_pos` is set.
     */
    return (number & (1 << bit_pos)) != 0;
}


// Clears the most significant bits in `number` up to the bit at position `bit_pos` (inclusive).
int clear_most_significant_bits_up_to_position(int number, int bit_pos)
{
    return number & ((1 << bit_pos) - 1);
}