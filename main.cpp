#include <raylib.h>

const int screenWidth = 1280;
const int screenHeight = 720;

const double playerX = 0;
double playerY;
const double gameGravity = 2;

void Player(Texture2D player, int y, double gravity)
{
    DrawTexture(player, 0 / 2, y, WHITE);
}

int main()
{
    playerY = screenHeight;
    InitWindow(screenWidth, screenHeight, "Flappy Boi");
    
    Texture2D playerSprite = LoadTexture("player.png");
    
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
            Player(playerSprite, playerY / 1.8, gameGravity);
        EndDrawing();
    }
    
    UnloadTexture(playerSprite);
    return 0;
}