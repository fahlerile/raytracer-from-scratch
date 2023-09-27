#pragma once
#include <memory>
#include "utils/vec/vec3.hpp"
#include "utils/color/color.hpp"

class Sphere;

class LightSource
{
public:
    virtual ~LightSource() {};
    // Calculate point color considering *only* this light source
    virtual double calculate_intensity(vec3d& point, vec3d& normal, vec3d& camera_pos,
                                       std::unique_ptr<Sphere>& p_object);
    virtual vec3d get_point_to_light_source_vector(vec3d& point) = 0;
    inline double get_intensity() { return intensity; }
    inline color_t get_color() { return color; }
protected:
    double intensity;
    color_t color;
};
