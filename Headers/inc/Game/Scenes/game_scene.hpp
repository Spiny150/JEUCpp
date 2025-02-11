#pragma once

#include "scene.h"

class GameScene : public Scene {
public:
    GameScene(WindowManager* WM) : Scene(WM) {};
    ~GameScene();

    void Init() override;
    void Update() override;
    void CleanUp() override;

    SceneTag GetTag() override {
        return SceneTag::MainMenu;
    }
};