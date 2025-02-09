#pragma once

#include "units.h"
#include <SDL2/SDL.h>

class Camera
{
public:
    Vector2 position;
    Vector2 velocity;
    Vector2Int scale;

    Camera(Vector2Int _scale);
    ~Camera();

    void Update();

    SDL_Rect GetViewRect() const; // Retourne le rectangle visible
};

