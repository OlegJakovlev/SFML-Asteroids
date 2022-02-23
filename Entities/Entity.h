#pragma once

#ifndef Entity_H
#define Entity_H

#include <iostream>
#include <string>
#include "../AllInterfaces/IGame.h"
#include <SFML/Graphics.hpp>

namespace Entities {

class Entity : public Interfaces::IGame {
 public:
    Entity();
    virtual ~Entity();
    std::string getName();
    sf::Sprite& getSprite();
    void update(sf::RenderWindow* window) override;
    bool checkCollision(Entity* checkCollisionWith);
    void setDead();
    bool isDead();

 protected:
    sf::Texture texture;
    sf::Sprite sprite;

    std::string name;
    bool dead = false;

    float velocity = 0;
    float angularVelocity = 0;

 protected:
    Entity(const std::string& newTexturePath, const sf::Vector2f& newPosition, const float newRotation);
    void setSprite(const std::string path);
};

}  // namespace Entities

#endif
