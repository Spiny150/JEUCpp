#pragma once

#include "camera.hpp"
#include "entity.h"
#include "entity_transform.h"
#include "entity_physics.h"
#include "entity_visual.h"

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

