#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>

class Floating_Object : public sf::Sprite
{
public:
    void update();  // function used for updating state of object
    float left();
    float right();
    float top();
    float bottom();
    const float ship_width = 40.0;
    const float ship_height = 80.0;     // test values, probably to be changed
    const float ship_velocity = 3.0;
    bool was_intersected = 1;
};


