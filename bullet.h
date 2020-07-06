#pragma once
#include <floating_object.h>

class Bullet : public Floating_Object
{
public:
    Bullet(int t_X, int t_Y);

    const float bullet_height = 15;
    const float bullet_width = 15;
    const float bullet_velocity = 5.0;
    void bullet_update();
};
