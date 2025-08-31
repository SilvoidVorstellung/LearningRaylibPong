#include "raylib.h"

#include "paddle.h"

void Paddle::limitMovement() {
  constexpr short int offset = 5;
  constexpr short int screenHeightStart = 0;

  if (position.y <= screenHeightStart + offset) {
    position.y = screenHeightStart + offset;
  }
  if (position.y + (height + offset) >= (GetScreenHeight())) {
    position.y = GetScreenHeight() - height - offset;
  }
}

void Paddle::Draw() {
  DrawRectangleRounded(Rectangle{position.x, position.y, width, height}, 0.8, 0,
                       color);
}

void Paddle::Update() {

  if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
    position.y -= speed;
  }

  if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
    position.y += speed;
  }

  limitMovement();
}

void CpuPaddle::Update(float &ballY) {

  if (position.y + height / 2 > ballY) {
    position.y -= speed;
  }
  if (position.y + height / 2 < ballY) {
    position.y += speed;
  }

  limitMovement();
}
