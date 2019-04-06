//
// Created by Alexandra Zaharia on 06/04/19.
//

#ifndef C_PLAYGROUND_IP_MATHS_H
#define C_PLAYGROUND_IP_MATHS_H

#define IP_ADDR_BITS 32       // number of bits needed to represent an IPv4 address
#define IP_ADDR_MAX_CHARS 16  // maximum number of characters for an IPv4 address

void get_broadcast_address(char *ip_addr, char mask, char *output_buffer);
unsigned int get_ip_integer_equivalent(char *ip_addr);
void get_ipv4_format(unsigned int ip_addr, char *output_buffer);
void get_network_id(char *ip_addr, char mask, char *output_buffer);
unsigned int get_subnet_cardinality(char mask);
int check_ip_subnet_membership(char *network_id, char mask, char *check_ip);

#endif //C_PLAYGROUND_IP_MATHS_H
