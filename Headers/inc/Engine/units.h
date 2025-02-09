#pragma once

struct Vector2 {
    float x, y;
    Vector2(float _x = 0.0f, float _y = 0.0f) : x(_x), y(_y) {};

    Vector2 operator+(const Vector2& other) const;
    Vector2& operator+=(const Vector2& other);
    Vector2 operator*(const float value) const;

    static Vector2 zero() {
        return {0, 0};
    };
    static Vector2 up() {
        return {0, -1};
    };
    static Vector2 down() {
        return {0, 1};
    };
    static Vector2 right() {
        return {1, 0};
    };
    static Vector2 left() {
        return {-1, 0};
    };
};
struct Vector2Int {
    int x, y;
    Vector2Int(int _x = 0, int _y = 0) : x(_x), y(_y) {};

    Vector2Int operator+(const Vector2Int& other) const;
    Vector2Int& operator+=(const Vector2Int& other);
    Vector2Int operator*(const float value) const;

    static Vector2Int zero() {
        return {0, 0};
    };
    static Vector2Int up() {
        return {0, -1};
    };
    static Vector2Int down() {
        return {0, 1};
    };
    static Vector2Int right() {
        return {1, 0};
    };
    static Vector2Int left() {
        return {-1, 0};
    };
};
