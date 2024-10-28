#include <raylib.h>
#include <raymath.h>

#include "config.h"
#include "utils.h"
#include "snake.h"

void DrawSnake(Vector2 snake[], int snakeSize) {
    for (int i = 0; i < snakeSize; i++) {
        int x = snake[i].x * CELL_SIZE;
        int y = snake[i].y * CELL_SIZE;
        DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, SNAKE_COLOR);
    }
}

void ChangeSnakeDirection(Vector2* snakeDirection) {
    if (IsKeyPressed(KEY_W) && snakeDirection->y != 1)
        *snakeDirection = (Vector2){0, -1};

    if (IsKeyPressed(KEY_A) && snakeDirection->x != 1)
        *snakeDirection = (Vector2){-1, 0};

    if (IsKeyPressed(KEY_S) && snakeDirection->y != -1)
        *snakeDirection = (Vector2){0, 1};

    if (IsKeyPressed(KEY_D) && snakeDirection->x != -1)
        *snakeDirection = (Vector2){1, 0};
}

void UpdateSnake(Vector2 snake[], Vector2 snakeDirection, int snakeSize) {
    for (int i = snakeSize - 1; i > 0; i--) 
        snake[i] = snake[i - 1];

    snake[0] = Vector2Add(snake[0], snakeDirection);
    snake[0].x = MathModulus(snake[0].x, NUM_CELLS_PER_SIDE);
    snake[0].y = MathModulus(snake[0].y, NUM_CELLS_PER_SIDE);
}
