#pragma once

#include <floating_object.h>

class Hero_Ship : public Floating_Object
{
public:
    Hero_Ship(int t_X, int t_Y);
    void hero_update();  // function used for updating state of object
    const int hero_ship_velocity = 8;
    int points = 0;
    int hero_life = 10;
};

