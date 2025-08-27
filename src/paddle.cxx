#include "raylib.h"

#include "paddle.h"

void Paddle::Draw() { DrawRectangle(x, y, width, height, color); }

void Paddle::Update() {
  if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
    y -= speed;
  } else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
    y += speed;
  }
}
