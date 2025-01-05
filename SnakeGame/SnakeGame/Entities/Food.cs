using System.Numerics;
using Raylib_cs;
using SnakeGame.Core;

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
            var x = random.Next(Grid.NumCellsPerSide);
            var y = random.Next(Grid.NumCellsPerSide); 
            Position = new Vector2(x, y);
        } while (snake.IsEating(this));
    }
    
    public void Draw()
    {
        var x = (int)Position.X * Grid.CellSize;
        var y = (int)Position.Y * Grid.CellSize;
        Raylib.DrawRectangle(x, y, Grid.CellSize, Grid.CellSize, Color);
    }
}