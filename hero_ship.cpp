#include <hero_ship.h>
#include <floating_object.h>

Hero_Ship::Hero_Ship(float t_X, float t_Y, const sf::Texture *tekstura)
{
    ship.setPosition(t_X, t_Y);
    ship.setSize(sf::Vector2f(this -> ship_Width, this->ship_Height));
    //ship.setFillColor(sf::Color::Red); //to be replaced by texture
    ship.setTexture(tekstura);
    ship.setOrigin(ship_Width/2.0, ship_Height/2.0);
}

void Hero_Ship::hero_update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        ship.move(ship_Velocity, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        ship.move(-ship_Velocity, 0);
    }
}
