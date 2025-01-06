using System.Numerics;
using Raylib_cs;
using SnakeGame.Game;

namespace SnakeGame.Entities;

public class Snake
{
    public int Score => _body.Count - 1;
    public bool IsDead { get; private set; }
    public Color Color { get; } = new(192, 255, 131, 255);

    private readonly LinkedList<Vector2> _body = new(new[] { Vector2.Zero });
    private Vector2 _direction = new(1, 0);

    private Vector2 Head => _body.First!.Value;
    private Vector2 Tail => _body.Last!.Value;

    public void Update()
    {
        if (Raylib.IsKeyPressed(KeyboardKey.W) && (int)_direction.Y != 1)
        {
            _direction = new Vector2(0, -1);
        }
        else if (Raylib.IsKeyPressed(KeyboardKey.A) && (int)_direction.X != 1)
        {
            _direction = new Vector2(-1, 0);
        }
        else if (Raylib.IsKeyPressed(KeyboardKey.S) && (int)_direction.Y != -1)
        {
            _direction = new Vector2(0, 1);
        }
        else if (Raylib.IsKeyPressed(KeyboardKey.D) && (int)_direction.X != -1)
        {
            _direction = new Vector2(1, 0);
        }

        var newHead = new Vector2(
            (Head.X + _direction.X + GameGrid.NumCellsPerSide) % GameGrid.NumCellsPerSide,
            (Head.Y + _direction.Y + GameGrid.NumCellsPerSide) % GameGrid.NumCellsPerSide
        );

        _body.AddFirst(newHead);

        if (_body.Count > 1)
        {
            _body.RemoveLast();
        }
    }

    public void Draw()
    {
        foreach (var segment in _body)
        {
            var x = (int)segment.X * GameGrid.CellSize;
            var y = (int)segment.Y * GameGrid.CellSize;
            Raylib.DrawRectangle(x, y, GameGrid.CellSize, GameGrid.CellSize, Color);
        }
    }

    public void Grow()
    {
        _body.AddLast(Tail);
    }

    public void Kill()
    {
        IsDead = true;
    }

    public bool IsSelfColliding()
    {
        return _body.Skip(1).Any(x => x.Equals(Head));
    }

    public bool IsEating(Food food)
    {
        return _body.Any(x => x.Equals(food.Position));
    }
}