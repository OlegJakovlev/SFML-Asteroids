#include "AsteroidFactory.h"

namespace Factories {

AsteroidFactory::AsteroidFactory(sf::Vector2f newWorldSize) {
    worldSize = newWorldSize;
    spawnOffset = sf::Vector2f(50, 30);
}

AsteroidFactory::~AsteroidFactory() {
}

Entities::Asteroid* AsteroidFactory::createHugeAsteroid() {
    Entities::Asteroid* newAsteroid = new Entities::HugeAsteroid(
        getSpawnCoordinates(), getRandom(0.0f, 360.0f));

    newAsteroid->subscribe(this);
    return newAsteroid;
}

Entities::Asteroid* AsteroidFactory::createMediumAsteroid() {
    Entities::Asteroid* newAsteroid = new Entities::MediumAsteroid(
        getSpawnCoordinates(), getRandom(0.0f, 360.0f));

    newAsteroid->subscribe(this);
    return newAsteroid;
}

Entities::Asteroid* AsteroidFactory::createSmallAsteroid() {
    Entities::Asteroid* newAsteroid = new Entities::SmallAsteroid(
        getSpawnCoordinates(), getRandom(0.0f, 360.0f));

    newAsteroid->subscribe(this);
    return newAsteroid;
}

Entities::Asteroid* AsteroidFactory::createHugeAsteroid(sf::Vector2f newPosition) {
    Entities::Asteroid* newAsteroid = new Entities::HugeAsteroid(
        newPosition, getRandom(0.0f, 360.0f));
    
    newAsteroid->subscribe(this);
    return newAsteroid;
}

Entities::Asteroid* AsteroidFactory::createMediumAsteroid(sf::Vector2f newPosition) {
    Entities::Asteroid* newAsteroid = new Entities::MediumAsteroid(
        newPosition, getRandom(0.0f, 360.0f));
    
    newAsteroid->subscribe(this);
    return newAsteroid;
}

Entities::Asteroid* AsteroidFactory::createSmallAsteroid(sf::Vector2f newPosition) {
    Entities::Asteroid* newAsteroid = new Entities::SmallAsteroid(
        newPosition, getRandom(0.0f, 360.0f));
    
    newAsteroid->subscribe(this);
    return newAsteroid;
}

float AsteroidFactory::getRandom(float min, float max) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<> distr(min, max);
    return distr(eng);
}

int AsteroidFactory::getRandom(int min, int max) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(eng);
}

// Get position with random offset from edge
sf::Vector2f AsteroidFactory::getSpawnCoordinates() {
    float x = (getRandom(0, 1)) ? worldSize.x - getRandom(0.0f, spawnOffset.x) 
        : worldSize.x + getRandom(0.0f, spawnOffset.x);

    float y = (getRandom(0, 1)) ? worldSize.y - getRandom(0.0f, spawnOffset.y) \
        : worldSize.y + getRandom(0.0f, spawnOffset.y);

    return sf::Vector2f(x, y);
}

}  // namespace Factories
