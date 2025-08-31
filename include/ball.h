#pragma once

#include <raylib.h>

#include "paddle.h"

class Ball {
public:
  Ball();

private:
  Vector2 mPosition;
  Vector2 mSpeed;
  float mRadius;
  Color mColor;

public:
  void setPosition(float x, float y);
  void setRadius(float radius);
  void setColor(Color color);
  void setSpeed(Vector2 speed);

  Vector2 &getPosition();
  Vector2 &getSpeed();
  float &getRadius();

  void Draw();
  void Update(Paddle &player, Paddle &cpu, int &randSpeed);
};
