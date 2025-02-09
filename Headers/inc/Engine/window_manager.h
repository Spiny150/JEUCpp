#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "units.h"
#include <SDL2/SDL.h>
#include <iostream>

class Entity;

class WindowManager
{
public:
    // Variables
    Vector2Int windowSize;
    SDL_Window* window;
    SDL_Renderer* SDLRenderer;

    // Constructeur / Déconstructeur
    WindowManager(Vector2Int windowSize, std::string windowName);
    ~WindowManager();

    // Méthodes
    bool createWindow(int width, int height, const std::string& windowName);
    bool createSDLRenderer();

    SDL_Texture* getTexture(SDL_Surface* surface);
    SDL_Surface* loadSurface(const std::string& img_path);

    //void renderScreen();
};

#endif