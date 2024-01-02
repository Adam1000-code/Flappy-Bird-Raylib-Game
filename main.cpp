// this is going to be a flappy bird game bc raylib is hard to use for anything else
#include <raylib.h>

// this defines the screen. touch and you will die
const int screenWidth = 1280;
const int screenHeight = 720;

const double playerX = 0;
double playerY;
const double gameGravity = 2;

void Player(Texture2D player, int y, double gravity)
{
    DrawTexture(player, 0, y, WHITE);
}

int main()
{
    playerY = screenHeight;
    // but why aren't the screen width and height defined IN the main function?
    // don't ask why. js go with the flow
    InitWindow(screenWidth, screenHeight, "Flappy Boi");
    
    // tha main gooberoo. delete this and I delete you
    Texture2D playerSprite = LoadTexture("player.png");
    
    // the target FPS. change it and I will murder you
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
            Player(playerSprite, playerY / 2, gameGravity);
        EndDrawing();
    }
    
    UnloadTexture(playerSprite);
    return 0;
}