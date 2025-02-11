#include "inputs.h"

const Uint8* Input::currentState = SDL_GetKeyboardState(NULL);
Uint8* Input::previousState = new Uint8[SDL_NUM_SCANCODES];
Vector2Int Input::mousePos = Vector2Int(-1, -1);
Uint32 Input::mouseButtons = 0;
Uint32 Input::previousMouseState = 0;

void Input::Update() {
    memcpy(previousState, currentState, SDL_NUM_SCANCODES);
    currentState = SDL_GetKeyboardState(NULL);  // Récupère l'état des touches actuel
    previousMouseState = mouseButtons;
    mouseButtons = SDL_GetMouseState(&mousePos.x, &mousePos.y);
}

bool Input::isKeyPressed(SDL_Scancode key) {
    return currentState[key] && !previousState[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
    return currentState[key];
}

bool Input::isKeyReleased(SDL_Scancode key) {
    return !currentState[key] && previousState[key];
}

bool Input::isClickPressed() {
    return (mouseButtons == 1) && (previousMouseState != 1);
}