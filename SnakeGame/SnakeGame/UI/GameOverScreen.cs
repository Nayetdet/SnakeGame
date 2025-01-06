using Raylib_cs;
using SnakeGame.Game;

namespace SnakeGame.UI;

public static class GameOverScreen
{
    public const int FontSize = 36;
    public static Color FontColor { get; } = new(211, 85, 86, 255);
    
    public static void Draw()
    {
        const string text = "Game Over! Press R to restart";
        var textWidth = Raylib.MeasureText(text, FontSize);
        var x = (GameGrid.ScreenSize - textWidth) / 2;
        var y = (GameGrid.ScreenSize - FontSize) / 2;
        Raylib.DrawText(text, x, y, FontSize, FontColor);        
    }
}