#pragma once

#include "scene.h"

class MainMenuScene : public Scene {
public:
    MainMenuScene(WindowManager* WM) : Scene(WM) {};
    ~MainMenuScene();

    void Init() override;
    void Update() override;
    void CleanUp() override;

    SceneTag GetTag() override {
        return SceneTag::MainMenu;
    }
};