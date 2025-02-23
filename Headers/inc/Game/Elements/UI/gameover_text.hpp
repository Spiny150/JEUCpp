#pragma once

#include "ui_element.hpp"
#include "image_visual_component.hpp"

class GameoverText : public UI_Element {
private:
    Camera* camera;
public:
    GameoverText(WindowManager* WM, Camera* _camera);
    virtual ~GameoverText() = default;

    void Update() override;
};