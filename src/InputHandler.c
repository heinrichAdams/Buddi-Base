#include "InputHandler.h"
#include "WindowHandler.h"
#include <SDL2/SDL.h>

extern Window_Handler window_handler;

void GetInput(bool* continue_execution_case)
{
    // Create Event Listener
    SDL_Event event;

    // While there are events that have not been processed
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                *(continue_execution_case) = false;
                break;
            default:
                break;
        }
    }

}