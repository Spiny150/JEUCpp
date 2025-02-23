#include "text_visual_component.hpp"
#include "exceptions.h"
#include <SDL2/SDL.h>
#include "assert.h"

TextVisualComponent::TextVisualComponent(Entity& entity, WindowManager* _WM, Camera* camera, const std::string& text) :
    VisualComponent(entity, _WM, camera),
    textColor({255, 255, 255, 255})
{

    font = TTF_OpenFont("Assets/Fonts/SuperPixel.ttf", 32);
    if (!font) {
        throw Exception("Erreur lors du TTF_OpenFont : " + std::string(TTF_GetError()));
    }

    SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), textColor);

    if (!textSurface) {
        throw Exception("Erreur lors du TTF_RenderText_Solid" + std::string(TTF_GetError()));
    }

    this->textTexture = SDL_CreateTextureFromSurface(WM->SDLRenderer, textSurface);
    if (!this->textTexture) {
        throw Exception("Erreur lors du SDL_CreateTextureFromSurface" + std::string(SDL_GetError()));
    }

    transform->scale.x = textSurface->w;
    transform->scale.y = textSurface->h;


    SDL_FreeSurface(textSurface);
}

void TextVisualComponent::UpdateText(const std::string& text) {

    SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), textColor);

    if (!textSurface) {
        throw Exception("Erreur lors du TTF_RenderText_Solid" + std::string(TTF_GetError()));
    }

    SDL_DestroyTexture(textTexture);
    this->textTexture = SDL_CreateTextureFromSurface(WM->SDLRenderer, textSurface);
    if (!this->textTexture) {
        throw Exception("Erreur lors du SDL_CreateTextureFromSurface" + std::string(SDL_GetError()));
    }

    transform->scale.x = textSurface->w;
    transform->scale.y = textSurface->h;

    SDL_FreeSurface(textSurface);
}

TextVisualComponent::~TextVisualComponent() {
    SDL_DestroyTexture(this->textTexture);
    TTF_CloseFont(font);
}

void TextVisualComponent::Render() {
    if (!isActive) return;

    SDL_FRect boxRect = transform->getFRect();

    SDL_RenderCopyF(WM->SDLRenderer, textTexture, NULL, &boxRect);
}
