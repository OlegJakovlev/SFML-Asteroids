#include "Spaceship.h"

namespace Entities {

Spaceship::Spaceship(const sf::Vector2f& newPosition, const float newRotation)
    : Entity("Sprites/Player.png", newPosition, newRotation) {
    angularVelocity = 5;
    terminalVelocity = 3;
    deltaClock = sf::Clock();
    name = "player";
    collisionMask = std::bitset<4>("1110");
    collisionLayer = 0;
    inputController = new InputController();
}

Spaceship::~Spaceship() {
    delete inputController;
}

void Spaceship::update(sf::RenderWindow* window) {
    Entity::update(window);

    // Calculate new offset
    projectileOffset = sf::Vector2f(
        cos(sprite.getRotation() * 3.14 / 180) * sprite.getLocalBounds().width,
        sin(sprite.getRotation() * 3.14 / 180) * sprite.getLocalBounds().height
    );

    // Apply boost
    if (inputController->isActionPressed("Boost")) {
        velocity += 0.125;
        if (velocity > terminalVelocity) velocity = terminalVelocity;
    }

    // Simulate space inertia behavior
    velocity -= 0.025;
    if (velocity < 0) velocity = 0;

    // Rotation
    if (inputController->isActionPressed("RotateRight"))
        sprite.setRotation(sprite.getRotation() + angularVelocity);

    if (inputController->isActionPressed("RotateLeft"))
        sprite.setRotation(sprite.getRotation() - angularVelocity);

    // Shoot event
    if (inputController->isActionPressed("Shoot")
        && deltaClock.getElapsedTime() >= delayBetweenShots) {
        deltaClock.restart();
        objectsToBeCreated.push(new Projectile(sprite.getPosition() + projectileOffset, sprite.getRotation()));
    }

    //std::cout << "X: " << (sprite.getPosition().x) << " | Y: " << (sprite.getPosition().y) << "\n";
    //std::cout << "Rotation: " << (sprite.getRotation()) << " degrees" << "\n";
}

std::queue<Entities::Projectile*>& Spaceship::getObjectsQueue() {
    return objectsToBeCreated;
}

}  // namespace Entities
