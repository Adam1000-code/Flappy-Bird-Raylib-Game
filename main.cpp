#include <raylib.h>

const float gravity = 0.2f;

float jumpForce = (2.1f);

const double screenWidth = 800;
const double screenHeight = 450;

struct Player
{
    Vector2 position;
    Vector2 velocity;
};

int main()
{
    //float deltaTime = GetFrameTime();
    
    InitWindow(screenWidth, screenHeight, "Flappy Boi");
    
    Texture2D playerSprite = LoadTexture("player2.png");
    
    Player player;
    player.position = {screenWidth / 2.3, screenHeight / 2.6};
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
        
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE))
        {
            player.velocity.y -= jumpForce * gravity;
        }
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            DrawTexture(playerSprite, player.position.x, player.position.y, WHITE);
        EndDrawing();
    }
    
    UnloadTexture(playerSprite);
    return 0;
}