#include <stdbool.h>

#include <raylib.h>
#include <raymath.h>

#include "collisions.h"

bool IsSnakeSegmentColliding(Vector2 snakeSegment, Vector2 other) {
    return Vector2Equals(snakeSegment, other);
}

bool IsSnakeHeadCollidingWithFood(Vector2 snakeHead, Vector2 food) {
    return IsSnakeSegmentColliding(snakeHead, food);
}

bool IsSnakeBodySubsequenceColliding(Vector2 snake[], Vector2 other, int snakeSize, int tailIndex) {
    for (int i = tailIndex; i < snakeSize; i++) {
        if (IsSnakeSegmentColliding(snake[i], other)) {
            return true;
        }
    }
    return false;
}

bool IsSnakeBodyColliding(Vector2 snake[], Vector2 other, int snakeSize) {
    return IsSnakeBodySubsequenceColliding(snake, other, snakeSize, 0);
}

bool IsSnakeBodySelfColliding(Vector2 snake[], int snakeSize) {
    return IsSnakeBodySubsequenceColliding(snake, snake[0], snakeSize - 1, 1);
}
