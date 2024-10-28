#include "config.h"
#include "utils.h"

const char* GetTitle(int score) {
    return TextFormat("Snake Game - Score: %d", score);
}

void DrawBackgroundGrid(void) {
    DrawRectangleLines(0, 0, SCREEN_SIZE, SCREEN_SIZE, BACKGROUND_COLOR);
    for (int i = 0; i < SCREEN_SIZE; i += CELL_SIZE) {
        DrawLine(0, i, SCREEN_SIZE, i, BACKGROUND_COLOR);
        DrawLine(i, 0, i, SCREEN_SIZE, BACKGROUND_COLOR);
    }
}

void DisplayGameOverMessage(void) {
    const int fontSize = 24;
    const char* message = "Game Over! Press R to restart";

    int textWidth = MeasureText(message, fontSize);
    int x = (SCREEN_SIZE - textWidth) / 2;
    int y = (SCREEN_SIZE - fontSize) / 2;
    DrawText(message, x, y, fontSize, APPLE_COLOR);
}

int MathModulus(int a, int b) {
    if (b < 0) {
        return -MathModulus(-a, -b);
    }

    int ret = a % b;
    return ret >= 0 ? ret : ret + b;
}
