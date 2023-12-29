#include "includes/Vec2.hpp"

Vec2::Vec2(float x, float y) : x(x), y(y) {}

bool Vec2::operator==(Vec2 vec) {
  return x == vec.x && y == vec.y;
}

bool Vec2::operator!=(Vec2 vec) {
  return x != vec.x && y != vec.y;
}

Vec2 Vec2::operator+(Vec2 vec) {
  return Vec2(x + vec.x, y + vec.y);
}

Vec2 Vec2::operator-(Vec2 vec) {
  return Vec2(x - vec.x, y - vec.y);
}

Vec2 Vec2::operator*(const float value) {
  return Vec2(x * value, y * value); 
}

Vec2 Vec2::operator/(const float value) {
  return Vec2(x / value, y / value);
}
  
  
void Vec2::operator-=(Vec2 vec) {
  x -= vec.x;
  y -= vec.y;
}

Vec2& Vec2::add(const Vec2& vec) {
  x += vec.x;
  y += vec.y;

  return *this;
}

Vec2& Vec2::scale(float scale) {
  x *= scale;
  y *= scale;

  return *this;
}
  
Vec2& Vec2::rotate(float deg) {
  return *this; 
}

Vec2& Vec2::normalize() {
  float length = this->length();
  x /= length;
  y /= length;

  return *this;
}

float Vec2::length() {
  return sqrt(x*x + y*y);
}

float Vec2::dist(const Vec2& vec) const {
  return 0;
}
