#include "floating_object.h"
#include <iostream>

void Floating_Object::update()
{
    move(0, ship_velocity);
}
