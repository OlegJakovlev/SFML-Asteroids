#include "Entity.h"

namespace Entities {
    Entity::Entity() {
        position = new Vector2<float>(0, 0);
        rotation = new Vector2<float>(0, 0);
        scale = new Vector2<int>(0, 0);
    }

    Entity::Entity(Vector2<float> newPosition, Vector2<float> newRotation, Vector2<int> newScale) {
        position = &newPosition;
        rotation = &newRotation;
        scale = &newScale;
    }
}