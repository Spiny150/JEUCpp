#include <iostream>
#include <SDL2/SDL.h>
#include "window_manager.h"
#include "entity.h"
#include "player.h"
#include "scene.h"
#include <time.h>
#include "Engine/time.hpp"
#include "inputs.h"

int main() {
    //INITIALISATION JEU
    srand(time(NULL));

    //INITIALISATION GENERALE
    WindowManager* WM = nullptr;
    SDL_Event event;

    try {
        WM = new WindowManager(800, 600, "DuckDuckGame");
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    Scene scene = Scene(WM);

    Entity* player = new Player(WM);
    Entity* player2 = new Player(WM);

    scene.AddEntity(player);
    scene.AddEntity(player2);

    scene.Start();
    player2->getComponent<TransformComponent>()->position.x += 30;
    std::cout << player2->getComponent<TransformComponent>()->position.x << std::endl;
    player->getComponent<VisualComponent>()->setRenderLayer(5);
    player2->getComponent<VisualComponent>()->setRenderLayer(10);

    //std::cout << player->getComponent<VisualComponent>()->texture << std::endl;
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
        scene.Update();
    }


    delete WM;
    WM = nullptr;
    return 0;
}