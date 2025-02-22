#include "scene.h"
#include "physics_component.hpp"
#include "visual_component.hpp"
#include "assert.h"

// Scene constructor
Scene::Scene(WindowManager* _WM) : WM(_WM), gameState(GameState::Undefined) {
    // Create camera with window size
    this->camera = new Camera(WM->windowSize);
    std::cout << "Scene initialized" << std::endl;
}

// Scene destructor
Scene::~Scene() {
    // Clean up resources
    this->CleanUp();
    std::cout << "Scene released" << std::endl;
}

// Initialize the scene (to be overridden by derived classes)
void Scene::Init() {
    // To override
}

// Clean up scene resources
void Scene::CleanUp() {
    // Delete camera
    if (camera) {
        delete camera;
        camera = nullptr;
    }

    // Delete all entities
    for (Entity*& entity : this->entities) {
        if (entity) {
            delete entity;
            entity = nullptr; // Avoid dangling pointer
        }
    }
    entities.clear(); // Empty entity vector
    renderStack.clear();
    std::cout << "Scene Cleaned Up" << std::endl;
}

// Set entity's render layer
void Scene::setEntityRenderLayer(Entity* entity, int renderLayer) {
    renderStack.insert({renderLayer, entity});
}

// Add entity to the scene
void Scene::AddEntity(Entity* entity) {
    entities.push_back(entity);
    entity->setScene(this);

    // Add to render stack if it has a visual component
    VisualComponent* visual = entity->getComponent<VisualComponent>();
    if (visual) this->setEntityRenderLayer(entity, visual->renderLayer);
}

// Start all entities in the scene
void Scene::Start() {
    for (Entity* entity : entities) {
        entity->Start();
    }
}

// Update scene logic (to be overridden by derived classes)
void Scene::Update() {
    // To override
}

// Render all entities in the scene
void Scene::Render() {
    // Render entities in order of their render layers
    for (const auto& [layer, entity] : renderStack) {
        VisualComponent* visual = entity->getComponent<VisualComponent>();
        if (!visual) continue;
        visual->Render();
    }
}

// Get scene tag (to be overridden by derived classes)
SceneTag Scene::GetTag() {
    return SceneTag::Undefined;
}
