#pragma once

#include "visual_component.hpp"
#include <SDL2/SDL.h>

class ImageVisualComponent : public VisualComponent {
private:
    SDL_Texture* texture;
    SDL_RendererFlip flip;
    SDL_Rect* srcRect; // Part de l'image selectionnée pour l'affichage
    SDL_Rect fullSrcRect; // Dimensions totale de l'image
public:

    ImageVisualComponent(Entity& entity, WindowManager* WM, Camera* camera, const std::string& imgPath);
    virtual ~ImageVisualComponent();

    void Render() override;

};