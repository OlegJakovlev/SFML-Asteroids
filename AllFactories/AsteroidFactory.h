#pragma once

#ifndef AsteroidFactory_H
#define AsteroidFactory_H

#include <vector>
#include <memory>
#include <random>
#include <queue>
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

     void createHugeAsteroid();
     void createMediumAsteroid();
     void createSmallAsteroid();
     void createHugeAsteroid(sf::Vector2f newPosition);
     void createMediumAsteroid(sf::Vector2f newPosition);
     void createSmallAsteroid(sf::Vector2f newPosition);

     float getRandom(float min, float max);
     int getRandom(int min, int max);
     sf::Vector2f getSpawnCoordinates();
     
     void addObjectToQueue(Entities::Asteroid* newAsteroid);
     std::queue<Entities::Asteroid*>& getObjectsQueue();

 private:
    sf::Vector2f worldSize;
    sf::Vector2f spawnOffset;
    std::queue<Entities::Asteroid*> objectsToBeCreated;
};

}  // namespace Factories


#endif
