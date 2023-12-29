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