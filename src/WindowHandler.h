#ifndef WINDOW_HANDLER
#define WINDOW_HANDLER

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "Demo/config.h"

typedef struct
{
    SDL_Renderer* renderer;
    SDL_Window* window;

    // Frame Control
    long previousFrame;
    float remainder;

    // Keyboard Array
    int keys[KEYBOARD_SIZE];

} Window_Handler;


#endif