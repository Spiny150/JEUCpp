#include "player.h"
#include "game_time.h"
#include "inputs.h"

Player::Player(Scene* _scene) : Entity(_scene) {
    transform = addComponent<TransformComponent>();
    physics = addComponent<PhysicsComponent>();
    visual = addComponent<VisualComponent>();

    visual->setSprite("Assets/Player/Duck.png", this->scene->WM);
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

