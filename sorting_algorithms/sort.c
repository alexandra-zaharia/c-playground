//
// Created by Alexandra Zaharia on 03/04/19.
//

#include <stdbool.h>
#include "sort.h"


// Swaps the values of the items pointed to by `a` and `b`, where both items have size `size`.
void _swap(void *a, void *b, size_t size)
{
    char *_a = a;
    char *_b = b;
    do {
        char tmp = *_a;
        *_a++ = *_b;
        *_b++ = tmp;
    } while(--size > 0);
}


// Swaps items at indexes `i` and `j` in the array `array`, where each item has size `size`.
void swap(size_t i, size_t j, void *array, size_t size)
{
    _swap((char *) array + i * size, (char *) array + j * size, size);
}


/*
 * Uses `compare` to determine whether the item at index `i` in `array` is less than the item at
 * index `j`, where all array items have size `size`.
 */
bool less(size_t i, size_t j, void *array, size_t size, int (*compare)(const void *, const void *))
{
    return compare((char *) array + i * size, (char *) array + j * size) < 0;
}


/*
 * Uses `compare` to determine whether the item at index `i` in `array` is greater than the item at
 * index `j`, where all array items have size `size`.
 */
bool greater(size_t i, size_t j, void *array, size_t size,
             int (*compare)(const void *, const void *))
{
    return compare((char *) array + i * size, (char *) array + j * size) > 0;
}


/*
 * Sorts the array `array` with `n_items` elements of size `size` using selection sort. Array
 * elements are sorted in ascending order according to a comparison function pointed to by
 * `compare`, which is called with two arguments that point to the objects being compared.
 *
 * Selection sort uses ~(n_items)^2 / 2 compares and `n_items` swaps to sort the array. Selection
 * sort uses no extra space.
 *
 * Selection sort is not stable, i.e. it does not preserve the order of equal items.
 */
void selection_sort(void *array, size_t n_items, size_t size,
                    int (*compare)(const void *, const void *))
{
    for (size_t i = 0; i < n_items; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < n_items; j++) {
            if (less(j, min, array, size, compare))
                min = j; // the minimum value so far is at index j if array[j] < array[min]
        }
        swap (i, min, array, size); // we swap array[i] with array[min]
    }
}


/*
 * Sorts the array `array` with `n_items` elements of size `size` using bubble sort. Array elements
 * are sorted in ascending order according to a comparison function pointed to by `compare`, which
 * is called with two arguments that point to the objects being compared.
 *
 * Bubble sort performs n_items^2 comparisons and swaps, on average and in the worst case. In the
 * best case, the array is already sorted, in which case bubble sort performs `n_items` comparisons
 * and no swap. Bubble sort uses no extra space.
 *
 * Bubble sort is stable, i.e. it preserves the order of equal items.
 */
void bubble_sort(void *array, size_t n_items, size_t size,
                 int (*compare)(const void *, const void *))
{
    size_t n = n_items - 1;
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < n; i++) {
            if (greater(i, i + 1, array, size, compare)) {
                swap(i, i + 1, array, size);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}