#include "gameover_text.hpp"

GameoverText::GameoverText(WindowManager* WM, Camera* _camera) {
    visual = addComponent<ImageVisualComponent>(WM, _camera, "Assets/World/gameover.png");
    visual->isActive = false;

    this->camera = _camera;

    activeStates.push_back(GameState::GameLost);
}

void GameoverText::Update() {
    UI_Element::Update();
    Vector2 position =
        camera->position +
        camera->scale / 2 -
        transform->scale / 2;
    position.y -= 200;
    transform->position = position;
}