#include "Projectile.h"

namespace Entities {
    
Projectile::Projectile(const sf::Vector2f& newPosition, const float newRotation) 
    : Entity("Sprites/Projectile.png", newPosition, newRotation) {
    velocity = 5;
    name = "projectile";
}

}  // namespace Entities
