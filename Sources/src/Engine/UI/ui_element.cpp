#include "ui_element.hpp"
#include "assert.h"

UI_Element::UI_Element() {
    transform = addComponent<TransformComponent>();
    visual = nullptr;
    //visual = addComponent<ButtonVisualComponent>(WM, _camera, buttonText);
}

void UI_Element::Update() {
    assert(visual);
    if (!visual) return;

    GameState sceneGameState = this->getScene()->gameState;
    for (GameState state : activeStates) {
        if (sceneGameState == state) {
            visual->isActive = true;
            return;
        }
    }
    visual->isActive = false;
}