#include "high_score_text.hpp"
#include "text_visual_component.hpp"
#include "score_manager.hpp"

HighScoreText::HighScoreText(WindowManager* WM, Camera* camera) {
    visual = addComponent<TextVisualComponent>(WM, camera, "Highscore : ");

    visual->isActive = true;
    this->camera = camera;

    transform->position = Vector2(0, 0);

    activeStates.push_back(GameState::Running);

}

void HighScoreText::Update() {
    UI_Element::Update();

    ScoreManager* scoreManager = ScoreManager::GetInstance();
    TextVisualComponent* textVisual = (TextVisualComponent*) visual;

    int bestScore = scoreManager->getBestScore(this->getScene()->GetTag());
    textVisual->UpdateText(std::string("Highscore : ") + std::to_string(bestScore));
}