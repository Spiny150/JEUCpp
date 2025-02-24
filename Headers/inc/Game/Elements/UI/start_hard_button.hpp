#pragma once

#include "button.hpp"
#include "window_manager.h"
#include "camera.hpp"

class StartHardButton : public Button {
public:
    StartHardButton(WindowManager* WM, Camera* camera);
    virtual ~StartHardButton() = default;

    void OnClick() override;
};