#include "player.h"
#include "Engine/time.hpp"
#include "inputs.h"

Player::Player(WindowManager* WM) : Entity() {
    transform = addComponent<TransformComponent>();
    physics = addComponent<PhysicsComponent>();
    visual = addComponent<VisualComponent>();

    visual->setSprite("Assets/Player/Duck.png", WM);
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
}

