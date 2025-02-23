#pragma once

#include "ui_element.hpp"

class ScoreText : public UI_Element {
private:
    Camera* camera;
public:
    ScoreText(WindowManager* WM, Camera* camera);
    virtual ~ScoreText() = default;

    void Update() override;
};