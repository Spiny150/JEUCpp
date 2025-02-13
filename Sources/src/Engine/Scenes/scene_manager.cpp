#include "scene_manager.hpp"
#include "assert.h"
#include "time.hpp"

SceneManager::SceneManager(WindowManager* _WM) :
    currentScene(nullptr),
    intendedSceneTag(SceneTag::Undefined),
    sceneState(SceneState::SceneSwitch),
    WM(_WM),
    transitionRect({0, 0, 0, 0}) {
        std::cout << "SceneManager instanciated" << std::endl;
}
SceneManager::~SceneManager() {
    std::cout << "SceneManager destroyed" << std::endl;
}


SceneManager* SceneManager::instance = nullptr;  // Définition de l'instance unique

SceneManager* SceneManager::CreateInstance(WindowManager* WM) {
    assert(!instance);
    instance = new SceneManager(WM);
    return instance;
}
SceneManager* SceneManager::GetInstance() {
    assert(instance);
    return instance;
}

void SceneManager::AddScene(SceneTag tag, std::unique_ptr<Scene> scene) {
    scenes[tag] = std::move(scene);
}

void SceneManager::SwitchToScene(SceneTag tag) {
    intendedSceneTag = tag;
    sceneState = SceneState::TransitionOut;
}

void SceneManager::Update() {
    //SDL_Delay(50);
    //printf("%d", sceneState);
    assert(WM && WM->SDLRenderer);
    SDL_RenderClear(WM->SDLRenderer);
    switch (sceneState)
    {
    case SceneState::SceneShown:
        if (currentScene) {
            currentScene->Update();
            currentScene->Render();
        }
        break;
    case SceneState::SceneSwitch:
        SDL_SetRenderDrawColor(WM->SDLRenderer, 0, 0, 0, 255);
        SDL_RenderFillRectF(WM->SDLRenderer, &transitionRect);
        if (currentScene) {
            currentScene->CleanUp();
        }

        currentScene = scenes[intendedSceneTag].get();

        assert(currentScene != nullptr);
        if (currentScene) {
            currentScene->Init();
        }
        sceneState = SceneState::TransitionIn;
        break;
    case SceneState::TransitionOut:
        if (!currentScene) { // If no scene is currently active, jump to SceneSwitching
            sceneState = SceneState::SceneSwitch;
            break;
        }
        currentScene->Render();
        transitionRect.x = 0;
        transitionRect.y = 0;
        transitionRect.w = 800;
        transitionRect.h += 1200 * Time::unscaledDeltaTime;

        SDL_SetRenderDrawColor(WM->SDLRenderer, 0, 0, 0, 255);
        SDL_RenderFillRectF(WM->SDLRenderer, &transitionRect);

        if (transitionRect.h > 600) {
            transitionRect.x = 0;
            transitionRect.y = 0;
            transitionRect.w = 0;
            transitionRect.h = 0;
            sceneState = SceneState::SceneSwitch;
        }
        break;
    case SceneState::TransitionIn:
        if (currentScene) currentScene->Render();
        transitionRect.x = 0;
        transitionRect.y += 1200 * Time::unscaledDeltaTime;
        transitionRect.w = 800;
        transitionRect.h = 600;
        SDL_SetRenderDrawColor(WM->SDLRenderer, 0, 0, 0, 255);
        SDL_RenderFillRectF(WM->SDLRenderer, &transitionRect);
        if (transitionRect.y > 600) {
            transitionRect.x = 0;
            transitionRect.y = 0;
            transitionRect.w = 0;
            transitionRect.h = 0;
            sceneState = SceneState::SceneShown;
        }
        break;
    }
    SDL_RenderPresent(WM->SDLRenderer);
}

void SceneManager::CleanUp() {
    if (currentScene) {
        currentScene->CleanUp();
        currentScene = nullptr;
    }
}