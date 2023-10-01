#include "Engine.h"

t_scene *__add_scene(t_scene *scene)
{
    t_scene *new_scene;

    new_scene = malloc(sizeof(t_scene));
    if (!new_scene)
        return (NULL);
    // new_scene->object = object;
    // new_scene->next = scene;
    return (new_scene);
}