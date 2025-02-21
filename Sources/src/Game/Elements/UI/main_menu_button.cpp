#include "main_menu_button.hpp"

MainMenuButton::MainMenuButton(WindowManager* WM, Camera* camera) :
    Button(WM, camera, "Main Menu") {
    visual->isActive = false;
    activeStates.push_back(GameState::Paused);
    Vector2 position = ((Vector2) camera->scale / 2) - defaultScale/2;
    position.y += 100;
    SetPosition(position);
}

void MainMenuButton::OnClick() {
    SceneManager* sceneManager = SceneManager::GetInstance();
    sceneManager->SwitchToScene(SceneTag::MainMenu);
}