using SnakeGame.Core;

namespace SnakeGame.Game;

public static class GameSettings
{
    public const string Title = "Snake";
    public const int Fps = 12;
    
    public static int WindowWidth => Grid.ScreenSize;
    public static int WindowHeight => Grid.ScreenSize;
}