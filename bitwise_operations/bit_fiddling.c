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
    int mask = 0;
    int bit_value = 1;

    for (int i = 0; i < n_bits; i++) { // Build the mask: 1...1, with `n_bits` 1s
        mask |= bit_value;
        bit_value <<= 1;
    }

    return mask ^ number;
}
