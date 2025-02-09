#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <iostream>
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "component.h"

class WindowManager;
class Scene;

class Entity
{
private:
    std::unordered_map<std::type_index, std::unique_ptr<Component>> components;
protected:
    Scene* scene;

public:

    Entity(Scene* _scene);
    virtual ~Entity();

    template<typename T, typename... Args>
    T* addComponent(Args&&... args);

    template<typename T>
    T* getComponent();

    virtual void Start() {};
    virtual void Update() {};

};
#include "entity.tpp"

#include "window_manager.h"
#include "scene.h"

#endif