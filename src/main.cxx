#include "raylib.h"

#include "ball.h"
#include "paddle.h"

int main() {

  constexpr int screenWidth = 800;
  constexpr int screenHeight = 460;

  InitWindow(screenWidth, screenHeight, "game");

  Ball ball;

  ball.position = {(float)screenWidth / 2, (float)screenHeight / 2};
  ball.radius = 10;
  ball.color = WHITE;
  ball.speed = (Vector2){7, 7};

  Paddle player;
  player.isPlayer = true;
  player.color = WHITE;
  player.height = 100;
  player.width = 18;
  player.position.x = 10;
  player.position.y = (int)(screenHeight / 2) - (int)(player.height / 2);
  player.speed = 8;
  player.score = 0;

  CpuPaddle ai;
  ai.isPlayer = false;
  ai.color = WHITE;
  ai.height = 100;
  ai.width = 18;
  ai.position.x = GetRenderWidth() - ai.width - 10;
  ai.position.y = (int)(screenHeight / 2) - (int)(ai.height / 2);
  ai.speed = 8;
  ai.score = 0;

  constexpr float speedAdd{0.5f};

  int randValue = GetRandomValue(-1, 1);
  unsigned int frameCounter = 0;

  SetTargetFPS(30);

  while (!WindowShouldClose()) {

    frameCounter++;

    if (((frameCounter / 120) % 2) == 1) {
      randValue = GetRandomValue(-1, 1);
      frameCounter = 0;
    }

    BeginDrawing();
    ClearBackground(DARKGREEN);

    ball.Update(player, ai, randValue);
    player.Update();
    ai.Update(ball.position.y);

    // Check for collision;

    if (CheckCollisionCircleRec(ball.position, ball.radius,
                                Rectangle{player.position.x - 10,
                                          player.position.y, player.width + 10,
                                          player.height})) {
      ball.speed.x *= -1;
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
      if (ball.speed.x < 0) {
        ball.speed.x -= speedAdd;
        ball.speed.y -= speedAdd;
      } else if (ball.speed.x > 0) {
        ball.speed.x += speedAdd;
        ball.speed.y += speedAdd;
      }
    }

    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

    player.Draw();
    ai.Draw();
    ball.Draw();
    DrawText(TextFormat("%02i", ai.score), 3 * screenWidth / 4 - 20, 20, 80,
             WHITE);
    DrawText(TextFormat("%02i", player.score), screenWidth / 4 - 20, 20, 80,
             WHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
