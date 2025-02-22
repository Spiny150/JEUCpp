#include "window_manager.h"
#include "entity.h"
#include "exceptions.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// WindowManager constructor
WindowManager::WindowManager(Vector2Int _windowSize, std::string windowName) : windowSize(_windowSize) {
    // Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw Exception("SDL_Init error: " + std::string(SDL_GetError()));
    }

    // Initialize SDL_ttf for font rendering
    if (TTF_Init() != 0) {
        throw Exception("TTF_Init error: " + std::string(TTF_GetError()));
    }

    // Initialize SDL_image for loading images
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        throw Exception("IMG_Init error: " + std::string(IMG_GetError()));
    }

    // Create window
    if (!createWindow(windowSize.x, windowSize.y, windowName)) {
        throw Exception("SDL_CreateWindow error: " + std::string(SDL_GetError()));
    }

    // Create renderer
    if (!createSDLRenderer()) {
        throw Exception("SDL_CreateRenderer error: " + std::string(SDL_GetError()));
    }
    std::cout << "WindowManager initialized" << std::endl;
}

// WindowManager destructor
WindowManager::~WindowManager() {
    // Clean up resources
    if (SDLRenderer) SDL_DestroyRenderer(SDLRenderer);
    if (window) SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    std::cout << "WindowManager destroyed" << std::endl;
}

// Create SDL window
bool WindowManager::createWindow(int width, int height, const std::string& windowName) {
    // Create centered window with specified size and name
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

// Create SDL renderer
bool WindowManager::createSDLRenderer() {
    // Create accelerated renderer
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

// Create texture from surface
SDL_Texture* WindowManager::getTexture(SDL_Surface* surface) {
    SDL_Texture* texture = SDL_CreateTextureFromSurface(SDLRenderer, surface);
    if (!texture) {
        throw Exception("SDL_CreateTextureFromSurface error: " + std::string(SDL_GetError()));
    }
    return texture;
}

// Load image surface from file
SDL_Surface* WindowManager::loadSurface(const std::string& img_path) {
    SDL_Surface* surface = IMG_Load(img_path.c_str());
    if (!surface) {
        throw Exception("IMG_Load error: " + std::string(IMG_GetError()));
    }
    return surface;
}
