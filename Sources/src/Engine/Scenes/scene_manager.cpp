#include "scene_manager.hpp"

SceneManager::SceneManager() : currentScene(nullptr) {
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
    if (currentScene) {
        currentScene->CleanUp();
    }

    currentScene = scenes[tag].get();
    currentScene->Init();
}

void SceneManager::Update() {
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