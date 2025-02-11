#pragma once
#include <SDL2/SDL.h>
#include "units.h"

class Input {
public:
    static void Update();  // Met à jour les états des entrées
    static bool isKeyPressed(SDL_Scancode key);  // Vérifie si une touche est pressée
    static bool isKeyHeld(SDL_Scancode key);  // Vérifie si une touche est pressée
    static bool isKeyReleased(SDL_Scancode key);  // Vérifie si une touche est relâchée

    static bool isClickPressed();

    static Vector2Int mousePos;
    static Uint32 mouseButtons;

private:
    static const Uint8* currentState;  // Etat actuel des touches
    static Uint8* previousState;  // Etat précédent des touches
    static Uint32 previousMouseState;
};
