#pragma once

#include <iostream>
#include <raylib.h>
#include <iomanip>

#include <thread>
#include <mutex>

bool loaded1 = false, loaded2 = false, loaded3, loaded4 = false, loaded5 = false, loaded6 = false, loaded7 = false, loaded8 = false, loaded9 = false, loaded10 = false, loaded11 = false, loaded12 = false;
bool loaded13 = false, loaded14, loaded15 = false, loaded16 = false, loaded17 = false;
Texture2D tex1, tex2,tex3,tex4,tex5,tex6,tex7,tex8,tex9, tex10, tex11, tex12,tex13,tex14,tex15,tex16, tex17;

template <typename T>
inline T clamp(T value, T min, T max) {
    return (value < min) ? min : (value > max) ? max : value;
}



inline void drawReactions()
{
   

    // Load textures once
    if (!loaded1)
    {
        tex1 = LoadTexture("image/Reaction_1.png");
        if (tex1.id == 0) std::cerr << "[drawReactions] Failed to load 'image/Reaction_1.png'" << std::endl;
        loaded1 = true;
    }
    if (!loaded2)
    {
        tex2 = LoadTexture("image/Reaction_2.jpg");
        if (tex2.id == 0) std::cerr << "[drawReactions] Failed to load 'image/Reaction_2.jpg'" << std::endl;
        loaded2 = true;
    }
    float t = GetTime();  // seconds since InitWindow
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();
   
    // 1) Reaction_1: animate from right → middle-left over 3–4s, stays until 5s
    if (t >= 3.0f && t <= 5.0f && tex1.id != 0)
    {
        float animTime = t - 3.0f;
        if (animTime > 1.0f) animTime = 1.0f;
        float startX = (float)sw;
        float endX = sw * 0.25f - tex1.width * 0.5f;
        float x = startX + (endX - startX) * animTime;
        int y = (sh - tex1.height) / 2;
        DrawTexture(tex1, (int)x, y, WHITE);
    }


    if (t >= 3.0f && t <= 4.0f && tex2.id != 0)
    {
        float x = (sw - tex2.width) / 2;
        float y = (sh - tex2.height) / 2;
        DrawTextureEx(tex2, { x, y, },0.0f,0.5f, WHITE);
    }
}

inline void drawReactions2()
{
    if (!loaded3)
    {
        tex3 = LoadTexture("image/art.jpg");
        if (tex3.id == 0) std::cerr << "[drawReactions] Failed to load 'image/art.jpg'" << std::endl;
        loaded3 = true;
    }

    if (!loaded4)
    {
        tex4 = LoadTexture("image/adobe.png");
        if (tex4.id == 0) std::cerr << "[drawReactions] Failed to load 'image/adobe.png'" << std::endl;
        loaded4 = true;
    }

    if (!loaded5)
    {
        tex5 = LoadTexture("image/OpenGL.png");
        if (tex5.id == 0) std::cerr << "[drawReactions] Failed to load 'image/OpenGL.png'" << std::endl;
        loaded5 = true;
    }

    float t = GetTime();  // seconds since InitWindow
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();
    if (t >= 18.0f && t <= 19.0f && tex3.id != 0)
    {
        float x = (sw - tex3.width) / 2 ;
        float y = (sh - tex3.height) / 2;
        DrawTextureEx(tex3, { x, y, }, 0.0f, 1.0f, WHITE);
    }

    if (t >= 20.0f && t <= 21.0f && tex4.id != 0)
    {
        float x = (sw - tex4.width) / 2;
        float y = (sh - tex4.height) / 2;
        DrawTextureEx(tex4, { x , y, }, 0.0f, 1.0f, WHITE);
    }

    if (t >= 23.0f && t <= 24.0f && tex5.id != 0)
    {
        float x = (sw - tex5.width) / 2;
        float y = (sh - tex5.height) / 2;
        DrawTextureEx(tex5, { x, y , }, 0.0f, 0.5f, WHITE);
    }
}

inline void drawReactions3()
{
    if (!loaded6)
    {
        tex6 = LoadTexture("image/raylib.jpg");
        if (tex6.id == 0) std::cerr << "[drawReactions] Failed to load 'image/raylib.jpg'" << std::endl;
        loaded6 = true;
    }

    float t = GetTime();  // seconds since InitWindow
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();
    if (t >= 30.0f && t <= 31.0f && tex6.id != 0)
    {
        float x = (sw - tex6.width) / 2;
        float y = (sh - tex6.height) / 2;
        DrawTextureEx(tex6, { x , y}, 0.0f, 1.0f, WHITE);
    }

}

inline void drawReactions4()
{
    if (!loaded7)
    {
        tex7 = LoadTexture("image/TimeLine.jpg");
        if (tex7.id == 0) std::cerr << "[drawReactions] Failed to load 'image/TimeLine.jpg'" << std::endl;
        loaded7 = true;
    }

    float t = GetTime();  // seconds since InitWindow
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();
    if (t >= 44.0f && t <= 45.0f && tex6.id != 0)
    {
        float x = (sw - tex7.width) / 2;
        float y = (sh - tex7.height) / 2;
        DrawTextureEx(tex7, { x - 100, y }, 0.0f, 1.5f, WHITE);
    }

}

inline void drawReactions5()
{
    if (!loaded8)
    {
        tex8 = LoadTexture("image/deltaTime.jpg");
        if (tex8.id == 0) std::cerr << "[drawReactions] Failed to load 'image/TimeLine.jpg'" << std::endl;
        loaded8 = true;
    }

    float t = GetTime();  // seconds since InitWindow
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();
    if (t >= 54.0f && t <= 56.0f && tex8.id != 0)
    {
        float x = (sw - tex8.width) / 2;
        float y = (sh - tex8.height) / 2;
        DrawTextureEx(tex8, { x - 100, y }, 0.0f, 1.5f, WHITE);
    }

}

inline void drawReactions6()
{
    if (!loaded6)
    {
        tex6 = LoadTexture("image/raylib.jpg");
        if (tex6.id == 0) std::cerr << "[drawReactions6] Failed to load 'image/raylib.jpg'" << std::endl;
        loaded6 = true;
    }

    if (!loaded9)
    {
        tex9 = LoadTexture("image/cpp_file.png");
        if (tex9.id == 0) std::cerr << "[drawReactions] Failed to load 'image/cpp_file.png'" << std::endl;
        loaded9 = true;
    }

    if (!loaded10)
    {
        tex10 = LoadTexture("image/arbic-line.jpg");
        if (tex10.id == 0) std::cerr << "[drawReactions] Failed to load 'image/arbic-line.jpg'" << std::endl;
        loaded10 = true;
    }

    if (!loaded11)
    {
        tex11 = LoadTexture("image/point.png");
        if (tex11.id == 0) std::cerr << "[drawReactions] Failed to load 'image/point.png'" << std::endl;
        loaded11 = true;
    }

    float t = GetTime();  // seconds since InitWindow
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();
    if (t >= 84.0f && t <= 86.0f && tex9.id != 0)
    {
        float x = (sw - tex9.width) / 2;
        float y = (sh - tex9.height) / 2;

        // Draw image
        DrawTextureEx(tex9, { x, y }, 0.0f, 1.0f, WHITE);


        const char* label = "Script";
        int fontSize = 24;
        int textWidth = MeasureText(label, fontSize);
        int textX = (sw - textWidth) / 2;
        int textY = static_cast<int>(y) - fontSize - 10; // 10 pixels above the image

        DrawText(label, textX, textY, fontSize, WHITE);
    }

    if (t >= 86.0f && t <= 88.0f && tex10.id != 0)
    {
        float x = 0;
        float y = 0;

        // Draw image
        DrawTextureEx(tex10, { x, y }, 0.0f, 2.0f, WHITE);
    }

    if (t >= 91.0f && t <= 93.0f && tex9.id != 0)
    {
        float x = (sw - tex9.width) / 2;
        float y = (sh - tex9.height) / 2;

        // Draw image
        DrawTextureEx(tex9, { x, y }, 0.0f, 1.0f, WHITE);
        DrawTextureEx(tex9, { x - 200, y }, 0.0f, 1.0f, WHITE);
        // Draw "Script" above the image
        const char* label = "Script";
        const char* label2 = "images";
        int fontSize = 24;
        int textWidth = MeasureText(label, fontSize);
        int textX = (sw - textWidth) / 2;
        int textY = static_cast<int>(y) - fontSize - 10; // 10 pixels above the image

        DrawText(label, textX, textY, fontSize, WHITE);
        DrawText(label2, textX - 200, textY, fontSize, WHITE);
    }

    if (t >= 95.0f && t <= 97.0f && tex9.id != 0)
    {
        float x = 0;
        float y = 0;

        const char label3[] = "LoadTexture(\"image / cpp_file.png\");";
        int fontSize = 24;
        int textWidth = MeasureText(label3, fontSize);
        int textX = 600;
        int textY = 0; // 10 pixels above the image
        // Draw image
        DrawTextureEx(tex9, { x + 200, y + 400 }, 0.0f, 1.0f, WHITE);

        DrawTextureEx(tex11, { x + 600, y + 400 }, 0.0f, 1.0f, WHITE);

        DrawText(label3, textX + 400, textY + 500, fontSize, WHITE);
    }

    if (t >= 97.0f && t <= 102.0f && tex9.id != 0)
    {
        float x = (sw - tex9.width) / 2;
        float y = (sh - tex9.height) / 2;

        // Draw image
        DrawTextureEx(tex9, { x, y }, 0.0f, 1.0f, WHITE);

        DrawTextureEx(tex9, { x + 200 , y }, 0.0f, 1.0f, WHITE);

        DrawTextureEx(tex9, { x + 400, y }, 0.0f, 1.0f, WHITE);

        const char* label = "Script";
        const char* label2 = "images";
        const char* label3 = "Video";
        int fontSize = 24;
        int textWidth = MeasureText(label, fontSize);
        int textX = (sw - textWidth) / 2;
        int textY = static_cast<int>(y) - fontSize - 10; // 10 pixels above the image

        DrawText(label, textX, textY, fontSize, WHITE);
        DrawText(label2, textX + 200, textY, fontSize, WHITE);
        DrawText(label3, textX + 400, textY, fontSize, WHITE);
    }


}

inline void drawReactions7()
{
    if (!loaded12)
    {
        tex12 = LoadTexture("image/frames.png");
        if (tex12.id == 0) std::cerr << "[drawReactions6] Failed to load 'image/frames.png'" << std::endl;
        loaded12 = true;
    }

    if (!loaded13)
    {
        tex13 = LoadTexture("image/video.png");
        if (tex13.id == 0) std::cerr << "[drawReactions6] Failed to load 'image/video.png'" << std::endl;
        loaded13 = true;
    }

    if (!loaded14)
    {
        tex14 = LoadTexture("image/not.png");
        if (tex14.id == 0) std::cerr << "[drawReactions6] Failed to load 'image/not.png'" << std::endl;
        loaded14 = true;
    }

    if (!loaded15)
    {
        tex15 = LoadTexture("image/150-frame.png");
        if (tex15.id == 0) std::cerr << "[drawReactions6] Failed to load 'image/150-frame.png'" << std::endl;
        loaded15 = true;
    }
    float t = GetTime();  // seconds since InitWindow
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    if (t >= 102.0f && t <= 106.0f && tex6.id != 0)
    {
        float x = (sw - tex12.width) / 2;
        float y = (sh - tex12.height) / 2;
        DrawTextureEx(tex13, { x , y }, 0.0f, 1.0f, WHITE);
        DrawTextureEx(tex14, { x , y }, 0.0f, 1.0f, WHITE);
    }

    if (t >= 106.0f && t <= 108.0f && tex6.id != 0)
    {
        float x = (sw - tex12.width) / 2;
        float y = (sh - tex12.height) / 2;
        DrawTextureEx(tex12, { x , y }, 0.0f, 1.0f, WHITE);
    }

    if (t >= 108.0f && t <= 110.0f && tex12.id != 0)
    {
        // 1) normalize time over the first 2 seconds (108→110)
        float animTime = clamp((t - 108.0f) / 2.0f, 0.0f, 1.0f);

        // 2) zoom 1× → 2×
        const float startScale = 1.0f;
        const float endScale = 2.0f;
        float scale = startScale + (endScale - startScale) * animTime;

        // 3) recenter as it grows
        float x = (sw - tex12.width * scale) / 2.0f;
        float y = (sh - tex12.height * scale) / 2.0f;

        // 4) draw at dynamic scale
        DrawTextureEx(tex12, { x, y }, 0.0f, scale, WHITE);
    }

    if (t >= 112.0f && t <= 116.0f && tex13.id != 0)
    {
        float x = (sw - tex13.width) / 2;
        float y = (sh - tex13.height) / 2;

        const char* label = "5 Sec";
        int fontSize = 24;
        int textWidth = MeasureText(label, fontSize);
        int textX = (sw - textWidth) / 2;
        int textY = static_cast<int>(y) - fontSize - 10; // 10 pixels above the image
        DrawText(label, textX, textY, fontSize, WHITE);
        DrawTextureEx(tex13, { x , y }, 0.0f, 1.0f, WHITE);

    }

    if (t >= 114.0f && t <= 116.0f && tex15.id != 0)
    {
        float x = (sw - tex15.width) / 2;
        float y = (sh - tex15.height) / 2;


        // Draw image
        DrawTextureEx(tex15, { x, y + 100 }, 0.0f, 1.0f, WHITE);
    }
}
inline void drawReactions8()
{
    if (!loaded9)
    {
        tex9 = LoadTexture("image/cpp_file.png");
        if (tex9.id == 0) std::cerr << "[drawReactions] Failed to load 'image/cpp_file.png'" << std::endl;
        loaded9 = true;
    }

    float t = GetTime();  // seconds since InitWindow
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    if (t >= 125.0f && t <= 128.0f && tex9.id != 0)
    {
        float x = (sw - tex9.width) / 2;
        float y = (sh - tex9.height) / 2;

        // Draw image
        DrawTextureEx(tex9, { x - 200, y }, 0.0f, 1.0f, WHITE);
        DrawTextureEx(tex9, { x, y }, 0.0f, 1.0f, WHITE);
        DrawTextureEx(tex9, { x + 200, y }, 0.0f, 1.0f, WHITE);
        DrawTextureEx(tex9, { x + 400, y }, 0.0f, 1.0f, WHITE);

        const char* label = "Script";
        const char* labe2 = "image";
        const char* labe3 = "video";
        const char* labe4 = "sound";

        int fontSize = 24;
        int textWidth = MeasureText(label, fontSize);
        int textX = (sw - textWidth) / 2;
        int textY = static_cast<int>(y) - fontSize - 10; // 10 pixels above the image

        DrawText(label, textX - 200, textY, fontSize, WHITE);
        DrawText(labe2, textX, textY, fontSize, WHITE);
        DrawText(labe3, textX + 200, textY, fontSize, WHITE);
        DrawText(labe4, textX + 400, textY, fontSize, WHITE);
    }
}

inline void drawReactions9()
{
    if (!loaded16)
    {
        tex16 = LoadTexture("image/animation.jpg");
        if (tex16.id == 0) std::cerr << "[drawReactions] Failed to load 'image/animation.jpg'" << std::endl;
        loaded16 = true;
    }

    if (!loaded17)
    {
        tex17 = LoadTexture("image/short_video.jpg");
        if (tex17.id == 0) std::cerr << "[drawReactions] Failed to load 'image/short_video.jpg'" << std::endl;
        loaded17 = true;
    }
    float t = GetTime();  // seconds since InitWindow
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    if (t >= 144.0f && t <= 146.0f && tex9.id != 0)
    {
        float x = (sw - tex9.width) / 2;
        float y = (sh - tex9.height) / 2;

        DrawTextureEx(tex16, { x - 200, y }, 0.0f, 1.0f, WHITE);
        DrawTextureEx(tex17, { x, y }, 0.0f, 1.0f, WHITE);
      
    }
}

bool loadedvideo1 = false, loadedvideo2 = false, loadedvideo3 = false, loadedvideo4 = false, loadedvideo5 = false, loadedvideo6 = false, loadedvideo7 = false, loadedvideo8 = false;
std::vector<Texture2D> frames;
std::vector<Texture2D> frames2;
std::vector<Texture2D> frames3;
std::vector<Texture2D> frames4;
std::vector<Texture2D> frames5;
std::vector<Texture2D> frames6;
std::vector<Texture2D> frames7;
std::vector<Texture2D> frames8;

inline void loadVideo(const std::string& dir = "video1") {
    if (loadedvideo1) return;
    frames.reserve(30);
    for (int i = 1; i <= 30; ++i) {
        std::string path = dir + "/Frame_" + std::to_string(i) + ".png";
        Texture2D tex = LoadTexture(path.c_str());
        if (tex.id == 0) {
            std::cerr << "[Video1] Failed to load '" << path << "'" << std::endl;
            continue; // Skip pushing invalid texture
        }
        frames.push_back(tex);
    }
    loadedvideo1 = true;
}

inline void drawvideo(float startTime, float duration = 2.0f) {
    loadVideo();
    float t = GetTime() - startTime;
    if (t < 0.0f || frames.empty() || t >= duration) return;

    int totalFrames = static_cast<int>(frames.size());
    int idx = static_cast<int>((t / duration) * totalFrames);
    idx = clamp(idx, 0, totalFrames - 1);

    Texture2D& tex = frames[idx];
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();
    float x = (sw - tex.width) / 2;
    float y = (sh - tex.height) / 2;
    DrawTextureEx(tex, { x, y }, 0.0f, 0.5f, WHITE);
}

inline void loadVideo2(const std::string& dir = "video2") {
    if (loadedvideo2) return;
    frames2.reserve(166);

    for (int i = 1; i <= 166; ++i) {
        std::string path = dir + "/frame_0" + std::to_string(i) + ".png";
        Texture2D tex = LoadTexture(path.c_str());
        if (tex.id == 0) {
            std::cerr << "[Video2] Failed to load '" << path << "'" << std::endl;
            continue;
        }
        frames2.push_back(tex);
    }
    loadedvideo2 = true;
}

inline void drawvide2(float startTime, float duration = 5.0f) {
    loadVideo2();

    float t = GetTime() - startTime;
    if (t < 0 || t >= duration) return;

    int total = static_cast<int>(frames2.size());
    int idx = static_cast<int>((t / duration) * total);
    idx = clamp(idx, 0, total - 1);

    Texture2D& tex2 = frames2[idx];
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    float scaleX = 1.0f, scaleY = 3.0f;
    float x = 0;
    float y = 0;

    DrawTextureEx(tex2, { x, y }, 0.0f, scaleY, WHITE);
}


inline void loadVideo3(const std::string& dir = "video3") {
    if (loadedvideo3) return;
    frames3.reserve(255);
    for (int i = 1; i <= 255; ++i) {
        std::string path = dir + "/frame_0" + std::to_string(i) + ".png";
        Texture2D tex = LoadTexture(path.c_str());
        if (tex.id == 0) {
            std::cerr << "[Video3] Failed to load '" << path << "'" << std::endl;
            continue;
        }
        frames3.push_back(tex);
    }
    loadedvideo3 = true;
}

inline void drawvideo3(float startTime, float duration = 6.0f) {
    loadVideo3();
    float t = GetTime() - startTime;
    if (t < 0.0f || frames3.empty() || t >= duration) return;

    int totalFrames = static_cast<int>(frames3.size());
    int idx = static_cast<int>((t / duration) * totalFrames);
    idx = clamp(idx, 0, totalFrames - 1);

    Texture2D& tex3 = frames3[idx];
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    // Apply different X and Y scaling
    float scaleX = 1.0f;  // Keep width the same
    float scaleY = 3.0f;  // Increase height (Y zoom)

    float x = 0;
    float y = 0;
    DrawTextureEx(tex3, { x , y }, 0.0f, scaleY, WHITE); // Use scaleX for scaling
}

inline void loadVideo4(const std::string& dir = "video4") {
    if (loadedvideo4) return;
    frames4.reserve(255);
    for (int i = 1; i <= 255; ++i) {
        std::string path = dir + "/frame_0" + std::to_string(i) + ".png";
        Texture2D tex = LoadTexture(path.c_str());
        if (tex.id == 0) {
            std::cerr << "[Video4] Failed to load '" << path << "'" << std::endl;
            continue;
        }
        frames4.push_back(tex);
    }
    loadedvideo4= true;
}

inline void drawvideo4(float startTime, float duration = 6.0f) {
    loadVideo4();
    float t = GetTime() - startTime;
    if (t < 0.0f || frames4.empty() || t >= duration) return;

    int totalFrames = static_cast<int>(frames4.size());
    int idx = static_cast<int>((t / duration) * totalFrames);
    idx = clamp(idx, 0, totalFrames - 1);

    Texture2D& tex4 = frames4[idx];
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    // Apply different X and Y scaling
    float scaleX = 1.0f;  // Keep width the same
    float scaleY = 3.0f;  // Increase height (Y zoom)

    float x = 0;
    float y = 0;
    DrawTextureEx(tex4, { x , y }, 0.0f, scaleY, WHITE); // Use scaleX for scaling
}

inline void loadVideo5(const std::string& dir = "video5") {
    if (loadedvideo5) return;
    frames5.reserve(269);
    for (int i = 1; i <= 269; ++i) {
        std::string path = dir + "/frame_0" + std::to_string(i) + ".png";
        Texture2D tex = LoadTexture(path.c_str());
        if (tex.id == 0) {
            std::cerr << "[Video5] Failed to load '" << path << "'" << std::endl;
            continue;
        }
        frames5.push_back(tex);
    }
    loadedvideo5 = true;
}

inline void drawvideo5(float startTime, float duration = 8.0f) {
    loadVideo5();
    float t = GetTime() - startTime;
    if (t < 0.0f || frames5.empty() || t >= duration) return;

    int totalFrames = static_cast<int>(frames5.size());
    int idx = static_cast<int>((t / duration) * totalFrames);
    idx = clamp(idx, 0, totalFrames - 1);

    Texture2D& tex5 = frames5[idx];
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    // Apply different X and Y scaling
    float scaleX = 1.0f;  // Keep width the same
    float scaleY = 3.0f;  // Increase height (Y zoom)

    float x = 0;
    float y = 0;
    DrawTextureEx(tex5, { x - 150, y }, 0.0f, scaleY, WHITE); // Use scaleX for scaling
}

inline void loadVideo6(const std::string& dir = "video6") {
    if (loadedvideo6) return;
    frames6.reserve(777);
    for (int i = 1; i <= 777; ++i) {
        std::string path = dir + "/frame_0" + std::to_string(i) + ".png";
        Texture2D tex = LoadTexture(path.c_str());
        if (tex.id == 0) {
            std::cerr << "[Video6] Failed to load '" << path << "'" << std::endl;
            continue;
        }
        frames6.push_back(tex);
    }
    loadedvideo6 = true;

}

inline void drawvideo6(float startTime, float duration = 24.0f) {
    loadVideo6();

    float t = GetTime() - startTime;
    if (t < 0.0f || t >= duration) return;

    int totalFrames = static_cast<int>(frames6.size());
    int idx = static_cast<int>((t / duration) * totalFrames);
    idx = clamp(idx, 0, totalFrames - 1);

    Texture2D& tex6 = frames6[idx];
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    float scaleX = 1.0f;
    float scaleY = 3.0f;

    float x = 0;
    float y = 0;
    DrawTextureEx(tex6, { x, y }, 0.0f, scaleY, WHITE);
}

inline void loadVideo7(const std::string& dir = "video7") {
    if (loadedvideo7) return;
    frames7.reserve(625);
    for (int i = 1; i <= 625; ++i) {
        std::string path = dir + "/frame_0" + std::to_string(i) + ".png";
        Texture2D tex = LoadTexture(path.c_str());
        if (tex.id == 0) {
            std::cerr << "[Video7] Failed to load '" << path << "'" << std::endl;
            continue;
        }
        frames7.push_back(tex);
    }
    loadedvideo7 = true;

}

inline void drawvideo7(float startTime, float duration = 24.0f) {
    loadVideo7();

    float t = GetTime() - startTime;
    if (t < 0.0f || t >= duration) return;

    int totalFrames = static_cast<int>(frames7.size());
    int idx = static_cast<int>((t / duration) * totalFrames);
    idx = clamp(idx, 0, totalFrames - 1);

    Texture2D& tex7 = frames7[idx];
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    float scaleX = 1.0f;
    float scaleY = 3.0f;

    float x = 0;
    float y = 0;
    DrawTextureEx(tex7, { x, y }, 0.0f, scaleY, WHITE);
}


inline void loadVideo8(const std::string& dir = "video8") {
    if (loadedvideo8) return;
    frames8.reserve(871);
    for (int i = 1; i <= 871; ++i) {
        std::string path = dir + "/frame_0" + std::to_string(i) + ".png";
        Texture2D tex = LoadTexture(path.c_str());
        if (tex.id == 0) {
            std::cerr << "[Video7] Failed to load '" << path << "'" << std::endl;
            continue;
        }
        frames8.push_back(tex);
    }
    loadedvideo8 = true;

}

inline void drawvideo8(float startTime, float duration = 29.0f) {
    loadVideo8();

    float t = GetTime() - startTime;
    if (t < 0.0f || t >= duration) return;

    int totalFrames = static_cast<int>(frames8.size());
    int idx = static_cast<int>((t / duration) * totalFrames);
    idx = clamp(idx, 0, totalFrames - 1);

    Texture2D& tex8 = frames8[idx];
    int sw = GetScreenWidth();
    int sh = GetScreenHeight();

    float scaleX = 1.0f;
    float scaleY = 3.0f;

    float x = 0;
    float y = 0;
    DrawTextureEx(tex8, { x, y }, 0.0f, scaleY, WHITE);
}

inline void unload() {
    if (loadedvideo1) {
        for (auto& tex : frames) UnloadTexture(tex);
        frames.clear();
        loadedvideo1 = false;
    }
    if (loadedvideo2) {
        for (auto& tex2 : frames2) UnloadTexture(tex2);
        frames2.clear();
        loadedvideo2 = false;
    }

    if (loadedvideo3) {
        for (auto& tex3 : frames3) UnloadTexture(tex3);
        frames3.clear();
        loadedvideo3 = false;
    }

    if (loadedvideo4) {
        for (auto& tex4 : frames4) UnloadTexture(tex4);
        frames4.clear();
        loadedvideo4 = false;
    }

    if (loadedvideo5) {
        for (auto& tex5 : frames5) UnloadTexture(tex5);
        frames5.clear();
        loadedvideo5 = false;
    }

    if (loadedvideo6) {
        for (auto& tex6 : frames6) UnloadTexture(tex6);
        frames6.clear();
        loadedvideo6 = false;
    }

    if (loadedvideo7) {
        for (auto& tex7 : frames7) UnloadTexture(tex7);
        frames7.clear();
        loadedvideo7 = false;
    }

}