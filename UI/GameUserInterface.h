#pragma once

#ifndef GameUserInterface_H
#define GameUserInterface_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Healthbar.h"

class GameUserInterface {
public:
    static GameUserInterface& getInstance();
    void draw(sf::RenderWindow *window);
    sf::Text& getScoreText();
    Healthbar& getHealthbar();

private:
    sf::Font globalFont;
    sf::Text* scoreText;
    Healthbar* healthbar;

private:
    GameUserInterface();
    GameUserInterface(const GameUserInterface&) = delete;
    GameUserInterface& operator=(const GameUserInterface&) = delete;
    GameUserInterface(GameUserInterface&&) = delete;
    GameUserInterface& operator=(GameUserInterface&&) = delete;
};

#endif