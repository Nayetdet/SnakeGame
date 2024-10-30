#include <stdlib.h>
#include <stdbool.h>

#include <raylib.h>

#include "collisions.h"
#include "constants.h"
#include "food.h"
#include "snake.h"
#include "utils.h"

int main(void) {
    Snake snake;
    Vector2 food;
    
    InitWindow(SCREEN_SIZE, SCREEN_SIZE, "Snake");
    SetTargetFPS(60);    
    
    Image icon = LoadImage("assets/icon.png");
    SetWindowIcon(icon);
    UnloadImage(icon);

    InitAudioDevice();
    Sound eatSound = LoadSound("sounds/eat.wav");
    Sound deathSound = LoadSound("sounds/death.wav");

    InitializeNewSnake(&snake);
    InitializeNewFood(&food, &snake);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        DrawBackgroundGrid();

        if (snake.isAlive) {
            ChangeSnakeDirection(&snake);
            UpdateSnake(&snake);

            DrawFood(food);
            DrawSnake(&snake);
            DisplayPlayerScore(snake.size - 1);

            if (IsSnakeSegmentColliding(snake.body[0], food)) {
                PlaySound(eatSound);
                InitializeNewFood(&food, &snake);
                snake.size++;
            }

            if (snake.isAlive && IsSnakeSelfColliding(&snake)) {
                PlaySound(deathSound);
                snake.isAlive = false;
            }
        } else {
            DisplayGameOverMessage();
            if (IsKeyPressed(KEY_R)) {
                InitializeNewSnake(&snake);
                InitializeNewFood(&food, &snake);
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
