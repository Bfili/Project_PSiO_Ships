#pragma once

#include <floating_object.h>

class Enemy_ship : public Floating_Object
{
public:
    Enemy_ship(float t_X, float t_Y);
    const float enemy_ship_width = 32.0;
    const float enemy_ship_height = 75.0;
};

