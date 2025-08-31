#include <raylib.h>

#include "ball.h"
#include "paddle.h"

<<<<<<< HEAD
void Ball::Draw() { DrawCircleV(position, radius, color); }
=======
Ball::Ball() {
  mColor = WHITE;
  mPosition = {1, 1};
  mSpeed = {1, 1};
  mRadius = 1.0f;
}

void Ball::setPosition(float &positionX, float &positionY) {
  mPosition = {positionX, positionY};
}
void Ball::setRadius(float &radius) { mRadius = radius; }
void Ball::setColor(Color &color) { mColor = color; }

Vector2 &Ball::getPosition() { return mPosition; }
Vector2 Ball::getSpeed() { return mSpeed; }
float Ball::getRadius() { return mRadius; }

void Ball::Draw() { DrawCircleV(mPosition, mRadius, mColor); }
>>>>>>> 49ce48f (Didn't remembered.)

void Ball::Update(Paddle &player, Paddle &cpu, int &randSpeed) {

  while (randSpeed == 0) {
    randSpeed = GetRandomValue(-1, 1);
  }

  int randPositionY = 0;

  while (randPositionY == 0) {
    randPositionY = GetRandomValue(2, (int)GetScreenHeight() - 2);
  }

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
    position = (Vector2){GetScreenWidth() / 2.0f, (float)randPositionY};

    if (player.isPlayer) {
      player.score++;
      speed = (Vector2){(float)8 * randSpeed, (float)8 * randSpeed};
    }
  }
  if (position.x - radius <= 0) {
    // speed.x *= -1;
    position = (Vector2){GetScreenWidth() / 2.0f, (float)randPositionY};
    if (!cpu.isPlayer) {
      cpu.score++;
      speed = (Vector2){(float)8 * randSpeed, (float)8 * randSpeed};
    }
  }
}
