#include "enemy_ship.h"
#include <floating_object.h>
Enemy_ship::Enemy_ship(float t_X, float t_Y)
{
    setTextureRect(sf::IntRect(0,0,enemy_ship_width,enemy_ship_height));
    setPosition(t_X, t_Y);
    setOrigin(enemy_ship_width/2.0, enemy_ship_height/2.0);
}
