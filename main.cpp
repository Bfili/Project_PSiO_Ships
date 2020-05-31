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

    Hero_Ship test_ship;
    //Floating_object test_object;
    int test_nr = test_ship.test(); // <-- test() is function from class Floating_object, not from Hero_Ship
    test_ship.test_fun(test_nr); // <-- test_fun() is also not a member of Hero_Ship class

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

        window.display();
    }

    return 0;
}
