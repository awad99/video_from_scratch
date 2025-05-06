#include <raylib.h>
#include "String.h"
#include "Reation.h"
#include "Sound.h"

inline void drawAnimation(float elapsedTime, float timelineLen, int screenWidth, int screenHeight)
{
    const int barX = 50;
    const int barY = screenHeight - 80;
    const int barW = screenWidth - 2 * barX;
    const int barH = 8;
    DrawRectangleLines(barX, barY, barW, barH, LIGHTGRAY);

    float progress = elapsedTime / timelineLen;
    DrawRectangle(barX, barY, (int)(barW * progress), barH, LIGHTGRAY);

    int handleX = barX + (int)(barW * progress);
    DrawLine(handleX, barY - 5, handleX, barY + barH + 5, RED);

    // After 9s until 11s, shrink indicator lines into the screen center over 2s
    if (elapsedTime >= 9.0f && elapsedTime <= 11.0f)
    {
        float animT = (elapsedTime - 9.0f) / 2.0f;
        if (animT > 1.0f) animT = 1.0f;

        int centerX = screenWidth / 2;
        int centerY = screenHeight / 2;
        int spacing = 100;            // horizontal gap between lines
        int halfSpacing = spacing / 2;

        const int initialHalfHeight = 100;    // starting vertical half-length
        int halfHeight = (int)(initialHalfHeight * (1.0f - animT));

        float thickness = 4.0f;

        // Draw "edit" above the left line
        const char* leftText = "edit";
        int fontSize = 20;
        int textW = MeasureText(leftText, fontSize);
        DrawText(leftText, centerX - halfSpacing - textW / 2, centerY - halfHeight - 30, fontSize, GREEN);

        // Draw "time" above the right line
        const char* rightText = "time";
        textW = MeasureText(rightText, fontSize);
        DrawText(rightText, centerX + halfSpacing - textW / 2, centerY - halfHeight - 30, fontSize, GREEN);

        // Left shrinking line
        DrawLineEx({ static_cast<float>(centerX - halfSpacing), static_cast<float>(centerY - halfHeight) },
            { static_cast<float>(centerX - halfSpacing), static_cast<float>(centerY + halfHeight) },
            thickness, GREEN);
        // Right shrinking line
        DrawLineEx({ static_cast<float>(centerX + halfSpacing), static_cast<float>(centerY - halfHeight) },
            { static_cast<float>(centerX + halfSpacing), static_cast<float>(centerY + halfHeight) },
            thickness, GREEN);
    }
    // After 11s, lines are fully shrunk (halfHeight=0) and no longer visible
}


int main()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "video1");
    InitAudioDevice();
    float videoStart = -2.0f, video2Start = -24.0f, video3Start = -25.0f, video4Start = -31.0f, video5Start = -46.0f;

    float video6Start = -54.0f, video7Start = -120.0f, video8Start = -150.0f;


    float elapsedTime = 0.0f;
    const float timelineLen = 180.0f; 

    SetTargetFPS(30);
    while (!WindowShouldClose())
    {
        // Update elapsed time
        float delta = GetFrameTime();
        elapsedTime += delta;
        if (elapsedTime > timelineLen) elapsedTime = timelineLen;

        // Compute current time display
        int minutes = (int)(elapsedTime / 60.0f);
        int seconds = (int)elapsedTime % 60;

        BeginDrawing();
        ClearBackground(BLACK);

        // Draw elapsed time
        DrawText(
            TextFormat("Time: %02i:%02i", minutes, seconds),
            20, 20, 24, WHITE
        );

        if (elapsedTime <= 3.0f) {
            // First string at upper position
            const std::string text = Strings::introduction();
            int fontSize = 32;
            int textW = MeasureText(text.c_str(), fontSize);
            int xPos = (screenWidth - textW) / 2;
            int yPos1 = screenHeight / 2 - fontSize;

            DrawText(text.c_str(), xPos, yPos1, fontSize, RED);

            // Second string appears after 1 second, drawn below
            if (elapsedTime >= 1.0f) {
                int yPos2 = screenHeight / 2 + 10;
                DrawText(text.c_str(), xPos, yPos2, fontSize, RED);
            }
        }

        if (elapsedTime >= 3.0f) {
            std::string revealedText = Strings::introduction2(elapsedTime - 3.0f); // offset for start
            int fontSize = 24;
            int textWidth = MeasureText(revealedText.c_str(), fontSize);
            int x = (screenWidth - textWidth) / 2;
            int y = screenHeight / 2 + 300;

            DrawText(revealedText.c_str(), x, y, fontSize, WHITE);
        }

        if (elapsedTime >= 9.0f) {
            // offset so elapsedTime for intro3 is zero at t=9s
            std::string revealed = Strings::introduction3(elapsedTime - 9.0f);
            int fontSize = 24;
            int y = screenHeight / 2 + 300;

            std::istringstream lines(revealed);
            std::string line;
            while (std::getline(lines, line)) {
                int textW = MeasureText(line.c_str(), fontSize);
                int x = (screenWidth - textW) / 2;
                DrawText(line.c_str(), x, y, fontSize, WHITE);
                y += fontSize + 5;
            }
        }
        // 5) Draw reactions (3–5s animated, 6–9s static)
        if (elapsedTime >= 3.0f && elapsedTime < 9.0f)
        {
            drawReactions();
        }
        drawAnimation(elapsedTime, timelineLen, screenWidth, screenHeight);


        drawReactions();
        
        drawReactions2();

        drawReactions3();

        drawReactions4();

        drawReactions5();

        drawReactions6();

        drawReactions6();

        drawReactions7();

        drawReactions8();

        drawReactions9();
       // if (elapsedTime >= 1.0f)
        firstSound();

        if (elapsedTime >= 5.0f && videoStart < 0.0f) {
            videoStart = GetTime();
        }

        // then draw the video:
        if (videoStart >= 0.0f) {
            drawvideo(videoStart);
        }

        if (elapsedTime >= 16.0f)
        {
            secondSound();

            std::string revealed = Strings::startdev(elapsedTime - 17.0f);
            int fontSize = 24;
            int y = screenHeight / 2 + 300;

            std::istringstream lines(revealed);
            std::string line;
            while (std::getline(lines, line)) {
                int textW = MeasureText(line.c_str(), fontSize);
                int x = (screenWidth - textW) / 2;
                DrawText(line.c_str(), x, y, fontSize, WHITE);
                y += fontSize + 5;
            }

        }


        if (elapsedTime >= 80.0f)
        {
            thireddSound();

            std::string revealed = Strings::videodev(elapsedTime - 81.0f);
            int fontSize = 24;
            int y = screenHeight / 2 + 300;

            std::istringstream lines(revealed);
            std::string line;
            while (std::getline(lines, line)) {
                int textW = MeasureText(line.c_str(), fontSize);
                int x = (screenWidth - textW) / 2;
                DrawText(line.c_str(), x, y, fontSize, WHITE);
                y += fontSize + 5;
            }
        }


        if (elapsedTime >= 142.0f)
        {
            fourthSound();
        }
        if (elapsedTime >= 24.0f && video2Start < 0.0f) {
            video2Start = GetTime();
        }

        if (elapsedTime >= 31.0f && video3Start < 0.0f) {
            video3Start = GetTime();
        }

        if (elapsedTime >= 37.0f && video4Start < 0.0f) {
            video4Start = GetTime();
        }

        if (elapsedTime >= 44.0f && video5Start < 0.0f) {
            video5Start = GetTime();
        }

        if (elapsedTime >= 54.0f && video6Start < 0.0f) {  
            video6Start = GetTime();
        }

        if (elapsedTime >= 120.0f && video7Start < 0.0f) {
            video7Start = GetTime();
        }

        if (elapsedTime >= 150.0f && video8Start < 0.0f) {
            video8Start = GetTime();
        }

        if (video2Start >= 0.0f) {
            drawvide2(video2Start);
        }

        if (video3Start >= 0.0f) {
            drawvideo3(video3Start);
        }

        if (video4Start >= 0.0f) {
            drawvideo4(video4Start);
        }

        if (video5Start >= 0.0f) {
            drawvideo5(video5Start);
        }

        if (video6Start >= 0.0f) 
        drawvideo6(video6Start, 24.0f);

        if (video7Start >= 0.0f)
            drawvideo7(video7Start, 20.0f);

        if (video8Start >= 0.0f)
            drawvideo8(video8Start, 29.0f);

        // Draw timeline bar
        const int barX = 50;
        const int barY = screenHeight - 80;
        const int barW = screenWidth - 2 * barX;
        const int barH = 8;
        DrawRectangleLines(barX, barY, barW, barH, LIGHTGRAY);

        float progress = elapsedTime / timelineLen;
        DrawRectangle(barX, barY, (int)(barW * progress), barH, LIGHTGRAY);

        
        int handleX = barX + (int)(barW * progress);
        DrawLine(handleX, barY - 5, handleX, barY + barH + 5, RED);

        EndDrawing();
    }

    unload();
    CloseWindow();
    CloseAudioDevice();
    return 0;
}
