#include "button.hpp"
#include "inputs.h"

Button::Button(WindowManager* WM) {
    transform = addComponent<TransformComponent>();
    visual = addComponent<VisualComponent>();


    visual->setSprite("Assets/Player/Duck.png", WM);
}

Button::~Button() {

}

void Button::Update() {
    SDL_FPoint mousePos = Input::mousePos.getSDL_FPoint();
    SDL_FRect buttonRect = transform->getFRect();

    transform->scale = defaultSize;
    if (SDL_PointInFRect(&mousePos, &buttonRect)) {
        transform->scale = hoverSize;
    }
    transform->position = centerPosition + (transform->scale * -0.5);
}

void Button::Start() {
    defaultSize = {transform->scale.x, transform->scale.y};
    centerPosition = Vector2(
        transform->position.x + defaultSize.x/2,
        transform->position.y + defaultSize.y/2
    );
    hoverSize = {defaultSize.x + 50, defaultSize.y + 50};
}