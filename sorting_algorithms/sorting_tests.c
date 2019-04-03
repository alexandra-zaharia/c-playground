//
// Created by Alexandra Zaharia on 03/04/19.
//

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"
#include "cmp.h"

#define SIZE 10


// Prints an array of integers of `n_items` elements.
void print_array_int(int *array, size_t n_items)
{
    for (size_t i = 0; i < n_items; i++)
        printf("%d ", array[i]);
    printf("\n");
}


// Prints an array of strings of `n_items` elements.
void print_array_str(char **array, size_t n_items)
{
    for (size_t i = 0; i < n_items; i++)
        printf("%s ", array[i]);
    printf("\n");
}


// Prints an array of Point structs of `n_items` elements.
void print_array_struct(Point **array, size_t n_items)
{
    for (size_t i = 0; i < n_items; i++)
        printf("(%d, %d) ", array[i]->x, array[i]->y);
    printf("\n");
}


// Initializes a predefined array of 10 integers.
void init_array_int(int *array)
{
    array[0] = 5; array[1] = 1; array[2] = 8; array[3] = 7; array[4] = 2;
    array[5] = 6; array[6] = 9; array[7] = 0; array[8] = 4; array[9] = 3;
}


// Initializes a predefined array of 10 strings.
void init_array_str(char **array)
{
    strcpy(array[0], "tiger");
    strcpy(array[1], "cheetah");
    strcpy(array[2], "leopard");
    strcpy(array[3], "cat");
    strcpy(array[4], "lion");
    strcpy(array[5], "jaguar");
    strcpy(array[6], "caracal");
    strcpy(array[7], "bobcat");
    strcpy(array[8], "puma");
    strcpy(array[9], "serval");
}


// Initializes a predefined array of 10 Point structs.
void init_array_struct(Point **array)
{
    array[0]->x = 4; array[0]->y = 3;
    array[1]->x = 5; array[1]->y = 9;
    array[2]->x = 2; array[2]->y = 5;
    array[3]->x = 4; array[3]->y = 1;
    array[4]->x = 1; array[4]->y = 5;
    array[5]->x = 4; array[5]->y = 2;
    array[6]->x = 1; array[6]->y = 3;
    array[7]->x = 4; array[7]->y = 3;
    array[8]->x = 2; array[8]->y = 7;
    array[9]->x = 2; array[9]->y = 6;
}


// Tests sorting a predefined array of 10 integers, in both ascending and descending order.
void test_integer_sort()
{
    int *arr_int = malloc(sizeof(int) * SIZE);
    if (!arr_int) {
        fprintf(stderr, "Cannot allocate array of integers\n");
        exit(EXIT_FAILURE);
    }

    printf("Sorting integers in ascending order:\n");
    init_array_int(arr_int);
    printf("Initial array:  ");
    print_array_int(arr_int, SIZE);

    selection_sort(arr_int, SIZE, sizeof(int), compare_int_asc);
    printf("Selection sort: ");
    print_array_int(arr_int, SIZE);
    printf("---\n");

    printf("Sorting integers in descending order:\n");
    init_array_int(arr_int);
    printf("Initial array:  ");
    print_array_int(arr_int, SIZE);
    selection_sort(arr_int, SIZE, sizeof(int), compare_int_desc);
    printf("Selection sort: ");
    print_array_int(arr_int, SIZE);
    printf("=====================================================================================\n");

    free(arr_int);
}


// Tests sorting a predefined array of 10 strings, in both ascending and descending order.
void test_string_sort()
{
    char **arr_str = malloc(sizeof(char *) * SIZE);
    if (!arr_str) {
        fprintf(stderr, "Cannot allocate array of strings\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < SIZE; i++)
        arr_str[i] = malloc(sizeof(char) * 20);

    printf("Sorting strings in ascending order:\n");
    init_array_str(arr_str);
    printf("Initial array:  ");
    print_array_str(arr_str, SIZE);
    selection_sort(arr_str, SIZE, sizeof(char *), compare_str_asc);
    printf("Selection sort: ");
    print_array_str(arr_str, SIZE);
    printf("---\n");

    printf("Sorting strings in descending order:\n");
    init_array_str(arr_str);
    printf("Initial array:  ");
    print_array_str(arr_str, SIZE);
    selection_sort(arr_str, SIZE, sizeof(char *), compare_str_desc);
    printf("Selection sort: ");
    print_array_str(arr_str, SIZE);
    printf("=====================================================================================\n");

    for (size_t i = 0; i < SIZE; i++)
        free(arr_str[i]);
    free(arr_str);
}


// Tests sorting a predefined array of 10 Point structs, in both ascending and descending order.
void test_struct_sort()
{
    Point **arr_struct = malloc(sizeof(Point *) * SIZE);
    if (!arr_struct) {
        fprintf(stderr, "Cannot allocate array of structs\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < SIZE; i++)
        arr_struct[i] = malloc(sizeof(Point));

    printf("Sorting Point structs in ascending order:\n");
    init_array_struct(arr_struct);
    printf("Initial array:  ");
    print_array_struct(arr_struct, SIZE);
    selection_sort(arr_struct, SIZE, sizeof(Point *), compare_struct_asc);
    printf("Selection sort: ");
    print_array_struct(arr_struct, SIZE);
    printf("---\n");

    printf("Sorting Point structs in descending order:\n");
    init_array_struct(arr_struct);
    printf("Initial array:  ");
    print_array_struct(arr_struct, SIZE);
    selection_sort(arr_struct, SIZE, sizeof(Point *), compare_struct_desc);
    printf("Selection sort: ");
    print_array_struct(arr_struct, SIZE);
    printf("=====================================================================================\n");

    for (size_t i = 0; i < SIZE; i++)
        free(arr_struct[i]);
    free(arr_struct);
}


int main()
{
    test_integer_sort();
    test_string_sort();
    test_struct_sort();
}