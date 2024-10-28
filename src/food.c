#include <stdlib.h>

#include <raylib.h>
#include <raymath.h>

#include "config.h"
#include "collisions.h"
#include "food.h"

Vector2 GenerateNewFood(Vector2 snake[], int snakeSize) {
    Vector2 food;
    do {
        food.x = rand() % NUM_CELLS_PER_SIDE;
        food.y = rand() % NUM_CELLS_PER_SIDE;
    } while(IsSnakeBodyColliding(snake, food, snakeSize));
    return food;
}

void DrawFood(Vector2 food) {
    int x = (food.x) * CELL_SIZE;
    int y = (food.y) * CELL_SIZE;
    DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, APPLE_COLOR);
}
