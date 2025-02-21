#pragma once

#include "button.hpp"
#include "window_manager.h"
#include "camera.hpp"

class MainMenuButton : public Button {
public:
    MainMenuButton(WindowManager* WM, Camera* camera);
    virtual ~MainMenuButton() = default;

    void OnClick() override;
};