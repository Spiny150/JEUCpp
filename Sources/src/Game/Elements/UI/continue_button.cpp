#include "continue_button.hpp"
#include "Engine/time.hpp"

ContinueButton::ContinueButton(WindowManager* WM, Camera* camera) :
    Button(WM, camera, "Continue") {
    visual->isActive = false;
    activeStates.push_back(GameState::Paused);
    Vector2 position = ((Vector2) camera->scale / 2) - defaultScale/2;
    position.y -= 100;
    SetPosition(position);
}

void ContinueButton::OnClick() {
    this->getScene()->gameState = GameState::Running;
    Time::timeScale = 1;
}