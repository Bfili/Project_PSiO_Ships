#include "barrel.h"

Barrel::Barrel(float t_X, float t_Y/*, const sf::Texture *texture*/)
{
    setTextureRect(sf::IntRect(0,0,barrel_width,barrel_height));
    setPosition(t_X, t_Y);
    //setSize(sf::Vector2f(this -> barrel_width, this->barrel_height));
    //setTexture(texture);
    setOrigin(barrel_width/2.0, barrel_height/2.0);
}
