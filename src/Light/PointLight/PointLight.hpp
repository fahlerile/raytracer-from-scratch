#pragma once
#include "Light/LightSource.hpp"
#include "utils/vec/vec3.hpp"

class PointLight : public LightSource
{
public:
    PointLight(double intensity, Color color, vec3d position);
    vec3d get_point_to_light_source_vector(vec3d& point) override;
    LightSourceType get_type() override;
    inline vec3d get_position() { return position; }
private:
    vec3d position;
};
