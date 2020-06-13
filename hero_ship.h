#pragma once

#include <floating_object.h>

class Hero_Ship : public Floating_Object
{
public:
    Hero_Ship(int t_X, int t_Y, const sf::Texture *texture);
    ~Hero_Ship() = default;
    Hero_Ship() = delete;
    void hero_update();  // function used for updating state of object
};

