#include <iostream>
#include <SDL2/SDL.h>
#include "window_manager.h"
#include "entity.h"
#include "player.h"
#include "scene.h"
#include <time.h>
#include "Engine/time.hpp"
#include "inputs.h"
#include "scene_manager.hpp"
#include "game_scene.hpp"
#include "main_menu_scene.hpp"
#include <memory>

// Main entry point of the application
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize window and event handler
    WindowManager* WM = nullptr;
    SDL_Event event;

    try {
        // Create game window with specified size and title
        WM = new WindowManager(Vector2Int(800, 600), "DuckDuckGame");
    } catch(const std::exception& e) {
        // Handle window creation errors
        std::cerr << e.what() << '\n';
        return 1;
    }

    // Create scene manager instance
    SceneManager* sceneManager = SceneManager::CreateInstance(WM);

    // Register game scenes
    sceneManager->AddScene(SceneTag::MainMenu, std::make_unique<MainMenuScene>(WM));
    sceneManager->AddScene(SceneTag::Game, std::make_unique<GameScene>(WM));

    // Start with the main menu scene
    sceneManager->SwitchToScene(SceneTag::MainMenu);

    // Main game loop
    bool quit = false;
    while (!quit) {
        // Update time and input states
        Time::Update();
        Input::Update();

        // Process SDL events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    // Exit the game if window is closed
                    quit = true;
                    break;
                
                default:
                    break;
            }
        }

        // Update current scene
        sceneManager->Update();
    }

    // Clean up resources
    delete sceneManager;
    sceneManager = nullptr;
    delete WM;
    WM = nullptr;

    return 0;
}
