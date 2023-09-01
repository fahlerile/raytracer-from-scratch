#pragma once
#include <stdexcept>
#include <string>
#include <sstream>
#include <cmath>
#include "vec3.hpp"

template <typename T>
struct vec2
{
public:
    T x = 0;
    T y = 0;

    vec2<T> operator+(vec2<T> other);
    vec2<T> operator-(vec2<T> other);
    vec2<T> operator*(int other);
    vec2<T> operator*(double other);
    T operator[](int index) const;
    T& operator[](int index);
    vec2<T> operator-();

    operator vec2<int>() const { return {(int) this->x, (int) this->y}; };
    operator vec2<float>() const { return {(float) this->x, (float) this->y}; };
    operator vec2<double>() const { return {(double) this->x, (double) this->y}; };

    vec3<T> cross_product(vec2<T> b);
    T dot_product(vec2<T> b);
    vec2<T> normalize();
    double magnitude();

    vec2<float> rotate(float rad, vec2<float> center);
    std::string to_string();
};

using vec2i = vec2<int>;
using vec2f = vec2<float>;
using vec2d = vec2<double>;

template <typename T>
vec2<T> vec2<T>::operator+(vec2<T> other)
{
    return vec2<T> {
        this->x + other.x,
        this->y + other.y
    };
}

template <typename T>
vec2<T> vec2<T>::operator-(vec2<T> other)
{
    return vec2<T> {
        this->x - other.x,
        this->y - other.y
    };
}

template <typename T>
vec2<T> vec2<T>::operator*(int other)
{
    return vec2<T> {
        this->x * other,
        this->y * other
    };
}

template <typename T>
vec2<T> vec2<T>::operator*(double other)
{
    return vec2<T> {
        this->x * other,
        this->y * other
    };
}

template <typename T>
T vec2<T>::operator[](int index) const
{
    if (index == 0) return this->x;
    else if (index == 1) return this->y;
    throw std::invalid_argument("vec2 invalid index " + index);
}

template <typename T>
T& vec2<T>::operator[](int index)
{
    if (index == 0) return this->x;
    else if (index == 1) return this->y;
    throw std::invalid_argument("vec2 invalid index " + index);
}

template <typename T>
vec2<T> vec2<T>::operator-()
{
    return {
        -this->x,
        -this->y
    };
}

template <typename T>
vec3<T> vec2<T>::cross_product(vec2<T> b)
{
    return vec3<T> {
        (T) 0,
        (T) 0,
        this->x * b.y - this->y * b.x
    };
}

template <typename T>
T vec2<T>::dot_product(vec2<T> b)
{
    return (this->x * b.x + this->y * b.y);
}

template <typename T>
vec2<T> vec2<T>::normalize()
{
    // casting to double to avoid ambiguity error if T = int
    double magnitude = this->magnitude();
    return {
        this->x / magnitude,
        this->y / magnitude
    };
}

template <typename T>
double vec2<T>::magnitude()
{
    return std::sqrt(std::pow((double) this->x, 2) + std::pow((double) this->y, 2));
}

template <typename T>
vec2f vec2<T>::rotate(float rad, vec2f center)
{
    // the idea is to place `center` at the origin of coordinate system,
    // then rotate the vector and place it to the same exact position as it was before
    vec2f temp = {this->x - center.x, this->y - center.y};
    vec2f result = {
        (temp.x * std::cos(rad)) - (temp.y * std::sin(rad)),
        (temp.x * std::sin(rad)) + (temp.y * std::cos(rad))
    };
    result.x += center.x;
    result.y += center.y;
    return result;
}

template <typename T>
std::string vec2<T>::to_string()
{
    std::ostringstream oss;
    oss << "vec2(" << this->x << ", " << this->y << ")";
    return oss.str();
}