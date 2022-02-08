#pragma once

#ifndef SpaceShip_H
#define SpaceShip_H

#include <memory>
#include <vector>
#include "Entity.h"
#include "Projectile.h"
#include "../InputController.h"

namespace Entities {

class Spaceship : public Entity {
 public:
    Spaceship(const sf::Vector2f& newPosition, const float newRotation);
    void update(sf::RenderWindow* window) override;
    std::vector<std::unique_ptr<Projectile>>& getProjectiles();

 private:
    InputController inputController;

    // Shooting
    sf::Vector2f projectileOffset;
    std::vector<std::unique_ptr<Projectile>> projectiles;
    const sf::Time delayBetweenShots = sf::seconds(0.25f);
    sf::Clock deltaClock;
};

}  // namespace Entities

#endif
