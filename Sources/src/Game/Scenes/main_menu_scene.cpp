#include "main_menu_scene.hpp"
#include "entity.h"
#include "physics_component.hpp"
#include "player.h"
#include "ground.hpp"
#include "button.hpp"
#include "sky.hpp"
#include "start_button.hpp"
#include "start_hard_button.hpp"

// Initialize the main menu scene
void MainMenuScene::Init() {
    // Reset camera position and velocity
    this->camera->position = Vector2();
    this->camera->velocity = Vector2();

    // Create ground entity
    Entity* ground = new Ground(WM, camera);

    // Create start button and sky entities
    Entity* startButton = new StartButton(WM, camera);
    Entity* startHardButton = new StartHardButton(WM, camera);
    Entity* sky = new Sky(WM, camera);

    // Add entities to the scene
    this->AddEntity(sky);
    this->AddEntity(ground);
    this->AddEntity(startButton);
    this->AddEntity(startHardButton);

    // Start the scene and set initial game state
    this->Start();
    this->gameState = GameState::MainMenu;
}

// Update main menu logic every frame
void MainMenuScene::Update() {
    // Update all entities in the scene
    for (Entity* entity : entities) {
        entity->Update();
    }
}

// Clean up resources when the scene ends
void MainMenuScene::CleanUp() {
    // Delete all entities and clear the list
    for (Entity*& entity : this->entities) {
        if (entity) {
            delete entity;
            entity = nullptr;
        }
    }
    entities.clear();
    renderStack.clear();
    std::cout << "Menu cleaned up" << std::endl;
}

// Destructor
MainMenuScene::~MainMenuScene() {
    std::cout << "MainMenu destroyed" << std::endl;
}
