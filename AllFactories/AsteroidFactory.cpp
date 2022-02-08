#include "AsteroidFactory.h"

namespace Factories {

void AsteroidFactory::createHugeAsteroid(const sf::Vector2f& newPosition) {
    asteroids.push_back(new Entities::Asteroid("Sprites/Asteroids/Huge.png", newPosition, 0));
}

void AsteroidFactory::createMediumAsteroid(const sf::Vector2f& newPosition) {
    asteroids.push_back(new Entities::Asteroid("Sprites/Asteroids/Middle.png", newPosition, 0));
}

void AsteroidFactory::createSmallAsteroid(const sf::Vector2f& newPosition) {
    asteroids.push_back(new Entities::Asteroid("Sprites/Asteroids/Small.png", newPosition, 0));
}

std::vector<Entities::Asteroid*>& AsteroidFactory::getAsteroids()
{
    return asteroids;
}

}  // namespace Factories
