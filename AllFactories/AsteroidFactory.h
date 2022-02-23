#pragma once

#ifndef AsteroidFactory_H
#define AsteroidFactory_H

#include <vector>
#include <memory>
#include <random>
#include <SFML/Graphics.hpp>
#include "../Entities/Asteroid.h"
#include "../Entities/SmallAsteroid.h"
#include "../Entities/MediumAsteroid.h"
#include "../Entities/HugeAsteroid.h"

namespace Factories {

class AsteroidFactory {
 public:
     AsteroidFactory(sf::Vector2f newWorldSize);
     ~AsteroidFactory();

     Entities::Asteroid* createHugeAsteroid();
     Entities::Asteroid* createMediumAsteroid();
     Entities::Asteroid* createSmallAsteroid();
     Entities::Asteroid* createHugeAsteroid(sf::Vector2f newPosition);
     Entities::Asteroid* createMediumAsteroid(sf::Vector2f newPosition);
     Entities::Asteroid* createSmallAsteroid(sf::Vector2f newPosition);

     float getRandom(float min, float max);
     int getRandom(int min, int max);
     sf::Vector2f getSpawnCoordinates();

 private:
    sf::Vector2f worldSize;
    sf::Vector2f spawnOffset;
};

}  // namespace Factories


#endif
