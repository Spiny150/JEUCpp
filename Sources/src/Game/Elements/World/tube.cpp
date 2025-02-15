#include "tube.hpp"

Tube::Tube(WindowManager* _WM, Camera* _camera, Vector2 position, SDL_RendererFlip flip) :
    Entity(),
    camera(_camera)
{

    transform = addComponent<TransformComponent>();
    physics = addComponent<PhysicsComponent>();
    visual = addComponent<ImageVisualComponent>(_WM, _camera, "Assets/World/tuyau.png");

    physics->bounciness = 1;
    visual->flip = flip;

    transform->position = position;

};

void Tube::Update() {
    if (transform->position.x + transform->scale.x < camera->position.x) {
        transform->position.x = camera->position.x + camera->scale.x;
    }
}