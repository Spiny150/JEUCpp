#include "game_title.hpp"
#include "text_visual_component.hpp"

GameTitle::GameTitle(WindowManager* WM, Camera* camera) {
    SDL_Color textColor = {0, 0, 0, 255};
    visual = addComponent<TextVisualComponent>(WM, camera, "DuckDuckGame", "Assets/Fonts/SuperPixel.ttf", textColor, 52);

    visual->isActive = true;

    Vector2 position = camera->scale / 2 - transform->scale / 2;
    position.y -= 150;
    transform->position = position;

    activeStates.push_back(GameState::MainMenu);
}

void GameTitle::Update() {
    UI_Element::Update();
}