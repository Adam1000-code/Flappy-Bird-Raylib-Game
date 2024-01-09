#pragma once

#include <raylib.h>

class Pipes
{
    public:
        Vector2 topLeft;
        Vector2 bottomLeft;
        float width = 4;
        float gapHeight = 2;
            
        Texture2D topPipeTexture;
        Texture2D bottomPipeTexture;

        Pipes(float x, float pipeSpace, float screenWidth, float screenHeight)
        {
            width = 50.0f;
            gapHeight = 150.0f;
                
            topPipeTexture = LoadTexture("resources/pipe_u.png");
            bottomPipeTexture = LoadTexture("resources/pipe_d.png");
                
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

            if(topLeft.x + width < 0)
            {
                Move(x + width + gapHeight);
            }
        }
            
        void Draw()
        {
            DrawTextureV(topPipeTexture, {topLeft.x, topLeft.y}, WHITE);
            DrawTextureV(bottomPipeTexture, bottomLeft, WHITE);
        }
        
        ~Pipes()
        {
            UnloadTexture(topPipeTexture);
            UnloadTexture(bottomPipeTexture);
        }
};