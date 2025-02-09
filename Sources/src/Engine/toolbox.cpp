#include "toolbox.h"

SDL_Rect toSDL_Rect(const SDL_FRect fRect) {
    return SDL_Rect{
        static_cast<int>(fRect.x),
        static_cast<int>(fRect.y),
        static_cast<int>(fRect.w),
        static_cast<int>(fRect.h)
    };
}
