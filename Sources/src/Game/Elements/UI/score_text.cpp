#include "score_text.hpp"
#include "text_visual_component.hpp"

ScoreText::ScoreText(WindowManager* WM, Camera* camera) {
    visual = addComponent<TextVisualComponent>(WM, camera, "1");

    visual->isActive = true;
    this->camera = camera;

    transform->position = Vector2(camera->scale.x / 2, 0);

    activeStates.push_back(GameState::Running);
}

void ScoreText::Update() {
    UI_Element::Update();

    int random = rand() % 10000;
    if (random >= 9999) {
        TextVisualComponent* visualComponent = (TextVisualComponent*) visual;
        visualComponent->UpdateText(std::to_string(rand() % 10));
    }
}