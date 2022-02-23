#pragma once

#ifndef HugeAsteroid_H
#define HugeAsteroid_H

#include "Asteroid.h"

namespace Entities {

class HugeAsteroid : public Asteroid {
 public:
    HugeAsteroid(const sf::Vector2f& newPosition, const float newRotation);
    virtual ~HugeAsteroid();
};

}  // namespace Entities

#endif
