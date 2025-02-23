#include "scene_manager.hpp"
#include "assert.h"
#include "time.hpp"
#include "score_manager.hpp"

// SceneManager constructor
SceneManager::SceneManager(WindowManager* _WM) :
    currentScene(nullptr),
    intendedSceneTag(SceneTag::Undefined),
    sceneState(SceneState::SceneSwitch),
    WM(_WM),
    transitionRect({0, 0, 0, 0}) {
        std::cout << "SceneManager instantiated" << std::endl;
}

// SceneManager destructor
SceneManager::~SceneManager() {
    std::cout << "SceneManager destroyed" << std::endl;
}

// Singleton instance
SceneManager* SceneManager::instance = nullptr;

// Create singleton instance
SceneManager* SceneManager::CreateInstance(WindowManager* WM) {
    assert(!instance);
    instance = new SceneManager(WM);
    return instance;
}

// Get singleton instance
SceneManager* SceneManager::GetInstance() {
    assert(instance);
    return instance;
}

// Add a scene to the manager
void SceneManager::AddScene(SceneTag tag, std::unique_ptr<Scene> scene) {
    scenes[tag] = std::move(scene);
}

// Switch to a different scene
void SceneManager::SwitchToScene(SceneTag tag) {
    ScoreManager* scoreManager = ScoreManager::GetInstance();
    scoreManager->saveScores("scores.data");

    intendedSceneTag = tag;
    sceneState = SceneState::TransitionOut;
}

// Update scene manager state
void SceneManager::Update() {
    assert(WM && WM->SDLRenderer);
    SDL_RenderClear(WM->SDLRenderer);

    switch (sceneState) {
        case SceneState::SceneShown:
            if (currentScene) {
                currentScene->camera->Update();
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
            if (!currentScene) {
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
                transitionRect = {0, 0, 0, 0};
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
                transitionRect = {0, 0, 0, 0};
                sceneState = SceneState::SceneShown;
            }
            break;
    }

    SDL_RenderPresent(WM->SDLRenderer);
}

// Clean up scene manager resources
void SceneManager::CleanUp() {
    if (currentScene) {
        currentScene->CleanUp();
        currentScene = nullptr;
    }
}
