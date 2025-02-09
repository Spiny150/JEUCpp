#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <SDL2/SDL.h>
#include <iostream>

class Entity;

class WindowManager
{
public:
    // Variables
    SDL_Window* window;
    SDL_Renderer* SDLRenderer;

    // Constructeur / Déconstructeur
    WindowManager(int width, int height, std::string windowName);
    ~WindowManager();

    // Méthodes
    bool createWindow(int width, int height, const std::string& windowName);
    bool createSDLRenderer();

    SDL_Texture* getTexture(SDL_Surface* surface);
    SDL_Surface* loadSurface(const std::string& img_path);

    //void renderScreen();
};

#endif