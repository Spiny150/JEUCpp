#include "game_scene.hpp"
#include "entity.h"
#include "physics_component.hpp"
#include "player.h"
#include "ground.hpp"
#include "button.hpp"
#include "sky.hpp"
#include "start_button.hpp"
#include "tube.hpp"
#include "gray_filter.hpp"
#include "time.hpp"
#include "inputs.h"

void GameScene::Init() {

    this->camera->position = Vector2();
    this->camera->velocity = Vector2();

    Entity* player = new Player(WM, camera);
    Entity* ground = new Ground(WM, camera);
    Entity* ground2 = new Ground(WM, camera);

    Entity* tube1 = new Tube(WM, camera, Vector2(212.5 * 1, -400), SDL_FLIP_VERTICAL);
    Entity* tube2 = new Tube(WM, camera, Vector2(212.5 * 1, 500), SDL_FLIP_NONE);
    Entity* tube3 = new Tube(WM, camera, Vector2(212.5 * 2, -400), SDL_FLIP_VERTICAL);
    Entity* tube4 = new Tube(WM, camera, Vector2(212.5 * 2, 500), SDL_FLIP_NONE);
    Entity* tube5 = new Tube(WM, camera, Vector2(212.5 * 3, -400), SDL_FLIP_VERTICAL);
    Entity* tube6 = new Tube(WM, camera, Vector2(212.5 * 3, 500), SDL_FLIP_NONE);
    Entity* tube7 = new Tube(WM, camera, Vector2(212.5 * 4, -400), SDL_FLIP_VERTICAL);
    Entity* tube8 = new Tube(WM, camera, Vector2(212.5 * 4, 500), SDL_FLIP_NONE);
    Entity* gray_filter = new GrayFilter(WM, camera);

    //Entity* button = new Button(WM, camera, "coucou");
    Entity* sky = new Sky(WM, camera);

    this->AddEntity(sky);
    this->AddEntity(player);
    this->AddEntity(ground2);
    this->AddEntity(ground);
    this->AddEntity(tube1);
    this->AddEntity(tube2);
    this->AddEntity(tube3);
    this->AddEntity(tube4);
    this->AddEntity(tube5);
    this->AddEntity(tube6);
    this->AddEntity(tube7);
    this->AddEntity(tube8);
    this->AddEntity(gray_filter);

    this->Start();
    this->camera->velocity = Vector2(200, 0);
    ground2->getComponent<TransformComponent>()->position.x = camera->scale.x;
    this->gameState = GameState::Running;
}

void GameScene::Update() {
    if (Input::isKeyPressed(SDL_SCANCODE_ESCAPE)) {
        Time::timeScale = !Time::timeScale;
        if (gameState == GameState::Running) {
            this->gameState = GameState::Paused;
        } else {
            gameState = GameState::Running;
        }
    }

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