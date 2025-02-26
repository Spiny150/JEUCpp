#include "player.h"
#include "Engine/time.hpp"
#include "inputs.h"
#include "assert.h"
#include "score_manager.hpp"

// Player constructor
Player::Player(WindowManager *WM, Camera *_camera) : Entity(), camera(_camera)
{
    // Add transform and physics components
    transform = addComponent<TransformComponent>();
    physics = addComponent<PhysicsComponent>();

    // Validate window manager and camera pointers
    assert(WM && camera);

    // Set entity tag
    this->tag = EntityTag::Player;

    // Add visual component with player sprite
    visual = addComponent<ImageVisualComponent>(WM, camera, "Assets/Player/Duck.png");

    // Set player as a dynamic physics object
    physics->isStatic = false;

    std::cout << "Player instantiated" << std::endl;
}

// Player destructor
Player::~Player()
{
    std::cout << "Player destroyed" << std::endl;
}

// Initialize player state
void Player::Start()
{
    // Set initial position and velocity
    this->transform->position = Vector2(300, 300);
    this->physics->velocity = Vector2(200, -300);
}

// Update player state every frame
void Player::Update()
{
    // Apply gravity to player velocity
    this->physics->velocity += Vector2::down() * 700 * Time::deltaTime;
    if (scene->gameState == GameState::Running)
    {
        this->physics->velocity.x = camera->velocity.x;
    }

    // Handle jump input
    if (Input::isKeyPressed(SDL_SCANCODE_SPACE))
    {
        this->physics->velocity.y = -250;
    }
    int score = transform->position.x / 283.33;
    ScoreManager *scoreManager = ScoreManager::GetInstance();
    scoreManager->setCurrentScore(this->getScene()->GetTag(), score);
}
