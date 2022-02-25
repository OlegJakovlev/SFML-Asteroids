#pragma once

#ifndef Healthbar_H
#define Healthbar_H

#include <SFML/Graphics.hpp>

class Healthbar {
public:
    Healthbar();
    sf::Texture& getTexture();
    sf::Sprite& getSprite();

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif