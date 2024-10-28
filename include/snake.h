#ifndef SNAKE_H
#define SNAKE_H

#include <stdbool.h>

#include <raylib.h>

void DrawSnake(Vector2 snake[], int snakeSize);
void ChangeSnakeDirection(Vector2* snakeDirection);
void UpdateSnake(Vector2 snake[], Vector2 snakeDirection, int snakeSize);

#endif
