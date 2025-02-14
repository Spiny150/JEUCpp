#include "start_button.hpp"

StartButton::StartButton(WindowManager* WM, Camera* camera) :
    Button(WM, camera, "Start") {
    defaultSize = {transform->scale.x, transform->scale.y};
    transform->position = ((Vector2) camera->scale / 2) - defaultSize/2;

    centerPosition = Vector2(
        transform->position.x + defaultSize.x/2,
        transform->position.y + defaultSize.y/2
    );
    hoverSize = {defaultSize.x * 1.05f, defaultSize.y * 1.05f};
}

void StartButton::OnClick() {
    SceneManager* sceneManager = SceneManager::GetInstance();
    sceneManager->SwitchToScene(SceneTag::Game);
}