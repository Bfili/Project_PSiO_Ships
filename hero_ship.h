#pragma once

#include <floating_object.h>

class Hero_Ship : public Floating_Object
{
public:
    Hero_Ship(float t_X, float t_Y);
    ~Hero_Ship() = default;
    Hero_Ship() = delete;
    void hero_update();  // function used for updating state of object
};

