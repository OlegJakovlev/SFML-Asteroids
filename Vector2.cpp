#include "Vector2.h"

template <>
Vector2<float>::Vector2(float newX, float newY) {
    x = newX;
    y = newY;
}

template <>
Vector2<int>::Vector2(int newX, int newY) {
    x = newX;
    y = newY;
}