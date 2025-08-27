#pragma once

#include <raylib.h>

class Ball {
public:
  Vector2 position;
  float speedX, speedY;
  float radius;
  Color color;

  void Draw() { DrawCircleV(position, radius, color); }

  void Update() {
    position.x += speedX;
    position.y += speedY;

    if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0) {
      speedY *= -1;
    }
    if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0) {
      speedX *= -1;
    }
  }
};
