#include "menu.h"
#include <iostream>

Menu::Menu(float width, float height)
{
    if(!menu_font.loadFromFile("../Tekstury/FFF_Tusj.ttf"))
    {
        std::cerr << "Could not load FFF Tusj font from file" << std::endl;
    }

    menu[0].setFont(menu_font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play Ships Game");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MENU_ITEMS + 1) * 1));
    menu[1].setFont(menu_font);
    menu[1].setColor(sf::Color::Black);
    menu[1].setString("Quit");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MENU_ITEMS + 1) * 2));

    pressed_Id = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i<MENU_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu:: Switch_up()
{
    if(pressed_Id - 1 >= 0)
    {
        menu[pressed_Id].setColor(sf::Color::Black);
        pressed_Id--;
        menu[pressed_Id].setColor(sf::Color::Red);
    }
}

void Menu:: Switch_down()
{
    if(pressed_Id + 1 < MENU_ITEMS)
    {
        menu[pressed_Id].setColor(sf::Color::Black);
        pressed_Id++;
        menu[pressed_Id].setColor(sf::Color::Red);
    }
}
