#include "start_button.hpp"

StartButton::StartButton(WindowManager* WM, Camera* camera) :
    Button(WM, camera, "Start") {
    activeStates.push_back(GameState::MainMenu);
    SetPosition(((Vector2) camera->scale / 2) - defaultScale/2);
}

void StartButton::OnClick() {
    SceneManager* sceneManager = SceneManager::GetInstance();
    sceneManager->SwitchToScene(SceneTag::Game);
}