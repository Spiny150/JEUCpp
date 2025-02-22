#include "button.hpp"
#include "inputs.h"
#include "scene_manager.hpp"
#include "assert.h"

Button::Button(WindowManager* WM, Camera* _camera, const std::string& buttonText) : camera(_camera) {
    transform = addComponent<TransformComponent>();
    visual = addComponent<ButtonVisualComponent>(WM, _camera, buttonText);

    SetPosition(Vector2());
}

void Button::Update() {
    UI_Element::Update();

    if (!visual->isActive) return;

    SDL_FPoint mousePos = Input::mousePos.getSDL_FPoint();
    SDL_FRect buttonRect = transform->getFRect();

    transform->scale = defaultScale;
    bool isHovered = SDL_PointInFRect(&mousePos, &buttonRect);
    ButtonVisualComponent* buttonVisual = (ButtonVisualComponent*) visual;
    buttonVisual->isHovered = isHovered;

    if (isHovered) {
        transform->scale = hoverScale;

        if (Input::isClickPressed()) {
            OnClick();
        }
    }
    transform->position = centerPosition - transform->scale / 2;
}

void Button::SetPosition(Vector2 position) {
    defaultScale = {transform->scale.x, transform->scale.y};

    transform->position = position;

    centerPosition = Vector2(
        transform->position.x + defaultScale.x/2,
        transform->position.y + defaultScale.y/2
    );
    hoverScale = {defaultScale.x * 1.05f, defaultScale.y * 1.05f};
}