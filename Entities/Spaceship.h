#pragma once

#ifndef SpaceShip_H
#define SpaceShip_H

#include "Entity.h"
#include "../InputController.h"

namespace Entities {

class Spaceship : public Entity {
 public:
    Spaceship(const sf::Vector2f& newPosition, const float newRotation);
    void update(sf::RenderWindow* window) override;

 private:
    InputController inputController;
    sf::Vector2f projectileOffset;
    const sf::Time delayBetweenShots = sf::seconds(0.25f);
    sf::Time currentDelay;

 private:
    void evaluateInput(sf::Event e);
};

}  // namespace Entities

#endif
