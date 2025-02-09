#pragma once

#include <SDL2/SDL.h>

class Time
{
private:
    static Uint64 lastFrameTime;
    static Uint64 currentFrameTime;
public:
    static double timeScale;
    static double deltaTime;
    static double unscaledDeltaTime;

    static void Update();
};

