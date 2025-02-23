#include "restart_button.hpp"

RestartButton::RestartButton(WindowManager* WM, Camera* camera) :
    Button(WM, camera, "Restart") {
    visual->isActive = false;
    activeStates.push_back(GameState::Paused);
    activeStates.push_back(GameState::GameLost);
    activeStates.push_back(GameState::GameWin);
    Vector2 position = ((Vector2) camera->scale / 2) - defaultScale/2;
    SetPosition(position);
}

void RestartButton::OnClick() {
    SceneManager* sceneManager = SceneManager::GetInstance();
    sceneManager->SwitchToScene(SceneTag::Game);
}