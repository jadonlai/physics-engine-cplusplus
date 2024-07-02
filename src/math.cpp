#include "math.h"

float length(Vector v) {
    return sqrt(v.X * v.X + v.Y * v.Y);
}

float distance(Vector v1, Vector v2) {
    float dx = v1.X - v2.X;
    float dy = v1.Y - v2.Y;
    return sqrt(dx * dx + dy * dy);
}

Vector normalize(Vector v) {
    float len = length(v);
    if (len == 0) {
        return Vector();
    }
    return Vector(v.X / len, v.Y / len);
}

float dot(Vector v1, Vector v2) {
    return v1.X * v2.X + v1.Y * v2.Y;
}

float cross(Vector v1, Vector v2) {
    return v1.X * v2.Y - v1.Y * v2.X;
}
