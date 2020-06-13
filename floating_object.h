#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Floating_Object : public sf::Sprite
{
public:
    //Floating_Object(float t_X, float t_Y, const sf::Texture *tekstura);
    //~Floating_Object() = default;
    //Floating_Object() = delete;
    void update();  // function used for updating state of object
    float left();
    float right();
    float top();
    float bottom();
    sf::RectangleShape ship;

    const float ship_Width = 40.0;
    const float ship_Height = 80.0;     // test values, probably to be changed
    const float ship_Velocity = 10.0;
    //sf::Vector2f Velocity = {ship_Velocity, 0.0};

private:
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override; //override flag used for clarifying that I'm overriding SFML draw()
};


