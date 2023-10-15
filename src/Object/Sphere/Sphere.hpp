#pragma once

#include "Object/Object.hpp"
#include "utils/color/color.hpp"
#include "utils/vec/vec3.hpp"
#include "constants.hpp"

class Sphere : public Object
{
public:
    Sphere(Color color, double shininess, double reflectiveness,
           vec3d position, double radius);

    double find_closest_intersection(vec3d& point, vec3d& direction) override;
    vec3d get_normal(vec3d& point) override;

    inline vec3d get_position() { return position; }
    inline double get_radius() { return radius; }

private:
    vec3d position;
    double radius;
};
