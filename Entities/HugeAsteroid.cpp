#include "HugeAsteroid.h"
#include "../AllFactories/AsteroidFactory.h"

namespace Entities {

HugeAsteroid::HugeAsteroid(const sf::Vector2f& newPosition, const float newRotation)
    : Asteroid("Sprites/Asteroids/Huge.png", newPosition, newRotation, velocity = 2.5f) {
    name = "huge_asteroid";
    score = 100;
}

HugeAsteroid::~HugeAsteroid() {
    factory->createMediumAsteroid(sprite.getPosition());
    factory->createMediumAsteroid(sprite.getPosition());
}

}  // namespace Entities