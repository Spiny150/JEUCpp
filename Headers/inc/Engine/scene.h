#pragma once

#include "window_manager.h"
#include "entity.h"

#include <vector>
#include <map>

class Scene {
private:
    std::vector<Entity*> entities;
    std::multimap<int, Entity*> renderStack;    // Ordre de rendu basé sur le layer

public:
    WindowManager* WM;
    Scene(WindowManager* _WM);
    ~Scene();

    void Clear();
    void AddEntity(Entity* entity);

    void setEntityRenderLayer(Entity* entity, int renderLayer);

    void Start();
    void Update();
    void Render();
};
