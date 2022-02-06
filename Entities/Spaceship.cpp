#include "Spaceship.h"

namespace Entities {
	Spaceship::Spaceship(sf::Vector2f* newPosition, float newRotation) 
		: Entity("Sprites/Player.png", newPosition, newRotation) {
		angularVelocity = 10;
		terminalVelocity = 3;
		velocity = 0;
	}

	void Spaceship::update(sf::RenderWindow* window) {
		Entity::update(window);

		sf::Event e;
		while ((*window).pollEvent(e)) evaluateInput(e);

		// Apply boost
		if (inputController.isActionPressed("Boost")) {
			velocity += 0.125;
			if (velocity > terminalVelocity) velocity = terminalVelocity;
		}

		// Move
		sprite.move(
			velocity * cos(sprite.getRotation() * 3.14 / 180),
			velocity * sin(sprite.getRotation() * 3.14 / 180)
		);

		// Simulate space inertia behavior
		velocity -= 0.025;
		if (velocity < 0) velocity = 0;
	
		// Rotation
		if (inputController.isActionPressed("RotateRight")) sprite.setRotation(sprite.getRotation() + angularVelocity);
		if (inputController.isActionPressed("RotateLeft")) sprite.setRotation(sprite.getRotation() - angularVelocity);

		//std::cout << "X: " << (sprite.getPosition().x) << " | Y: " << (sprite.getPosition().y) << "\n";
		//std::cout << "Rotation: " << (360 - sprite.getRotation()) << " degrees" << "\n";
	}

	void Spaceship::evaluateInput(sf::Event e) {
		inputController.evaluateInput("Shoot", e);
		inputController.evaluateInput("Boost", e);
		inputController.evaluateInput("RotateRight", e);
		inputController.evaluateInput("RotateLeft", e);
	}
}