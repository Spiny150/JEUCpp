#include "button.hpp"
#include "inputs.h"
#include "scene_manager.hpp"
#include "assert.h"

Button::Button(WindowManager* WM, Camera* _camera, const std::string& buttonText) : camera(_camera) {
    transform = addComponent<TransformComponent>();
    visual = addComponent<ButtonVisualComponent>(WM, _camera, buttonText);

    defaultScale = {transform->scale.x, transform->scale.y};
    transform->position = ((Vector2) camera->scale / 2) - defaultScale/2;

    centerPosition = Vector2(
        transform->position.x + defaultScale.x/2,
        transform->position.y + defaultScale.y/2
    );
    hoverScale = {defaultScale.x * 1.05f, defaultScale.y * 1.05f};
}

void Button::Update() {
    UI_Element::Update();

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