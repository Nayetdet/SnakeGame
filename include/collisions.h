#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <stdbool.h>

#include <raylib.h>

bool IsSnakeHeadCollidingWithFood(Vector2 snakeHead, Vector2 food);
bool IsSnakeBodyColliding(Vector2 snake[], Vector2 segment, int snakeSize);
bool IsSnakeBodySelfColliding(Vector2 snake[], int snakeSize);

#endif
