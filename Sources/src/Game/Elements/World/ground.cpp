#include "ground.hpp"

Ground::Ground(WindowManager* WM) : Entity() {
    transform = addComponent<TransformComponent>();
    physics = addComponent<PhysicsComponent>();
    visual = addComponent<VisualComponent>();

    visual->setSprite("Assets/World/floor.png", WM);
    std::cout << "Ground instancié" << std::endl;
}

Ground::~Ground() {
    std::cout << "Ground destroyed" << std::endl;
}

void Ground::Start() {
    this->transform->position = Vector2(0, 540);
}

void Ground::Update() {

}