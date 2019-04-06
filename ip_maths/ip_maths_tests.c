//
// Created by Alexandra Zaharia on 06/04/19.
//

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>
#include <cmocka.h>

#include <stdio.h>
#include "ip_maths.h"


static void test_broadcast_address_1()
{
    char bcast[16];
    get_broadcast_address("192.168.2.10", 24, bcast);
    assert_string_equal(bcast, "192.168.2.255");
}


static void test_broadcast_address_2()
{
    char bcast[16];
    get_broadcast_address("10.1.23.10", 20, bcast);
    assert_string_equal(bcast, "10.1.31.255");
}


static void test_integer_equivalent_1()
{
    assert_int_equal(get_ip_integer_equivalent("192.168.2.10"), 3232236042);
}


static void test_integer_equivalent_2()
{
    assert_int_equal(get_ip_integer_equivalent("10.1.23.10"), 167843594);
}


static void test_ipv4_format_1()
{
    char ip_addr[16];
    get_ipv4_format(3232236042, ip_addr);
    assert_string_equal(ip_addr, "192.168.2.10");
}


static void test_ipv4_format_2()
{
    char ip_addr[16];
    get_ipv4_format(167843594, ip_addr);
    assert_string_equal(ip_addr, "10.1.23.10");
}

static void test_network_id_1()
{
    char network_id[16];
    get_network_id("192.168.2.10", 24, network_id);
    assert_string_equal(network_id, "192.168.2.0");
}


static void test_network_id_2()
{
    char network_id[16];
    get_network_id("10.1.23.10", 20, network_id);
    assert_string_equal(network_id, "10.1.16.0");
}


static void test_subnet_cardinality_1()
{
    assert_int_equal(get_subnet_cardinality(24), 254);
}


static void test_subnet_cardinality_2()
{
    assert_int_equal(get_subnet_cardinality(20), 4094);
}


static void test_subnet_membership_1()
{
    assert_int_equal(check_ip_subnet_membership("192.168.2.0", 24, "192.168.2.0"), 0);
    assert_int_equal(check_ip_subnet_membership("192.168.2.0", 24, "192.168.2.1"), 0);
    assert_int_equal(check_ip_subnet_membership("192.168.2.0", 24, "192.168.2.254"), 0);
    assert_int_equal(check_ip_subnet_membership("192.168.2.0", 24, "192.168.2.255"), 0);
    assert_int_equal(check_ip_subnet_membership("192.168.2.0", 24, "192.168.1.255"), -1);
    assert_int_equal(check_ip_subnet_membership("192.168.2.0", 24, "192.167.2.1"), -1);
}


static void test_subnet_membership_2()
{
    assert_int_equal(check_ip_subnet_membership("10.1.16.0", 20, "10.1.23.10"), 0);
    assert_int_equal(check_ip_subnet_membership("10.1.16.0", 20, "10.1.31.31"), 0);
    assert_int_equal(check_ip_subnet_membership("10.1.16.0", 20, "10.1.17.31"), 0);
    assert_int_equal(check_ip_subnet_membership("10.1.16.0", 20, "10.1.15.31"), -1);
    assert_int_equal(check_ip_subnet_membership("10.1.16.0", 20, "10.1.48.31"), -1);
    assert_int_equal(check_ip_subnet_membership("10.1.16.0", 20, "10.1.80.31"), -1);
    assert_int_equal(check_ip_subnet_membership("10.1.16.0", 20, "10.1.95.31"), -1);
}


/*
 * Test runners
 * -----------------------------------------------------------------------------
 */

int run_tests_broadcast()
{
    const struct CMUnitTest tests_broadcast[] = {
            cmocka_unit_test(test_broadcast_address_1),
            cmocka_unit_test(test_broadcast_address_2)
    };

    printf("Testing broadcast address\n");
    return cmocka_run_group_tests(tests_broadcast, NULL, NULL);
}


int run_tests_integer_equivalent()
{
    const struct CMUnitTest tests_integer_equivalent[] = {
            cmocka_unit_test(test_integer_equivalent_1),
            cmocka_unit_test(test_integer_equivalent_2)
    };

    printf("\nTesting integer equivalent of an IP address\n");
    return cmocka_run_group_tests(tests_integer_equivalent, NULL, NULL);
}


int run_tests_ipv4_format()
{
    const struct CMUnitTest tests_ipv4_format[] = {
            cmocka_unit_test(test_ipv4_format_1),
            cmocka_unit_test(test_ipv4_format_2)
    };

    printf("\nTesting IPv4 address format\n");
    return cmocka_run_group_tests(tests_ipv4_format, NULL, NULL);
}


int run_tests_network_id()
{
    const struct CMUnitTest tests_network_id[] = {
            cmocka_unit_test(test_network_id_1),
            cmocka_unit_test(test_network_id_2)
    };

    printf("\nTesting network ID\n");
    return cmocka_run_group_tests(tests_network_id, NULL, NULL);
}


int run_tests_cardinality()
{
    const struct CMUnitTest tests_cardinality[] = {
            cmocka_unit_test(test_subnet_cardinality_1),
            cmocka_unit_test(test_subnet_cardinality_2)
    };

    printf("\nTesting subnet cardinality\n");
    return cmocka_run_group_tests(tests_cardinality, NULL, NULL);
}


int run_tests_subnet_membership()
{
    const struct CMUnitTest tests_membership[] = {
            cmocka_unit_test(test_subnet_membership_1),
            cmocka_unit_test(test_subnet_membership_2)
    };

    printf("\nTesting subnet membership\n");
    return cmocka_run_group_tests(tests_membership, NULL, NULL);
}


int main()
{
    return run_tests_broadcast()
        || run_tests_integer_equivalent()
        || run_tests_ipv4_format()
        || run_tests_network_id()
        || run_tests_cardinality()
        || run_tests_subnet_membership();
}