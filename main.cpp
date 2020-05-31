#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <hero_ship.h>
#include <floating_object.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,1000), "Ships Game");
    window.setFramerateLimit(60);
    //test
    //test
    //test
    sf::Event event;
    Hero_Ship test_ship;
    int test_nr = test_ship.test;
    while(window.isOpen())
    {
        window.clear(sf::Color::Black);
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                std::cout << "Window has been closed successfully" << std::endl;
            }
        }

        test_ship.test_fun(test_nr);

        window.display();
    }

    return 0;
}
