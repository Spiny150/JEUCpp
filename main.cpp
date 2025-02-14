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

int main() {
    //INITIALISATION JEU
    srand(time(NULL));

    //INITIALISATION GENERALE
    WindowManager* WM = nullptr;
    SDL_Event event;

    try {
        WM = new WindowManager(Vector2Int(800, 600), "DuckDuckGame");
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    SceneManager* sceneManager = SceneManager::CreateInstance(WM);

    sceneManager->AddScene(SceneTag::MainMenu, std::make_unique<MainMenuScene>(WM));
    sceneManager->AddScene(SceneTag::Game, std::make_unique<GameScene>(WM));

    sceneManager->SwitchToScene(SceneTag::MainMenu);

    bool quit = false;
    while (!quit)
    {
        Time::Update();
        Input::Update();

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            
            default:
                break;
            }
        }
        if (Input::isKeyPressed(SDL_SCANCODE_ESCAPE)) {
            Time::timeScale = !Time::timeScale;
        }
        sceneManager->Update();
    }

    delete sceneManager;
    sceneManager = nullptr;
    delete WM;
    WM = nullptr;
    return 0;
}