#include "Asteroid.h"

namespace Entities {
	Asteroid::Asteroid(sf::Vector2f* newPosition, float newRotation) 
		: Entity("Sprites/Asteroids/Huge.png", newPosition, newRotation) {
	}
}