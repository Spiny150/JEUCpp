#pragma once

#include <unordered_map>
#include <memory>

class Scene;

enum class SceneTag {
    Undefined,
    MainMenu,
    Game
};

class SceneManager
{
private:
    std::unordered_map<SceneTag, std::unique_ptr<Scene>> scenes;
    Scene* currentScene;

    static SceneManager* instance;

public:
    SceneManager();
    ~SceneManager();

    static SceneManager* GetInstance();

    // Ajouter une scène au gestionnaire
    void AddScene(SceneTag tag, std::unique_ptr<Scene> scene);

    // Sélectionner la scène active
    void SwitchToScene(SceneTag tag);

    // Mise à jour de la scène actuelle
    void Update();

    // Rendu de la scène actuelle
    void Render();

    // Nettoyage de la scène actuelle
    void CleanUp();
};

#include "scene.h"

