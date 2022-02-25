#include "GameUserInterface.h"

GameUserInterface::GameUserInterface() {
    globalFont.loadFromFile("./Fonts/HyperSpace.ttf");

    // Score text
    scoreText = new sf::Text();
    scoreText->setPosition(10, 20);
    scoreText->setCharacterSize(32);
    scoreText->setFont(globalFont);

    healthbar = new Healthbar();
}

GameUserInterface& GameUserInterface::getInstance() {
    static GameUserInterface* singleton = new GameUserInterface();
    return *singleton;
}

void GameUserInterface::draw(sf::RenderWindow* window) {
    window->draw(*scoreText);
    window->draw(healthbar->getSprite());
}

sf::Text& GameUserInterface::getScoreText() {
    return *scoreText;
}

Healthbar& GameUserInterface::getHealthbar() {
    return *healthbar;
}

