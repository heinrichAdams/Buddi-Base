#include "InputHandler.h"
#include "WindowHandler.h"
#include <SDL2/SDL.h>


extern Window_Handler window_handler;

static void Key_Up(SDL_KeyboardEvent* key_event)
{
    if(key_event->repeat == 0 && key_event->keysym.scancode < KEYBOARD_SIZE)
    {
        window_handler.keys[key_event->keysym.scancode] = 0;
    }
}

static void Key_Down(SDL_KeyboardEvent* key_event)
{
        if(key_event->repeat == 0 && key_event->keysym.scancode < KEYBOARD_SIZE)
    {
        window_handler.keys[key_event->keysym.scancode] = 1;
    }
}

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
            case SDL_KEYDOWN:
                Key_Down(&event.key);
                break;
            case SDL_KEYUP:
                Key_Up(&event.key);
                break;
            default:
                break;
        }
    }

}