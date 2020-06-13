#pragma once

#include <floating_object.h>

class Barrel : public Floating_Object
{
public:
    Barrel(float t_X, float t_Y, const sf::Texture *texture);
    Barrel() = delete;
    ~Barrel() = default;
    const float barrel_height = 30;
    const float barrel_width = 30;
    const float barrel_velocity = 3.0;

};
