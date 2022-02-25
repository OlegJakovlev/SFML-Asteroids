#include "MediumAsteroid.h"
#include "../AllFactories/AsteroidFactory.h"

namespace Entities {

MediumAsteroid::MediumAsteroid(const sf::Vector2f& newPosition, const float newRotation)
    : Asteroid("Sprites/Asteroids/Middle.png", newPosition, newRotation, velocity = 3.5f) {
    name = "medium_asteroid";
    score = 200;
}

MediumAsteroid::~MediumAsteroid() {
    factory->createSmallAsteroid(sprite.getPosition());
    factory->createSmallAsteroid(sprite.getPosition());
}

}  // namespace Entities