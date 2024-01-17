#pragma once

#include <raylib.h>

class Pipes
{
public:
    Vector2 topLeft;
    Vector2 bottomLeft;
    float width;
    float gapHeight;

    Texture2D topPipeTexture;
    Texture2D bottomPipeTexture;

    Pipes(float x, float pipeSpace, float screenWidth, float screenHeight)
    {
        width = 50.0f;
        gapHeight = 150.0f;

        topPipeTexture = LoadTexture("path_to_top_pipe_texture.png");
        bottomPipeTexture = LoadTexture("path_to_bottom_pipe_texture.png");

        topLeft = {x, 0};
        bottomLeft = {x, screenHeight - gapHeight};

        Move(pipeSpace);

        if(topLeft.x + width < 0)
        {
            Move(screenWidth);
        }
    }

    void Move(float x)
    {
        topLeft.x = x;
        bottomLeft.x = x;

        // Check if the pipes are off-screen and reposition if necessary
        if(topLeft.x + width < 0)
        {
            Move(x + width + gapHeight);
        }
    }

    // Draw the pipes using sprites
    void Draw()
    {
        // Draw the top pipe
        DrawTextureV(topPipeTexture, {topLeft.x, topLeft.y}, WHITE);

        // Draw the bottom pipe
        DrawTextureV(bottomPipeTexture, bottomLeft, WHITE);
    }

    // Unload the textures when the Pipes object is destroyed
    ~Pipes()
    {
        UnloadTexture(topPipeTexture);
        UnloadTexture(bottomPipeTexture);
    }
};
