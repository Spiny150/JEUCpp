#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "entity_transform.h"
#include "entity_physics.h"
#include "entity_visual.h"

class Player : public Entity {
private:
    TransformComponent* transform;
    PhysicsComponent* physics;
    VisualComponent* visual;

public:
    Player(Scene* _scene);
    ~Player();

    void Start() override;
    void Update() override;
};

#endif