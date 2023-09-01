#pragma once
#include <stdexcept>
#include <cmath>
#include <sstream>

template <typename T>
struct vec3
{
public:
    T x = 0;
    T y = 0;
    T z = 0;

    vec3<T> operator+(vec3<T> other);
    vec3<T> operator-(vec3<T> other);
    vec3<T> operator*(double other);
    T operator[](int index) const;
    T& operator[](int index);
    vec3<T> operator-();

    operator vec3<int>() const { return {(int) this->x, (int) this->y, (int) this->z}; };
    operator vec3<float>() const { return {(float) this->x, (float) this->y, (float) this->z}; };
    operator vec3<double>() const { return {(double) this->x, (double) this->y, (double) this->z}; };

    vec3<T> cross_product(vec3<T> b);
    T dot_product(vec3<T> b);
    vec3<T> normalize();
    double magnitude();

    std::string to_string();
};

using vec3i = vec3<int>;
using vec3f = vec3<float>;
using vec3d = vec3<double>;

template <typename T>
vec3<T> vec3<T>::operator+(vec3<T> other)
{
    return {
        this->x + other.x,
        this->y + other.y,
        this->z + other.z
    };
}

template <typename T>
vec3<T> vec3<T>::operator-(vec3<T> other)
{
    return {
        this->x - other.x,
        this->y - other.y,
        this->z - other.z
    };
}

template <typename T>
vec3<T> vec3<T>::operator*(double other)
{
    return vec3<T> {
        this->x * other,
        this->y * other,
        this->z * other
    };
}

template <typename T>
T vec3<T>::operator[](int index) const
{
    if (index == 0) return this->x;
    else if (index == 1) return this->y;
    else if (index == 2) return this->z;
    throw std::invalid_argument("vec3 invalid index " + index);
}

template <typename T>
T& vec3<T>::operator[](int index)
{
    if (index == 0) return this->x;
    else if (index == 1) return this->y;
    else if (index == 2) return this->z;
    throw std::invalid_argument("vec3 invalid index " + index);
}

template <typename T>
vec3<T> vec3<T>::operator-()
{
    return {
        -this->x,
        -this->y,
        -this->z
    };
}

template <typename T>
vec3<T> vec3<T>::cross_product(vec3<T> b)
{
    return vec3<T> {
        this->y * b.z - this->z * b.y,
        this->z * b.x - this->x * b.z,
        this->x * b.y - this->y * b.x
    };
}

template <typename T>
T vec3<T>::dot_product(vec3<T> b)
{
    return (this->x * b.x + this->y * b.y + this->z * b.z);
}

template <typename T>
vec3<T> vec3<T>::normalize()
{
    // casting to double to avoid ambiguity error if T = int
    double magnitude = this->magnitude();
    return {
        this->x / magnitude,
        this->y / magnitude,
        this->z / magnitude
    };
}

template <typename T>
double vec3<T>::magnitude()
{
    return std::sqrt(std::pow((double) this->x, 2) + std::pow((double) this->y, 2) + std::pow((double) this->z, 2));
}

template <typename T>
std::string vec3<T>::to_string()
{
    std::ostringstream oss;
    oss << "vec3(" << this->x << ", " << this->y << ", " << this->z << ")";
    return oss.str();
}
