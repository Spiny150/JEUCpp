#include "main_menu_scene.hpp"
#include "entity.h"
#include "physics_component.hpp"
#include "player.h"
#include "ground.hpp"
#include "button.hpp"
#include "sky.hpp"
#include "start_button.hpp"

void MainMenuScene::Init() {

    this->camera->position = Vector2();
    this->camera->velocity = Vector2();

    Entity* ground = new Ground(WM, camera);

    //Entity* button = new Button(WM, camera, "coucou");
    Entity* startButton = new StartButton(WM, camera);
    Entity* sky = new Sky(WM, camera);

    this->AddEntity(sky);
    this->AddEntity(ground);
    this->AddEntity(startButton);

    this->Start();

    this->gameState = GameState::MainMenu;
}

void MainMenuScene::Update() {
    for (Entity* entity : entities) {
        entity->Update();
    }
}

void MainMenuScene::CleanUp() {
    for (Entity*& entity : this->entities) { // Référence au pointeur pour le modifier
        if (entity) {  // Vérifie que le pointeur est valide
            delete entity;
            entity = nullptr;  // Évite les pointeurs suspendus
        }
    }
    entities.clear();  // Vide le vecteur après suppression
    renderStack.clear();
    std::cout << "Menu cleaned up" << std::endl;
}

MainMenuScene::~MainMenuScene() {
    std::cout << "MainMenu destroyed" << std::endl;
}