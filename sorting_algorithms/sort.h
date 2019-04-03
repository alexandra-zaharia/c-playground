//
// Created by Alexandra Zaharia on 03/04/19.
//

#ifndef C_PLAYGROUND_SORT_H
#define C_PLAYGROUND_SORT_H

#include <stddef.h> // size_t

void selection_sort(void *array, size_t n_items, size_t size,
                    int (*compare)(const void *, const void *));
void bubble_sort(void *array, size_t n_items, size_t size,
                 int (*compare)(const void *, const void *));
void insertion_sort(void *array, size_t n_items, size_t size,
                   int (*compare)(const void *, const void *));
void mergesort(void *array, size_t n_items, size_t size,
               int (*compare)(const void *, const void *));

#endif //C_PLAYGROUND_SORT_H
