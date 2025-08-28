#pragma once

#include "paddle.h"
#include <raylib.h>

class Ball {
public:
  Vector2 position;
  Vector2 speed;
  float radius;
  Color color;

  void Draw();

  void Update(Paddle &player, Paddle &cpu, int &randSpeed);
};
