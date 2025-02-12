#ifndef ENTITY_PHYSICS_H
#define ENTITY_PHYSICS_H

#include "units.h"
#include "component.hpp"
#include "transform_component.hpp"

class PhysicsComponent : public Component {
private:
    TransformComponent* transform;
public:
    bool hasCollider;
    bool isStatic;
    Vector2 nextPosition;
    Vector2 velocity;
    float bounciness;

    PhysicsComponent(Entity& entity);
    ~PhysicsComponent();
    void computeNextPosition();
    void applyNextPosition();

    SDL_FRect getNextPosFRect();
    void checkCollision(Entity* other);
};

#endif