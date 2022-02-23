#pragma once

#ifndef SmallAsteroid_H
#define SmallAsteroid_H

#include "Asteroid.h"

namespace Entities {

class SmallAsteroid : public Asteroid {
 public:
    SmallAsteroid(const sf::Vector2f& newPosition, const float newRotation);
};

}  // namespace Entities

#endif
