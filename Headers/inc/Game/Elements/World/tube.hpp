#pragma once

#include "entity.h"
#include "transform_component.hpp"
#include "physics_component.hpp"
#include "image_visual_component.hpp"
#include "window_manager.h"
#include "camera.hpp"


class Tube : public Entity {
public:
    TransformComponent* transform;
    PhysicsComponent* physics;
    ImageVisualComponent* visual;
    Camera* camera;

    Tube(WindowManager* WM, Camera* camera, Vector2 position, SDL_RendererFlip flip);
    ~Tube() = default;

    void Update() override;

};