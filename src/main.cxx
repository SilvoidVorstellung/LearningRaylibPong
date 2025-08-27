#include "raylib.h"

#include "ball.h"
#include "paddle.h"

int main() {

  constexpr int screenWidth = 800;
  constexpr int screenHeight = 400;

  InitWindow(screenWidth, screenHeight, "game");

  Ball ball;

  ball.position = {(float)screenWidth / 2, (float)screenHeight / 2};
  ball.radius = 10;
  ball.color = WHITE;
  ball.speedX = 7;
  ball.speedY = 7;

  Paddle player;
  player.color = WHITE;
  player.height = 100;
  player.width = 18;
  player.x = 10;
  player.y = ((int)(screenHeight / 2) - (int)(player.height / 2));
  player.speed = 8;

  SetTargetFPS(30);

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(SKYBLUE);

    ball.Update();
    player.Update();

    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

    player.Draw();
    ball.Draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
