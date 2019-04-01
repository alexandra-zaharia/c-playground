//
// Created by Alexandra Zaharia on 30/03/19.
//

#ifndef C_PLAYGROUND_BIT_FIDDLING_H
#define C_PLAYGROUND_BIT_FIDDLING_H

char *int_to_binary_string(int number, char *binary_string);
int invert_last_n_bits(int number, int n_bits);
unsigned int number_of_bits_set(int number);
int get_bit(int number, int bit_pos);

int clear_most_significant_bits_up_to_position(int number, int bit_pos);
int clear_least_significant_bits_from_position(int number, int bit_pos);

unsigned int rotate_left(unsigned int number, unsigned int positions);

#endif //C_PLAYGROUND_BIT_FIDDLING_H
