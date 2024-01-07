#include "Initialize_Buddi.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>

bool Initialize_Buddi(Window_Handler* window_handler)
{
    int windowFlags = 0;
    int renderFlags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;

    // INITIALIZE SDL VIDEO

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("\n\n---ERROR: COULDNT INITIALIZE SDL VIDEO---\n\n");
		return false;
    }

    // INITIALIZE WINDOW

    window_handler->window = SDL_CreateWindow(WINDOW_TITLE, 
    SDL_WINDOWPOS_UNDEFINED, 
    SDL_WINDOWPOS_UNDEFINED, 
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    windowFlags);

    if(!window_handler->window)
    {
        printf("\n\n---ERROR: COULDNT CREATE SDL WINDOW---\n\n");
		return false;
    }

    // USE SDL HINT TO SET SCALING METHOD
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    // INITIALIZE RENDERER
    window_handler->renderer = SDL_CreateRenderer(window_handler->window, -1, renderFlags);
    
    if(!window_handler->renderer)
    {
        printf("\n\n---ERROR: COULDNT CREATE SDL RENDERER---\n\n");
		return false;
    }

    // INITIALIZE SDL_IMAGE
    if(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG) < 0)
    {
        printf("\n\n---ERROR: COULDNT INITIALIZE SDL_IMAGE---\n\n");
		return false;
    }

    // INTITIALIZE FRAME COUNTER
    window_handler->previousFrame = SDL_GetTicks();
    window_handler->remainder = 0;

    return true;

}