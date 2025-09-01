#include <raylib.h>

#include "ball.h"
#include "colors.h"
#include "paddle.h"

Ball::Ball() : speed({4, 4}), radius(10), mColor(yellow) {}

void Ball::setColor(Color color) { mColor = color; }

void Ball::Draw() { DrawCircleV(position, radius, mColor); }

void Ball::Update(Paddle &player, Paddle &cpu) {

  position.x += speed.x;
  position.y += speed.y;

  if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0) {
    speed.y *= -1;

    if (position.y > GetScreenHeight()) {
      position.y += radius;
    } else if (position.y < 0) {
      position.y -= radius;
    }
  }
  if (position.x + radius >= GetScreenWidth()) {
    // speed.x *= -1;

    if (player.isPlayer) {
      player.score++;
      Reset();
    }
  }
  if (position.x + radius <= 0) {
    // speed.x *= -1;
    if (!cpu.isPlayer) {
      cpu.score++;
      Reset();
    }
  }
}

void Ball::Reset() {
  float randPositionY = GetRandomValue(1.0f, GetScreenHeight() - 1.0f);
  int speedChoice[2] = {-1, 1};

  speed = {7, 7};

  speed.x *= speedChoice[GetRandomValue(0, 1)];
  speed.y *= speedChoice[GetRandomValue(0, 1)];

  position.x = (float)GetScreenWidth() / 2;
  position.y = randPositionY;
}
