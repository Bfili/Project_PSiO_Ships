#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <sstream>
#include <hero_ship.h>
#include <floating_object.h>
#include <barrel.h>
#include <bullet.h>
#include <enemy_ship.h>

//TODO :
// - menu with difficulty settings
// - points description
// - if possible - pause/saving


int randomInt_pos(int min, int max) {
    static
    std::default_random_engine e{};
    std::uniform_int_distribution<int> d{min, max};
    return d(e);
}

std::vector<Barrel> barrels_vector()
{
    std::vector<Barrel> vec_bar;
    for(int i = 0; i<10; i++) // 5 to be replaced, depends on difficulty level chosen
    {
        Barrel barrel(randomInt_pos(0, 800), -randomInt_pos(0, 1000));
        vec_bar.emplace_back(barrel);
    }
    return vec_bar;
}
std::vector<Enemy_ship> Enemy_ship_vector()
{
    std::vector<Enemy_ship> vec_ene;
    for(int i = 0; i<10; i++) // 5 to be replaced, depends on difficulty level chosen
    {
        Enemy_ship enemy_ship(randomInt_pos(0, 800), -randomInt_pos(0, 1000));
        vec_ene.emplace_back(enemy_ship);
    }
    return vec_ene;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,1000), "Ships Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event event;
    sf::Clock clock;
    sf::Text points_text, lives_text, points, lives;
    sf::Font font;
    if(!font.loadFromFile("../tekstury/FFF_Tusj.ttf"))
    {
        std::cerr << "Could not load FFF Tusj font from file" << std::endl;
        return 1;
    }
    points.setFont(font);
    points.setCharacterSize(30);
    points.setFillColor(sf::Color::Black);
    points.setPosition(15, 40);
    points_text.setFont(font);
    points_text.setCharacterSize(30);
    points_text.setFillColor(sf::Color::Black);
    points_text.setString("Points:");
    points_text.setPosition(15, 10);
    lives.setFont(font);
    lives.setCharacterSize(30);
    lives.setFillColor(sf::Color::Black);
    lives.setPosition(760, 40);
    lives_text.setFont(font);
    lives_text.setCharacterSize(30);
    lives_text.setFillColor(sf::Color::Black);
    lives_text.setString("Lives:");
    lives_text.setPosition(700, 10);


    //TEXTURES

    sf::Texture texture_hero_ship;
    if(!texture_hero_ship.loadFromFile("../tekstury/hero_ship.png"))
    {
        std::cerr << "Could not load texture hero_ship from file" << std::endl;
        return 1;
    }

    sf::Texture texture_enemy_ship;
    if(!texture_enemy_ship.loadFromFile("../tekstury/enemy_ship1.png"))
    {
        std::cerr << "Could not load texture enemy_ship from file" << std::endl;
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
    std::vector<Enemy_ship> vec_ene = Enemy_ship_vector();
    for(size_t i = 0; i<vec_ene.size(); i++)
    {
        vec_ene[i].setTexture(texture_enemy_ship);
    }
    std::vector<Barrel> vec_bar = barrels_vector();
    for(size_t i = 0; i<vec_bar.size(); i++)
    {
        vec_bar[i].setTexture(texture_barrel);
    }
    std::vector<Bullet> vec_bul;

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

        float time = clock.getElapsedTime().asSeconds();

        H_ship.hero_update();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) //to be replaced by another button, also need to add time limitation for creating bullets
        {
            if(time >= 0.3)
            {
            Bullet bullet(H_ship.getPosition().x, H_ship.getPosition().y);
            bullet.setTexture(texture_bullet);
            vec_bul.emplace_back(bullet);
            clock.restart();
            }
        }

        for(size_t i = 0; i<vec_bul.size(); i++)
        {
            vec_bul[i].bullet_update();
        }
        for(size_t i = 0; i<vec_bar.size(); i++)
        {
            vec_bar[i].update();
            if(vec_bar[i].was_intersected)
                if(vec_bar[i].getGlobalBounds().intersects(H_ship.getGlobalBounds()))
                {
                    vec_bar[i].setScale(0,0);
                    H_ship.hero_life--;
                    std::cout << "YOU'VE BEEN HIT BY A BARREL!" << std::endl;
                    vec_bar[i].was_intersected = false;
                }
            if(vec_bar[i].getPosition().y+vec_bar[i].barrel_height>=1010)
            {
                vec_bar[i].setPosition(randomInt_pos(0, 800), -randomInt_pos(0, 400));
                vec_bar[i].barrel_lives = 2;
            }
            for(size_t j = 0; j<vec_bul.size(); j++)
            {
                if(vec_bul[j].was_intersected)
                {
                    if(vec_bar[i].getGlobalBounds().intersects(vec_bul[j].getGlobalBounds()))
                    {
                        vec_bar[i].barrel_lives--;
                        vec_bul[j].setScale(0,0);
                        vec_bul[j].was_intersected = 0;
                        if(vec_bar[i].barrel_lives<=0)
                        {
                            vec_bar[i].setScale(0,0);
                            H_ship.points = H_ship.points + 100;
                        }
                    }
                }
            }
        }

        for(size_t i = 0; i<vec_ene.size(); i++)
        {
            vec_ene[i].update();
            if(H_ship.getGlobalBounds().intersects(vec_ene[i].getGlobalBounds()))
            {
                std::cout << "YOU'VE CRASHED WITH ENEMY SHIP!" << std::endl;
                H_ship.hero_life = 0;
            }
            if(vec_ene[i].getPosition().y-vec_ene[i].enemy_ship_height>=1010)
            {
                vec_ene[i].setPosition(randomInt_pos(0, 800), -randomInt_pos(0, 400));
                vec_ene[i].enemy_ship_lives = 4;
            }
            for(size_t j = 0; j<vec_bul.size(); j++)
            {
                if(vec_bul[j].was_intersected)
                {
                    if(vec_ene[i].getGlobalBounds().intersects(vec_bul[j].getGlobalBounds()))
                    {
                        vec_ene[i].enemy_ship_lives--;
                        vec_bul[j].setScale(0,0);
                        vec_bul[j].was_intersected = 0;
                        if(vec_ene[i].enemy_ship_lives<=0)
                        {
                            vec_ene[i].setScale(0,0);
                            H_ship.points = H_ship.points + 500;
                        }
                    }
                }
            }
        }

        if(H_ship.points >= 3000) //value to be changed for other difficulties
        {
            window.close();
            std::cout << "YOU WIN!" << std::endl;
        }

        if(H_ship.hero_life <= 0)
        {
            window.close();
            std::cout << "YOU LOST!" << std::endl;
        }

        std::ostringstream out_points;
        out_points << static_cast<int>(H_ship.points);
        points.setString(out_points.str());

        std::ostringstream out_lives;
        out_lives << static_cast<int>(H_ship.hero_life);
        lives.setString(out_lives.str());

        //DRAW AREA

        window.draw(background);
        for(size_t i = 0; i<vec_bar.size(); i++)
        {
            window.draw(vec_bar[i]);
        }
        for(size_t i = 0; i<vec_bul.size(); i++)
        {
            window.draw(vec_bul[i]);
        }
        for(size_t i = 0; i<vec_ene.size(); i++)
        {
            window.draw(vec_ene[i]);
        }
        window.draw(lives_text);
        window.draw(lives);
        window.draw(points_text);
        window.draw(points);
        window.draw(H_ship);
        window.display();
    }

    return 0;
}
