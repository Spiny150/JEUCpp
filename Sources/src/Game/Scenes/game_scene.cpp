#include "game_scene.hpp"
#include "entity.h"
#include "entity_physics.h"
#include "player.h"
#include "ground.hpp"
#include "button.hpp"

void MainMenuScene::Init() {

    this->camera->position = Vector2();
    this->camera->velocity = Vector2();

    Entity* player = new Player(this->WM);
    Entity* ground  = new Ground(this->WM);
    Entity* ground2  = new Ground(this->WM);
    Entity* ground3  = new Ground(this->WM);

    Entity* button = new Button(this->WM);
    
    this->AddEntity(player);
    this->AddEntity(ground3);
    this->AddEntity(ground2);
    this->AddEntity(ground);
    this->AddEntity(button);

    this->Start();
    ground2->getComponent<TransformComponent>()->position.x = camera->scale.x;
    ground2->getComponent<TransformComponent>()->position.y += 0;
    ground3->getComponent<TransformComponent>()->position.y = 80;
}

void MainMenuScene::Update() {

    for (Entity* entity : entities) {
        entity->Update();
        PhysicsComponent* physics = entity->getComponent<PhysicsComponent>();
        if (physics) physics->computeNextPosition();
    }

    for (Entity* entityA : entities) {
        for (Entity* entityB : entities) {
            if (entityA == entityB) continue;
            PhysicsComponent* physicsA = entityA->getComponent<PhysicsComponent>();
            if (physicsA) physicsA->checkCollision(entityB);
        }
    }

    for (Entity* entity : entities) {
        //Manage collisions
        PhysicsComponent* physics = entity->getComponent<PhysicsComponent>();
        if (physics) physics->applyNextPosition();
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
    std::cout << "MainMenuScene destroyed" << std::endl;
}