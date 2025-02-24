#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "transform_component.hpp"
#include "physics_component.hpp"
#include "image_visual_component.hpp"
#include "camera.hpp"

class Player : public Entity
{
private:
    TransformComponent *transform;
    PhysicsComponent *physics;
    ImageVisualComponent *visual;

    Camera *camera;

public:
    Player(WindowManager *WM, Camera *_camera);
    ~Player();

    void Start() override;
    void Update() override;
};

#endif