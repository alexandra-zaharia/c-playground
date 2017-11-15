#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdbool.h>

#define KELVIN 1
#define CELSIUS 2
#define FAHRENHEIT 3

#define C_K 273.15 /* Passage de Celsius <-> Kelvin */
#define C_F1 32    /* Passage de Celsius <-> Fahrenheit */
#define C_F2 1.8   /* Passage de Celsius <-> Fahrenheit */

double celsius_to_fahrenheit(double);
double celsius_to_kelvin(double);
double kelvin_to_celsius(double);
double kelvin_to_fahrenheit(double);
double fahrenheit_to_celsius(double);
double fahrenheit_to_kelvin(double);

bool is_temp_scale_valid(int);
bool is_conv_scale_valid(int, int);

double do_conversion(int, int, double);

#endif /* CONVERSION_H */


