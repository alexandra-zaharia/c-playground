//
// Created by Alexandra Zaharia on 03/04/19.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort.h"


/*
 * Swaps the values of the items pointed to by `a` and `b` byte by byte, where both items have size
 * `size`.
 */
void _swap(void *a, void *b, size_t size)
{
    char *_a = a;
    char *_b = b;
    do {
        char tmp = *_a;
        *_a++ = *_b;
        *_b++ = tmp;
    } while (--size > 0);
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
 * Sorts the array `array` with `n_items` elements of size `size` using selection sort. Array
 * elements are sorted in ascending order according to a comparison function pointed to by
 * `compare`, which is called with two arguments that point to the objects being compared.
 *
 * Selection sort uses ~(n_items^2) / 2 comparisons and `n_items` swaps to sort the array. Selection
 * sort uses no extra space.
 *
 * Selection sort is not stable, i.e. it does not preserve the order of equal items. It is not
 * adaptive, i.e. it does not perform better when the array is nearly sorted.
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
        swap(i, min, array, size); // we swap array[i] with array[min]
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
 * Bubble sort is stable, i.e. it preserves the order of equal items. It is adaptive, i.e. it
 * performs better when the array is nearly sorted.
 */
void bubble_sort(void *array, size_t n_items, size_t size,
                 int (*compare)(const void *, const void *))
{
    size_t n = n_items - 1;
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < n; i++) {
            if (less(i + 1, i, array, size, compare)) {
                swap(i, i + 1, array, size);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}


/*
 * Sorts the array `array` with `n_items` elements of size `size` using insertion sort. Array
 * elements are sorted in ascending order according to a comparison function pointed to by
 * `compare`, which is called with two arguments that point to the objects being compared.
 *
 * Insertion sort performs (n_items^2) / 4 comparisons and swaps on average, (n_items^2) / 2
 * comparisons and swaps in the worst case, and n_items - 1 comparisons and 0 swaps in the best
 * case. Insertion sort uses no extra space.
 *
 * Insertion sort is stable and adaptive.
 */
void insertion_sort(void *array, size_t n_items, size_t size,
                    int (*compare)(const void *, const void *))
{
    for (size_t i = 1; i < n_items; i++)
        for (size_t j = i; j > 0; j--)
            if (less(j, j - 1, array, size, compare))
                swap(j, j - 1, array, size);
}


/*
 * Merges sub-arrays array[lo..mid] and array[mid+1..hi] using the auxiliary array `aux`. Every
 * element in `array` has size `size`, and elements are compared using the provided `compare`
 * function. The array resulting from the merge is sorted.
 */
void _merge(void *array, size_t size, int (*compare)(const void *, const void *),
            size_t lo, size_t mid, size_t hi, void *aux)
{
    for (size_t k = lo; k <= hi; k++) // copy array[lo..hi] into aux[lo..hi]
        memcpy((char *) aux + k * size, (char *) array + k * size, size);

    size_t i = lo;
    size_t j = mid + 1;

    for (size_t k = lo; k <= hi; k++) {
        if (i > mid) {                               // array[k] = aux[j++]
            memcpy((char *) array + k * size, (char *) aux + j++ * size, size);
        } else if (j > hi) {                         // array[k] = aux[i++]
            memcpy((char *) array + k * size, (char *) aux + i++ * size, size);
        } else if (less(j, i, aux, size, compare)) { // array[k] = aux[j++]
            memcpy((char *) array + k * size, (char *) aux + j++ * size, size);
        } else {                                     // array[k] = aux[i++]
            memcpy((char *) array + k * size, (char *) aux + i++ * size, size);
        }
    }
}

/*
 * Helper function for performing top-down mergesort on the array `array` with `n_items` elements,
 * where each element has size `size`. Items are compared using the provided `compare` function.
 * The lowest index in the array on which mergesort is performed is `lo`, and the highest is `hi`.
 * The auxiliary array `aux` is used for merging two sorted sub-arrays.
 */
void _mergesort(void *array, size_t size,
               int (*compare)(const void *, const void *),
               size_t lo, size_t hi, void *aux)
{
    if (hi <= lo) return;
    size_t mid = lo + (hi - lo) / 2;
    _mergesort(array, size, compare, lo, mid, aux);
    _mergesort(array, size, compare, mid + 1, hi, aux);
    _merge(array, size, compare, lo, mid, hi, aux);
}


/*
 * Sorts the array `array` with `n_items` elements of size `size` using top-down mergesort. Array
 * elements are sorted in ascending order according to a comparison function pointed to by
 * `compare`, which is called with two arguments that point to the objects being compared.
 *
 * Mergesort performs n_items * lg(n_items) comparisons on average.
 *
 * Mergesort is stable and non adaptive.
 *
 */
void mergesort(void *array, size_t n_items, size_t size,
               int (*compare)(const void *, const void *))
{
    void *aux = malloc(size * n_items);
    if (!aux) {
        fprintf(stderr, "Cannot allocate auxiliary array for mergesort\n");
        exit(EXIT_FAILURE);
    }

    memset(aux, 0, n_items * size);
    _mergesort(array, size, compare, 0, n_items - 1, aux);

    free(aux);
}