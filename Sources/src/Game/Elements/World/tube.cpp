#include "tube.hpp"
#define MIN_TOP_DIST 50
#define INTER_TUBE_DIST 200
#define SPAWN_RANGE 250

// Tube constructor
Tube::Tube(WindowManager* _WM, Camera* _camera, Vector2 position, SDL_RendererFlip flip, Entity* _matchingTube) :
    Entity(),
    camera(_camera),
    matchingTube(_matchingTube)
{
    // Add transform, physics, and visual components
    transform = addComponent<TransformComponent>();
    physics = addComponent<PhysicsComponent>();
    visual = addComponent<ImageVisualComponent>(_WM, _camera, "Assets/World/tuyau.png");

    // Set entity tag
    this->tag = EntityTag::Obstacle;

    // Set tube properties
    physics->bounciness = 1;
    visual->flip = flip;

    // Set initial position
    transform->position = position;
}

// Update tube position every frame
void Tube::Update() {
    // Handle tube positioning relative to camera
    if (transform->position.x + transform->scale.x < camera->position.x) {
        transform->position.x = camera->position.x + camera->scale.x;

        // If tube is the main tube, select a new random height
        if (!matchingTube) {
            transform->position.y = -transform->scale.y + MIN_TOP_DIST + rand() % SPAWN_RANGE;
        }
        else { // If the tube follow another tube, position it below the matching tube
            transform->position.y = matchingTube->getComponent<TransformComponent>()->position.y + INTER_TUBE_DIST + transform->scale.y;
        }
    }
}
