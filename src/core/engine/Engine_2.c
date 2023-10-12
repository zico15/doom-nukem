#include "Engine.h"

t_scene *__add_scene(t_scene *scene)
{
    if (!scene)
        return (NULL);
    array(engine()->scenes)->add(scene)->destroy = (void *)scene->destroy;
    if (engine()->scene == NULL)
        engine()->scene = scene;
    return (scene);
}