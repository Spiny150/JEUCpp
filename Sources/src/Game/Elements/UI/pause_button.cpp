#include "pause_button.hpp"
#include "Engine/time.hpp"

PauseButton::PauseButton(WindowManager* WM, Camera* camera) :
    Button(WM, camera, "Pause") {
    visual->isActive = true;
    activeStates.push_back(GameState::Running);
    Vector2 position = (Vector2) camera->scale - (defaultScale + hoverScale)/2;
    SetPosition(position);
}

void PauseButton::OnClick() {
    this->getScene()->gameState = GameState::Paused;
    Time::timeScale = 0;
}