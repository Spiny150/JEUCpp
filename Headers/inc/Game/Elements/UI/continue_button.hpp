#pragma once

#include "button.hpp"
#include "window_manager.h"
#include "camera.hpp"

class ContinueButton : public Button {
public:
    ContinueButton(WindowManager* WM, Camera* camera);
    virtual ~ContinueButton() = default;

    void OnClick() override;
};