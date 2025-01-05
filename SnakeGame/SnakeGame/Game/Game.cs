using Raylib_cs;
using SnakeGame.Core;
using SnakeGame.Entities;
using SnakeGame.UI;

namespace SnakeGame.Game;

public class Game : GameBase
{
    private Snake _snake;
    private Food _food;

    public Game()
    {
        _snake = new Snake();
        _food = new Food(_snake);
    }

    protected override void LoadContent()
    {
        LoadIcon("Assets/Images/icon.png");
        LoadSound("Death", "Assets/Sounds/death.wav");
        LoadSound("Eat", "Assets/Sounds/eat.wav");
    }

    protected override void Update()
    {
        if (_snake.IsDead)
        {
            if (Raylib.IsKeyPressed(KeyboardKey.R))
            {
                _snake = new Snake();
                _food = new Food(_snake);
            }
            
            return;
        }
        
        _snake.Update();

        if (_snake.IsSelfColliding())
        {
            _snake.Kill();
            PlaySound("Death");
        }
        
        if (_snake.IsEating(_food))
        {
            _snake.Grow();
            _food = new Food(_snake);
            PlaySound("Eat");
        }
    }
    
    protected override void Draw()
    {
        Grid.Draw();
        
        _food.Draw();
        _snake.Draw();
        
        Hud.Draw(_snake.Size - 1);

        if (_snake.IsDead)
        {
            GameOverScreen.Draw();
        }
    }
}