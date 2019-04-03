//
// Created by Alexandra Zaharia on 03/04/19.
//

#ifndef C_PLAYGROUND_CMP_H
#define C_PLAYGROUND_CMP_H

int compare_int_asc(const void *a, const void *b);    // compare 2 integers (ascending order)
int compare_int_desc(const void *a, const void *b);   // compare 2 integers (descending order)

int compare_str_asc(const void *a, const void *b);    // compare 2 strings (asscending order)
int compare_str_desc(const void *a, const void *b);   // compare 2 strings (descending order)

typedef struct point_t {
    int x;
    int y;
} Point;

int compare_struct_asc(const void *a, const void *b);  // compare 2 structs Point (ascending order)
int compare_struct_desc(const void *a, const void *b); // compare 2 structs Point (descending order)

#endif //C_PLAYGROUND_CMP_H
