using System.Numerics;
using Raylib_cs;
using SnakeGame.Core;

namespace SnakeGame.Entities;

public class Snake
{
    public int Size { get; private set; } = 1;
    public bool IsDead { get; private set; }
    public Color Color { get; } = new Color(192, 255, 131, 255);
    
    private readonly Vector2[] _body = new Vector2[Grid.ScreenSize];
    private Vector2 _direction = new Vector2(1, 0);

    public void Update()
    {
        if (Raylib.IsKeyPressed(KeyboardKey.W) && _direction.Y != 1)
        {
            _direction = new Vector2(0, -1);
        }
        else if (Raylib.IsKeyPressed(KeyboardKey.A) && _direction.X != 1)
        {
            _direction = new Vector2(-1, 0);
        }
        else if (Raylib.IsKeyPressed(KeyboardKey.S) && _direction.Y != -1)
        {
            _direction = new Vector2(0, 1);
        }
        else if (Raylib.IsKeyPressed(KeyboardKey.D) && _direction.X != -1)
        {
            _direction = new Vector2(1, 0);
        }
        
        for (var i = Size - 1; i > 0; i--)
        {
            _body[i] = _body[i - 1];
        }
        
        _body[0].X = (_body[0].X + _direction.X + Grid.NumCellsPerSide) % Grid.NumCellsPerSide;
        _body[0].Y = (_body[0].Y + _direction.Y + Grid.NumCellsPerSide) % Grid.NumCellsPerSide;
    }
    
    public void Draw()
    {
        for (var i = 0; i < Size; i++)
        {
            var x = (int)_body[i].X * Grid.CellSize;
            var y = (int)_body[i].Y * Grid.CellSize;
            Raylib.DrawRectangle(x, y, Grid.CellSize, Grid.CellSize, Color);
        }
    }

    public void Grow()
    {
        _body[Size] = _body[Size - 1];
        Size++;
    }

    public void Kill()
    {
        IsDead = true;
    }
    
    public bool IsSelfColliding()
    {
        return _body.Skip(1).Take(Size - 1).Any(x => x.Equals(_body[0]));
    }
    
    public bool IsEating(Food food)
    {
        return _body.Take(Size).Any(x => x.Equals(food.Position));
    }
}