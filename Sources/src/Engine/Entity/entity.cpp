
#include "window_manager.h"
#include "entity.h"
#include <iostream>
#include <memory>



Entity::Entity(Scene* _scene) : scene(_scene) {
    components = std::unordered_map<std::type_index, std::unique_ptr<Component>>();
    std::cout << "Entity initialisée" << std::endl;
}

Entity::~Entity() {
    /*
    for (auto& [key, comp] : components) {
        delete comp;
    }
    std::cout << "Entity libérée" << std::endl;
    */
}

