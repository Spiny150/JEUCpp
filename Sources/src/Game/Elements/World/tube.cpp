#include "tube.hpp"

// Tube constructor
Tube::Tube(WindowManager* _WM, Camera* _camera, Vector2 position, SDL_RendererFlip flip) :
    Entity(),
    camera(_camera)
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
    }
}
