#pragma once

#ifndef MediumAsteroid_H
#define MediumAsteroid_H

#include "Asteroid.h"

namespace Entities {

class MediumAsteroid : public Asteroid {
 public:
    MediumAsteroid(const sf::Vector2f& newPosition, const float newRotation);
    ~MediumAsteroid();
};

}  // namespace Entities

#endif
