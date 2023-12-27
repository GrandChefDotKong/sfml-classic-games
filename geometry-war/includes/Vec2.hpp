#pragma once

class Vec2 {
 public:
  double x;
  double y;

  bool operator==(Vec2 vec);
  bool operator!=(Vec2 vec);

  Vec2 operator+(Vec2 vec);
  Vec2 operator-(Vec2 vec);
  Vec2 operator*(Vec2 vec);
  Vec2 operator/(Vec2 vec);

  void normalize();
  double length();

};