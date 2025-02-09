#include "entity_physics.h"
#include "game_time.h"
#include "iostream"
#include "entity.h"


PhysicsComponent::PhysicsComponent(Entity& entity) : Component(entity), nextPosition(Vector2()), velocity(Vector2()), bounciness(0.0f) {
    transform = entity.getComponent<TransformComponent>();
    std::cout << "PhysicsComponent instancié" << std::endl;
};

void PhysicsComponent::computeNextPosition() {
    nextPosition = transform->position;
    nextPosition += velocity * Time::deltaTime;
}

void PhysicsComponent::applyNextPosition() {
    transform = entity.getComponent<TransformComponent>();
    transform->position = nextPosition;
}