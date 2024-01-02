#include <raylib.h>

const float gravity = 0.2f;

struct Player
{
    Vector2 position;
    Vector2 velocity;
};

int main()
{
    //float deltaTime = GetFrameTime();
    
    const double screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "Flappy Boi");
    
    Texture2D playerSprite = LoadTexture("player2.png");
    
    Player player;
    player.position = {screenWidth / 2.2, screenHeight / 2};
    player.velocity = {0, 0};
    
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        player.velocity.y += gravity;
        player.position.y += player.velocity.y;
        
        if(player.position.y >= screenHeight - 25)
        {
            player.position.y = screenHeight - 25;
            player.velocity.y = 0;
        }
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(playerSprite, player.position.x, player.position.y, WHITE);
        EndDrawing();
    }
    
    UnloadTexture(playerSprite);
    return 0;
}