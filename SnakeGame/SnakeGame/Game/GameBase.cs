using Raylib_cs;

namespace SnakeGame.Game;

public abstract class GameBase
{
    private readonly Dictionary<string, Sound> _sounds = new();

    public void Run()
    {
        Raylib.InitWindow(GameSettings.WindowWidth, GameSettings.WindowHeight, GameSettings.Title);
        Raylib.SetTargetFPS(GameSettings.Fps);
        Raylib.InitAudioDevice();
        
        LoadContent();
        
        while (!Raylib.WindowShouldClose())
        {
            Raylib.BeginDrawing();
            Update();
            Draw();
            Raylib.EndDrawing();
        }
        
        foreach (var sound in _sounds)
        {
            Raylib.UnloadSound(sound.Value);
        }
        
        Raylib.CloseAudioDevice();
        Raylib.CloseWindow();
    }
    
    protected void LoadIcon(string path)
    {
        var icon = Raylib.LoadImage(path);
        Raylib.SetWindowIcon(icon);
        Raylib.UnloadImage(icon);
    }

    protected void LoadSound(string name, string path)
    {
        var sound = Raylib.LoadSound(path);
        _sounds.Add(name, sound);
    }

    protected void PlaySound(string name)
    {
        var sound = _sounds[name];
        Raylib.PlaySound(sound);
    }
    
    protected abstract void LoadContent();
    protected abstract void Update();
    protected abstract void Draw();
}