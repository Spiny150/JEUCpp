#include "game_scene_harder.hpp"
#include "entity.h"
#include "physics_component.hpp"
#include "player.h"
#include "ground.hpp"
#include "button.hpp"
#include "sky.hpp"
#include "start_button.hpp"
#include "tube.hpp"
#include "gray_filter.hpp"
#include "time.hpp"
#include "inputs.h"
#include "continue_button.hpp"
#include "pause_button.hpp"
#include "main_menu_button.hpp"
#include "restart_button.hpp"
#include "gameover_text.hpp"
#include "score_text.hpp"
#include "high_score_text.hpp"
#include "score_manager.hpp"

// Initialize the game scene
void GameSceneHarder::Init()
{
    // Reset camera position and velocity
    this->camera->position = Vector2();
    this->camera->velocity = Vector2();

    // Set initial time scale
    Time::timeScale = 1;

    // Create game entities
    Entity *player = new Player(WM, camera);
    Entity *ground = new Ground(WM, camera);
    Entity *ground2 = new Ground(WM, camera);

    // Create tube obstacles with different positions and orientations
    Entity *tube1 = new Tube(WM, camera, Vector2(283.33 * 1, -400), SDL_FLIP_VERTICAL);
    Entity *tube2 = new Tube(WM, camera, Vector2(283.33 * 1, 500), SDL_FLIP_NONE, tube1);
    Entity *tube3 = new Tube(WM, camera, Vector2(283.33 * 2, -400), SDL_FLIP_VERTICAL);
    Entity *tube4 = new Tube(WM, camera, Vector2(283.33 * 2, 500), SDL_FLIP_NONE, tube3);
    Entity *tube5 = new Tube(WM, camera, Vector2(283.33 * 3, -400), SDL_FLIP_VERTICAL);
    Entity *tube6 = new Tube(WM, camera, Vector2(283.33 * 3, 500), SDL_FLIP_NONE, tube5);

    // Create UI elements
    Entity *gray_filter = new GrayFilter(WM, camera);
    Entity *continue_button = new ContinueButton(WM, camera);
    Entity *pause_button = new PauseButton(WM, camera);
    Entity *main_menu_button = new MainMenuButton(WM, camera);
    Entity *restart_button = new RestartButton(WM, camera);
    Entity *sky = new Sky(WM, camera);
    Entity *gameover_text = new GameoverText(WM, camera);
    Entity *score_text = new ScoreText(WM, camera);
    Entity *high_score_text = new HighScoreText(WM, camera);

    // Add all entities to the scene
    this->AddEntity(sky);
    this->AddEntity(player);
    this->AddEntity(ground2);
    this->AddEntity(ground);
    this->AddEntity(tube1);
    this->AddEntity(tube2);
    this->AddEntity(tube3);
    this->AddEntity(tube4);
    this->AddEntity(tube5);
    this->AddEntity(tube6);
    this->AddEntity(gray_filter);
    this->AddEntity(continue_button);
    this->AddEntity(pause_button);
    this->AddEntity(main_menu_button);
    this->AddEntity(restart_button);
    this->AddEntity(gameover_text);
    this->AddEntity(score_text);
    this->AddEntity(high_score_text);

    // Start the scene and set initial game state
    this->Start();
    this->camera->velocity = Vector2(200, 0);
    ground2->getComponent<TransformComponent>()->position.x = camera->scale.x;
    this->gameState = GameState::Running;
}

// Update game logic every frame
void GameSceneHarder::Update()
{
    // Handle pause/unpause with ESC key
    if (Input::isKeyPressed(SDL_SCANCODE_ESCAPE))
    {
        if (gameState == GameState::Running)
        {
            this->gameState = GameState::Paused;
            Time::timeScale = 0;
        }
        else if (gameState == GameState::Paused)
        {
            gameState = GameState::Running;
            Time::timeScale = 1;
        }
    }
    if (gameState == GameState::GameLost)
    {
        Time::timeScale *= 1 - 3 * Time::unscaledDeltaTime;
    }

    // Update all entities
    for (Entity *entity : entities)
    {
        entity->Update();
        PhysicsComponent *physics = entity->getComponent<PhysicsComponent>();
        if (physics)
            physics->computeNextPosition();
    }

    // Check for collisions between entities
    for (Entity *entityA : entities)
    {
        for (Entity *entityB : entities)
        {
            if (entityA == entityB)
                continue;
            PhysicsComponent *physicsA = entityA->getComponent<PhysicsComponent>();
            if (physicsA)
            {
                bool isColliding = physicsA->checkCollision(entityB);
                if (isColliding && entityA->tag == EntityTag::Player && entityB->tag == EntityTag::Obstacle)
                {
                    this->gameState = GameState::GameLost;
                }
            }
        }
    }

    // Apply physics updates
    for (Entity *entity : entities)
    {
        PhysicsComponent *physics = entity->getComponent<PhysicsComponent>();
        if (physics)
            physics->applyNextPosition();
    }

    this->camera->velocity.x *= 1 + .01 * Time::deltaTime;
}

// Clean up resources when the scene ends
void GameSceneHarder::CleanUp()
{
    // Delete all entities and clear the list
    for (Entity *&entity : this->entities)
    {
        if (entity)
        {
            delete entity;
            entity = nullptr; // Avoid dangling pointers
        }
    }
    entities.clear(); // Empty entity list
    renderStack.clear();
    std::cout << "Menu cleaned up" << std::endl;
}

// Destructor
GameSceneHarder::~GameSceneHarder()
{
    std::cout << "GameScene destroyed" << std::endl;
}
