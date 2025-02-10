#include "inputs.h"

const Uint8* Input::currentState = SDL_GetKeyboardState(NULL);
Uint8* Input::previousState = new Uint8[SDL_NUM_SCANCODES];
Vector2Int Input::mousePos = Vector2Int(-1, -1);

void Input::Update() {
    memcpy(previousState, currentState, SDL_NUM_SCANCODES);
    currentState = SDL_GetKeyboardState(NULL);  // Récupère l'état des touches actuel
    SDL_GetMouseState(&mousePos.x, &mousePos.y);
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
