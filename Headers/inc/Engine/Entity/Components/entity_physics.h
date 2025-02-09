#ifndef ENTITY_PHYSICS_H
#define ENTITY_PHYSICS_H

#include "units.h"
#include "component.h"
#include "entity_transform.h"

class PhysicsComponent : public Component {
private:
    TransformComponent* transform;
public:
    Vector2 nextPosition;
    Vector2 velocity;
    float bounciness;

    PhysicsComponent(Entity& entity);
    ~PhysicsComponent();
    void computeNextPosition();
    void applyNextPosition();
};

#endif