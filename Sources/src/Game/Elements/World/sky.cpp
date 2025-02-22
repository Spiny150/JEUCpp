#include "Engine/time.hpp"
#include "sky.hpp"

// Sky constructor
Sky::Sky(WindowManager* WM, Camera* camera) : Entity() {
    // Add transform and visual components
    transform = addComponent<TransformComponent>();
    visual = addComponent<ImageVisualComponent>(WM, camera, "Assets/World/sky.png");
    this->camera = camera;

    std::cout << "Sky instantiated" << std::endl;
}

// Sky destructor
Sky::~Sky() {
    std::cout << "Sky destroyed" << std::endl;
}

// Initialize sky state
void Sky::Start() {
    // No specific initialization needed
}

// Update sky position every frame
void Sky::Update() {
    // Make sky follow camera position
    transform->position = camera->position;
}
