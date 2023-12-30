#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "WindowHandler.h"

extern Window_Handler window_handler;

void Clean(void)
{
    IMG_Quit();
    SDL_DestroyRenderer(window_handler.renderer);
    SDL_DestroyWindow(window_handler.window);
    SDL_Quit();
}

void LimitFramerate(long* previousFrame, float* remainder)
{
    long wait = 16 + *remainder;
    long frameTime = SDL_GetTicks() - *previousFrame;

    *remainder -= (int)*remainder;

    wait -= frameTime;

    if(wait < 1)
    {
        wait = 1;
    }

    SDL_Delay(wait);

    *remainder += 0.667;

    *previousFrame = SDL_GetTicks();
}