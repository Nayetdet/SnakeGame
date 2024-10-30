#include <stdbool.h>

#include <raylib.h>
#include <raymath.h>

#include "snake.h"

#include "collisions.h"

bool IsSnakeSegmentColliding(Vector2 snakeSegment, Vector2 other) {
    return Vector2Equals(snakeSegment, other);
}

bool IsSnakeSubsequenceColliding(
    Vector2 snakeBody[],
    Vector2 other,
    int startIndex,
    int endIndex
) {
    for (int i = startIndex; i < endIndex; i++) {
        if (IsSnakeSegmentColliding(snakeBody[i], other)) {
            return true;
        }
    }
    return false;
}

bool IsSnakeColliding(Snake* snake, Vector2 other) {
    return IsSnakeSubsequenceColliding(snake->body, other, 0, snake->size);
}

bool IsSnakeSelfColliding(Snake* snake) {
    return IsSnakeSubsequenceColliding(snake->body, snake->body[0], 1, snake->size - 1);
}
