#include "game_scene.hpp"
#include "entity.h"
#include "entity_physics.h"
#include "player.h"

void MainMenuScene::Init() {
    Entity* player = new Player(this->WM);
    this->AddEntity(player);

    this->Start();
}

void MainMenuScene::Update() {

    for (Entity* entity : entities) {
        entity->Update();
        PhysicsComponent* physics = entity->getComponent<PhysicsComponent>();
        physics->computeNextPosition();
    }

    for (Entity* entity : entities) {
        //Manage collisions
        PhysicsComponent* physics = entity->getComponent<PhysicsComponent>();
        physics->applyNextPosition();
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
    std::cout << "Menu cleaned up" << std::endl;
}

MainMenuScene::~MainMenuScene() {
    std::cout << "MainMenuScene destroyed" << std::endl;
}