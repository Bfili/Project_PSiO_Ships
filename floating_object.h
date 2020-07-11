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
    /*const*/ float ship_velocity = 2.0; //const flag commented for future pause option
    bool was_intersected = 1;
    int number_of_enemies;
    int number_of_barrels;  //For menu implementation
};


