#include "raylib.h"

#include "ball.h"
#include "paddle.h"

int main() {

  constexpr int screenWidth = 800;
  constexpr int screenHeight = 460;

  InitWindow(screenWidth, screenHeight, "game");

  Ball ball;

  float xMidScreen, yMidScreen, ballRadius;
  Color ballColor;
  Vector2 ballSpeed;
  xMidScreen = (float)screenWidth / 2;
  yMidScreen = (float)screenHeight / 2;
  ballRadius = 10;
  ballColor = WHITE;
  ballSpeed = {7, 7};

  ball.setPosition(xMidScreen, yMidScreen);
  ball.setRadius(ballRadius);
  ball.setColor(ballColor);
  ball.setSpeed(ballSpeed.x, ballSpeed.y);

  Paddle player;
  player.isPlayer = true;
  player.color = WHITE;
  player.height = 100;
  player.width = 18;
  player.position.x = 10;
  player.position.y = (int)(screenHeight / 2) - (int)(player.height / 2);
  player.speed = 10;
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
  float offset = 5;

  SetTargetFPS(30);

  while (!WindowShouldClose()) {

    frameCounter++;

    if (((frameCounter / 120) % 2) == 1) {
      randValue = GetRandomValue(-1, 1);
      frameCounter = 0;
    }

    Vector2 ballPosition = ball.getPosition();
    Vector2 ballSpeed = ball.getSpeed();
    float ballRadius = ball.getRadius();

    BeginDrawing();
    ClearBackground(DARKGREEN);

    ball.Update(player, ai, randValue);
    player.Update();
    ai.Update(ballPosition.y);

    // Check for collision;

    if (CheckCollisionCircleRec(ballPosition, ballRadius,
                                Rectangle{player.position.x,
                                          player.position.y + 2, player.width,
                                          player.height - 2})) {
      ballSpeed.x *= -1;

      if (ballPosition.x < (player.position.x + player.width)) {
        ballPosition.x += player.width;
      }

      player.speed += 0.8f;
      if (ballSpeed.x < 0) {
        ballSpeed.x -= speedAdd;
        ballSpeed.y -= speedAdd;
      } else if (ballSpeed.x > 0) {
        ballSpeed.x += speedAdd;
        ballSpeed.y += speedAdd;
      }
    }

    if (CheckCollisionCircleRec(
            ballPosition, ballRadius,
            Rectangle{ai.position.x, ai.position.y, ai.width, ai.height})) {
      ballSpeed.x *= -1;

      if (ballPosition.x < ai.position.x) {
        ballPosition.x -= 2;
      }

      if (ballSpeed.x < 0) {
        ballSpeed.x -= speedAdd;
        ballSpeed.y -= speedAdd;
      } else if (ballSpeed.x > 0) {
        ballSpeed.x += speedAdd;
        ballSpeed.y += speedAdd;
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
