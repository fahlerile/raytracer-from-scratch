#include <cmath>
#include "PointLight.hpp"
#include "utils/vec/vec3.hpp"

PointLight::PointLight(double intensity, Color color, vec3d position)
{
    this->intensity = intensity;
    this->color = color;
    this->position = position;
}

vec3d PointLight::get_point_to_light_source_vector(vec3d& point)
{
    return this->position - point;
}

LightSourceType PointLight::get_type()
{
    return LightSourceType::PointLight;
}
