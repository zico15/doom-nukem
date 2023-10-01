#include "Engine.h"

static void key(t_scene *this, bool *key, SDL_EventType event)
{
    printf("Key pressed: %d\n", event);
    for (int i = 0; i < 2; i++)
    {
        if (this->objects[i])
            this->objects[i]->key(this->objects[i], key, event);
    }
}

static void render(t_scene *this, SDL_Renderer *renderer)
{
    for (int i = 0; i < 2; i++)
    {
        if (this->objects[i])
            this->objects[i]->render(this->objects[i], renderer);
    }
}

t_object *add(t_scene *this, t_object *object)
{
    if (!object)
        return (NULL);
    for (int i = 0; i < 2; i++)
    {
        if (!this->objects[i])
        {
            this->objects[i] = object;
            // if (object->key)
            //     engine()->scene->event_key.add(object->key);
            return (object);
        }
    }
    return (NULL);
}
static void destroy(t_scene *this)
{
    for (int i = 0; i < 2; i++)
    {
        if (this->objects[i])
            this->objects[i]->destroy(this->objects[i]);
    }
    free(this);
}

t_scene *new_scene(int width, int height)
{
    t_scene *scene;

    scene = (t_scene *)new_object(sizeof(t_scene));
    if (!scene)
        return (NULL);
    scene->render = render;
    scene->key = key;
    scene->rect.w = width;
    scene->rect.h = height;
    scene->add = add;
    scene->destroy = destroy;
    return (scene);
}