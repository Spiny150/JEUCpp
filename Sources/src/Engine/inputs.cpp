#include "inputs.h"

const Uint8* Input::currentState = SDL_GetKeyboardState(NULL);
Uint8* Input::previousState = new Uint8[SDL_NUM_SCANCODES];

void Input::Update() {
    memcpy(previousState, currentState, SDL_NUM_SCANCODES);
    currentState = SDL_GetKeyboardState(NULL);  // Récupère l'état des touches actuel
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
