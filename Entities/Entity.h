#pragma once

#ifndef Entity_H
#define Entity_H

#include "../IGame.h"
#include <SFML/Graphics.hpp>
#include <iostream>

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
        Entity(std::string newTexturePath, sf::Vector2f* newPosition, float newRotation);
        void setSprite(std::string path);
    };
}

#endif