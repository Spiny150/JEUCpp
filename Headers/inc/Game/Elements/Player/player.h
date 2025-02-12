#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "transform_component.hpp"
#include "physics_component.hpp"
#include "visual_component.hpp"

class Player : public Entity {
private:
    TransformComponent* transform;
    PhysicsComponent* physics;
    VisualComponent* visual;

public:
    Player(WindowManager* WM);
    ~Player();

    void Start() override;
    void Update() override;
};

#endif