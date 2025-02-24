#pragma once

#include "visual_component.hpp"
#include <SDL2/SDL_ttf.h>

class TextVisualComponent : public VisualComponent
{
private:
    SDL_Texture* textTexture;
    SDL_Color textColor;
    TTF_Font* font;

public:

    TextVisualComponent(Entity& entity, WindowManager* _WM, Camera* camera, const std::string& text, const std::string& fontName = "Assets/Fonts/MightySouly.ttf", SDL_Color _textColor = {255, 255, 255, 255}, int textSize = 32);
    virtual ~TextVisualComponent();

    void UpdateText(const std::string& text);
    void Render() override;
};