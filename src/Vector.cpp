#include <cmath>

#include "ofMain.h"

#include "Vector.h"


Vector::Vector() : x(0), y(0) {}
Vector::Vector(float x, float y) : x(x), y(y) {}
Vector::Vector(float magnitude, float angle, bool flag) {
    x = magnitude * std::cos(angle);
    y = magnitude * std::sin(angle);
}

float Vector::magnitude() const
{
    return sqrt(x * x + y * y);
}

float Vector::angle() const
{
    return std::atan(std::abs(y) / std::abs(x));
}

float Vector::normalizedAngle() const
{
    // fix theta so that it is relative to the positive x-axis
    if (x < 0) {
        if (y < 0) {
            return PI + this->angle();
        } else {
            return PI - this->angle();
        }
    } else {
        if (y < 0) {
            return 2 * PI - this->angle();
        } else {
            return this->angle();
        }
    }
}

void Vector::setMagnitude(float magnitude)
{
    float theta = this->normalizedAngle();
    x = magnitude * std::cos(theta);
    y = magnitude * std::sin(theta);
}

void Vector::operator+=(Vector other)
{
    x += other.x;
    y += other.y;
}

void Vector::operator-=(Vector other)
{
    x -= other.x;
    y -= other.y;
}

void Vector::operator*=(float magnitude)
{
    this->setMagnitude(this->magnitude() * magnitude);
}

void Vector::operator/=(float magnitude)
{
    this->setMagnitude(this->magnitude() / magnitude);
}

Vector Vector::operator+(Vector other)
{
    Vector newV;
    newV.x = x + other.x;
    newV.y = y + other.y;
    return newV;
}

Vector Vector::operator-(Vector other)
{
    Vector newV;
    newV.x = x - other.x;
    newV.y = y - other.y;
    return newV;
}

Vector Vector::operator*(float magnitude)
{
    Vector newV(x * magnitude, y * magnitude);
    return newV;
}

Vector Vector::operator/(float magnitude)
{
    Vector newV(x / magnitude, y / magnitude);
    return newV;
}
