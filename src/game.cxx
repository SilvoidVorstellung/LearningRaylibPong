#include <raylib.h>

#include "ball.h"
#include "colors.h"
#include "game.h"
#include "paddle.h"

void game() {

  constexpr int screenWidth = 800;
  constexpr int screenHeight = 460;

  InitWindow(screenWidth, screenHeight, "game");

  Ball ball;
  Vector2 ballPosition;
  ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

  ball.position = {ballPosition.x, ballPosition.y};

  Paddle player;
  player.isPlayer = true;
  player.position.x = 10;
  player.position.y = (int)(screenHeight / 2) - (int)(player.height / 2);

  CpuPaddle ai;
  ai.isPlayer = false;
  ai.position.x = GetRenderWidth() - ai.width - 10;
  ai.position.y = (int)(screenHeight / 2) - (int)(ai.height / 2);
  ai.speed = 5;

  constexpr float speedAdd{0.5f};

  int randValue = GetRandomValue(-1, 1);
  unsigned int frameCounter = 0;
  float offset = 5;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    frameCounter++;

    if (((frameCounter / 120) % 2) == 1) {
      randValue = GetRandomValue(-1, 1);
      frameCounter = 0;
    }

    BeginDrawing();
    ClearBackground(darkGreen);
    DrawRectangle(screenWidth / 2, 0, screenWidth / 2, screenHeight, green);
    DrawCircle(screenWidth / 2, screenHeight / 2, 100, lightGreen);
    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

    ball.Update(player, ai);
    player.Update();
    ai.Update(ball.position.y);

    // Check for collision;

    if (CheckCollisionCircleRec(ball.position, ball.radius,
                                Rectangle{player.position.x,
                                          player.position.y + 2, player.width,
                                          player.height - 2})) {
      ball.speed.x *= -1;

      if (ball.position.x < (player.position.x + player.width)) {
        ball.position.x += player.width;
      }

      player.speed += 0.8f;
      if (ball.speed.x < 0) {
        ball.speed.x -= speedAdd;
        ball.speed.y -= speedAdd;
      } else if (ball.speed.x > 0) {
        ball.speed.x += speedAdd;
        ball.speed.y += speedAdd;
      }
    }

    if (CheckCollisionCircleRec(
            ball.position, ball.radius,
            Rectangle{ai.position.x, ai.position.y, ai.width, ai.height})) {
      ball.speed.x *= -1;

      if (ball.position.x < ai.position.x) {
        ball.position.x -= 2;
      }

      if (ball.speed.x < 0) {
        ball.speed.x -= speedAdd;
        ball.speed.y -= speedAdd;
      } else if (ball.speed.x > 0) {
        ball.speed.x += speedAdd;
        ball.speed.y += speedAdd;
      }
    }

    player.Draw();
    ai.Draw();
    ball.Draw();
    DrawText(TextFormat("%02i", ai.score), 3 * (screenWidth / 4 - 15), 20, 80,
             WHITE);
    DrawText(TextFormat("%02i", player.score), (screenWidth / 4 - 50), 20, 80,
             WHITE);

    EndDrawing();
  }

  CloseWindow();
}
