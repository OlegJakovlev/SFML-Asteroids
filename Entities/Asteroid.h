#pragma once

#ifndef Asteroid_H
#define Asteroid_H

#include "Entity.h"
#include <string>

namespace Entities {

class Asteroid : public Entity {
 public:
    Asteroid(const std::string& newTexturePath,
        const sf::Vector2f& newPosition,
        const float newRotation);
};

}  // namespace Entities

#endif
