#include "bullet.h"

Bullet::Bullet(int t_X, int t_Y)
{
    setTextureRect(sf::IntRect(0,0,bullet_width,bullet_height));
    setPosition(t_X, t_Y);

    setOrigin(bullet_width/2.0, bullet_height/2.0);
}

void Bullet :: bullet_update()
{
    move(0, -bullet_velocity);
}
