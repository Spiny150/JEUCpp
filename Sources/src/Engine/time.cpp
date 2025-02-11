#include "Engine/time.hpp"
#include <iostream>

Uint64 Time::lastFrameTime = 0;
Uint64 Time::currentFrameTime = SDL_GetPerformanceCounter();
double Time::unscaledDeltaTime = 0;
double Time::deltaTime = 0;
double Time::timeScale = 1;

int Time::measurementFrequency = 5000;
int Time::frameCount = 0;
Uint64 Time::timeSinceLM = SDL_GetTicks64();

void Time::Update() {
    lastFrameTime = currentFrameTime;
    currentFrameTime = SDL_GetPerformanceCounter();
    unscaledDeltaTime = (double) (currentFrameTime - lastFrameTime) / SDL_GetPerformanceFrequency();
    deltaTime = unscaledDeltaTime * timeScale;

    frameCount++;
    if (SDL_GetTicks64() > timeSinceLM + measurementFrequency) {
        int fps = frameCount / (measurementFrequency/1000);
        std::cout << "Fps : " << fps << std::endl;
        frameCount = 0;
        timeSinceLM = SDL_GetTicks64();
    }
}