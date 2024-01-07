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
bool isRunning = false;
// ---------------------------------------------

// FUNCTION PROTOTYPES
// ---------------------------------------------
bool Initialize_Buddi(Window_Handler* window_handler);
bool Setup(void);
void Process_Input(void);
void Update(void);
void Render(void);
void Clean_Up(void);
// ---------------------------------------------


int main(int argc, char* argv[])
{

    // !!! Always needs to run first !!! (start)
    isRunning = Setup();
    // !!! Always needs to run first !!! (end)

    // DEBUG
    logo = LoadTextureFromFile("assets/debug/set 01/BuddiLogo.png");
    printf("\n\n---REACHED MAIN LOOP---\n\n");
    // DEBUG

    // Process Loop / Game Loop
    while(isRunning)
    {
        Process_Input();
        Update();
        Render();
    }

    // DEBUG 
    printf("\n\n---EXIT MAIN LOOP---\n\n");
    // DEBUG

    return 0;
}

bool Setup(void)
{
    memset(&window_handler, 0,sizeof(Window_Handler));

    if(!Initialize_Buddi(&window_handler))
    {
        printf("\n\n---ERROR: FAILED TO INITIALIZE BUDDI_BASE---\n\n");
        return false;
    }

    atexit(Clean_Up);

    return true;
}

void Process_Input(void)
{
    GetInput(&isRunning);
}

void Update(void)
{
    LimitFramerate(&window_handler.previousFrame, &window_handler.remainder);
}

void Render(void)
{
    UpdateBackBuffer();

    // DEBUG
    DrawTexture(logo, 100, 250);
    // DEBUG

    UpdateFrontBuffer();
}

void Clean_Up(void)
{
    printf("\n\n---CLEANUP EXECUTED---\n\n");
    Clean();
}
