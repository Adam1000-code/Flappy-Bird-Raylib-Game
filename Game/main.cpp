#include <raylib.h>

const float gravity = 0.3f;

float jumpForce = 3.8f;

const int screenWidth = 800; // both should remain as ints
const int screenHeight = 450;

Vector2 topLeft;
Vector2 bottomLeft;
float width = 50.0f;
float gapHeight = 100.0f;

struct Player
{
    Vector2 position;
    Vector2 velocity;
};

void Move(float x, float gapSpace)
{
    topLeft.x += x;
    bottomLeft.x += x;

    if(topLeft.x + width < 0)
    {
        topLeft.x += width + gapSpace;
        bottomLeft.x += width + gapSpace;
    }
}

void Pipes(float x, float pipeSpace, float screenWidth, float screenHeight)
{
    pipeSpace = -2.0f;
    if(topLeft.x == 0 && bottomLeft.x == 0)
    {
        topLeft = { x, 0 };
        bottomLeft = { x, screenHeight + gapHeight };
    }
    
    Move(pipeSpace, gapHeight * GetFrameTime());

    if(topLeft.x + width < 0)
    {
        Move(screenWidth, gapHeight);
    }
}

int main()
{
    //float deltaTime = GetFrameTime();
    
    InitWindow(screenWidth, screenHeight, "Flappy Clone");
    
    Texture2D topPipeTexture = LoadTexture("game/resources/pipe_up.png");
    Texture2D bottomPipeTexture = LoadTexture("game/resources/pipe_down.png");
    Texture2D playerSprite = LoadTexture("game/resources/player2.png");
    
    Player player;
    player.position = { screenWidth / 2.3, screenHeight / 2.6 };
    player.velocity = { 0, 0 };
    
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        Pipes(screenWidth, 200.0f, screenWidth, screenHeight); // originally 200.0f
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
        
        //Move(-2.0f, gapHeight * GetFrameTime());
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTextureV(topPipeTexture, {topLeft.x, topLeft.y}, WHITE);
            DrawTextureV(bottomPipeTexture, bottomLeft, WHITE);
            DrawTexture(playerSprite, player.position.x, player.position.y, WHITE);
        EndDrawing();
    }
    
    UnloadTexture(topPipeTexture);
    UnloadTexture(bottomPipeTexture);
    UnloadTexture(playerSprite);
    
    CloseWindow();
    
    return 0;
}