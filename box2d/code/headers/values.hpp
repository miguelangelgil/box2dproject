#pragma once

typedef coord_2d position_2d;
typedef coord_2d size_2d;
struct coord_2d
{
    float x = 0;
    float y = 0;
};
enum body_kind
{
    STATIC,
    KINEMATIC,
    DYNAMIC,
    
};
