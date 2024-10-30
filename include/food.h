#ifndef FOOD_H
#define FOOD_H

#include <raylib.h>

#include "snake.h"

void InitializeNewFood(Vector2* food, Snake* snake);
void DrawFood(Vector2 food);

#endif
