#include "conversion.h"
#include <stdbool.h>

double celsius_to_fahrenheit(double temp_c) {
    return temp_c * C_F2 + C_F1;
}

double celsius_to_kelvin(double temp_c) {
    return temp_c + C_K;
}

double kelvin_to_celsius(double temp_k) {
    return temp_k - C_K;
}

double kelvin_to_fahrenheit(double temp_k) {
    return C_F2 * (temp_k - C_K) + C_F1;
}

double fahrenheit_to_celsius(double temp_f) {
    return (temp_f - C_F1) / C_F2;
}

double fahrenheit_to_kelvin(double temp_f) {
    return (temp_f - C_F1) / C_F2 + C_K;
}

bool is_temp_scale_valid(int scale) {
    return scale == KELVIN || scale == CELSIUS || scale == FAHRENHEIT;
}

bool is_conv_scale_valid(int temp_scale, int conv_scale) {
    if (temp_scale == KELVIN) 
        return conv_scale == CELSIUS || conv_scale == FAHRENHEIT;
    if (temp_scale == CELSIUS)
        return conv_scale == KELVIN || conv_scale == FAHRENHEIT;
    return conv_scale == KELVIN || conv_scale == CELSIUS;    
}

double do_conversion(int temp_scale, int conv_scale, double init_temp) {
    double conv_temp;
    
    switch (temp_scale) {
        case KELVIN: {
            conv_temp = conv_scale == CELSIUS
                ? kelvin_to_celsius(init_temp)
                : kelvin_to_fahrenheit(init_temp);
        }; break;
        case CELSIUS: {
            conv_temp = conv_scale == KELVIN
                ? celsius_to_kelvin(init_temp)
                : celsius_to_fahrenheit(init_temp);
        }; break;
        case FAHRENHEIT: {
            conv_temp = conv_scale == KELVIN
                ? fahrenheit_to_kelvin(init_temp)
                : fahrenheit_to_celsius(init_temp);
        }; break;
        default: conv_temp = 0.0;
    }
    
    return conv_temp;
}

