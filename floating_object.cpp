#include "floating_object.h"
#include <iostream>

//Floating_Object::Floating_Object(float t_X, float t_Y)
//{
//    ship.setPosition(t_X, t_Y);
//    ship.setSize(sf::Vector2f(this -> ship_Width, this->ship_Height));
//    //ship.setFillColor(sf::Color::Red); //to be replaced by texture
//    ship.setTexture(tekstura);
//    ship.setOrigin(ship_Width/2.0, ship_Height/2.0);
//}

void Floating_Object::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->ship, state);
}

void Floating_Object::update()
{
    ship.move(0, ship_velocity);
}
