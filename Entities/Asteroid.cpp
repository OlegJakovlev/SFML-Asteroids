#include "Asteroid.h"
#include "../AllFactories/AsteroidFactory.h"

namespace Entities {

Asteroid::Asteroid(const std::string& newTexturePath, const sf::Vector2f& newPosition, const float newRotation, const float newVelocity)
    : Entity(newTexturePath, newPosition, newRotation) {
    velocity = newVelocity;
    name = "asteroid";
}

Asteroid::~Asteroid() {
}

void Asteroid::subscribe(Factories::AsteroidFactory* newFactory) {
    factory = newFactory;
}

}  // namespace Entities
