#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>

typedef struct
{
    float xPos;
    float yPos;
    float xDirection;
    float yDirection;
    int width;
    int height;
    int health;
    SDL_Texture* sprite;
    // container for address of next entity for linked list functionality
    Entity* next_entity;
} Entity;

typedef struct
{
    float xPos;
    float yPos;
    float xDirection;
    float yDirection;
    int width;
    int height;
    int health;
    SDL_Texture* sprite;
    // container for address of next projectile for linked list functionality
    Projectile* next_projectile;
} Projectile;


#endif