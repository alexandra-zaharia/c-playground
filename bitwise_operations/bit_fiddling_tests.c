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

    printf("Testing int conversion into binary string\n");
    int status_i2b = cmocka_run_group_tests(tests_conversion, NULL, NULL);

    printf("\nTesting inversion of last n bits\n");
    int status_inv = cmocka_run_group_tests(tests_inversion, NULL, NULL);

    printf("\nTesting count of bits set to on\n");
    int status_set = cmocka_run_group_tests(tests_count_bits_set, NULL, NULL);

    printf("\nTesting bit checking\n");
    int status_get = cmocka_run_group_tests(tests_get_bit, NULL, NULL);

    return status_i2b && status_inv && status_set && status_get;
}