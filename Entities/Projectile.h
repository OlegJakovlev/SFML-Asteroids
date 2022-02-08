#pragma once

#ifndef Projectile_H
#define Projectile_H

#include "Entity.h"

namespace Entities {

class Projectile : public Entity {
 public:
     Projectile(const sf::Vector2f& newPosition, const float newRotation);
};

}  // namespace Entities

#endif
