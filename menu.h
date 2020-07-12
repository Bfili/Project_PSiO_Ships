#pragma once
#include <SFML/Graphics.hpp>

#define MENU_ITEMS 3

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();
    void draw(sf::RenderWindow &window);
    void Switch_up();
    void Switch_down();
    int Switch_pressed()
    {
        return pressed_Id;
    }
    int pressed_Id;
    sf::Font menu_font;
    sf::Text menu[MENU_ITEMS];
};

