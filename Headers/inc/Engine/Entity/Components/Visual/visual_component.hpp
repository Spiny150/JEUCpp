#pragma once

#include <SDL2/SDL_image.h>
#include <iostream>
#include "component.hpp"
#include "transform_component.hpp"
#include "camera.hpp"
#include "window_manager.h"

class WindowManager;

class VisualComponent : public Component {
protected:
    TransformComponent* transform;
    WindowManager* WM;
    Camera* camera;
public:
    int renderLayer;

    VisualComponent(Entity& entity, WindowManager* _WM, Camera* camera);
    virtual ~VisualComponent() = default;

    void setRenderLayer(int renderLayer);

    //WindowManager* getWindowManager();
    //Camera* getCamera();
    //TransformComponent* getTransform();

    virtual void Render() = 0;
};
