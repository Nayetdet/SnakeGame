#include <stdlib.h>
#include <stdbool.h>

#include <raylib.h>
#include <raymath.h>

#include "collisions.h"
#include "config.h"
#include "food.h"
#include "snake.h"
#include "utils.h"  

int main(void) {
    int score = 0;
    bool isGameOver = false;

    int snakeSize = 1;
    Vector2 snake[SCREEN_SIZE];
    snake[0] = (Vector2){0, 0};

    Vector2 snakeDirection = {1, 0};
    Vector2 food = GenerateNewFood(snake, snakeSize);

    InitWindow(SCREEN_SIZE, SCREEN_SIZE, GetTitle(score));
    SetTargetFPS(60);    
    InitAudioDevice();
    
    Sound eatSound = LoadSound("sounds/eat.wav");
    Sound deathSound = LoadSound("sounds/death.wav");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(CELL_COLOR);
        DrawBackgroundGrid();

        if (!isGameOver) {
            ChangeSnakeDirection(&snakeDirection);
            UpdateSnake(snake, snakeDirection, snakeSize);

            DrawFood(food);
            DrawSnake(snake, snakeSize);

            if (IsSnakeHeadCollidingWithFood(snake[0], food)) {
                PlaySound(eatSound);
                food = GenerateNewFood(snake, snakeSize);
                score++;
                snakeSize++;
            }

            if (IsSnakeBodySelfColliding(snake, snakeSize)) {
                PlaySound(deathSound);
                isGameOver = true;
            }
            
            SetWindowTitle(GetTitle(score));
        } else {
            DisplayGameOverMessage();
            if (IsKeyPressed(KEY_R)) {
                score = 0;
                snakeSize = 1;
                snakeDirection = (Vector2){1, 0};
                food = GenerateNewFood(snake, snakeSize);
                isGameOver = false;
            }
        }

        WaitTime(0.08);
        EndDrawing();
    }

    UnloadSound(eatSound);
    UnloadSound(deathSound);
    
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
