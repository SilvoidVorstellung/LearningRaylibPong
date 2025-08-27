#pragma once

#include <raylib.h>

class Ball {
public:
  Vector2 position;
  float speedX, speedY;
  float radius;
  Color color;

  void Draw();

  void Update();
};
