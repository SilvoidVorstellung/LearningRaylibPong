#pragma once

#include "raylib.h"

class Paddle {
public:
  float x, y;
  float width, height;
  int speed;
  Color color;

  void Draw() { DrawRectangle(x, y, width, height, color); }

  void Update() {
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
      y -= speed;
    } else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
      y += speed;
    }
  }
};
