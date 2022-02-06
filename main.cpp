#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "InputController.h"

#include "Entities/Entity.h"
#include "Entities/Asteroid.h"
#include "Entities/Spaceship.h"

int main() {
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 8),
        "Asteroids");

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::Font globalFont;
    if (!globalFont.loadFromFile("./Fonts/HyperSpace.ttf"))
        return EXIT_FAILURE;

    std::unique_ptr<Entities::Spaceship> player(
        new Entities::Spaceship (
            sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
            90.0f
        )
    );

    while (window.isOpen()) {
        // Check if user exits the game
        sf::Event e;
        while (window.pollEvent(e)) {
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

        // Call update for each object
        (*player).update(&window);

        // Erase old and draw new frame
        window.clear();
        window.draw((*player).getSprite());

        window.display();
    }

    return 0;
}
