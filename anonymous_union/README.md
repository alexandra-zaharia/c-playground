# Segment projection using anonymous `union`s

## About

Example of `union` usage in C that does not involve anything low-level. Check out this [article](https://sites.google.com/view/alexandra-zaharia/blog/unions-in-c) for a detailed explanation. This is an improved version of the [projection example](https://github.com/alexandra-zaharia/c-playground/tree/master/projection) that uses an **anonymous union**.

As its name implies, an _anonymous union_ is an unnamed member of another structure. Therefore, instead of writing:

```c
union SegmentProjection {
	Point2D point;
	Segment segment;
};

struct Projection {
	union SegmentProjection proj;
	bool is_segment;
}; 
```

and accessing the `segment` in the union as `projection.proj.segment` in a `struct Projection` named `projection`, you can simply write:

```c
struct Projection {
	union {
		Point2D point;
		Segment segment;
	};
	bool is_segment;
};
```

and access the `segment` in the union as `projection.segment` in a `struct Projection` named `projection`.

## Motivation

  * Needed an example involving `union` that was both visual and easy to grasp.
  * This example involves the notion of _segment projection_. A segment is defined by its two endpoints and can be projected on either the horizontal (X) axis or the vertical (Y) axis. The projection of a segment is:
    * A point if a vertical segment is projected on the horizontal axis;
    * A point if a horizontal segment is projected on the vertical axis, e.g. the blue segment defined by endpoints (1, 2) and (2, 2) in the figure;
    * A segment in any other case.

## Compiling

```bash
gcc -Wall -Wextra -o test_anonymous_union test_anonymous_union.c projection_anon.c
```

## Test cases

Four test cases are provided in [`test_anonymous_union.c`](https://github.com/alexandra-zaharia/c-playground/blob/master/anonymous_union/test_anonymous_union.c).

Run the tests with:

```bash
$ ./test_anonymous_union
```

## Notes

This implementation does not use pointers as it was beyond the scope of the class I was giving.

