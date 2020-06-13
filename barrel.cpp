#include "barrel.h"

Barrel::Barrel(float t_X, float t_Y, const sf::Texture *texture)
{
    ship.setPosition(t_X, t_Y);
    ship.setSize(sf::Vector2f(this -> barrel_width, this->barrel_height));
    ship.setTexture(texture);
    ship.setOrigin(barrel_width/2.0, barrel_height/2.0);
}
