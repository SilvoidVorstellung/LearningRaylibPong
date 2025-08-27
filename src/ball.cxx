#include <raylib.h>

#include "ball.h"

void Ball::Draw() { DrawCircleV(position, radius, color); }

void Ball::Update() {
  position.x += speedX;
  position.y += speedY;

  if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0) {
    speedY *= -1;
  }
  if (position.x + radius >= GetScreenWidth() || position.x - radius <= 0) {
    speedX *= -1;
  }
}
