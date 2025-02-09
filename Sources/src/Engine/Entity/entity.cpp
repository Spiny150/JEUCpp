
#include "window_manager.h"
#include "entity.h"
#include <iostream>
#include <memory>
#include "entity_visual.h"


Entity::Entity() : scene(nullptr) {
    std::cout << "Entity initialisée" << std::endl;
}

Entity::~Entity() {
    /*
    for (auto& [key, comp] : components) {
        delete comp;
    }
    */
    std::cout << "Entity libérée" << std::endl;
}

Scene* Entity::getScene() {
    return this->scene;
}

void Entity::setScene(Scene* _scene) {
    this->scene = _scene;
}