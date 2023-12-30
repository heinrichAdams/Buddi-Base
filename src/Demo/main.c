#include "../WindowHandler.h"
#include "../Utility.h"
#include "../Display.h"
#include "../InputHandler.h"
#include <stdbool.h>
#include <stdio.h>


// GLOBAL VARIABLES
// ---------------------------------------------
Window_Handler window_handler;
SDL_Texture* logo;
// ---------------------------------------------

// FUNCTION PROTOTYPES
// ---------------------------------------------
void Initialize_Buddi(Window_Handler* window_handler);
// ---------------------------------------------


int main(int argc, char* argv[])
{

    // !!! Always needs to run first !!! (start)

    memset(&window_handler, 0,sizeof(Window_Handler));
    Initialize_Buddi(&window_handler);
    atexit(Clean);

    // !!! Always needs to run first !!! (end)

    logo = LoadTextureFromFile("assets/debug/set 01/BuddiLogo.png");

    printf("\n --- Reached Main Loop -- \n");
    while(true)
    {
        UpdateBackBuffer();

        GetInput();

        DrawTexture(logo, 100, 250);

        UpdateFrontBuffer();

        LimitFramerate(&window_handler.previousFrame, &window_handler.remainder);
    }

    return 0;
}