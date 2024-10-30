#include <stdbool.h>

#include <raylib.h>
#include <raymath.h>

#include "constants.h"

#include "snake.h"

void InitializeNewSnake(Snake* snake) {
    snake->size = 1;
    snake->isAlive = true;
    snake->body[0] = Vector2Zero();
    snake->direction = (Vector2){1, 0};
}

void DrawSnake(Snake* snake) {
    for (int i = 0; i < snake->size; i++) {
        int x = snake->body[i].x * CELL_SIZE;
        int y = snake->body[i].y * CELL_SIZE;
        DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, SNAKE_COLOR);
    }
}

void ChangeSnakeDirection(Snake* snake) {
    if (IsKeyPressed(KEY_W) && snake->direction.y != 1)
        snake->direction = (Vector2){0, -1};
    else if (IsKeyPressed(KEY_A) && snake->direction.x != 1)
        snake->direction = (Vector2){-1, 0};
    else if (IsKeyPressed(KEY_S) && snake->direction.y != -1)
        snake->direction = (Vector2){0, 1};
    else if (IsKeyPressed(KEY_D) && snake->direction.x != -1)
        snake->direction = (Vector2){1, 0};
}

void UpdateSnake(Snake* snake) {
    for (int i = snake->size - 1; i > 0; i--)
        snake->body[i] = snake->body[i - 1];

    snake->body[0] = Vector2Add(snake->body[0], snake->direction);
    snake->body[0].x = ((int)snake->body[0].x + NUM_CELLS_PER_SIDE) % NUM_CELLS_PER_SIDE;
    snake->body[0].y = ((int)snake->body[0].y + NUM_CELLS_PER_SIDE) % NUM_CELLS_PER_SIDE;
}
