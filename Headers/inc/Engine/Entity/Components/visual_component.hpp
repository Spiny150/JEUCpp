#pragma once

#include <SDL2/SDL_image.h>
#include <iostream>
#include "component.hpp"
#include "transform_component.hpp"
#include "camera.hpp"

class WindowManager;

class VisualComponent : public Component {
private:
    TransformComponent* transform;
public:
    int renderLayer;
    SDL_Texture* texture;
    SDL_RendererFlip flip;
    SDL_Rect* srcRect; // Part de l'image selectionnée pour l'affichage
    SDL_Rect fullSrcRect; // Dimensions totale de l'image

    VisualComponent(Entity& entity);
    ~VisualComponent();

    void setRenderLayer(int renderLayer);

    void setSprite(const std::string& img_path, WindowManager* WM);
    void render(SDL_Renderer* renderer, Camera* camera);
};
