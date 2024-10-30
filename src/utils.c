#include "constants.h"
#include "food.h"

#include "utils.h"

void DrawBackgroundGrid(void) {
    DrawRectangleLines(0, 0, SCREEN_SIZE, SCREEN_SIZE, BORDER_COLOR);
    for (int i = 0; i < SCREEN_SIZE; i += CELL_SIZE) {
        DrawLine(0, i, SCREEN_SIZE, i, BORDER_COLOR);
        DrawLine(i, 0, i, SCREEN_SIZE, BORDER_COLOR);
    }
}

void DisplayGameOverMessage(void) {
    const int fontSize = 36;
    const char* message = "Game Over! Press R to restart";

    int textWidth = MeasureText(message, fontSize);
    int x = (SCREEN_SIZE - textWidth) / 2;
    int y = (SCREEN_SIZE - fontSize) / 2;
    DrawText(message, x, y, fontSize, APPLE_COLOR);
}

void DisplayPlayerScore(int score) {
    const char* message = TextFormat("Score: %d", score);
    int textWidth = MeasureText(message, CELL_SIZE);
    int x = (SCREEN_SIZE - textWidth) / 2;
    DrawText(message, x, 0, CELL_SIZE, RAYWHITE);
}
