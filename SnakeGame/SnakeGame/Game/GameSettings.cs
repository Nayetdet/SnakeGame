namespace SnakeGame.Game;

public static class GameSettings
{
    public const string Title = "Snake";
    public const int Fps = 15;
    
    public static int WindowWidth => GameGrid.ScreenSize;
    public static int WindowHeight => GameGrid.ScreenSize;
}