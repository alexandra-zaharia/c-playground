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


static void test_rotate_left_1_byte()
{
    assert_int_equal(rotate_left(100, 3), 35);  // rotL(011 00100, 3) => 00100 011
    assert_int_equal(rotate_left(116, 3), 163); // rotL(011 10100, 3) => 10100 011
    assert_int_equal(rotate_left(244, 3), 167); // rotL(111 10100, 3) => 10100 111
}


static void test_rotate_left_2_bytes()
{
    // rotL(0110 111100001010, 4) => 111100001010 0110
    assert_int_equal(rotate_left(28426, 4), 61606);

    // rotL(0000000101 100100, 10) => (100100 0000000101)
    assert_int_equal(rotate_left(356, 10), 36869);
}


static void test_rotate_left_3_bytes()
{
    if (sizeof(unsigned int) == 2) return;

    // rotL(00001111 0000000101100100, 8) => 0000000101100100 00001111
    assert_int_equal(rotate_left(983396, 8), 91151);
}


static void test_rotate_left_4_bytes()
{
    if (sizeof(unsigned int) == 2) return;

    // rotL(11001 100000000010110010000001111, 5) => 100000000010110010000001111 11001
    assert_true(rotate_left(3422643215, 5) == 2150400505);
}


static void test_insert_number_1024_19()
{
    // n = 1024    : 100 00000000
    // m =   19    :      10011
    // i = 2, j = 6: 100 01001100 = 1100
    assert_int_equal(insert_number(1024, 19, 2, 6), 1100);
}

static void test_insert_number_127_4()
{
    // n = 127     : 1111111
    // m = 4       :     100
    // i = 3, j = 5: 1100111 = 103
    assert_int_equal(insert_number(127, 4, 3, 5), 103);
}


static void test_power_of_two_true()
{
    assert_true(is_power_of_two(1));
    assert_true(is_power_of_two(2));
    assert_true(is_power_of_two(4));
    assert_true(is_power_of_two(8));
    assert_true(is_power_of_two(16));
    assert_true(is_power_of_two(32));
    assert_true(is_power_of_two(64));
    assert_true(is_power_of_two(128));
    assert_true(is_power_of_two(256));
    assert_true(is_power_of_two(512));
    assert_true(is_power_of_two(1024));
}


static void test_power_of_two_false()
{
    assert_false(is_power_of_two(0));
    assert_false(is_power_of_two(3));
    assert_false(is_power_of_two(7));
    assert_false(is_power_of_two(9));
    assert_false(is_power_of_two(15));
    assert_false(is_power_of_two(127));
    assert_false(is_power_of_two(129));
    assert_false(is_power_of_two(130));
    assert_false(is_power_of_two(-1));
    assert_false(is_power_of_two(-2));
}


static void test_flip_bit_to_win_615()
{
    // 615: 100110*0111*
    assert_int_equal(flip_bit_to_win(615), 4);
}


static void test_flip_bit_to_win_1775()
{
    // 1775: 110*11101111*
    assert_int_equal(flip_bit_to_win(1775), 8);
}


static void test_flip_bit_to_win_1774()
{
    // 1774: 110*1110111*0
    assert_int_equal(flip_bit_to_win(1774), 7);
}


static void test_flip_bit_to_win_9967()
{
    // 9967: 100110*11101111*
    assert_int_equal(flip_bit_to_win(9967), 8);
}


static void test_flip_bit_to_win_52975()
{
    // 52975: 11001110*11101111*
    assert_int_equal(flip_bit_to_win(52975), 8);
}


static void test_flip_bit_to_win_0()
{
    assert_int_equal(flip_bit_to_win(0), 1);
}


static void test_flip_bit_to_win_1()
{
    assert_int_equal(flip_bit_to_win(1), 2);
}


static void test_flip_bit_to_win_2()
{
    assert_int_equal(flip_bit_to_win(2), 2);
}


static void test_flip_bit_to_win_30()
{
    assert_int_equal(flip_bit_to_win(30), 5);
}


static void test_flip_bit_to_win_31()
{
    assert_int_equal(flip_bit_to_win(31), 6);
}


static void test_flip_bit_to_win_minus_1()
{
    assert_int_equal(flip_bit_to_win(-1), CHAR_BIT * sizeof(int));
}


static void test_flip_bit_to_win_minus_2()
{
    assert_int_equal(flip_bit_to_win(-2), CHAR_BIT * sizeof(int));
}


int run_tests_conversion()
{
    const struct CMUnitTest tests_conversion[] = {
            cmocka_unit_test(test_convert_int_to_binary_string_7),
            cmocka_unit_test(test_convert_int_to_binary_string_2019),
            cmocka_unit_test(test_convert_int_to_binary_string_minus_1),
            cmocka_unit_test(test_convert_int_to_binary_string_minus_2)
    };

    printf("Testing int conversion into binary string\n");
    return cmocka_run_group_tests(tests_conversion, NULL, NULL);
}


int run_tests_inversion()
{
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

    printf("\nTesting inversion of last n bits\n");
    return cmocka_run_group_tests(tests_inversion, NULL, NULL);
}


int run_tests_count_bits_set()
{
    const struct CMUnitTest tests_count_bits_set[] = {
            cmocka_unit_test(test_count_bits_set_7),
            cmocka_unit_test(test_count_bits_set_2019),
            cmocka_unit_test(test_count_bits_set_minus_1),
            cmocka_unit_test(test_count_bits_set_minus_2),
    };

    printf("\nTesting count of bits set to on\n");
    return cmocka_run_group_tests(tests_count_bits_set, NULL, NULL);
}


int run_tests_get_bit()
{
    const struct CMUnitTest tests_get_bit[] = {
            cmocka_unit_test(test_get_bits_7),
            cmocka_unit_test(test_get_bits_2019),
            cmocka_unit_test(test_get_bits_minus_1),
            cmocka_unit_test(test_get_bits_minus_2)
    };

    printf("\nTesting bit checking\n");
    return cmocka_run_group_tests(tests_get_bit, NULL, NULL);
}


int run_tests_clear_most_significant_bits()
{
    const struct CMUnitTest tests_clear_most_significant_bits[] = {
            cmocka_unit_test(test_clear_most_significant_bits_7),
            cmocka_unit_test(test_clear_most_significant_bits_2019),
            cmocka_unit_test(test_clear_most_significant_bits_minus_1),
            cmocka_unit_test(test_clear_most_significant_bits_minus_2)
    };

    printf("\nTesting clearing most significant bits up to a given position\n");
    return cmocka_run_group_tests(tests_clear_most_significant_bits, NULL, NULL);
}


int run_tests_clear_least_significant_bits()
{
    const struct CMUnitTest tests_clear_least_significant_bits[] = {
            cmocka_unit_test(test_clear_least_significant_bits_7),
            cmocka_unit_test(test_clear_least_significant_bits_2019),
            cmocka_unit_test(test_clear_least_significant_bits_minus_1),
            cmocka_unit_test(test_clear_least_significant_bits_minus_2)
    };

    printf("\nTesting clearing least significant bits from a given position through 0\n");
    return cmocka_run_group_tests(tests_clear_least_significant_bits, NULL, NULL);
}


int run_tests_rotate_left()
{
    const struct CMUnitTest tests_rotate_left[] = {
            cmocka_unit_test(test_rotate_left_1_byte),
            cmocka_unit_test(test_rotate_left_2_bytes),
            cmocka_unit_test(test_rotate_left_3_bytes),
            cmocka_unit_test(test_rotate_left_4_bytes)
    };

    printf("\nTesting rotating a number to the left by a specified number of positions\n");
    return cmocka_run_group_tests(tests_rotate_left, NULL, NULL);
}


int run_tests_insert_number()
{
    const struct CMUnitTest tests_insert_number[] = {
            cmocka_unit_test(test_insert_number_1024_19),
            cmocka_unit_test(test_insert_number_127_4)
    };

    printf("\nTesting insertion of a number into another number between specified positions\n");
    return cmocka_run_group_tests(tests_insert_number, NULL, NULL);
}


int run_tests_power_of_two()
{
    const struct CMUnitTest tests_power_of_two[] = {
            cmocka_unit_test(test_power_of_two_true),
            cmocka_unit_test(test_power_of_two_false)
    };

    printf("\nTesting check for power of two\n");
    return cmocka_run_group_tests(tests_power_of_two, NULL, NULL);
}


int run_tests_flip_bit_to_win()
{
    const struct CMUnitTest tests_flip_bit_to_win[] = {
            cmocka_unit_test(test_flip_bit_to_win_615),
            cmocka_unit_test(test_flip_bit_to_win_1775),
            cmocka_unit_test(test_flip_bit_to_win_1774),
            cmocka_unit_test(test_flip_bit_to_win_9967),
            cmocka_unit_test(test_flip_bit_to_win_52975),
            cmocka_unit_test(test_flip_bit_to_win_0),
            cmocka_unit_test(test_flip_bit_to_win_1),
            cmocka_unit_test(test_flip_bit_to_win_2),
            cmocka_unit_test(test_flip_bit_to_win_30),
            cmocka_unit_test(test_flip_bit_to_win_31),
            cmocka_unit_test(test_flip_bit_to_win_minus_1),
            cmocka_unit_test(test_flip_bit_to_win_minus_2)
    };

    printf("\nTesting flip_bit_to_win()\n");
    return cmocka_run_group_tests(tests_flip_bit_to_win, NULL, NULL);
}


int main()
{
    int status_i2b = run_tests_conversion();
    int status_inv = run_tests_inversion();
    int status_set = run_tests_count_bits_set();
    int status_get = run_tests_get_bit();
    int status_clr_msig = run_tests_clear_most_significant_bits();
    int status_clr_lsig = run_tests_clear_least_significant_bits();
    int status_rot_l = run_tests_rotate_left();
    int status_ins = run_tests_insert_number();
    int status_pow2 = run_tests_power_of_two();
    int status_flip = run_tests_flip_bit_to_win();

    return status_i2b || status_inv || status_set || status_get || status_clr_msig
        || status_clr_lsig || status_rot_l || status_ins || status_pow2 || status_flip;
}
