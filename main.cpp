#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <hero_ship.h>
#include <floating_object.h>
#include <barrel.h>
#include <bullet.h>

int randomInt_pos(int min, int max) {
    static
    std::default_random_engine e{};
    std::uniform_int_distribution<int> d{min, max};
    if(d(e) < 200 && d(e) > 600)
    {
        return d(e);
    }
    else
    {
        randomInt_pos(min, max);
    }
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,1000), "Ships Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event event;

    //TEXTURES

    sf::Texture texture_hero_ship;
    sf::Texture *tex_hero = &texture_hero_ship;
    if(!texture_hero_ship.loadFromFile("../tekstury/hero_ship.png"))
    {
        std::cerr << "Could not load texture hero_ship from file" << std::endl;
        return 1;
    }

    sf::Texture texture_barrel;
    sf::Texture *tex_bar = &texture_barrel;
    if(!texture_barrel.loadFromFile("../tekstury/barrel.png"))
    {
        std::cerr << "Could not load texture barrel from file" << std::endl;
        return 1;
    }

    sf::Texture texture_water;
    //sf::Texture *tex_wat = &texture_water;
    if(!texture_water.loadFromFile("../tekstury/water.png"))
    {
        std::cerr << "Could not load texture water from file" << std::endl;
        return 1;
    }

    sf::Texture texture_bullet;
    sf::Texture *tex_bul = &texture_bullet;
    if(!texture_bullet.loadFromFile("../tekstury/bullet.png"))
    {
        std::cerr << "Could not load texture bullet from file" << std::endl;
        return 1;
    }

    texture_water.setRepeated(true);
    sf:: Sprite background;
    background.setTexture(texture_water);
    background.setTextureRect(sf::IntRect(0, 0, 800, 1000));


    //TEST AREA ---> delete this after testing

    Hero_Ship H_ship(400, 900, tex_hero);
    Barrel test_barrel(randomInt_pos(0, 800), 50, tex_bar);
    Bullet test_bullet(400, 50, tex_bul);

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
        test_barrel.update();
        test_bullet.update();
        //DRAW AREA
        window.draw(background);
        window.draw(test_barrel);
        window.draw(test_bullet);
        window.draw(H_ship);
        window.display();
    }

    return 0;
}
