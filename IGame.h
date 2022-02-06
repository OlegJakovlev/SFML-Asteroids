#pragma once

#ifndef IGame_H
#define IGame_H

#include <SFML/Graphics.hpp>

class IGame {
 public:
    virtual void update(sf::RenderWindow* window);
};

#endif

