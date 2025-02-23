#include "component.hpp"
#include "transform_component.hpp"

// TransformComponent constructor
TransformComponent::TransformComponent(Entity& entity) :
    Component(entity),
    position(Vector2()),
    scale(Vector2()),
    rotation(0.0f) {}

// Get the transform as an SDL_FRect
SDL_FRect TransformComponent::getFRect() {
    SDL_FRect rect = {
        position.x,
        position.y,
        scale.x,
        scale.y,
    };
    return rect;
}

// Get the transform as an SDL_Rect
SDL_Rect TransformComponent::getRect() {
    SDL_Rect rect = {
        (int) position.x,
        (int) position.y,
        (int) scale.x,
        (int) scale.y,
    };
    return rect;
}

