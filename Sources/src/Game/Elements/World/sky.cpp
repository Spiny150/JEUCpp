#include "Engine/time.hpp"
#include "sky.hpp"

Sky::Sky(WindowManager* WM, Camera* camera) : Entity() {
    transform = addComponent<TransformComponent>();
    visual = addComponent<ImageVisualComponent>(WM, camera, "Assets/World/sky.png");
    this->camera = camera;

    std::cout << "Sky instancié" << std::endl;
}

Sky::~Sky() {
    std::cout << "Sky destroyed" << std::endl;
}

void Sky::Start() {
}

void Sky::Update() {
    transform->position = camera->position;
}