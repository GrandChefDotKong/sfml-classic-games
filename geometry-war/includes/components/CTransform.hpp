#pragma once
#include "../Vec2.hpp"

struct CTransform {
  Vec2 position = {0, 0};
  Vec2 velocity = {0, 0};
  Vec2 scale = {0, 0};
  float angle = 0;

  CTransform(const Vec2& pos, const Vec2& vel, const Vec2& scale, float angle) :
    position(pos), velocity(vel), scale(scale), angle(angle) {}
};
