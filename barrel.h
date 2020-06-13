#pragma once

#include <floating_object.h>

class Barrel : public Floating_Object
{
public:
    Barrel(float t_X, float t_Y, const sf::Texture *texture);
    Barrel() = delete;
    ~Barrel() = default;

};
