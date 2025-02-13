#include "player.h"
#include "Engine/time.hpp"
#include "inputs.h"
#include "assert.h"

Player::Player(WindowManager* WM, Camera* camera) : Entity() {
    transform = addComponent<TransformComponent>();
    physics = addComponent<PhysicsComponent>();
    assert(WM && camera);
    visual = addComponent<ImageVisualComponent>(WM, camera, "Assets/Player/Duck.png");

    physics->isStatic = false;

    std::cout << "Player instancié" << std::endl;
}

Player::~Player() {
    std::cout << "Player détruit" << std::endl;
}

void Player::Start() {
    this->transform->position = Vector2(300, 300);
    this->physics->velocity = Vector2(0, -500);
}

void Player::Update() {
    this->physics->velocity += Vector2::down() * 700 * Time::deltaTime;
    if (Input::isKeyPressed(SDL_SCANCODE_SPACE)) {
        this->physics->velocity.y = -250;
    }
    this->physics->velocity.x = this->scene->camera->velocity.x;
}

