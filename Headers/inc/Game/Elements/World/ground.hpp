#pragma once

#include "camera.hpp"
#include "entity.h"
#include "transform_component.hpp"
#include "physics_component.hpp"
#include "image_visual_component.hpp"

class Ground : public Entity {
private:
    TransformComponent* transform;
    PhysicsComponent* physics;
    ImageVisualComponent* visual;

    Camera* camera;

public:
    Ground(WindowManager* WM, Camera* camera);
    ~Ground();

    void Start() override;
    void Update() override;
};

