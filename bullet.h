#pragma once
#include <floating_object.h>

class Bullet : public Floating_Object
{
public:
    Bullet(int t_X, int t_Y, const sf::Texture *texture);
    ~Bullet() = default;
    Bullet() = delete;
    const float bullet_height = 15;
    const float bullet_width = 15;
    const float bullet_velocity = 15.0;
};
