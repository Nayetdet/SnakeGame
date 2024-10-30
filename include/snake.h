#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#include <raylib.h>

#include "constants.h"

typedef struct Snake {
    int size;
    bool isAlive;
    Vector2 body[SCREEN_SIZE];
    Vector2 direction;
} Snake;

void InitializeNewSnake(Snake* snake);
void DrawSnake(Snake* snake);
void ChangeSnakeDirection(Snake* snake);
void UpdateSnake(Snake* snake);

#endif
