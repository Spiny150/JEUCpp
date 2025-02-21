#pragma once

#include "button.hpp"
#include "window_manager.h"
#include "camera.hpp"

class PauseButton : public Button {
public:
    PauseButton(WindowManager* WM, Camera* camera);
    virtual ~PauseButton() = default;

    void OnClick() override;
};