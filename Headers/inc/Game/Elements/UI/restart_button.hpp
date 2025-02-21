#pragma once

#include "button.hpp"
#include "window_manager.h"
#include "camera.hpp"

class RestartButton : public Button {
public:
    RestartButton(WindowManager* WM, Camera* camera);
    virtual ~RestartButton() = default;

    void OnClick() override;
};