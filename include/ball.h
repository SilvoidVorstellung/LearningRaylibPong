#pragma once

#include <raylib.h>

#include "paddle.h"

struct Ball {
public:
  Ball();

public:
  Vector2 position;
  Vector2 speed;
  float radius;

private:
  Color mColor;

public:
  void setColor(Color color);

  void Draw();
  void Update(Paddle &player, Paddle &cpu);
  void Reset();
};
