#pragma once

#include "entity.h"
#include "transform_component.hpp"
#include "button_visual_component.hpp"
#include "camera.hpp"

class Button : public Entity
{
public:
    TransformComponent* transform;
    ButtonVisualComponent* visual;

    Vector2 centerPosition;
    Vector2 defaultSize;
    Vector2 hoverSize;

    Camera* camera;
    
    Button(WindowManager* WM, Camera* camera, const std::string& buttonText);
    ~Button() = default;

    virtual void OnClick() {};

    void Update() override;
};
