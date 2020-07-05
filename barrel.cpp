#include "barrel.h"

Barrel::Barrel(float t_X, float t_Y)
{
    setTextureRect(sf::IntRect(0,0,barrel_width,barrel_height));
    setPosition(t_X, t_Y);
    setOrigin(barrel_width/2.0, barrel_height/2.0);
}

