using Raylib_cs;

namespace SnakeGame.Core;

public static class Grid
{
    public const int CellSize = 25;
    public const int NumCellsPerSide = 25;
    public static int ScreenSize => CellSize * NumCellsPerSide;
    
    public static Color BackgroundColor { get; } = new Color(31, 27, 40, 255);
    public static Color BorderColor { get; } = new Color(58, 53, 63, 255);
    
    public static void Draw()
    {
        Raylib.ClearBackground(BackgroundColor);
        Raylib.DrawRectangleLines(0, 0, ScreenSize, ScreenSize, BorderColor);
        
        for (var i = 0; i < ScreenSize; i += CellSize)
        {
            Raylib.DrawLine(0, i, ScreenSize, i, BorderColor);
            Raylib.DrawLine(i, 0, i, ScreenSize, BorderColor);
        }
    }
}