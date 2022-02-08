#pragma once

#ifndef AsteroidFactory_H
#define AsteroidFactory_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../Entities/Asteroid.h"

namespace Factories {

class AsteroidFactory {
 public:
     void createHugeAsteroid(const sf::Vector2f& newPosition);
     void createMediumAsteroid(const sf::Vector2f& newPosition);
     void createSmallAsteroid(const sf::Vector2f& newPosition);
     std::vector<Entities::Asteroid*>& getAsteroids();

 private:
    std::vector<Entities::Asteroid*> asteroids; // TODO: replace with smart pointers
};

}  // namespace Factories


#endif
