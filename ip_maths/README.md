# IP maths

## About
This is a small collection of utilities for dealing with IP address maths (IPv4). It was an 
assignment for the Udemy course [Network Concepts and Programming from Scratch](https://www.udemy.com/network-programming-from-scratch) by Abhishek Sagar.

Note that the functions do not perform sanity checks on their arguments (i.e., it is assumed functions expecting IP addresses receive actual IP addresses; the same goes with subnet masks).  


## Included functions
The IP maths collection currently contains functions allowing to achieve the following objectives:

* Obtaining the broadcast address for a given IPv4 address and subnet mask
* Computing the integer equivalent of a 32-bit IPv4 address
* Obtaining the 32-bit IPv4 address corresponding to an integer
* Obtaining the network ID for a given IPv4 address and subnet mask
* Determining the maximum number of hosts in a subnet with a given subnet mask
* Checking whether a given IPv4 address with its subnet mask belongs to a specified subnet  


## Compiling
The library [cmocka](https://cmocka.org) needs to be installed in order to compile the tests.
Compile as follows:

```
gcc -g -Wall -Wextra -Wpedantic -Wconversion -o ip_maths_tests ip_maths_tests.c ip_maths.c -lcmocka -lm
```

Run the tests:

```
./ip_maths_tests
```