#pragma once

#include "entity.h"
#include "transform_component.hpp"
#include "visual_component.hpp"

class Button : public Entity
{
public:
    TransformComponent* transform;
    VisualComponent* visual;

    Vector2 centerPosition;
    Vector2 defaultSize;
    Vector2 hoverSize;
    
    Button(WindowManager* WM);
    ~Button();

    void Update() override;
    void Start() override;
};
