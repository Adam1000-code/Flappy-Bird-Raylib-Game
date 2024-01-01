// this is going to be a flappy bird game bc raylib is hard to use for anything else
#include <raylib.h>
#include <iostream>

using namespace std;

// this defines the screen. touch and you will die
const int screenWidth = 800;
const int screenHeight = 450;

const double playerX;
double playerY;

int main()
{
    // but why aren't the screen width and height defined IN the main function?
    // don't ask why. js go with the flow
    InitWindow(screenWidth, screenHeight, "Flappy Boi");
    
    // tha main gooberoo. delete this and I delete you
    Texture2D player = LoadTexture("player.png");
    
    // the target FPS. change it and I will murder you
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
            
        EndDrawing();
    }
    
    return 0;
}

void pipes(int x, int y)
{
}

void player(const int gravity, double y )
{
}