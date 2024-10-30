#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <stdbool.h>

#include <raylib.h>

#include "snake.h"

bool IsSnakeSegmentColliding(Vector2 snakeSegment, Vector2 other);
bool IsSnakeColliding(Snake* snake, Vector2 other);
bool IsSnakeSelfColliding(Snake* snake);

#endif
