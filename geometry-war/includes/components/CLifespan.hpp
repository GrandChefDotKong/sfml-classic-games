#pragma once

struct CLifespan {
  int remaining = 0;
  int total = 0;

  CLifespan(int total) : remaining(total), total(total) {}
};
