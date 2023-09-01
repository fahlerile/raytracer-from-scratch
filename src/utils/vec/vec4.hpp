#pragma once
#include <stdexcept>
#include <sstream>
#include "vec3.hpp"

template <typename T>
struct vec4
{
public:
    T x = 0;
    T y = 0;
    T z = 0;
    T w = 0;

    vec4<T> operator+(vec4<T> other);
    vec4<T> operator-(vec4<T> other);
    vec4<T> operator*(double other);
    T operator[](int index) const;
    T& operator[](int index);
    vec4<T> operator-();

    operator vec4<int>() const { return vec4<int> {(int) this->x, (int) this->y, (int) this->z, (int) this->w}; };
    operator vec4<float>() const { return vec4<float> {(float) this->x, (float) this->y, (float) this->z, (float) this->w}; };
    operator vec4<double>() const { return vec4<double> {(double) this->x, (double) this->y, (double) this->z, (double) this->w}; };

    T dot_product(vec4<T> b);
    vec4<T> normalize();
    double magnitude();

    std::string to_string();
};

typedef vec4<int> vec4i;
typedef vec4<float> vec4f;
typedef vec4<double> vec4d;

template <typename T>
vec4<T> vec4<T>::operator+(vec4<T> other)
{
    return {
        this->x + other.x,
        this->y + other.y,
        this->z + other.z,
        this->w + other.w
    };
}

template <typename T>
vec4<T> vec4<T>::operator-(vec4<T> other)
{
    return {
        this->x - other.x,
        this->y - other.y,
        this->z - other.z,
        this->w - other.w
    };
}

template <typename T>
vec4<T> vec4<T>::operator*(double other)
{
    return vec4<T> {
        this->x * other,
        this->y * other,
        this->z * other,
        this->w * other
    };
}

template <typename T>
T vec4<T>::operator[](int index) const
{
    if (index == 0) return this->x;
    else if (index == 1) return this->y;
    else if (index == 2) return this->z;
    else if (index == 3) return this->w;
    throw std::invalid_argument("vec4 invalid index " + index);
}

template <typename T>
T& vec4<T>::operator[](int index)
{
    if (index == 0) return this->x;
    else if (index == 1) return this->y;
    else if (index == 2) return this->z;
    else if (index == 3) return this->w;
    throw std::invalid_argument("vec4 invalid index " + index);
}

template <typename T>
vec4<T> vec4<T>::operator-()
{
    return {
        -this->x,
        -this->y,
        -this->z,
        -this->w
    };
}

template <typename T>
T vec4<T>::dot_product(vec4<T> b)
{
    return (this->x * b.x + this->y * b.y + this->z * b.z + this->w * b.w);
}

template <typename T>
vec4<T> vec4<T>::normalize()
{
    // casting to double to avoid ambiguity error if T = int
    double magnitude = this->magnitude();
    return {
        this->x / magnitude,
        this->y / magnitude,
        this->z / magnitude,
        this->w / magnitude
    };
}

template <typename T>
double vec4<T>::magnitude()
{
    return std::sqrt(std::pow((double) this->x, 2) + std::pow((double) this->y, 2) + std::pow((double) this->z, 2) + std::pow((double) this->w, 2));
}

template <typename T>
std::string vec4<T>::to_string()
{
    std::ostringstream oss;
    oss << "vec4(" << this->x << ", " << this->y << ", " << this->z << ", " << this->w << ")";
    return oss.str();
}
