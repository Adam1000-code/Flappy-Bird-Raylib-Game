#pragma once

#include <raylib.h>

class Pipes
{
public:
    Vector2 topLeft;    // Top-left corner of the pipe
    Vector2 bottomLeft; // Bottom-left corner of the pipe
    float width;
    float gapHeight;     // Height of the gap between pipes

    Texture2D topPipeTexture;
    Texture2D bottomPipeTexture;

    Pipes(float x, float pipeSpace, float screenWidth, float screenHeight)
    {
        width = 50.0f; // Adjust the width as needed
        gapHeight = 150.0f; // Adjust the gap height as needed

        // Load texture for the pipes
        topPipeTexture = LoadTexture("path_to_top_pipe_texture.png");
        bottomPipeTexture = LoadTexture("path_to_bottom_pipe_texture.png");

        // Initialize the top and bottom pipes' positions
        topLeft = { x, 0 };
        bottomLeft = { x, screenHeight - gapHeight };

        // Set initial positions based on the pipeSpace parameter
        Move(pipeSpace);

        // Check if the pipes are off-screen and reposition if necessary
        if(topLeft.x + width < 0)
        {
            Move(screenWidth);
        }
    }

    // Move the pipes to the right, repositioning them if they go off-screen
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
        DrawTextureV(topPipeTexture, { topLeft.x, topLeft.y }, WHITE);

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
