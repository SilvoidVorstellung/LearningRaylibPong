#pragma once

#include "raylib.h"

class Paddle {
public:
  float x, y;
  float width, height;
  int speed;
  Color color;

  void Draw();

  void Update();
};
