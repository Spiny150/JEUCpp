#pragma once

#include "scene.h"

class GameSceneHarder : public Scene {
public:
    GameSceneHarder(WindowManager* WM) : Scene(WM) {};
    ~GameSceneHarder();

    void Init() override;
    void Update() override;
    void CleanUp() override;

    SceneTag GetTag() override {
        return SceneTag::GameHard;
    }
};