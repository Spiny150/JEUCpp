#include "gray_filter.hpp"

GrayFilter::GrayFilter(WindowManager* WM, Camera* _camera) {
    visual = addComponent<ImageVisualComponent>(WM, _camera, "Assets/World/gray_filter.png");
    visual->isActive = false;

    this->camera = _camera;

    activeStates.push_back(GameState::GameLost);
    activeStates.push_back(GameState::GameWin);
    activeStates.push_back(GameState::Paused);
}

void GrayFilter::Update() {
    UI_Element::Update();
    transform->position = camera->position;
}