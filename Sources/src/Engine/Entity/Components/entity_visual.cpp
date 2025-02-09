#include "entity_visual.h"
#include <iostream>
#include "window_manager.h"
#include "entity.h"
#include "exceptions.h"

VisualComponent::VisualComponent(Entity& entity) :
    Component(entity),
    renderLayer(0),
    texture(nullptr),
    flip(SDL_FLIP_NONE),
    srcRect(nullptr),
    fullSrcRect({0, 0, 0, 0}) {
        transform = entity.getComponent<TransformComponent>();
        std::cout << "VisualComponent instancié" << std::endl;
};

VisualComponent::~VisualComponent() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    if (srcRect) {
        delete srcRect;
        srcRect = nullptr;
    }
    std::cout << "VisualComponent détruit" << std::endl;
}

void VisualComponent::setRenderLayer(int renderLayer) {
    this->entity.getScene()->setEntityRenderLayer(&this->entity, renderLayer);
}

void VisualComponent::setSprite(const std::string& img_path, WindowManager* WM) {
    std::cout << "HERE ?" << std::endl;
    if (!transform) return;

    SDL_Surface* surface = WM->loadSurface(img_path);
    std::cout << "HERE2 ?" << std::endl;
    this->fullSrcRect.w = surface->w;
    this->fullSrcRect.h = surface->h;

    transform->scale.x = surface->w;
    transform->scale.y = surface->h;

    this->texture = WM->getTexture(surface);
    

    SDL_FreeSurface(surface);
}

void VisualComponent::render(SDL_Renderer* renderer, Camera* camera) {

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
        renderer,
        texture,
        srcRect,
        &dstRect,
        transform->rotation,
        NULL,
        flip
    );
}