#pragma once

#include "entity.h"

template<typename T, typename... Args>
T* Entity::addComponent(Args&&... args) {
    auto component = std::make_unique<T>(*this, std::forward<Args>(args)...);
    T* ptr = component.get();
    components[typeid(T)] = std::move(component);
    return ptr;
}

template<typename T>
T* Entity::getComponent() {
    auto it = components.find(typeid(T));
    return (it != components.end()) ? static_cast<T*>(it->second.get()) : nullptr;
}