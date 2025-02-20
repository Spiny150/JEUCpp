#pragma once

#include "entity.h"
#include "transform_component.hpp"
#include "visual_component.hpp"

class UI_Element : public Entity {
public:
    TransformComponent* transform;
    VisualComponent* visual;
    std::vector<GameState> activeStates;

    UI_Element();
    virtual ~UI_Element() = default;

    void Update() override;
};