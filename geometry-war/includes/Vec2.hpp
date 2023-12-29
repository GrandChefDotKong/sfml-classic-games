#pragma once
#include <math.h>

class Vec2 {
 public:
  float x;
  float y;

  Vec2(float x, float y);

  bool operator==(Vec2 vec);
  bool operator!=(Vec2 vec);

  Vec2 operator+(Vec2 vec);
  Vec2 operator-(Vec2 vec);
  Vec2 operator*(const float value);
  Vec2 operator/(const float value);

  void operator-=(Vec2 vec);

  Vec2& add(const Vec2& vec);
  Vec2& scale(float scale);
  Vec2& rotate(float deg);
  Vec2& normalize();
  
  float length();

  float dist(const Vec2& vec) const;
};