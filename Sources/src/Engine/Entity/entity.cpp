#include "window_manager.h"
#include "entity.h"
#include <iostream>
#include <memory>
#include "visual_component.hpp"

// Entity constructor
Entity::Entity() : scene(nullptr) {
    std::cout << "Entity initialized" << std::endl;
}

// Entity destructor
Entity::~Entity() {
    /*
    // Clean up components
    for (auto& [key, comp] : components) {
        delete comp;
    }
    */
    std::cout << "Entity released" << std::endl;
}

// Get the scene this entity belongs to
Scene* Entity::getScene() {
    return this->scene;
}

// Set the scene for this entity
void Entity::setScene(Scene* _scene) {
    this->scene = _scene;
}
