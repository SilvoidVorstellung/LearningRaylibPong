#pragma once

#include "raylib.h"

class Paddle {
private:
  // I'm not using it cause I don't know how to do it without making the
  // constructor parameter to long.
  // So all of my variable are public.

protected:
  void limitMovement();

public:
  Vector2 position;
  float width, height;
  int speed;
  Color color;
  int score;
  bool isPlayer;

  void Draw();
  void Update();
};

class CpuPaddle : public Paddle {
public:
  void Update(float &ballY);
};
