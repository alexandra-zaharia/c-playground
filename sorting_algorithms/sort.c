//
// Created by Alexandra Zaharia on 03/04/19.
//

#include "sort.h"


void swap(void *a, void *b, size_t size)
{
    char *_a = a;
    char *_b = b;
    do {
        char tmp = *_a;
        *_a++ = *_b;
        *_b++ = tmp;
    } while(--size > 0);
}


/*
 * Sorts the array `array` with `n_items` elements of size `size` using selection sort. Array
 * elements are sorted in ascending order according to a comparison function pointed to by
 * `compare`, which is called with two arguments that point to the objects being compared.
 *
 * Selection sort uses ~(n_items)^2 / 2 compares and `n_items` swaps to sort the array.
 *
 * Selection sort is not stable, i.e. it does not preserve the order of equal items.
 */
void selection_sort(void *array, size_t n_items, size_t size,
                    int (*compare)(const void *, const void *))
{
    for (size_t i = 0; i < n_items; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < n_items; j++) {
            if (compare((char *) array + j * size, (char *) array + min * size) < 0)
                min = j; // the minimum value so far is at index j if array[j] < array[min]
        }
        // We swap array[i] with array[min]
        swap((char *) array + i * size, (char *) array + min * size, size);
    }
}