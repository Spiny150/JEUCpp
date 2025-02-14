#pragma once

#include "visual_component.hpp"
#include <SDL2/SDL_ttf.h>

class ButtonVisualComponent : public VisualComponent
{
private:
    SDL_Texture* textTexture;
    SDL_Color textColor;
    SDL_Color backgroundColor;
    SDL_Color hoverBackgroundColor;
    SDL_Color borderColor;
    int buttonMargin;
    //SDL_Rect textRect;
public:
    bool isHovered;

    ButtonVisualComponent(Entity& entity, WindowManager* _WM, Camera* camera, const std::string& buttonText);
    virtual ~ButtonVisualComponent();

    void Render() override;
};