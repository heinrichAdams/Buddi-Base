#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>

typedef struct
{
    int xPos;
    int yPos;
    int xDirection;
    int yDirection;
    int health;
    SDL_Texture* sprite;
    Entity* next_entity;
} Entity;

typedef struct
{
    int xPos;
    int yPos;
    int xDirection;
    int yDirection;
    int health;
    SDL_Texture* sprite;
    Projectile* next_projectile;
} Projectile;


#endif