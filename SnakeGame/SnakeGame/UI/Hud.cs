using Raylib_cs;
using SnakeGame.Game;

namespace SnakeGame.UI;

public static class Hud
{
    public static Color FontColor { get; } = Color.RayWhite;

    public static void Draw(int score)
    {
        var text = $"Score: {score}";
        var textWidth = Raylib.MeasureText(text, GameGrid.CellSize);
        var x = (GameGrid.ScreenSize - textWidth) / 2;
        Raylib.DrawText(text, x, 0, GameGrid.CellSize, FontColor);
    }
}