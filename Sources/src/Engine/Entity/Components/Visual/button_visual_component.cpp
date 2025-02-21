#include "button_visual_component.hpp"
#include "exceptions.h"
#include <SDL2/SDL.h>
#include "assert.h"

ButtonVisualComponent::ButtonVisualComponent(Entity& entity, WindowManager* _WM, Camera* camera, const std::string& buttonText) :
    VisualComponent(entity, _WM, camera),
    textColor({0, 0, 0, 255}),
    backgroundColor({225, 225, 225, 255}),
    hoverBackgroundColor({255, 255, 255, 255}),
    borderColor({0, 0, 0, 255}),
    buttonMargin(30)
{

    TTF_Font* font = TTF_OpenFont("Assets/Fonts/SuperPixel.ttf", 52);
    if (!font) {
        throw Exception("Erreur lors du TTF_OpenFont : " + std::string(TTF_GetError()));
    }

    SDL_Surface* textSurface = TTF_RenderText_Blended(font, buttonText.c_str(), textColor);

    if (!textSurface) {
        throw Exception("Erreur lors du TTF_RenderText_Solid" + std::string(TTF_GetError()));
    }

    this->textTexture = SDL_CreateTextureFromSurface(WM->SDLRenderer, textSurface);
    if (!this->textTexture) {
        throw Exception("Erreur lors du SDL_CreateTextureFromSurface" + std::string(SDL_GetError()));
    }

    transform->scale.x = textSurface->w + buttonMargin;
    transform->scale.y = textSurface->h + buttonMargin;


    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
}

ButtonVisualComponent::~ButtonVisualComponent() {
    SDL_DestroyTexture(this->textTexture);
}

void ButtonVisualComponent::Render() {
    if (!isActive) return;

    SDL_FRect boxRect = transform->getFRect();

    SDL_Rect textRect;
    textRect.w = transform->scale.x - buttonMargin;
    textRect.h = transform->scale.y - buttonMargin;
    textRect.x = transform->position.x + transform->scale.x/2 - textRect.w/2;
    textRect.y = transform->position.y + transform->scale.y/2 - textRect.h/2;

    SDL_Color drawColor = (isHovered) ? hoverBackgroundColor : backgroundColor;
    SDL_SetRenderDrawColor(WM->SDLRenderer, drawColor.r, drawColor.g, drawColor.b, drawColor.a);
    SDL_RenderFillRectF(WM->SDLRenderer, &boxRect);

    SDL_SetRenderDrawColor(WM->SDLRenderer, borderColor.r, borderColor.g, borderColor.b, borderColor.a);
    SDL_RenderDrawRectF(WM->SDLRenderer, &boxRect);

    SDL_RenderCopy(WM->SDLRenderer, textTexture, NULL, &textRect);

}
