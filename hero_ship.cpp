#include <hero_ship.h>
#include <floating_object.h>

Hero_Ship::Hero_Ship(int t_X, int t_Y)
{
    setTextureRect(sf::IntRect(0,0,ship_width,ship_height));
    setPosition(t_X, t_Y);
    setOrigin(ship_width/2.0, ship_height/2.0);
}

void Hero_Ship::hero_update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) /*&& getPosition().x - ship_width/2 > 0*/)
    {
        move(hero_ship_velocity, 0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        move(-hero_ship_velocity, 0);
    }
    if(getPosition().x - ship_width/2 < -10)
    {
        setPosition(20, 900);
    }
    if(getPosition().x + ship_width/2 > 810)
    {
        setPosition(780, 900);
    }
}
