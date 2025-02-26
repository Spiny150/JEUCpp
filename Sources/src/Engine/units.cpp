#include "units.h"
#include <cmath>

Vector2 Vector2::operator+(const Vector2 &other) const
{
    return {this->x + other.x, this->y + other.y};
}

Vector2 Vector2::operator-(const Vector2 &other) const
{
    return {this->x - other.x, this->y - other.y};
}

Vector2 Vector2::operator*(const float value) const
{
    return {this->x * value, this->y * value};
}

Vector2 Vector2::operator/(const float value) const
{
    return {this->x / value, this->y / value};
}

Vector2 &Vector2::operator+=(const Vector2 &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2::operator Vector2Int() const
{
    return Vector2Int((int)(std::round(x)), (int)(std::round(y)));
}

Vector2Int Vector2Int::operator+(const Vector2Int &other) const
{
    return {this->x + other.x, this->y + other.y};
}

Vector2Int Vector2Int::operator-(const Vector2Int &other) const
{
    return {this->x - other.x, this->y - other.y};
}

Vector2 Vector2Int::operator*(const float value) const
{
    return {this->x * value, this->y * value};
}

Vector2 Vector2Int::operator/(const float value) const
{
    return {this->x / value, this->y / value};
}

Vector2Int &Vector2Int::operator+=(const Vector2Int &other)
{
    x += other.x;
    y += other.y;
    return *this;
}

Vector2Int::operator Vector2() const
{
    return Vector2((float)x, (float)y);
}