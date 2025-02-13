#include "window_manager.h"
#include "entity.h"
#include "exceptions.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

WindowManager::WindowManager(Vector2Int _windowSize, std::string windowName) : windowSize(_windowSize) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw Exception("Erreur SDL_Init: " + std::string(SDL_GetError()));
    }

    if (TTF_Init() != 0) {
        throw Exception("Erreur TTF_Init: " + std::string(TTF_GetError()));
    }

    // Initialisation de SDL_image pour charger des images
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        throw Exception("Erreur IMG_Init: " + std::string(IMG_GetError()));
    }

    if (!createWindow(windowSize.x, windowSize.y, windowName)) {
        throw Exception("Erreur SDL_CreateWindow: " + std::string(SDL_GetError()));
    }

    if (!createSDLRenderer()) {
        throw Exception("Erreur SDL_CreateRenderer: " + std::string(SDL_GetError()));
    }
    std::cout << "WindowManager initialisé" << std::endl;
}

WindowManager::~WindowManager() {
    if (SDLRenderer) SDL_DestroyRenderer(SDLRenderer);
    if (window) SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    std::cout << "WindowManager libéré" << std::endl;
}

bool WindowManager::createWindow(int width, int height, const std::string& windowName) {
    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow(
        windowName.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        return false;
    }
    this->window = window;
    return true;
}

bool WindowManager::createSDLRenderer() {
    SDL_Renderer* renderer = SDL_CreateRenderer(
        this->window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if (!renderer) {
        return false;
    }
    this->SDLRenderer = renderer;
    return true;
}

SDL_Texture* WindowManager::getTexture(SDL_Surface* surface) {
    SDL_Texture* texture = SDL_CreateTextureFromSurface(SDLRenderer, surface);
    if (!texture) {
        throw Exception("Erreur SDL_CreateTextureFromSurface: " + std::string(SDL_GetError()));
    }
    return texture;
}

SDL_Surface* WindowManager::loadSurface(const std::string& img_path) {
    SDL_Surface* surface = IMG_Load(img_path.c_str());
    if (!surface) {
        throw Exception("Erreur IMG_Load: " + std::string(IMG_GetError()));
    }
    return surface;
}