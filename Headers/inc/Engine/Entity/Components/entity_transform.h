#ifndef ENTITY_TRANSFORM_H
#define ENTITY_TRANSFORM_H

//#include "component.h"
#include "units.h"

class TransformComponent : public Component {
public:
    Vector2 position;
    Vector2 scale; // On-screen size
    float rotation;

    TransformComponent(Entity& entity) : Component(entity), position(Vector2()), scale(Vector2()), rotation(0.0f) {};
};

#endif