#include "scene.h"
#include "entity_physics.h"
#include "entity_visual.h"

Scene::Scene(WindowManager* _WM) : WM(_WM) {
    std::cout << "Scene initialisée" << std::endl;
}

Scene::~Scene() {
    this->Clear();
    std::cout << "Scene libérée" << std::endl;
}

void Scene::Clear() {
    for (Entity*& entity : this->entities) { // Référence au pointeur pour le modifier
        if (entity) {  // Vérifie que le pointeur est valide
            delete entity;
            entity = nullptr;  // Évite les pointeurs suspendus
        }
    }
    entities.clear();  // Vide le vecteur après suppression
}

void Scene::AddEntity(Entity* entity) {
    entities.push_back(entity);
}

void Scene::Start() {
    for (Entity* entity : entities) {
        entity->Start();
    }
}

void Scene::Update() {
    SDL_RenderClear(WM->SDLRenderer);

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

    for (Entity* entity : entities) {
        VisualComponent* visual = entity->getComponent<VisualComponent>();
        visual->render(WM->SDLRenderer);
    }
    SDL_RenderPresent(WM->SDLRenderer);
}