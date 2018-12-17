# Segment projection using `union`s

## Update

For an improved version using C11 **anonymous unions**, see [anonymous\_union](https://github.com/alexandra-zaharia/c-playground/tree/master/anonymous_union).

## About

Example of `union` usage in C that does not involve anything low-level. Check out this [article](https://sites.google.com/view/alexandra-zaharia/blog/unions-in-c) for a detailed explanation.

## Motivation

* Needed an example involving `union` that was both visual and easy to grasp.
* This example involves the notion of _segment projection_. A segment is defined by its two endpoints and can be projected on either the horizontal (X) axis or the vertical (Y) axis. The projection of a segment is:
  * A point if a vertical segment is projected on the horizontal axis;
  * A point if a horizontal segment is projected on the vertical axis;
  * A segment in any other case.

## Compiling

```
gcc -Wall -Wextra -o test_projection test_projection.c projection.c
```

## Test cases

Four test cases are provided in [`test_projection.c`](https://github.com/alexandra-zaharia/c-playground/blob/master/projection/test_projection.c).

Run the tests with:

``` 
$ ./test_projection
```

## Notes

This implementation does not use pointers as it was beyond the scope of the class I was giving.

