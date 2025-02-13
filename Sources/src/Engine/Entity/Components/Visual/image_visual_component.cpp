#include "image_visual_component.hpp"
#include "exceptions.h"
#include "assert.h"

ImageVisualComponent::ImageVisualComponent(Entity& entity, WindowManager* _WM, Camera* camera, const std::string& imgPath) : VisualComponent(entity, _WM, camera) {

    assert(transform);
    if (transform) return;

    SDL_Surface* surface = WM->loadSurface(imgPath);
    this->fullSrcRect.w = surface->w;
    this->fullSrcRect.h = surface->h;

    transform->scale.x = surface->w;
    transform->scale.y = surface->h;

    this->texture = WM->getTexture(surface);
    

    SDL_FreeSurface(surface);
}

void ImageVisualComponent::Render() {

    if (!transform) {
        throw Exception("Visual component missing transform");
    }
    if (!camera) {
        throw Exception("Visual component missing camera");
    }

    SDL_FRect dstRect = {
        transform->position.x - camera->position.x,
        transform->position.y - camera->position.y,
        transform->scale.x,
        transform->scale.y,
    };
    SDL_RenderCopyExF(
        WM->SDLRenderer,
        texture,
        srcRect,
        &dstRect,
        transform->rotation,
        NULL,
        flip
    );
}