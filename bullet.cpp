#include "bullet.h"

Bullet::Bullet(int t_X, int t_Y, const sf::Texture *texture)
{
    ship.setPosition(t_X, t_Y);
    ship.setSize(sf::Vector2f(this -> bullet_width, this->bullet_height));
    ship.setTexture(texture);
    ship.setOrigin(bullet_width/2.0, bullet_height/2.0);
}

void Bullet :: bullet_update(/*int t_X, int t_Y, const sf::Texture *texture*/)
{
    ship.move(0, -bullet_velocity);
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//    {
//        Bullet testing_bullet(t_X, t_Y, texture);
//        testing_bullet.move(0, -bullet_velocity);
//        std::cout << "test" << std::endl;
//    }
}
