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
            new sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
            90.0f));

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

        // Check if object is out of level bounds (TODO: move to entity function)
        sf::Vector2f position = (*player).getSprite().getPosition();
        std::cout << "X: " << (position.x) << " | Y: " << (position.y) << "\n";

        if (position.x < 0) position.x = WINDOW_WIDTH;
        if (position.x > WINDOW_WIDTH) position.x = 0;
        if (position.y < 0) position.y = WINDOW_HEIGHT;
        if (position.y > WINDOW_HEIGHT) position.y = 0;

        (*player).getSprite().setPosition(position);

        // Erase old and draw new frame
        window.clear();
        window.draw((*player).getSprite());

        window.display();
    }

    return 0;
}
