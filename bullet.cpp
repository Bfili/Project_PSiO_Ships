#include "bullet.h"

Bullet::Bullet(int t_X, int t_Y, const sf::Texture *texture)
{
    ship.setPosition(t_X, t_Y);
    ship.setSize(sf::Vector2f(this -> bullet_width, this->bullet_height));
    ship.setTexture(texture);
    ship.setOrigin(bullet_width/2.0, bullet_height/2.0);
}
