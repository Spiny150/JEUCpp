#pragma once

#include <unordered_map>
#include <memory>
#include "window_manager.h"
#include "scene_tag.hpp"

class Scene;

enum class SceneState {
    SceneShown,
    SceneSwitch,
    TransitionIn,
    TransitionOut
};

class SceneManager
{
private:
    std::unordered_map<SceneTag, std::unique_ptr<Scene>> scenes;
    Scene* currentScene;
    SceneTag intendedSceneTag;
    SceneState sceneState;

    WindowManager* WM;
    SDL_FRect transitionRect;

    static SceneManager* instance;

public:
    SceneManager(WindowManager* _WM);
    ~SceneManager();

    static SceneManager* CreateInstance(WindowManager* WM);
    static SceneManager* GetInstance();

    // Ajouter une scène au gestionnaire
    void AddScene(SceneTag tag, std::unique_ptr<Scene> scene);

    // Sélectionner la scène active
    void SwitchToScene(SceneTag tag);

    // Mise à jour de la scène actuelle
    void Update();

    // Nettoyage de la scène actuelle
    void CleanUp();
};

#include "scene.h"

