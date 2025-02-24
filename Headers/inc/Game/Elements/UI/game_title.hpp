#pragma once

#include "ui_element.hpp"

class GameTitle : public UI_Element {
public:
    GameTitle(WindowManager* WM, Camera* camera);
    virtual ~GameTitle() = default;

    void Update() override;
};