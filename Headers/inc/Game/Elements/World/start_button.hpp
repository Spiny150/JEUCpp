#pragma once

#include "button.hpp"
#include "window_manager.h"
#include "camera.hpp"

class StartButton : public Button {
public:
    StartButton(WindowManager* WM, Camera* camera);
    virtual ~StartButton() = default;

    void OnClick() override;
};