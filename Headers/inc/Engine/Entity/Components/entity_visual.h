#pragma once

#include <SDL2/SDL_image.h>
#include <iostream>
#include "component.h"
#include "entity_transform.h"

class WindowManager;

class VisualComponent : public Component {
private:
public:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_RendererFlip flip;
    SDL_Rect* srcRect; // Part de l'image selectionnée pour l'affichage
    SDL_Rect fullSrcRect; // Dimensions totale de l'image

    VisualComponent(Entity& entity);
    ~VisualComponent();

    void setSprite(const std::string& img_path, WindowManager* WM);
    void render(SDL_Renderer* renderer);
};
