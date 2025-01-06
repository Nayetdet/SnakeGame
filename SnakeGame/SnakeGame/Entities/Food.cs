using System.Numerics;
using Raylib_cs;
using SnakeGame.Game;

namespace SnakeGame.Entities;

public class Food
{
    public Vector2 Position { get; }
    public Color Color { get; } = new(211, 85, 86, 255);

    public Food(Snake snake)
    {
        var random = new Random();
        do
        {
            var x = random.Next(GameGrid.NumCellsPerSide);
            var y = random.Next(GameGrid.NumCellsPerSide); 
            Position = new Vector2(x, y);
        } while (snake.IsEating(this));
    }
    
    public void Draw()
    {
        var x = (int)Position.X * GameGrid.CellSize;
        var y = (int)Position.Y * GameGrid.CellSize;
        Raylib.DrawRectangle(x, y, GameGrid.CellSize, GameGrid.CellSize, Color);
    }
}