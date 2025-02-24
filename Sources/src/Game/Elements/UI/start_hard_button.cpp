#include "start_hard_button.hpp"

StartHardButton::StartHardButton(WindowManager* WM, Camera* camera) :
    Button(WM, camera, "Start Hard Mode") {
    activeStates.push_back(GameState::MainMenu);
    Vector2 position = ((Vector2) camera->scale / 2) - defaultScale/2;
    position.y += 100;
    SetPosition(position);
}

void StartHardButton::OnClick() {
    SceneManager* sceneManager = SceneManager::GetInstance();
    sceneManager->SwitchToScene(SceneTag::GameHard);
}