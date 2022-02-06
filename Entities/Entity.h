#pragma once

#ifndef Entity_H
#define Entity_H

#include <iostream>
#include <string>
#include "../IGame.h"
#include <SFML/Graphics.hpp>

namespace Entities {

class Entity : protected IGame {
 public:
    virtual ~Entity();
    sf::Sprite& getSprite();
    void update(sf::RenderWindow* window) override;

 protected:
    sf::Texture texture;
    sf::Sprite sprite;

    float velocity = 0;
    float terminalVelocity = 0;
    float angularVelocity = 0;

 protected:
    Entity();
    Entity(const std::string& newTexturePath, const sf::Vector2f& newPosition, const float newRotation);
    void setSprite(const std::string path);
};

}  // namespace Entities

#endif
