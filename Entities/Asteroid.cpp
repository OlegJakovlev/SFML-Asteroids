#include "Asteroid.h"

namespace Entities {

Asteroid::Asteroid(const std::string& newTexturePath,
    const sf::Vector2f& newPosition,
    const float newRotation)
    : Entity(newTexturePath, newPosition, newRotation) {
}

}  // namespace Entities
