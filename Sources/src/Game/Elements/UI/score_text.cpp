#include "score_text.hpp"
#include "text_visual_component.hpp"
#include "score_manager.hpp"

ScoreText::ScoreText(WindowManager* WM, Camera* camera) {
    visual = addComponent<TextVisualComponent>(WM, camera, "1");

    visual->isActive = true;
    this->camera = camera;

    transform->position = Vector2(camera->scale.x / 2, 0);

    activeStates.push_back(GameState::Running);
}

void ScoreText::Update() {
    UI_Element::Update();

    ScoreManager* scoreMananger = ScoreManager::GetInstance();
    TextVisualComponent* textVisual = (TextVisualComponent*) visual;

    int currentScore = scoreMananger->getCurrentScore(this->getScene()->GetTag());
    textVisual->UpdateText(std::to_string(currentScore));
}