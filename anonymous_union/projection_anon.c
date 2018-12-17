#include "projection_anon.h"

/* 
 * Projects 'segment' on the horizontal (X) axis and returns the projection
 * result: a point if 'segment' is vertical, or another segment otherwise.
 */
Projection horizontal_projection(Segment segment)
{
    Projection result;
    
    if (segment.start.x == segment.end.x) {
        result.is_segment = false;
        result.point.x = segment.start.x;
        result.point.y = 0;
    } else {
        result.is_segment = true;
        result.segment.start.x = segment.start.x;
        result.segment.end.x = segment.end.x;
        result.segment.start.y = result.segment.end.y = 0;
    }

    return result;
}

/*
 * Projects 'segment' on the vertical (Y) axis and returns the projection
 * result: a point if 'segment' is horizontal, or another segment otherwise.
 */
Projection vertical_projection(Segment segment)
{
    Projection result;

    if (segment.start.y == segment.end.y) {
       result.is_segment = false;
       result.point.x = 0;
       result.point.y = segment.start.y;
    } else {
        result.is_segment = true;
        result.segment.start.x = result.segment.end.x = 0;
        result.segment.start.y = segment.start.y;
        result.segment.end.y = segment.end.y;
    }

    return result;
}
