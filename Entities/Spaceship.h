#pragma once

#ifndef SpaceShip_H
#define SpaceShip_H

#include "Entity.h"
#include "../InputController.h"

namespace Entities {
	class Spaceship : public Entity
	{
	public:
		Spaceship(sf::Vector2f* newPosition, float newRotation);
		void update(sf::RenderWindow* window) override;

	private:
		InputController inputController;

	private:
		void evaluateInput(sf::Event e);
	};
}

#endif