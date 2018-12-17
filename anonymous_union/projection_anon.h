/* projection_anon.h */

#ifndef PROJECTION_ANON_H
#define PROJECTION_ANON_H

#include <stdbool.h>

typedef struct {
    double x;
    double y;
} Point2D;

typedef struct {
    Point2D start;
    Point2D end;
} Segment;

typedef struct {
    union {
		Point2D point;
		Segment segment;
    };
    bool is_segment;
} Projection;

Projection horizontal_projection(Segment);
Projection vertical_projection(Segment);

#endif // PROJECTION_ANON_H
