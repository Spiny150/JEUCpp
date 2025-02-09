#include "scene.h"
#include "entity_physics.h"
#include "entity_visual.h"

Scene::Scene(WindowManager* _WM) : WM(_WM) {
    std::cout << "Scene initialisée" << std::endl;
}

Scene::~Scene() {
    this->CleanUp();
    std::cout << "Scene libérée" << std::endl;
}

void Scene::Init() {
    // To override
}

void Scene::CleanUp() {
    for (Entity*& entity : this->entities) { // Référence au pointeur pour le modifier
        if (entity) {  // Vérifie que le pointeur est valide
            delete entity;
            entity = nullptr;  // Évite les pointeurs suspendus
        }
    }
    entities.clear();  // Vide le vecteur après suppression
}

void Scene::setEntityRenderLayer(Entity* entity, int renderLayer) {
    renderStack.insert({renderLayer, entity});
}

void Scene::AddEntity(Entity* entity) {
    entities.push_back(entity);
    entity->setScene(this);

    VisualComponent* visual = entity->getComponent<VisualComponent>();
    if (visual) this->setEntityRenderLayer(entity, visual->renderLayer);
}

void Scene::Start() {
    for (Entity* entity : entities) {
        entity->Start();
    }
}

void Scene::Update() {
    // To override
}

void Scene::Render() {
    SDL_RenderClear(WM->SDLRenderer);
    for (const auto& [layer, entity] : renderStack) {
        VisualComponent* visual = entity->getComponent<VisualComponent>();
        if (!visual) continue;
        visual->render(WM->SDLRenderer);
    }
    SDL_RenderPresent(WM->SDLRenderer);
}

SceneTag Scene::GetTag() {
    return SceneTag::Undefined;
}