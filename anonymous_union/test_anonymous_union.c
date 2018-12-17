#include "projection_anon.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void assert_is_point(Projection result, Point2D point) 
{
    assert(!result.is_segment
        && result.point.x == point.x
        && result.point.y == point.y);
}

void assert_is_segment(Projection result, Segment segment) 
{
    assert(result.is_segment
        && result.segment.start.x == segment.start.x
        && result.segment.start.y == segment.start.y
        && result.segment.end.x == segment.end.x
        && result.segment.end.y == segment.end.y);
}

void test_projection_is_segment() 
{
    Segment segment = {{1, 1}, {2, 2}};
    Segment v_proj = {{0, 1}, {0, 2}};
    Segment h_proj = {{1, 0}, {2, 0}};

    assert_is_segment(vertical_projection(segment), v_proj);
    assert_is_segment(horizontal_projection(segment), h_proj);

    printf("%s: OK\n", __func__);
}

void test_v_projection_is_point()
{    
    Segment segment = {{1, 2}, {2, 2}};
    Point2D v_proj = {0, 2};
    assert_is_point(vertical_projection(segment), v_proj);
    printf("%s: OK\n", __func__);
}

void test_h_projection_is_point()
{
    Segment segment = {{1, 2}, {1, 3}};
    Point2D h_proj = {1, 0};
    assert_is_point(horizontal_projection(segment), h_proj);
    printf("%s: OK\n", __func__);
}

int main(void) 
{
    test_projection_is_segment();
    test_v_projection_is_point();
    test_h_projection_is_point();

    return EXIT_SUCCESS;
}

