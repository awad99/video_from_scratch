#pragma once
#include <iostream>
#include <raylib.h>

bool Loaded1 = false;
bool Loaded2 = false;
bool Loaded3 = false;
bool Loaded4 = false;
Sound sound1, sound2, sound3, sound4;

void firstSound()
{
    if (!Loaded1)
    {
        sound1 = LoadSound("sound/sound1.wav");
        if (sound1.frameCount == 0)
        {
            std::cerr << "[firstSound] Failed to load 'sound/sound1.wav'" << std::endl;
            return;
        }
        PlaySound(sound1);
        Loaded1 = true;
    }
}

void secondSound()
{
    if (!Loaded2)
    {
        sound2 = LoadSound("sound/sound2.wav");
        if (sound2.frameCount == 0)
        {
            std::cerr << "[secondSound] Failed to load 'sound/sound2.wav'" << std::endl;
            return;
        }
        PlaySound(sound2);
        Loaded2 = true;
    }
}

void thireddSound()
{
    if (!Loaded3)
    {
        sound3 = LoadSound("sound/sound3.wav");
        if (sound3.frameCount == 0)
        {
            std::cerr << "[thireddSound] Failed to load 'sound/sound3.wav'" << std::endl;
            return;
        }
        PlaySound(sound3);
        Loaded3 = true;
    }
}

void fourthSound()
{
    if (!Loaded4)
    {
        sound4 = LoadSound("sound/sound4.wav");
        if (sound4.frameCount == 0)
        {
            std::cerr << "[thireddSound] Failed to load 'sound/sound4.wav'" << std::endl;
            return;
        }
        PlaySound(sound4);
        Loaded4 = true;
    }
}