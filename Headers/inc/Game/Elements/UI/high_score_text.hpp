#pragma once

#include "ui_element.hpp"

class HighScoreText : public UI_Element {
private:
    Camera* camera;
public:
    HighScoreText(WindowManager* WM, Camera* camera);
    virtual ~HighScoreText() = default;

    void Update() override;
};