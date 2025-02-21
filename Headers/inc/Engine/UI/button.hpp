#pragma once

#include "ui_element.hpp"
#include "transform_component.hpp"
#include "button_visual_component.hpp"
#include "camera.hpp"

class Button : public UI_Element
{
public:

    Vector2 centerPosition;
    Vector2 defaultScale;
    Vector2 hoverScale;

    Camera* camera;
    
    Button(WindowManager* WM, Camera* camera, const std::string& buttonText);
    ~Button() = default;

    virtual void OnClick() {};

    void Update() override;
};
