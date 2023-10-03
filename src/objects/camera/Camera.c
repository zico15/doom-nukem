#include "Engine.h"

t_object *new_camera()
{
    t_object *camera;

    camera = new_object(sizeof(t_object));
    camera->rect.x = 0;
    camera->rect.y = 0;
    camera->rect.w = 640;
    camera->rect.h = 480;
    return (camera);
}