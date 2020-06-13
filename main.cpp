#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <hero_ship.h>
#include <floating_object.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,1000), "Ships Game");
    window.setFramerateLimit(60);
    sf::Event event;

    //TEST AREA ---> delete this after testing
    Hero_Ship H_ship(400, 900);

    //END OF TEST AREA

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

        H_ship.hero_update();

        //DRAW AREA
        window.draw(H_ship);
        window.display();
    }

    return 0;
}
