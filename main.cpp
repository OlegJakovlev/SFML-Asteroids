#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AllFactories/AsteroidFactory.h"
#include "Entities/Entity.h"
#include "Entities/Spaceship.h"
#include "Entities/Projectile.h"
#include "UI/GameUserInterface.h"

void startGame(int& currentDifficulty, Factories::AsteroidFactory& asteroidFactory, int& toBeDestoyed);

int main() {
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 8),
        "Asteroids");

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    // UI
    sf::Text& scoreText = GameUserInterface::getInstance().getScoreText();
    Healthbar& healthbar = GameUserInterface::getInstance().getHealthbar();

    // Game settings
    int currentDifficulty = 1;
    int toBeDestoyed = 0;
    int restarts = 2;
    const int maxRestarts = 3;

    // Store all entities in list
    std::vector<Entities::Entity*> entities;

    // Factory for asteroids
    Factories::AsteroidFactory asteroidFactory(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));

    // Player
    Entities::Spaceship* player = nullptr;

    while (window.isOpen()) {

        sf::Event e;
        while (window.pollEvent(e)) {
            // Check if user exits the game
            if (e.type == sf::Event::Closed)
                window.close();

            if (e.type == sf::Event::KeyPressed) {
                switch (e.key.code) {
                case sf::Keyboard::Escape:
                    window.close();
                    break;

                default:
                    break;
                }
            }
        }

        // Check if all asteroids are being destoyed, if so, spawn them and increment difficulty
        if (toBeDestoyed == 0) {
            startGame(currentDifficulty, asteroidFactory, toBeDestoyed);
            currentDifficulty++;
        }

        // Check if player need to be respawned or game should end
        if (player == nullptr) {
            if (restarts >= 0) {
                player = new Entities::Spaceship(
                    sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
                    -90.0f);
                entities.push_back(player);
            }
            else {
                return 0;
            }
        }

        // Check if any asteroids need to be spawned
        std::queue<Entities::Asteroid*>& objectToCreate = asteroidFactory.getObjectsQueue();
        while (!objectToCreate.empty()) {
            entities.push_back(objectToCreate.front());
            objectToCreate.pop();
        }

        // Check if any projectiles need to be spawned
        if (player != nullptr) {
            std::queue<Entities::Projectile*>& projectilesToCreate = player->getObjectsQueue();
            while (!projectilesToCreate.empty()) {
                entities.push_back(projectilesToCreate.front());
                projectilesToCreate.pop();
            }
        }

        // Erase old frame
        window.clear();

        // Update UI
        scoreText.setString(std::to_string(ScoreController::getInstance().getScore()));

        // Draw score object
        GameUserInterface::getInstance().draw(&window);

        // Update and draw update every object
        for (Entities::Entity* gameObject : entities) {
            gameObject->update(&window);
            window.draw(gameObject->getSprite());
        }

        // Display new frame to player
        window.display();

        // Check collisions
        for (auto firstCollider : entities) {
            for (auto secondCollider : entities) {
                if (firstCollider->checkCollision(secondCollider)) {
                    firstCollider->setDead();
                    secondCollider->setDead();
                }
            }
        }

        // Erase dead objects or reduce health
        std::vector<Entities::Entity*>::iterator it = entities.begin();

        for (; it != entities.end();) {
            if ((*it)->isDead()) {
                Entities::Entity* tmp = *it;

                // Set player object to null
                if ((*it)->getName() == "player") {
                    player = nullptr;
                    restarts--;

                    healthbar.getSprite().setTextureRect(sf::IntRect(0, 0, 
                        healthbar.getTexture().getSize().x * (restarts + 1) / maxRestarts,
                        healthbar.getTexture().getSize().y));
                }

                // Reduce amount of asteroids
                if ((*it)->getName().find("asteroid") != std::string::npos) {
                    toBeDestoyed--;
                }

                // Erase pointer from vector
                it = entities.erase(it);

                // Call destructor of object
                delete tmp;
            }
            else {
                it++;
            }
        }
    }

    return 0;
}

void startGame(int& currentDifficulty, Factories::AsteroidFactory& asteroidFactory, int& toBeDestoyed) {
    // Spawn asteroids
    for (int n = 0; n < currentDifficulty; n++) asteroidFactory.createHugeAsteroid();
    toBeDestoyed = 7 * currentDifficulty;
}