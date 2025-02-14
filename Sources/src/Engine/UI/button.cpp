#include "button.hpp"
#include "inputs.h"
#include "scene_manager.hpp"
#include "assert.h"

Button::Button(WindowManager* WM, Camera* camera, const std::string& buttonText) {
    transform = addComponent<TransformComponent>();
    visual = addComponent<ButtonVisualComponent>(WM, camera, buttonText);

    defaultSize = {transform->scale.x, transform->scale.y};
    centerPosition = Vector2(
        transform->position.x + defaultSize.x/2,
        transform->position.y + defaultSize.y/2
    );
    hoverSize = {defaultSize.x * 1.05f, defaultSize.y * 1.05f};
}

Button::~Button() {}

void Button::OnClick() {
    SceneManager* sceneManager = SceneManager::GetInstance();
    sceneManager->SwitchToScene(SceneTag::Game);
}

void Button::Update() {
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