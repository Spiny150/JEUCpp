#include "Engine/time.hpp"
#include "ground.hpp"

Ground::Ground(WindowManager* WM, Camera* camera) : Entity() {
    transform = addComponent<TransformComponent>();
    physics = addComponent<PhysicsComponent>();
    visual = addComponent<ImageVisualComponent>(WM, camera, "Assets/World/ground.png");

    std::cout << "Ground instancié" << std::endl;
}

Ground::~Ground() {
    std::cout << "Ground destroyed" << std::endl;
}

void Ground::Start() {
    this->transform->position = Vector2(0, 540);
    camera = this->getScene()->camera;
}

void Ground::Update() {
    //transform->position.x = camera->position.x;
    //transform->position.y -= -10 * Time::deltaTime;
    if (transform->position.x + transform->scale.x < camera->position.x) {
        transform->position.x = camera->position.x + camera->scale.x;
    }
}