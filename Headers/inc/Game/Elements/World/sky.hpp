#pragma once

#include "camera.hpp"
#include "entity.h"
#include "transform_component.hpp"
#include "physics_component.hpp"
#include "image_visual_component.hpp"

class Sky : public Entity {
private:
    TransformComponent* transform;
    ImageVisualComponent* visual;

    Camera* camera;

public:
    Sky(WindowManager* WM, Camera* camera);
    ~Sky();

    void Start() override;
    void Update() override;
};

