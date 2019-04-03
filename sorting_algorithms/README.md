# Sorting algorithms

## About

The file [`sort.c`](https://github.com/alexandra-zaharia/c-playground/blob/master/sorting_algorithms/sort.c) contains implementations for several sorting algorithms. They all follow the template proposed by the `qsort` implementation in `stdlib.h`:

```c
void sorting_algorithm(void *array, size_t n_items, size_t size, int (*compare)(const void *, const void *));
```

The sorting algorithms sort an array `array` with `n_items` elements, each of size `size`, in ascending order using the function `compare`. This function takes two pointers to the values being compared. Note that if you want the algorithm to sort the array in descending order, you need to provide it with a `compare` function that compares items in descending order.

A compare function for sorting in ascending order that compares two `const void` pointers `a` and `b`:
* casts the `void` pointers to the respective type of values being compared;
* returns -1 if the value pointed to by `a` is less than the value pointed to by `b`;
* returns 0 if the values pointed to by `a` and `b` are equal;
* returns 1 if the value pointed to by `a` is greater than the value pointed to by `b`.

Comparison functions have been implemented in the file [`cmp.c`](https://github.com/alexandra-zaharia/c-playground/blob/master/sorting_algorithms/cmp.c) in both ascending and descending order for:
* integers
* strings
* a data structure `Point` with two integer members `x` and `y` (defined in [`cmp.h`](https://github.com/alexandra-zaharia/c-playground/blob/master/sorting_algorithms/cmp.h))

## Included algorithms

Let us assume there are *N* items in the array. The included algorithms are:
* **Selection sort** -- naïve algorithm where the smallest item in the array is placed in the first position, then the next smallest item is placed in the second position, and so on, until the whole array is sorted.
  * Time complexity: *O*(*N*<sup>2</sup>) (performs ~*N*<sup>2</sup>/2 comparisons and *N* swaps)
  * Space complexity: *O*(1) auxiliary space
  * Not stable (meaning the order of equal values is not preserved)
  * Not adaptive (meaning it does not perform better when data is nearly sorted)
  
* **Bubble sort** -- naïve algorithm where consecutive items are compared and swapped if they are in the wrong order; this process is repeated until no swap is performed for a whole pass.
  * Time complexity: *O*(*N*<sup>2</sup>) comparisons and swaps in the average and worst-case scenario; *O*(*N*) comparisons and *O*(1) swaps in the best-case scenario, i.e. when the array is already sorted
  * Space complexity: *O*(1) auxiliary space
  * Stable (meaning the order of equal values is preserved)
  * Adaptive (meaning it performs better when the data is nearly sorted)
  
* **Insertion sort** -- naïve algorithm where an out-of-order item is inserted among the already sorted items; the process is repeated until the whole array is sorted. Insertion sort is what you would typically do to manually sort a deck of cards.
  * Time complexity: *O*(*N*<sup>2</sup>) comparisons and swaps in the average and worst-case scenario; *O*(*N*) comparisons and *O*(1) swaps in the best-case scenario
  * Space complexity: *O*(1) auxiliary space
  * Stable
  * Adaptive

## Compiling

The file [`sorting_tests.c`](https://github.com/alexandra-zaharia/c-playground/blob/master/sorting_algorithms/sorting_tests.c) sorts three predefined arrays of 10 integers, 10 strings, and 10 `Point` data structures in both ascending and descending order using every sorting algorithm implemented in [`sort.c`](https://github.com/alexandra-zaharia/c-playground/blob/master/sorting_algorithms/sort.c). Compile as follows:

```
gcc -g -Wall -Wextra -Wpedantic -Wconversion -o sorting_tests sorting_tests.c sort.c cmp.c
```

Run the executable:

```
./sorting_tests
```

## TODO

Add full suite of tests using [cmocka](https://cmocka.org/) (integer, strings, custom data structure) for the following cases and for every implemented algorithm, using the ascending and descending compare functions:
* random order
* nearly sorted
* reversed order
* few unique values