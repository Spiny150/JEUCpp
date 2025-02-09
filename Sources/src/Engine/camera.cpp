#include "camera.hpp"
#include "Engine/time.hpp"

Camera::Camera(Vector2Int _scale) :
    position(Vector2()),
    velocity(Vector2()),
    scale(_scale) {}

Camera::~Camera() {}

void Camera::Update() {
    position += velocity * Time::deltaTime;
}

SDL_Rect Camera::GetViewRect() const {
    return { (int)position.x, (int)position.y, scale.x, scale.y };
}