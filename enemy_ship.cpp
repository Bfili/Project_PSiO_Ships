#include "enemy_ship.h"
#include <floating_object.h>
Enemy_ship::Enemy_ship(float t_X, float t_Y)
{
    setTextureRect(sf::IntRect(0,0,ship_width,ship_height));
    setPosition(t_X, t_Y);
    setOrigin(ship_width/2.0, ship_height/2.0);
}
