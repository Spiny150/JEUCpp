#include "component.h"
#include "entity_transform.h"

TransformComponent::TransformComponent(Entity& entity) :
    Component(entity),
    position(Vector2()),
    scale(Vector2()),
    rotation(0.0f) {};

SDL_FRect TransformComponent::getFRect() {
    SDL_FRect rect = {
        position.x,
        position.y,
        scale.x,
        scale.y,
    };
    return rect;
}