#pragma once

#include "units.h"
#include <SDL2/SDL.h>

class TransformComponent : public Component {
public:
    Vector2 position;
    Vector2 scale; // On-screen size
    float rotation;

    TransformComponent(Entity& entity);
    SDL_FRect getFRect();
    SDL_Rect getRect();
};
