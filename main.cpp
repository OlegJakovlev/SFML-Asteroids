#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "AllFactories/AsteroidFactory.h"
#include "Entities/Entity.h"
#include "Entities/Spaceship.h"
#include "Entities/Projectile.h"

int main() {
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 8),
        "Asteroids");

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::Font globalFont;
    if (!globalFont.loadFromFile("./Fonts/HyperSpace.ttf"))
        return EXIT_FAILURE;

    Factories::AsteroidFactory asteroidFactory(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));

    // Store all entities in list
    std::vector<Entities::Entity*> entities;

    // Player
    Entities::Spaceship* player = new Entities::Spaceship(
        sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2),
        -90.0f);
    entities.push_back(player);

    // Asteroids
    for (int n = 0; n < 5; n++) {
        entities.push_back(asteroidFactory.createHugeAsteroid());
    }

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

            if (player != nullptr && player->shootProjectile()) {
                entities.push_back(new Entities::Projectile(
                    player->getSprite().getPosition() + player->getProjectileOffset(),
                    player->getSprite().getRotation())
                );
            }
        }

        // Erase old frame
        window.clear();

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
                // Player + Projectile
                if (firstCollider->getName() == "player" && secondCollider->getName() == "projectile") {
                    if (firstCollider->checkCollision(secondCollider)) {
                        firstCollider->setDead();
                        secondCollider->setDead();
                    }
                }

                // // Player + Asteroid
                if (firstCollider->getName() == "player" && secondCollider->getName() == "asteroid") {
                    if (firstCollider->checkCollision(secondCollider)) {
                        firstCollider->setDead();
                        secondCollider->setDead();
                    }
                }

                // Projectile + Asteroid
                if (firstCollider->getName() == "projectile" && secondCollider->getName() == "asteroid") {
                    if (firstCollider->checkCollision(secondCollider)) {
                        firstCollider->setDead();
                        secondCollider->setDead();
                    }
                }
            }
        }

        // Erase dead objects
        std::vector<Entities::Entity*>::iterator it = entities.begin();

        for (; it != entities.end();) {
            if ((*it)->isDead()) {
                Entities::Entity* e = *it;
                it = entities.erase(it);
                //delete e;
            }
            else {
                it++;
            }
        }

        it = entities.begin();
        for (; it != entities.end();) {
            std::cout << (*it)->getName() << "\n";
            it++;
        }

        std::cout << "---------\n\n";
    }

    return 0;
}
