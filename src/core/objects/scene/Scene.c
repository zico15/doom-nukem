#include "Engine.h"

static void __key(t_scene *this, bool *key, SDL_Event *event)
{
    t_node *nodes;
    size_t i;
    size_t size;
    t_object *object;

    printf("key\n");
    if (event->type == SDL_KEYDOWN)
    {
        if (event->key.keysym.sym == SDLK_LEFT)
            rotate_left(this->map);
        if (event->key.keysym.sym == SDLK_RIGHT)
            rotate_right(this->map);
    }

    nodes = array(this->event_key)->array;
    i = 0;
    size = array(this->event_key)->size;
    if (!nodes)
        return;
    while (i < size)
    {
        object = nodes[i].value;
        object->key(object, key, event);
        i++;
    }
}

static void __render(t_scene *this, SDL_Renderer *renderer)
{
    t_node *nodes;
    size_t i;
    size_t size;
    t_object *object;

    i = 0;
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);
    if (this->map)
        this->map->render(this->map, renderer);
    size = array(this->event_render)->size;
    if (!size)
        return;
    nodes = array(this->event_render)->array;
    while (i < size)
    {
        object = nodes[i].value;
        object->render(object, renderer);
        i++;
    }
}

static void __update(t_scene *this, t_sdl *sdl)
{
    t_node *nodes;
    size_t i;
    size_t size;
    t_object *object;

    nodes = array(this->event_update)->array;
    i = 0;
    size = array(this->event_update)->size;
    if (!nodes)
        return;
    while (i < size)
    {
        object = nodes[i].value;
        object->update(object, sdl);
        i++;
    }
}

t_object *__add(t_scene *this, t_object *object)
{
    if (!object)
        return (NULL);
    array(this->objects)->add(object)->destroy = (void *)object->destroy;
    if (object->key)
        array(this->event_key)->add(object)->destroy = NULL;
    if (object->render)
        array(this->event_render)->add(object)->destroy = NULL;
    if (object->update)
        array(this->event_update)->add(object)->destroy = NULL;
    return (object);
}
static void __destroy(t_scene *this)
{
    printf("destroy scene\n");
    array(this->event_key)->destroy();
    array(this->event_render)->destroy();
    array(this->event_update)->destroy();
    array(this->objects)->destroy();

    free(this);
}

t_scene *new_scene(char *wad_path)
{
    t_scene *scene;

    scene = (t_scene *)new_object(sizeof(t_scene));
    if (!scene)
        return (NULL);
    scene->objects = new_array(OBJECT);
    scene->event_key = new_array(OBJECT);
    scene->event_render = new_array(OBJECT);
    scene->event_update = new_array(OBJECT);
    scene->render = __render;
    scene->update = __update;
    scene->key = __key;
    scene->add = (void *)__add;
    scene->destroy = __destroy;
    scene->wad = init_wad_data(wad_path);
    scene->map = new_map(&scene->wad, "E1M1");
    return (scene);
}