using Raylib_cs;
using SnakeGame.Core;

namespace SnakeGame.UI;

public static class Hud
{
    public static Color FontColor { get; } = Color.RayWhite;

    public static void Draw(int score)
    {
        var text = $"Score: {score}";
        var textWidth = Raylib.MeasureText(text, Grid.CellSize);
        var x = (Grid.ScreenSize - textWidth) / 2;
        Raylib.DrawText(text, x, 0, Grid.CellSize, FontColor);
    }
}