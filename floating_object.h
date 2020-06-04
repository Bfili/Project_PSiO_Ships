#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Floating_Object : public sf::Drawable
{
public:
    Floating_Object(float t_X, float t_Y);
    ~Floating_Object() = default;
    Floating_Object() = delete;
    void update();  // function used for updating state of object
    void draw();    // function used for drawing object
    float left();
    float right();
    float top();
    float bottom();
    sf::RectangleShape ship;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override; //override flag used for clarifying that I'm overriding SFML draw()

    const float ship_Width = 20.0;
    const float ship_Height = 80.0;     // test values, probably to be changed
    const float ship_Velocity = 10.0;
};


