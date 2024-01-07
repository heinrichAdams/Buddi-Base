#include "../WindowHandler.h"
#include "../Utility.h"
#include "../Display.h"
#include "../InputHandler.h"
#include "../Entity.h"
#include <stdbool.h>
#include <stdio.h>


// GLOBAL VARIABLES
// ---------------------------------------------
Window_Handler window_handler;
Entity player;
Projectile bullet;
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
    memset(&player, 0, sizeof(Entity));
    memset(&bullet,0,sizeof(Projectile));

    if(!Initialize_Buddi(&window_handler))
    {
        printf("\n\n---ERROR: FAILED TO INITIALIZE BUDDI_BASE---\n\n");
        return false;
    }

    // DEBUG
    player.xPos = 100;
    player.yPos = 100;
    player.sprite = LoadTextureFromFile("assets/debug/set 01/donk.png");

    bullet.xPos = 0;
    bullet.yPos = 0;
    bullet.health = 0;
    bullet.sprite = LoadTextureFromFile("assets/debug/set 01/bullet.png");
    // DEBUG

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

    // Debug
    if(window_handler.keys[SDL_SCANCODE_W])
    {
        player.yPos -= 5;
    }
    if(window_handler.keys[SDL_SCANCODE_S])
    {
        player.yPos += 5;
    }
    if(window_handler.keys[SDL_SCANCODE_A])
    {
        player.xPos -= 5;
    }
    if(window_handler.keys[SDL_SCANCODE_D])
    {
        player.xPos += 5;
    }
    if(window_handler.keys[SDL_SCANCODE_SPACE] && bullet.health == 0)
    {
        bullet.xPos = player.xPos;
        bullet.yPos = player.yPos;
        bullet.xDirection = 10;
        bullet.yDirection = 0;
        bullet.health = 1;
    }

    // Bullet Debug Logic
    bullet.xPos += bullet.xDirection;
    bullet.yPos += bullet.yDirection;

    if(bullet.xPos > WINDOW_WIDTH)
    {
        bullet.health = 0;
    }


    // Bullet Debug Logic

    // Debug
}

void Render(void)
{
    UpdateBackBuffer();

    // DEBUG
    DrawTexture(player.sprite,player.xPos,player.yPos);

    if(bullet.health > 0)
    {
        DrawTexture(bullet.sprite, bullet.xPos, bullet.yPos);
    }
    // DEBUG

    UpdateFrontBuffer();
}

void Clean_Up(void)
{
    printf("\n\n---CLEANUP EXECUTED---\n\n");
    Clean();
}
