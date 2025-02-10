#pragma once

#include "entity.h"
#include "entity_transform.h"
#include "entity_visual.h"

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
