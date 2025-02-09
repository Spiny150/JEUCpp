#ifndef SCENE_H
#define SCENE_H

#include "window_manager.h"
#include "entity.h"

#include <vector>

class Scene {
private:
    std::vector<Entity*> entities;

public:
    WindowManager* WM;
    Scene(WindowManager* _WM);
    ~Scene();
    void Clear();
    void AddEntity(Entity* entity);

    void Start();
    void Update();
};

#endif