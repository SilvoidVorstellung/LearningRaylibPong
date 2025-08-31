#include <raylib.h>

#include "ball.h"
#include "paddle.h"

Ball::Ball() {
  mColor = WHITE;
  mPosition = {1, 1};
  mSpeed = {1, 1};
  mRadius = 1.0f;
}

void Ball::setPosition(float positionX, float positionY) {
  mPosition = {positionX, positionY};
}
void Ball::setRadius(float radius) { mRadius = radius; }
void Ball::setColor(Color color) { mColor = color; }
void Ball::setSpeed(Vector2 speed) { mSpeed = speed; }

Vector2 &Ball::getPosition() { return mPosition; }
Vector2 &Ball::getSpeed() { return mSpeed; }
float &Ball::getRadius() { return mRadius; }

void Ball::Draw() { DrawCircleV(mPosition, mRadius, mColor); }

void Ball::Update(Paddle &player, Paddle &cpu, int &randSpeed) {

  while (randSpeed == 0) {
    randSpeed = GetRandomValue(-1, 1);
  }

  int randPositionY = 0;

  while (randPositionY == 0) {
    randPositionY = GetRandomValue(2, (int)GetScreenHeight() - 2);
  }

  mPosition.x += mSpeed.x;
  mPosition.y += mSpeed.y;

  if (mPosition.y + mRadius >= GetScreenHeight() ||
      mPosition.y - mRadius <= 0) {
    mSpeed.y *= -1;

    if (mPosition.y > GetScreenHeight()) {
      mPosition.y += mRadius;
    } else if (mPosition.y < 0) {
      mPosition.y -= mRadius;
    }
  }
  if (mPosition.x + mRadius >= GetScreenWidth()) {
    // mSpeed.x *= -1;
    mPosition = (Vector2){GetScreenWidth() / 2.0f, (float)randPositionY};

    if (player.isPlayer) {
      player.score++;
      mSpeed = (Vector2){(float)8 * randSpeed, (float)8 * randSpeed};
    }
  }
  if (mPosition.x - mRadius <= 0) {
    // mSpeed.x *= -1;
    mPosition = (Vector2){GetScreenWidth() / 2.0f, (float)randPositionY};
    if (!cpu.isPlayer) {
      cpu.score++;
      mSpeed = (Vector2){(float)8 * randSpeed, (float)8 * randSpeed};
    }
  }
}
