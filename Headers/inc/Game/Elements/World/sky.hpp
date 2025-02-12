#pragma once

#include "camera.hpp"
#include "entity.h"
#include "entity_transform.h"
#include "entity_physics.h"
#include "entity_visual.h"

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

