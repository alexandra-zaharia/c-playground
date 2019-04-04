//
// Created by Alexandra Zaharia on 30/03/19.
//


#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include "bit_fiddling.h"

#define MAX(a, b)  (a) < (b) ? (b) : (a)


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


/*
 * Inserts the number m into the number n, from bit positions j through i. Assumes there is enough
 * space between positions j and i to insert m.
 */
int insert_number(int n, int m, int i, int j)
{
    /*
     * Create a mask that zeroes out bits from positions j through i (inclusive) in n when using the
     * AND operator between n and the mask. The mask has the following form:
     *      Mask:        1   ...  1   0   ...   0   1   ...   1
     *      Positions: |n|-1     j+1  j         i  i-1        0
     */
    int mask = ~((1 << (j + 1)) - 1) | ((1 << i) - 1);

    /*
     * We apply the mask to n to turn off bits between positions j and i, then we turn on the bits
     * between j and i that are turned on in m.
     */
    return (n & mask) | (m << i);
}


// Determines whether the specified number is a power of two.
bool is_power_of_two(int number)
{
    if (number == 0) return false;
    /*
     * A number is a power of two if it only has one of its bits set to 1. In this case, if we
     * subtract 1 from the number, we get a sequence of 1s starting from the next most significant
     * bit with respect to the bit that is set. If we AND the number and this sequence of 1s
     * together, we get 0. For a number that is not a power of two, applying the AND operator to the
     * number and the number from which we subtract 1 will always result in a value different from
     * zero.
     */
    return (number & (number - 1)) == 0;
}


/*
 * Returns the length of the longest sequence of 1s that can be obtained from the given number by
 * flipping exactly one bit from 0 to 1.
 */
int flip_bit_to_win(int number)
{
    int seq_lengths[CHAR_BIT * sizeof(int)];  // will store lengths of sequences of 0s and 1s
    int seq_counter = 0;                      // number of sequences in `seq_lengths` + 1
    int current_value = 0;                    // current bit value (0 or 1)

    for (size_t i = 0; i < CHAR_BIT * sizeof(int); i++)   // all sequence lengths are initially 0
        seq_lengths[i] = 0;

    for (size_t i = 0; i < CHAR_BIT * sizeof(int); i++) {
        if ((number & 1) == current_value) {  // still in the same sequence as before
           seq_lengths[seq_counter]++;
        } else {                              // reading a different sequence than before
            seq_lengths[++seq_counter] = 1;
            current_value = number & 1;
        }
        number >>= 1;                         // move on to the next bit
    }

    if (seq_counter == 0) return 1;
    if (seq_counter == 1) return seq_lengths[0] > 0 ? seq_lengths[1] + 1 : seq_lengths[1];
    if (seq_counter == 2) return seq_lengths[1] + 1;

    int max_len = 0;

    for (int i = 1; i < seq_counter - 1; i += 2) {
        int current_max = seq_lengths[i + 1] == 1         // if there is one 0 between two sequences
                ? seq_lengths[i] + 1 + seq_lengths[i + 2] // of ones, we can flip the 0 bit
                : MAX(seq_lengths[i], seq_lengths[i + 2]) + 1; // longest sequence of 1s + 1
        if (max_len < current_max)
            max_len = current_max;
    }

    return max_len;
}