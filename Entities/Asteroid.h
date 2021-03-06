#pragma once

#ifndef Asteroid_H
#define Asteroid_H

#include <string>
#include "Entity.h"
#include "../ScoreController.h";

namespace Factories {
    class AsteroidFactory;
}

namespace Entities {

class Asteroid : public Entity {
 public:
    Asteroid(const std::string& newTexturePath, const sf::Vector2f& newPosition,
        const float newRotation, const float newVelocity);
    ~Asteroid();
    void subscribe(Factories::AsteroidFactory* newFactory);

protected:
    Factories::AsteroidFactory* factory;
    int score = 0;
};

}  // namespace Entities

#endif
