#include "Projectile.h"

namespace Entities {
    
Projectile::Projectile(const sf::Vector2f& newPosition, const float newRotation) 
    : Entity("Sprites/Projectile.png", newPosition, newRotation) {
    velocity = 5;
    name = "projectile";
    collisionMask = std::bitset<4>("1101");
    collisionLayer = 1;
}

}  // namespace Entities
