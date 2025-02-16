#include "button.hpp"
#include "inputs.h"
#include "scene_manager.hpp"
#include "assert.h"

Button::Button(WindowManager* WM, Camera* _camera, const std::string& buttonText) : camera(_camera) {
    transform = addComponent<TransformComponent>();
    visual = addComponent<ButtonVisualComponent>(WM, _camera, buttonText);

    defaultSize = Vector2();
    centerPosition = Vector2();
    hoverSize = Vector2();
}

void Button::Update() {
    if (!visual->isActive) return;

    SDL_FPoint mousePos = Input::mousePos.getSDL_FPoint();
    SDL_FRect buttonRect = transform->getFRect();

    transform->scale = defaultSize;
    bool isHovered = SDL_PointInFRect(&mousePos, &buttonRect);
    visual->isHovered = isHovered;

    if (isHovered) {
        transform->scale = hoverSize;

        if (Input::isClickPressed()) {
            OnClick();
        }
    }
    transform->position = centerPosition + (transform->scale * -0.5);
}