#include "Asteroid.h"
#include "../AllFactories/AsteroidFactory.h"

namespace Entities {

Asteroid::Asteroid(const std::string& newTexturePath, const sf::Vector2f& newPosition, const float newRotation, const float newVelocity)
    : Entity(newTexturePath, newPosition, newRotation) {
    velocity = newVelocity;
    name = "asteroid";
    collisionMask = std::bitset<4>("0011");
    collisionLayer = 2;
}

Asteroid::~Asteroid() {
    ScoreController::getInstance().addScore(score);
}

void Asteroid::subscribe(Factories::AsteroidFactory* newFactory) {
    factory = newFactory;
}

}  // namespace Entities
