#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <SDL2/SDL.h>
#include "../Entity.h"
#include "../Scene.h"
#include "../Display.h"
#include "../WindowHandler.h"

#define PLAYER_SPEED = 2;
#define BULLET_SPEED = 10;

// GLOBAL VARIABLES
// ---------------------------------------------
extern Window_Handler window_handler;
Scene scene;
Entity* player = NULL;
SDL_Texture* bullet_texture = NULL;
// ---------------------------------------------


void Initialize_Game(void);
void Game_Logic(void);
void Initialize_Player(void);
void Fire_Bullet(void);
void Process_Player(void);
void Process_Bullets(void);
void Draw_Player(void);
void Draw_Bullets(void);

#endif