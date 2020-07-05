#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <hero_ship.h>
#include <floating_object.h>
#include <barrel.h>
#include <bullet.h>

//TODO :
//- tworzenie przeciwników i beczek (jeden kontener) i usuwanie ich, wraz z punktacją, ew. ogarnięcie menu
int randomInt_pos(int min, int max) {
    static
    std::default_random_engine e{};
    std::uniform_int_distribution<int> d{min, max};
//    if(d(e) < min && d(e) > 600)
//    {
//        return d(e);
//    }
//    else
//    {
//        randomInt_pos(min, max);
//    }
    return d(e);
}

std::vector<Barrel> barrels_vector()
{
    std::vector<Barrel> vec_bar;
    for(int i = 0; i<5; i++) // 5 to be replaced, depends on difficulty level chosen
    {
        Barrel barrel(randomInt_pos(0, 800), -randomInt_pos(0, 1000));
        vec_bar.emplace_back(barrel);
    }
    return vec_bar;
}
//std::vector<Enemy_ship> enemies_vector()
//{
//    std::vector<Enemy_ship> vec_ene;
//    for(int i = 0; i<5; i++) // 5 to be replaced, depends on difficulty level chosen
//    {
//        Enemy_ship enemy_ship(randomInt_pos(0, 800), randomInt_pos(0, 800));
//        vec_ene.emplace_back(enemy_ship);
//    }
//    return vec_ene;
//}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,1000), "Ships Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event event;

    //TEXTURES

    sf::Texture texture_hero_ship;
    if(!texture_hero_ship.loadFromFile("../tekstury/hero_ship.png"))
    {
        std::cerr << "Could not load texture hero_ship from file" << std::endl;
        return 1;
    }

    sf::Texture texture_barrel;
    if(!texture_barrel.loadFromFile("../tekstury/barrel.png"))
    {
        std::cerr << "Could not load texture barrel from file" << std::endl;
        return 1;
    }

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

    //TEST AREA ---> delete this after testing

    Hero_Ship H_ship(400, 900);
    H_ship.setTexture(texture_hero_ship);
    std::vector<Barrel> vec_bar = barrels_vector();
    for(size_t i = 0; i<vec_bar.size(); i++)
    {
        vec_bar[i].setTexture(texture_barrel);
    }
//    Bullet test_bullet(H_ship.getPosition().x/2, 750, tex_bul);
//    std::unique_ptr<Bullet> ptr_bullet = std::make_unique<Bullet>(H_ship.getPosition().x/2, 750/*, tex_bul*/);

    //END OF TEST AREA

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

        H_ship.hero_update();
        for(size_t i = 0; i<vec_bar.size(); i++)
        {
            vec_bar[i].update();
            if(vec_bar[i].getGlobalBounds().intersects(H_ship.getGlobalBounds()))
            {
                H_ship.hero_life = H_ship.hero_life-5;
            }
        }

        if(H_ship.hero_life <= 0)
        {
            std::cout << "PRZEGRANA" << std::endl;
        }

        //DRAW AREA

        window.draw(background);
        for(size_t i = 0; i<vec_bar.size(); i++)
        {
            window.draw(vec_bar[i]);
        }
        window.draw(H_ship);
        window.display();
    }

    return 0;
}
