#pragma once

#ifndef Vector2_H
#define Vector2_H

template<class T>
class Vector2
{
    T x;
    T y;

public:
    Vector2(T newX, T newY);

public:
    Vector2 operator+(Vector2 newVector) {
        x += newVector.x;
        y += newVector.y;
    }

    Vector2 operator-(Vector2 newVector) {
        x -= newVector.x;
        y -= newVector.y;
    }
};

#endif