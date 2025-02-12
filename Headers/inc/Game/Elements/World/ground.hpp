#pragma once

#include "camera.hpp"
#include "entity.h"
#include "transform_component.hpp"
#include "physics_component.hpp"
#include "visual_component.hpp"

class Ground : public Entity {
private:
    TransformComponent* transform;
    PhysicsComponent* physics;
    VisualComponent* visual;

    Camera* camera;

public:
    Ground(WindowManager* WM);
    ~Ground();

    void Start() override;
    void Update() override;
};

