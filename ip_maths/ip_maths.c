//
// Created by Alexandra Zaharia on 06/04/19.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ip_maths.h"


// Assigns the broadcast address for IP `ip_addr` with mask `mask` to `output_buffer` (IPv4 format).
void get_broadcast_address(char *ip_addr, char mask, char *output_buffer)
{
    char network_id[IP_ADDR_MAX_CHARS];
    get_network_id(ip_addr, mask, network_id);
    unsigned int id_int = get_ip_integer_equivalent(network_id);
    unsigned int bcast = id_int | (unsigned int) ((1 << (IP_ADDR_BITS - mask)) - 1);
    get_ipv4_format(bcast, output_buffer);
}


// Returns the integer equivalent of the IPv4 address `ip_addr`.
unsigned int get_ip_integer_equivalent(char *ip_addr)
{
    unsigned char ip_groups[4];
    sscanf(ip_addr, "%hhu.%hhu.%hhu.%hhu",
           &ip_groups[0], &ip_groups[1], &ip_groups[2], &ip_groups[3]);
    return (unsigned int) (ip_groups[0] << 24
                         | ip_groups[1] << 16
                         | ip_groups[2] << 8
                         | ip_groups[3]);
}


/*
 * Assigns the IPv4 address corresponding to its integer representation `ip_addr` to
 * `output_buffer`.
 */
void get_ipv4_format(unsigned int ip_addr, char *output_buffer)
{
    sprintf(output_buffer, "%d.%d.%d.%d",
            (ip_addr & 0xFF000000) >> 24,
            (ip_addr & 0x00FF0000) >> 16,
            (ip_addr & 0x0000FF00) >> 8,
            ip_addr & 0x000000FF);
}


// Assigns the network ID for the IPv4 address `ip_addr` with mask `mask` to `output_buffer`.
void get_network_id(char *ip_addr, char mask, char *output_buffer)
{
    unsigned int ip_int = get_ip_integer_equivalent(ip_addr);
    unsigned int id_int = ip_int & (unsigned int) ~((1 << (IP_ADDR_BITS - mask)) - 1);
    get_ipv4_format(id_int, output_buffer);
}


// Returns the maximum number of machines in a subnet with mask `mask`.
unsigned int get_subnet_cardinality(char mask)
{
    return (unsigned int) pow(2, IP_ADDR_BITS - mask) - 2;
}


/*
 * Determines whether the IPv4 address `check_ip` with mask `mask` belongs to the subnet with
 * network ID `network_id`. Returns 0 if `check_ip` belongs to the subnet, -1 otherwise.
 */
int check_ip_subnet_membership(char *network_id, char mask, char *check_ip)
{
    char check_id[IP_ADDR_MAX_CHARS];
    get_network_id(check_ip, mask, check_id);
    return strncmp(network_id, check_id, IP_ADDR_MAX_CHARS) == 0 ? 0 : -1;
}
