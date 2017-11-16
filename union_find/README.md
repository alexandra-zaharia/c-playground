# Union-Find

## About

Simple [union-find](https://en.wikipedia.org/wiki/Disjoint-set_data_structure) implementation.

## Motivation

* Very useful algorithm for graph connectivity and for studying percolation.
* Optimized **find** operation using _path compression_ (the resulting tree is flattened).
* Optimized **union** operation using _union by rank_ (the shorter tree is always attached to the root of the taller tree).

## Compiling

```
gcc -Wall -Wextra -o uf_client uf_client.c uf.c
```

## Test cases

Two test cases are provided in [`data/`](https://github.com/alexandra-zaharia/c-playground/blob/master/union_find/data):

* `test_case_small.txt` contains 10 sites;
* `test_case_medium.txt` contains 625 sites.

## Running the union-find client

``` 
$ ./uf_client data/test_case_small.txt
```

Creates an output file at `data/test_case_small.txt.out` with the sites from the input file, their parents and respective weights. 
