#include "Engine/time.hpp"

Uint64 Time::lastFrameTime = 0;
Uint64 Time::currentFrameTime = SDL_GetPerformanceCounter();
double Time::unscaledDeltaTime = 0;
double Time::deltaTime = 0;
double Time::timeScale = 1;

void Time::Update() {
    lastFrameTime = currentFrameTime;
    currentFrameTime = SDL_GetPerformanceCounter();
    unscaledDeltaTime = (double) (currentFrameTime - lastFrameTime) / SDL_GetPerformanceFrequency();
    deltaTime = unscaledDeltaTime * timeScale;
}