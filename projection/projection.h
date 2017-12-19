/* projection.h */

#ifndef PROJECTION_H
#define PROJECTION_H

#include <stdbool.h>

typedef struct {
    double x;
    double y;
} Point2D;

typedef struct {
    Point2D start;
    Point2D end;
} Segment;

typedef union {
    Point2D point;
    Segment segment;
} SegmentProjection;

typedef struct {
    SegmentProjection proj;
    bool is_segment;
} Projection;

Projection horizontal_projection(Segment);
Projection vertical_projection(Segment);

#endif /* projection.h */
