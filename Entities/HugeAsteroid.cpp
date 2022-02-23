#include "HugeAsteroid.h"

namespace Entities {

HugeAsteroid::HugeAsteroid(const sf::Vector2f& newPosition, const float newRotation)
    : Asteroid("Sprites/Asteroids/Huge.png", newPosition, newRotation, velocity = 2.5f) {
}

HugeAsteroid::~HugeAsteroid() {
    
}

}  // namespace Entities