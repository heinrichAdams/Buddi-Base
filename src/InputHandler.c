#include "InputHandler.h"
#include "WindowHandler.h"
#include <SDL2/SDL.h>

extern Window_Handler window_handler;

void GetInput(void)
{
    // Create Event Listener
    SDL_Event event;

    // While there are events that have not been processed
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;
            default:
                break;
        }
    }

}