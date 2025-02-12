#include "Engine/time.hpp"
#include "sky.hpp"

Sky::Sky(WindowManager* WM) : Entity() {
    transform = addComponent<TransformComponent>();
    visual = addComponent<VisualComponent>();

    visual->setSprite("Assets/World/sky.png", WM);
    std::cout << "Sky instancié" << std::endl;
}

Sky::~Sky() {
    std::cout << "Sky destroyed" << std::endl;
}

void Sky::Start() {
}

void Sky::Update() {
}