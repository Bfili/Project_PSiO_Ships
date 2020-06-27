#include <hero_ship.h>
#include <floating_object.h>

Hero_Ship::Hero_Ship(int t_X, int t_Y/*, const sf::Texture *texture*/)
{
    setTextureRect(sf::IntRect(0,0,ship_width,ship_height));
    setPosition(t_X, t_Y);
    //setSize(sf::Vector2f(this -> ship_width, this->ship_height));
    //setFillColor(sf::Color::Red); //to be replaced by texture
    //setTexture(texture);
    setOrigin(ship_width/2.0, ship_height/2.0);
}

void Hero_Ship::hero_update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        move(ship_velocity, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        move(-ship_velocity, 0);
    }
}
