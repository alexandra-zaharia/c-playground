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
* a used-defined data structure `Point` with two integer members `x` and `y`

## Included algorithms

Let us assume there are *N* items in the array. The included algorithms are:
* **Selection sort** -- naïve algorithm where the smallest item in the array is placed in the first position, then the next smallest item is placed in the second position, and so on, until the whole array is sorted.
  * Time complexity: *O(N<sup>2</sup>)* (uses ~*N<sup>2</sup>/2 compares, performs *N* exchanges)
  * Space complexity: *O(1)* auxiliary space
  * Not stable (meaning the order of equal values is not preserved)

## Compiling

The file [`sorting_tests.c`](https://github.com/alexandra-zaharia/c-playground/blob/master/sorting_algorithms/sorting_tests.c) sorts three predefined arrays of 10 integers, 10 strings, and 10 `Point` data structures in both ascending and descending order using every sorting algorithm implemented in [`sort.c`](https://github.com/alexandra-zaharia/c-playground/blob/master/sorting_algorithms/sort.c). Compile as follows:

```
gcc -g -Wall -Wextra -Wpedantic -Wconversion -o sorting_tests sorting_tests.c sort.c cmp.c
```

Run the executable:

```
./sorting_tests
```
