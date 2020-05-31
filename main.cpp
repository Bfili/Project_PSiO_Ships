#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,1000), "Ships Game");
    window.setFramerateLimit(60);
    //test
    //test
    //test
    sf::Event event;
    while(window.isOpen())
    {
        window.clear(sf::Color::Black);
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
                std::cout << "okno zostalo zamkniete pomyslnie" << std::endl;
            }
        }
        window.display();
    }

    return 0;
}
