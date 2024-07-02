#pragma once

#include "vector.h"
#include <SFML/Graphics.hpp>

class Converter {
    public:
    sf::Vector2f ToVector2f(Vector v) {
        return sf::Vector2f(v.X, -v.Y);
    }
};
