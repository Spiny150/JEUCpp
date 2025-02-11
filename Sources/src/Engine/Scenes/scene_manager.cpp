#include "scene_manager.hpp"
#include "assert.h"

SceneManager::SceneManager() :
    currentScene(nullptr),
    intendedSceneTag(SceneTag::Undefined),
    reloadScene(true) {
        std::cout << "SceneManager instanciated" << std::endl;
}
SceneManager::~SceneManager() {
    std::cout << "SceneManager destroyed" << std::endl;
}


SceneManager* SceneManager::instance = nullptr;  // Définition de l'instance unique

SceneManager* SceneManager::GetInstance() {
    if (!instance) {
        instance = new SceneManager();
    }
    return instance;
}

void SceneManager::AddScene(SceneTag tag, std::unique_ptr<Scene> scene) {
    scenes[tag] = std::move(scene);
}

void SceneManager::SwitchToScene(SceneTag tag) {
    intendedSceneTag = tag;
    reloadScene = true;
}

void SceneManager::Update() {
    if (reloadScene) {
        reloadScene = false;
        // Possibilité d'ajouter animation de changement de scene ici
        if (currentScene) {
            currentScene->CleanUp();
        }

        currentScene = scenes[intendedSceneTag].get();

        assert(currentScene != nullptr);
        if (currentScene) {
            currentScene->Init();
        }
    }

    if (currentScene) {
        currentScene->Update();
    }
}

void SceneManager::Render() {
    if (currentScene) {
        currentScene->Render();
    }
}

void SceneManager::CleanUp() {
    if (currentScene) {
        currentScene->CleanUp();
        currentScene = nullptr;
    }
}