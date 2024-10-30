#include <stdlib.h>

#include <raylib.h>
#include <raymath.h>

#include "collisions.h"
#include "constants.h"
#include "snake.h"

#include "food.h"

void InitializeNewFood(Vector2* food, Snake* snake) {
    do {
        food->x = rand() % NUM_CELLS_PER_SIDE;
        food->y = rand() % NUM_CELLS_PER_SIDE;
    } while(IsSnakeColliding(snake, *food));
}

void DrawFood(Vector2 food) {
    int x = (food.x) * CELL_SIZE;
    int y = (food.y) * CELL_SIZE;
    DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, APPLE_COLOR);
}
