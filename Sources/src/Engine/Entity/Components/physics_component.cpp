#include "physics_component.hpp"
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

bool PhysicsComponent::checkCollision(Entity* other) {
    if (this->isStatic || !hasCollider) return false;

    PhysicsComponent* otherPhysics = other->getComponent<PhysicsComponent>();
    if (!otherPhysics) return false;
    if (!otherPhysics->hasCollider) return false;

    SDL_FRect nextRectA = getNextPosFRect();
    SDL_FRect nextRectB = otherPhysics->getNextPosFRect();


    SDL_bool isColliding = SDL_HasIntersectionF(&nextRectA, &nextRectB);

    if (isColliding) {
        TransformComponent* otherTransform = other->getComponent<TransformComponent>();

        if ((transform->position.y + transform->scale.y <= otherTransform->position.y) || (transform->position.y >= otherTransform->position.y + otherTransform->scale.y)) {
            char direction = (transform->position.y + transform->scale.y <= otherTransform->position.y) ? -1 : 1;

            this->velocity.y = -otherPhysics->bounciness * (velocity.y - otherPhysics->velocity.y);

            this->nextPosition.y = (direction == -1) ?
                otherTransform->position.y - transform->scale.y :
                otherTransform->position.y + otherTransform->scale.y;
        }
        if ((transform->position.x + transform->scale.x <= otherTransform->position.x) || (transform->position.x >= otherTransform->position.x + otherTransform->scale.x)) {
            char direction = (transform->position.x + transform->scale.x <= otherTransform->position.x) ? -1 : 1;

            this->velocity.x = -otherPhysics->bounciness * (velocity.x - otherPhysics->velocity.x);

            this->nextPosition.x = (direction == -1) ?
                otherTransform->position.x - transform->scale.x :
                otherTransform->position.x + otherTransform->scale.x;
        }
    }
    return isColliding;
}