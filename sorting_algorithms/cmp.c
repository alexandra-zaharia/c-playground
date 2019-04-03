//
// Created by Alexandra Zaharia on 03/04/19.
//

#include <string.h>
#include "cmp.h"


// Compares two integers pointed to by `a` and `b` in ascending order, i.e. returns -1 if a < b.
int compare_int_asc(const void *a, const void *b)
{
    int _a = *((int *) a);
    int _b = *((int *) b);
    if (_a < _b) return -1;
    return _a != _b;
}


// Compares two integers pointed to by `a` and `b` in descending order, i.e. returns -1 if a > b.
int compare_int_desc(const void *a, const void *b)
{
    int _a = *((int *) a);
    int _b = *((int *) b);
    if (_a > _b) return -1;
    return _a < _b;
}


// Compares two strings pointed to by `a` and `b` in ascending order, i.e. returns -1 if a < b.
int compare_str_asc(const void *a, const void *b)
{
    return strcmp(*(const char **) a, *(const char **) b);
}


// Compares two strings pointed to by `a` and `b` in descending order, i.e. returns -1 if a > b.
int compare_str_desc(const void *a, const void *b)
{
    int cmp = strcmp(*(const char **) a, *(const char **) b);
    if (cmp == 1) return -1;
    return cmp != 0;
}


/*
 * Compares two Point structs pointed to by `a` and `b` in ascending order, i.e. returns -1 if
 * a < b.
 */
int compare_struct_asc(const void *a, const void *b)
{
    const Point *_a = *((const Point **) a);
    const Point *_b = *((const Point **) b);

    if (_a->x < _b->x) return -1;
    if (_a->x > _b->x) return 1;
    if (_a->y < _b->y) return -1;
    return _a->y != _b->y;
}


/*
 * Compares two Point structs pointed to by `a` and `b` in descending order, i.e. returns -1 if
 * a > b.
 */
int compare_struct_desc(const void *a, const void *b)
{
    const Point *_a = *((const Point **) a);
    const Point *_b = *((const Point **) b);

    if (_a->x < _b->x) return 1;
    if (_a->x > _b->x) return -1;
    if (_a->y > _b->y) return -1;
    return _a->y != _b->y;
}
