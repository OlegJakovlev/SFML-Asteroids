#pragma once

#ifndef Asteroid_H
#define Asteroid_H

#include "Entity.h"

namespace Entities {
    class Asteroid : public Entity
    {
    public:
        Asteroid(sf::Vector2f* newPosition, float newRotation);
    };
}

#endif