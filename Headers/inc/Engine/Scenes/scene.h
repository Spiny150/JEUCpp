#pragma once

#include "window_manager.h"
#include "entity.h"
#include "scene_manager.hpp"
#include "camera.hpp"
#include <vector>
#include <map>

class Scene {
protected:
    std::vector<Entity*> entities;
    std::multimap<int, Entity*> renderStack;    // Ordre de rendu basé sur le layer

public:
    WindowManager* WM;
    Camera* camera;
    Scene(WindowManager* _WM);
    ~Scene();

    void AddEntity(Entity* entity);

    void setEntityRenderLayer(Entity* entity, int renderLayer);
    void Render();

    virtual void Start();
    virtual void Update();

    virtual void Init();
    virtual void CleanUp();
    virtual SceneTag GetTag();
};
