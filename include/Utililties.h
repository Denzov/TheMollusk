#ifndef _UTILITYDEFINES_H_
#define _UTILITYDEFINES_H_  

#include <raylib.h>
#include <stdint.h>
#include <cmath>
#include <iostream>

#define half(x) (x / 2)
#define constrain(x, min, max) (x < min ? min : (x > max ? max : x))
#define sign(x) (x < 0 ? -1 : (x > 0 ? 1 : 0))

inline Vector2 vec_from_angle(const float angle, const float magnitude, const Vector2& base) {
    return { base.x + std::cos(angle) * magnitude, base.y + std::sin(angle) * magnitude };
}

inline float length(const Vector2& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

inline Vector2 norm(const Vector2& v) {
    const float len = length(v);

    if(len == 0) return { 0, 0 };
    return { v.x / len, v.y / len};
}

inline Vector2 add(const Vector2& a, const Vector2& b) { 
    return { a.x + b.x, a.y + b.y };
}

inline Vector2 multiply(const Vector2& a, const Vector2& b) {
    return { a.x * b.x, a.y * b.y };
}

inline Vector2 multiply(const Vector2& a, const float b) {
    return { a.x * b, a.y * b };
}

inline float lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

inline float dot(const Vector2& a, const Vector2& b) {
    return a.x * b.x + a.y * b.y;
}

#endif // !_UTILITYDEFINES_H_