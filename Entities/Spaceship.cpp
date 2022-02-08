#include "Spaceship.h"

namespace Entities {

Spaceship::Spaceship(const sf::Vector2f& newPosition, const float newRotation)
    : Entity("Sprites/Player.png", newPosition, newRotation) {
    angularVelocity = 5;
    terminalVelocity = 3;
    velocity = 0;
    projectileOffset = sf::Vector2f(0, sprite.getLocalBounds().height / 2);
    deltaClock = sf::Clock();
}

void Spaceship::update(sf::RenderWindow* window) {
    Entity::update(window);

    // Shoot event
    if (inputController.isActionPressed("Shoot")
        && deltaClock.getElapsedTime() >= delayBetweenShots) {
        deltaClock.restart();
        projectiles.push_back(std::unique_ptr<Projectile>
            (new Projectile(sprite.getPosition(), sprite.getRotation())));
    }

    // Apply boost
    if (inputController.isActionPressed("Boost")) {
        velocity += 0.125;
        if (velocity > terminalVelocity) velocity = terminalVelocity;
    }

    // Simulate space inertia behavior
    velocity -= 0.025;
    if (velocity < 0) velocity = 0;

    // Rotation
    if (inputController.isActionPressed("RotateRight"))
        sprite.setRotation(sprite.getRotation() + angularVelocity);

    if (inputController.isActionPressed("RotateLeft"))
        sprite.setRotation(sprite.getRotation() - angularVelocity);

    std::cout << "X: " << (sprite.getPosition().x) << " | Y: " << (sprite.getPosition().y) << "\n";
    std::cout << "Rotation: " << (sprite.getRotation()) << " degrees" << "\n";
}

std::vector<std::unique_ptr<Projectile>>& Spaceship::getProjectiles() {
    return projectiles;
}

}  // namespace Entities
