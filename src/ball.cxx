#include <raylib.h>

#include "ball.h"
#include "paddle.h"

void Ball::Draw() { DrawCircleV(position, radius, color); }

void Ball::Update(Paddle &player, Paddle &cpu, int &randSpeed) {

  while (randSpeed == 0) {
    randSpeed = GetRandomValue(-1, 1);
  }

  position.x += speed.x;
  position.y += speed.y;

  if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0) {
    speed.y *= -1;
  }
  if (position.x + radius >= GetScreenWidth()) {
    // speed.x *= -1;
    position = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    if (player.isPlayer) {
      player.score++;
      speed = (Vector2){(float)8 * randSpeed, (float)8 * randSpeed};
    }
  }
  if (position.x - radius <= 0) {
    // speed.x *= -1;
    position = (Vector2){GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    if (!cpu.isPlayer) {
      cpu.score++;
      speed = (Vector2){(float)8 * randSpeed, (float)8 * randSpeed};
    }
  }
}
