#include "entity_physics.h"
#include "Engine/time.hpp"
#include "iostream"
#include "entity.h"


PhysicsComponent::PhysicsComponent(Entity& entity) :
    Component(entity),
    hasCollider(true),
    isStatic(true),
    nextPosition(Vector2()),
    velocity(Vector2()),
    bounciness(0.0f) {
        transform = entity.getComponent<TransformComponent>();
        std::cout << "PhysicsComponent instancié" << std::endl;
};

PhysicsComponent::~PhysicsComponent() {
    std::cout << "PhysicsComponent destroyed" << std::endl;
}

void PhysicsComponent::computeNextPosition() {
    nextPosition = transform->position;
    if (isStatic) return;
    nextPosition += velocity * Time::deltaTime;
}

void PhysicsComponent::applyNextPosition() {
    transform = entity.getComponent<TransformComponent>();
    transform->position = nextPosition;
}

SDL_FRect PhysicsComponent::getNextPosFRect() {
    SDL_FRect rect = {
        nextPosition.x,
        nextPosition.y,
        transform->scale.x,
        transform->scale.y,
    };
    return rect;
}

void PhysicsComponent::checkCollision(Entity* other) {
    if (this->isStatic || !hasCollider) return;

    PhysicsComponent* otherPhysics = other->getComponent<PhysicsComponent>();
    if (!otherPhysics) return;
    if (!otherPhysics->hasCollider) return;

    Entity* entityA = &entity;
    Entity* entityB = other;
    SDL_FRect rectA = getNextPosFRect();
    SDL_FRect rectB = otherPhysics->getNextPosFRect();


    SDL_bool isColliding = SDL_HasIntersectionF(&rectA, &rectB);

    if (isColliding) {
        TransformComponent* transformA = entityA->getComponent<TransformComponent>();
        TransformComponent* transformB = entityB->getComponent<TransformComponent>();

        if (transformA->position.y + transformA->scale.y > transformB->position.y) {
            this->nextPosition.y = otherPhysics->nextPosition.y - transformA->scale.y;
            this->velocity.y *= -otherPhysics->bounciness;
        }

    }
}