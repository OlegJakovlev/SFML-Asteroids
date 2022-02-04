#pragma once

#ifndef Entity_H
#define Entity_H

#include "../Vector2.h"

namespace Entities {
    class Entity {
    public:
        Entity();
        Entity(Vector2<float> newPosition, Vector2<float> newRotation, Vector2<int> newScale);
        ~Entity();

    protected:
        Vector2<float>* position;
        Vector2<float>* rotation;
        Vector2<int>* scale;

        float velocity = 0;
        float angularVelocity = 0;

        int health = 0;
    };
}

#endif