#include "Scene.h"

void Initialize_Scene(Scene* scene)
{
    memset(scene, 0, sizeof(Scene));

    scene->last_entity = &(scene->first_entity);
    scene->last_projectile = &(scene->first_projectile);
}