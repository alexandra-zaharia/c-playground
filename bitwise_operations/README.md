# Bitwise operations

## About

Common operations on bits and a few exercises on bit fiddling.

## Motivation

Getting comfortable with:
* Bitwise logical operators
* Bitwise shift operators
* Applying bitwise masks

## Included functions

* `char *int_to_binary_string(int number, char *binary_string`) -- returns the string that is the **binary representation** of `number` (the string is also stored into `binary_string`)

* `int invert_last_n_bits(int number, int n_bits)` -- **inverts the last `n_bits` bits** of the specified `number`

* `unsigned int number_of_bits_set(int number)` -- returns the **number of bits equal to 1** in the specified `number`

* `int get_bit(int number, int bit_pos)` -- returns the **bit at the specified position** `bit_pos` in `number`

* `int clear_most_significant_bits_up_to_position(int number, int bit_pos)` -- **clears the most significant bits** in `number`, up to position `bit_pos` (inclusive)

* `int clear_least_significant_bits_from_position(int number, int bit_pos)` -- **clears the least significant bits** in `number`, from position `bit_pos` through 0 (inclusive)

* `unsigned int rotate_left(unsigned int number, unsigned int positions)` -- **rotates the specified `number` to the left for a given number of `positions`**; overflowing bits (with respect to the number of bits multiple of 8 that the `number` needs for its representation) are placed in the least significant positions of the resulting number

* `int insert_number(int n, int m, int i, int j)` -- inserts number `m` into number `n`, from bit positions `j` through `i` (inclusive); it is assumed that the `m` fits between bits `j` and `i`

* `bool is_power_of_two(int number)` -- determines whether the specified `number` is a **power of 2**

* `int flip_bit_to_win(int number)` -- determines the length of the longest sequence of 1s that can be obtained from `number` by flipping exactly one bit from 0 to 1

## Compiling

The executable runs the tests for the functions mentioned above. [cmocka](https://cmocka.org/) is required to run the tests. Compile as follows:

```
gcc -g -Wall -Wextra -Wpedantic -Wconversion -o bit_fiddling_tests bit_fiddling_tests.c bit_fiddling.c -lcmocka -lm
```
