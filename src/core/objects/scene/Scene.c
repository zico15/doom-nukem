#include "Engine.h"

static void key(t_scene *this, bool *key, SDL_EventType event)
{
    printf("Key pressed: %d\n", event);
    t_node **nodes;
    t_object *object;

    nodes = array(this->event_key)->array;
    if (!nodes)
        return;
    while (*nodes)
    {
        object = (*nodes)->value;
        object->key(object, key, event);
        nodes++;
    }
}

static void render(t_scene *this, SDL_Renderer *renderer)
{
    t_node **nodes;
    t_object *object;

    nodes = array(this->event_render)->array;
    if (!nodes)
        return;
    while (*nodes)
    {
        object = (*nodes)->value;
        object->render(object, renderer);
        nodes++;
    }
}

t_object *add(t_scene *this, t_object *object)
{
    if (!object)
        return (NULL);
    array(this->objects)->add(object)->destroy = (void *)object->destroy;
    if (object->key)
        array(this->event_key)->add(object)->destroy = NULL;
    if (object->render)
        array(this->event_render)->add(object)->destroy = NULL;
    return (object);
}
static void destroy(t_scene *this)
{
    array(this->objects)->destroy();
    array(this->event_key)->destroy();
    array(this->event_render)->destroy();
    free(this);
}

t_scene *new_scene(int width, int height)
{
    t_scene *scene;

    scene = (t_scene *)new_object(sizeof(t_scene));
    if (!scene)
        return (NULL);
    scene->objects = new_array(OBJECT);
    scene->event_key = new_array(OBJECT);
    scene->event_render = new_array(OBJECT);
    scene->render = render;
    scene->key = key;
    scene->rect.w = width;
    scene->rect.h = height;
    scene->add = add;
    scene->destroy = destroy;
    return (scene);
}