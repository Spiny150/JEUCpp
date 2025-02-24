#include "Engine/time.hpp"
#include "ground.hpp"

// Ground constructor
Ground::Ground(WindowManager* WM, Camera* camera) : Entity() {
    // Add transform, physics, and visual components
    transform = addComponent<TransformComponent>();
    physics = addComponent<PhysicsComponent>();
    visual = addComponent<ImageVisualComponent>(WM, camera, "Assets/World/ground.png");

    std::cout << "Ground instantiated" << std::endl;
}

// Ground destructor
Ground::~Ground() {
    std::cout << "Ground destroyed" << std::endl;
}

// Initialize ground state
void Ground::Start() {
    // Set initial position and get camera reference
    this->transform->position = Vector2(0, 540);
    camera = this->getScene()->camera;
}

// Update ground position every frame
void Ground::Update() {
    // Handle ground positioning relative to camera
    if (transform->position.x + transform->scale.x < camera->position.x) {
        transform->position.x = camera->position.x + camera->scale.x;
    }
}
