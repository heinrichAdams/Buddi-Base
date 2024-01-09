#include "game_logic.h"

void Initialize_Game(void)
{
    Initialize_Scene(&scene);
    Initialize_Player();
    bullet_texture = LoadTextureFromFile("assets/debug/set 01/bullet.png");
}

void Initialize_Player(void)
{
    player = calloc(1, sizeof(Entity));
    scene.last_entity->next_entity = player;
    scene.last_entity = player;

    player->xPos = 5;
    player->yPos = 5;

    player->sprite = LoadTextureFromFile("assets/debug/set 01/donk.png");
    SDL_QueryTexture(player->sprite, NULL, NULL, &(player->width), &(player->height));
}

void Game_Logic(void)
{
    Process_Player();
    Process_Bullets();
}

void Fire_Bullet(void)
{

}

void Process_Player(void)
{
    player->xDirection = 0;
    player->yDirection = 0;

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
    if(window_handler.keys[SDL_SCANCODE_SPACE])
    {
        bullet.xPos = player.xPos;
        bullet.yPos = player.yPos;
        bullet.xDirection = 10;
        bullet.yDirection = 0;
        bullet.health = 1;
    }
}

void Process_Bullets(void)
{

}

void Draw_Player(void)
{

}

void Draw_Bullets(void)
{

}