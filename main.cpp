#include <raylib.h>

/*void Player(Texture2D player, int y, double gravity)
{
    playerY += gravity;
}*/

struct Player
{
    Vector2 position;
    Vector2 velocity;
};

int main()
{
    float deltaTime = GetFrameTime();
    
    const int screenWidth = 1280;
    const int screenHeight = 720;
    
    const float gravity;
    
    InitWindow(screenWidth, screenHeight, "Flappy Boi");
    
    Texture2D playerSprite = LoadTexture("player2.png");
    
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
            DrawTexture(playerSprite, playerX / 2, playerY /2, WHITE);
        EndDrawing();
    }
    
    UnloadTexture(playerSprite);
    return 0;
}