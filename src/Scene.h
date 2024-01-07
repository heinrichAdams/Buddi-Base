#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"

typedef struct 
{
    // Linked Lists Of Objects In Scene

    // Linked List of entities
    Entity first_entity;
    Entity* last_entity;

    // Linked List of projectiles
    Projectile first_projectile;
    Projectile* last_projectile;

} Scene;

void Initialize_Scene(Scene* scene);

#endif