#include "SmallAsteroid.h"
#include "../AllFactories/AsteroidFactory.h"

namespace Entities {

SmallAsteroid::SmallAsteroid(const sf::Vector2f& newPosition, const float newRotation) 
    : Asteroid("Sprites/Asteroids/Small.png", newPosition, newRotation, velocity = 5) {
    name = "small_asteroid";
    score = 500;
}

}  // namespace Entities