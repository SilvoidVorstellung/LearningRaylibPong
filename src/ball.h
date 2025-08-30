#pragma once

#include "paddle.h"
#include <raylib.h>

class Ball {
private:
  Vector2 mPosition;
  Vector2 mSpeed;
  float mRadius;
  Color mColor;

public:
  Ball();
  void Draw();
  void Update(Paddle &player, Paddle &cpu, int &randSpeed);

  void setPosition(float &, float &);
  void setSpeed(float &, float &);
  void setRadius(float &);
  void setColor(Color &);

  Vector2 getPosition();
  Vector2 getSpeed();
  float getRadius();
};
