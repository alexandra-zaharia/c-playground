//
// Created by Alexandra Zaharia on 30/03/19.
//

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>
#include <cmocka.h>

#include <limits.h>
#include <stdio.h>
#include "bit_fiddling.h"


char binary[CHAR_BIT * sizeof(int) + 1];  // CHAR_BIT: number of bits in a char


static void test_convert_int_to_binary_string_7()
{
    assert_string_equal(int_to_binary_string(7, binary), "00000000000000000000000000000111");
}


static void test_convert_int_to_binary_string_2019()
{
    assert_string_equal(int_to_binary_string(2019, binary), "00000000000000000000011111100011");
}


static void test_convert_int_to_binary_string_minus_1()
{
    assert_string_equal(int_to_binary_string(-1, binary), "11111111111111111111111111111111");
}


static void test_convert_int_to_binary_string_minus_2()
{
    assert_string_equal(int_to_binary_string(-2, binary), "11111111111111111111111111111110");
}


static void test_invert_last_4_bits_7()
{
    assert_string_equal(int_to_binary_string(invert_last_n_bits(7, 4), binary),
                        "00000000000000000000000000001000");
}


static void test_invert_last_8_bits_7()
{
    assert_string_equal(int_to_binary_string(invert_last_n_bits(7, 8), binary),
                        "00000000000000000000000011111000");
}


static void test_invert_last_4_bits_2019()
{
    assert_string_equal(int_to_binary_string(invert_last_n_bits(2019, 4), binary),
                        "00000000000000000000011111101100");
}


static void test_invert_last_8_bits_2019()
{
    assert_string_equal(int_to_binary_string(invert_last_n_bits(2019, 8), binary),
                        "00000000000000000000011100011100");
}


static void test_invert_last_4_bits_minus_1()
{
    assert_string_equal(int_to_binary_string(invert_last_n_bits(-1, 4), binary),
                        "11111111111111111111111111110000");
}


static void test_invert_last_8_bits_minus_1()
{
    assert_string_equal(int_to_binary_string(invert_last_n_bits(-1, 8), binary),
                        "11111111111111111111111100000000");
}


static void test_invert_last_4_bits_minus_2()
{
    assert_string_equal(int_to_binary_string(invert_last_n_bits(-2, 4), binary),
                        "11111111111111111111111111110001");
}


static void test_invert_last_8_bits_minus_2()
{
    assert_string_equal(int_to_binary_string(invert_last_n_bits(-2, 8), binary),
                        "11111111111111111111111100000001");
}


static void test_count_bits_set_7()
{
    assert_true(number_of_bits_set(7) == 3);
}


static void test_count_bits_set_2019()
{
    assert_true(number_of_bits_set(2019) == 8);
}


static void test_count_bits_set_minus_1()
{
    assert_true(number_of_bits_set(-1) == CHAR_BIT * sizeof(int));
}


static void test_count_bits_set_minus_2()
{
    assert_true(number_of_bits_set(-2) == CHAR_BIT * sizeof(int) - 1);
}


static void test_get_bits_7()
{
    for (int i = 0; i < 8; i++) {
        if (i < 3)
            assert_int_equal(get_bit(7, i), 1);
        else
            assert_int_equal(get_bit(7, i), 0);
    }
}


static void test_get_bits_2019()
{
    for (int i = 0; i < 16; i++) {
        if (i < 2 || (5 <= i && i <= 10))
            assert_int_equal(get_bit(2019, i), 1);
        else
            assert_int_equal(get_bit(2019, i), 0);
    }
}


static void test_get_bits_minus_1()
{
    for (int i = 0; i < (int) (CHAR_BIT * sizeof(int)); i++) {
        assert_int_equal(get_bit(-1, i), 1);
    }
}


static void test_get_bits_minus_2()
{
    assert_int_equal(get_bit(-2, 0), 0);
    for (int i = 1; i < (int) (CHAR_BIT * sizeof(int)); i++) {
        assert_int_equal(get_bit(-2, i), 1);
    }
}


static void test_clear_most_significant_bits_7()
{
    assert_int_equal(clear_most_significant_bits_up_to_position(7, 3), 7);
    assert_int_equal(clear_most_significant_bits_up_to_position(7, 2), 3);
    assert_int_equal(clear_most_significant_bits_up_to_position(7, 1), 1);
    assert_int_equal(clear_most_significant_bits_up_to_position(7, 0), 0);
}


static void test_clear_most_significant_bits_2019()
{
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 10), 995);
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 9), 483);
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 8), 227);
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 7), 99);
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 6), 35);
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 5), 3);
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 4), 3);
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 3), 3);
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 2), 3);
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 1), 1);
    assert_int_equal(clear_most_significant_bits_up_to_position(2019, 0), 0);
}


static void test_clear_most_significant_bits_minus_1()
{
    assert_int_equal(clear_most_significant_bits_up_to_position(-1, 7), 127);
    assert_int_equal(clear_most_significant_bits_up_to_position(-1, 6), 63);
    assert_int_equal(clear_most_significant_bits_up_to_position(-1, 5), 31);
    assert_int_equal(clear_most_significant_bits_up_to_position(-1, 4), 15);
    assert_int_equal(clear_most_significant_bits_up_to_position(-1, 3), 7);
    assert_int_equal(clear_most_significant_bits_up_to_position(-1, 2), 3);
    assert_int_equal(clear_most_significant_bits_up_to_position(-1, 1), 1);
    assert_int_equal(clear_most_significant_bits_up_to_position(-1, 0), 0);
}


static void test_clear_most_significant_bits_minus_2()
{
    assert_int_equal(clear_most_significant_bits_up_to_position(-2, 7), 126);
    assert_int_equal(clear_most_significant_bits_up_to_position(-2, 6), 62);
    assert_int_equal(clear_most_significant_bits_up_to_position(-2, 5), 30);
    assert_int_equal(clear_most_significant_bits_up_to_position(-2, 4), 14);
    assert_int_equal(clear_most_significant_bits_up_to_position(-2, 3), 6);
    assert_int_equal(clear_most_significant_bits_up_to_position(-2, 2), 2);
    assert_int_equal(clear_most_significant_bits_up_to_position(-2, 1), 0);
    assert_int_equal(clear_most_significant_bits_up_to_position(-2, 0), 0);
}


static void test_clear_least_significant_bits_7()
{
    // 7: 0000 0111
    assert_int_equal(clear_least_significant_bits_from_position(7, 3), 0);
    assert_int_equal(clear_least_significant_bits_from_position(7, 2), 0);
    assert_int_equal(clear_least_significant_bits_from_position(7, 1), 4);
    assert_int_equal(clear_least_significant_bits_from_position(7, 0), 6);
}


static void test_clear_least_significant_bits_2019()
{
    // 2019: 0000 0111 1110 0011
    for (int i = 15; i >= 10; i--)
        assert_int_equal(clear_least_significant_bits_from_position(2019, i), 0);

    assert_int_equal(clear_least_significant_bits_from_position(2019, 9), 1024);
    assert_int_equal(clear_least_significant_bits_from_position(2019, 8), 1536);
    assert_int_equal(clear_least_significant_bits_from_position(2019, 7), 1792);
    assert_int_equal(clear_least_significant_bits_from_position(2019, 6), 1920);
    assert_int_equal(clear_least_significant_bits_from_position(2019, 5), 1984);

    for (int i = 4; i >= 1; i--)
        assert_int_equal(clear_least_significant_bits_from_position(2019, i), 2016);

    assert_int_equal(clear_least_significant_bits_from_position(2019, 0), 2018);
}


static void test_clear_least_significant_bits_minus_1()
{
    // -1: 1111 1111
    assert_int_equal(clear_least_significant_bits_from_position(-1, 7), -256);
    assert_int_equal(clear_least_significant_bits_from_position(-1, 6), -128);
    assert_int_equal(clear_least_significant_bits_from_position(-1, 5), -64);
    assert_int_equal(clear_least_significant_bits_from_position(-1, 4), -32);
    assert_int_equal(clear_least_significant_bits_from_position(-1, 3), -16);
    assert_int_equal(clear_least_significant_bits_from_position(-1, 2), -8);
    assert_int_equal(clear_least_significant_bits_from_position(-1, 1), -4);
    assert_int_equal(clear_least_significant_bits_from_position(-1, 0), -2);
}


static void test_clear_least_significant_bits_minus_2()
{
    // -2: 1111 1110
    assert_int_equal(clear_least_significant_bits_from_position(-2, 7), -256);
    assert_int_equal(clear_least_significant_bits_from_position(-2, 6), -128);
    assert_int_equal(clear_least_significant_bits_from_position(-2, 5), -64);
    assert_int_equal(clear_least_significant_bits_from_position(-2, 4), -32);
    assert_int_equal(clear_least_significant_bits_from_position(-2, 3), -16);
    assert_int_equal(clear_least_significant_bits_from_position(-2, 2), -8);
    assert_int_equal(clear_least_significant_bits_from_position(-2, 1), -4);
    assert_int_equal(clear_least_significant_bits_from_position(-2, 0), -2);
}


int main() {
    const struct CMUnitTest tests_conversion[] = {
            cmocka_unit_test(test_convert_int_to_binary_string_7),
            cmocka_unit_test(test_convert_int_to_binary_string_2019),
            cmocka_unit_test(test_convert_int_to_binary_string_minus_1),
            cmocka_unit_test(test_convert_int_to_binary_string_minus_2)
    };

    const struct CMUnitTest tests_inversion[] = {
            cmocka_unit_test(test_invert_last_4_bits_7),
            cmocka_unit_test(test_invert_last_8_bits_7),
            cmocka_unit_test(test_invert_last_4_bits_2019),
            cmocka_unit_test(test_invert_last_8_bits_2019),
            cmocka_unit_test(test_invert_last_4_bits_minus_1),
            cmocka_unit_test(test_invert_last_8_bits_minus_1),
            cmocka_unit_test(test_invert_last_4_bits_minus_2),
            cmocka_unit_test(test_invert_last_8_bits_minus_2)
    };

    const struct CMUnitTest tests_count_bits_set[] = {
            cmocka_unit_test(test_count_bits_set_7),
            cmocka_unit_test(test_count_bits_set_2019),
            cmocka_unit_test(test_count_bits_set_minus_1),
            cmocka_unit_test(test_count_bits_set_minus_2),
    };

    const struct CMUnitTest tests_get_bit[] = {
            cmocka_unit_test(test_get_bits_7),
            cmocka_unit_test(test_get_bits_2019),
            cmocka_unit_test(test_get_bits_minus_1),
            cmocka_unit_test(test_get_bits_minus_2)
    };

    const struct CMUnitTest tests_clear_most_significant_bits[] = {
            cmocka_unit_test(test_clear_most_significant_bits_7),
            cmocka_unit_test(test_clear_most_significant_bits_2019),
            cmocka_unit_test(test_clear_most_significant_bits_minus_1),
            cmocka_unit_test(test_clear_most_significant_bits_minus_2)
    };

    const struct CMUnitTest tests_clear_least_significant_bits[] = {
            cmocka_unit_test(test_clear_least_significant_bits_7),
            cmocka_unit_test(test_clear_least_significant_bits_2019),
            cmocka_unit_test(test_clear_least_significant_bits_minus_1),
            cmocka_unit_test(test_clear_least_significant_bits_minus_2)
    };

    printf("Testing int conversion into binary string\n");
    int status_i2b = cmocka_run_group_tests(tests_conversion, NULL, NULL);

    printf("\nTesting inversion of last n bits\n");
    int status_inv = cmocka_run_group_tests(tests_inversion, NULL, NULL);

    printf("\nTesting count of bits set to on\n");
    int status_set = cmocka_run_group_tests(tests_count_bits_set, NULL, NULL);

    printf("\nTesting bit checking\n");
    int status_get = cmocka_run_group_tests(tests_get_bit, NULL, NULL);

    printf("\nTesting clearing most significant bits up to a given position\n");
    int status_clr_msig = cmocka_run_group_tests(tests_clear_most_significant_bits, NULL, NULL);

    printf("\nTesting clearing least significant bits from a given position through 0\n");
    int status_clr_lsig = cmocka_run_group_tests(tests_clear_least_significant_bits, NULL, NULL);

    return status_i2b && status_inv && status_set && status_get && status_clr_msig
        && status_clr_lsig;
}