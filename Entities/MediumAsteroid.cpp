#include "MediumAsteroid.h"

namespace Entities {

MediumAsteroid::MediumAsteroid(const sf::Vector2f& newPosition, const float newRotation)
    : Asteroid("Sprites/Asteroids/Middle.png", newPosition, newRotation, velocity = 3.5f) {
}

}  // namespace Entities