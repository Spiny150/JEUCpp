#include "game_scene.hpp"
#include "entity.h"
#include "physics_component.hpp"
#include "player.h"
#include "ground.hpp"
#include "button.hpp"
#include "sky.hpp"

void GameScene::Init() {

    this->camera->position = Vector2();
    this->camera->velocity = Vector2();

    Entity* player = new Player(WM, camera);
    Entity* ground  = new Ground(WM, camera);
    Entity* ground2  = new Ground(WM, camera);

    Entity* button = new Button(WM, camera);
    Entity* sky = new Sky(WM, camera);

    this->AddEntity(sky);
    this->AddEntity(player);
    this->AddEntity(ground2);
    this->AddEntity(ground);
    this->AddEntity(button);

    this->Start();
    ground2->getComponent<TransformComponent>()->position.x = camera->scale.x;
    ground2->getComponent<TransformComponent>()->position.y += 0;
}

void GameScene::Update() {

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

void GameScene::CleanUp() {
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

GameScene::~GameScene() {
    std::cout << "GameScene destroyed" << std::endl;
}