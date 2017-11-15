#ifndef CONV_IO_H
#define CONV_IO_H

#include "conversion.h"

void do_menu();
int get_temp_scale();
int get_conv_scale(int);
char scale_to_char(int);
void display_result(double, int, double, int);

#endif /* CONV_IO_H */
