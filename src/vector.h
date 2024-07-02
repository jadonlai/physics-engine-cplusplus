#pragma once

#include <iostream>

class Vector {
    public:
    float X, Y;

    Vector(float x, float y) : X(x), Y(y) {}

    // Vector with no values is the zero vector
    Vector() : X(0.f), Y(0.f) {}
    
    Vector operator+(const Vector& other) const {
        return Vector(X + other.X, Y + other.Y);
    }

    Vector operator-(const Vector& other) const {
        return Vector(X - other.X, Y - other.Y);
    }

    Vector operator-() const {
        return Vector(-X, -Y);
    }

    Vector operator*(float s) const {
        return Vector(X * s, Y * s);
    }

    Vector operator/(float s) const {
        if (s == 0) {
            throw std::invalid_argument("Cannot divide by zero");
        }

        return Vector(X / s, Y / s);
    }

    bool operator==(const Vector& other) const {
        return X == other.X && Y == other.Y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
        return os << "(" << v.X << ", " << v.Y << ")";
    }
};
