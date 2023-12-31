#pragma once
#include <limits>
#include "utils/color/color.hpp"
#include "utils/vec/vec3.hpp"
#include "constants.hpp"

class Sphere
{
public:
    Sphere(vec3d position,
           double radius,
           Color color,
           double shininess = qNaN,
           double reflectiveness = 0);

    inline vec3d get_position() { return position; }
    inline double get_radius() { return radius; }
    inline Color get_color() { return color; }
    inline double get_shininess() { return shininess; }
    inline double get_reflectiveness() { return reflectiveness; }

private:
    vec3d position;
    double radius;
    Color color;
    double shininess;
    double reflectiveness;
};
