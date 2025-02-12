#pragma once

#include "camera.hpp"
#include "entity.h"
#include "transform_component.hpp"
#include "physics_component.hpp"
#include "visual_component.hpp"

class Sky : public Entity {
private:
    TransformComponent* transform;
    VisualComponent* visual;

    Camera* camera;

public:
    Sky(WindowManager* WM);
    ~Sky();

    void Start() override;
    void Update() override;
};

