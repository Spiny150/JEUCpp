#pragma once

#include "entity.h"
#include "transform_component.hpp"
#include "image_visual_component.hpp"
#include "camera.hpp"

class Button : public Entity
{
public:
    TransformComponent* transform;
    ImageVisualComponent* visual;

    Vector2 centerPosition;
    Vector2 defaultSize;
    Vector2 hoverSize;
    
    Button(WindowManager* WM, Camera* camera);
    ~Button();

    void Update() override;
    void Start() override;
};
