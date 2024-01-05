#include <raylib.h>

const float gravity = 0.3f;

float jumpForce = 3.8f;

const int screenWidth = 800; // both should remain as ints
const int screenHeight = 450;

struct Player
{
    Vector2 position;
    Vector2 velocity;
};

int main()
{
    //float deltaTime = GetFrameTime();
    
    InitWindow(screenWidth, screenHeight, "Flappy Boi");
    
    Texture2D playerSprite = LoadTexture("resources/player2.png");
    
    Player player;
    player.position = {screenWidth / 2.3, screenHeight / 2.6};
    player.velocity = {0, 0};
    
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        player.velocity.y += gravity;
        player.position.y += player.velocity.y;
        
        if(player.position.y >= screenHeight - 40)
        {
            player.position.y = screenHeight - 40;
            player.velocity.y = 0;
        }
        else if(player.position.y <= -55)
        {
            player.position.y = -55;
            player.velocity.y = 0;
        }
        
        // there's a small bug that has to be fixed. idk where it is yet, but I have a feeling it's here
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE))
        {
            player.velocity.y -= jumpForce / (gravity);
            player.position.y += player.velocity.y;
        }
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            DrawTexture(playerSprite, player.position.x, player.position.y, WHITE);
        EndDrawing();
    }
    
    UnloadTexture(playerSprite);
    return 0;
}