#include "gray_filter.hpp"
#include "image_visual_component.hpp"

GrayFilter::GrayFilter(WindowManager* WM, Camera* _camera) {
    visual = addComponent<ImageVisualComponent>(WM, _camera, "Assets/Player/Duck.png");
    this->camera = _camera;

    activeStates.push_back(GameState::GameLost);
    activeStates.push_back(GameState::GameWin);
    activeStates.push_back(GameState::Paused);
}

void GrayFilter::Update() {
    UI_Element::Update();
    transform->position = camera->position;
}