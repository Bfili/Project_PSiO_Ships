#pragma once

#include <floating_object.h>

class Barrel : public Floating_Object
{
public:
    Barrel(float t_X, float t_Y);
    const float barrel_height = 35;
    const float barrel_width = 35;
    const float barrel_velocity = 3.0;
    int barrel_lives = 2;
};
