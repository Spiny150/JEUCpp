#pragma once

#include <SDL2/SDL.h>

class Time
{
private:
    static Uint64 lastFrameTime;
    static Uint64 currentFrameTime;

    static int frameCount;
    static Uint64 timeSinceLM; // LM = LastMeasurement
    static int measurementFrequency;

public:
    static double timeScale;
    static double deltaTime;
    static double unscaledDeltaTime;

    static void Update();
};

