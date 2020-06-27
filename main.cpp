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

    //TEST AREA ---> delete this after testing

    Hero_Ship H_ship(400, 900/*, tex_hero*/);
    Barrel test_barrel(randomInt_pos(0, 800), 50/*, tex_bar*/);
//    Bullet test_bullet(H_ship.getPosition().x/2, 750, tex_bul);
    std::unique_ptr<Bullet> ptr_bullet = std::make_unique<Bullet>(H_ship.getPosition().x/2, 750/*, tex_bul*/);

    //END OF TEST AREA

    //TEXTURES

    sf::Texture texture_hero_ship;
    if(!texture_hero_ship.loadFromFile("../tekstury/hero_ship.png"))
    {
        std::cerr << "Could not load texture hero_ship from file" << std::endl;
        return 1;
    }
    H_ship.setTexture(texture_hero_ship);


    sf::Texture texture_barrel;
    if(!texture_barrel.loadFromFile("../tekstury/barrel.png"))
    {
        std::cerr << "Could not load texture barrel from file" << std::endl;
        return 1;
    }
    test_barrel.setTexture(texture_barrel);

    sf::Texture texture_water;
    if(!texture_water.loadFromFile("../tekstury/water.png"))
    {
        std::cerr << "Could not load texture water from file" << std::endl;
        return 1;
    }

    sf::Texture texture_bullet;
    if(!texture_bullet.loadFromFile("../tekstury/bullet.png"))
    {
        std::cerr << "Could not load texture bullet from file" << std::endl;
        return 1;
    }
    //test_bullet.setTexture(texture_bullet);

    texture_water.setRepeated(true);
    sf:: Sprite background;
    background.setTexture(texture_water);
    background.setTextureRect(sf::IntRect(0, 0, 800, 1000));

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
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            std::cout << "test" << std::endl;
            //test_bullet(H_ship.getPosition().x/2, 750, tex_bul);
            //Bullet test_bullet(H_ship.getPosition().x/2, 750, tex_bul);
            ptr_bullet->bullet_update();
            std::cout << ptr_bullet->bullet_width;
            //test_bullet.bullet_update();
            window.draw(*ptr_bullet);
        }
        H_ship.hero_update();
        test_barrel.update();
        //test_bullet.bullet_update(/*H_ship.getPosition().x/2, 750, tex_bul*/);
        //DRAW AREA

        //window.draw(test_bullet);
        window.draw(background);
        window.draw(test_barrel);
        window.draw(H_ship);
        window.display();
    }

    return 0;
}
