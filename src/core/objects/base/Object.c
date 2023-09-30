
#include "Core.h"

static void move(t_object *this, float x, float y)
{
    this->rect.x += x * this->speed * engine()->delta_time;
    this->rect.y += y * this->speed * engine()->delta_time;
}

static void render(t_object *this, SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, this->image->textura, NULL, &this->rect);
    // SDL_RenderPresent(renderer);
}

t_object *object_new(size_t size)
{
    t_object *obj;

    obj = calloc(size, 1);
    if (!obj)
        return NULL;
    obj->render = render;
    obj->move = move;
    obj->image = new_image_file("resources/textures/player.png");
    obj->rect = (SDL_Rect){100.0f, 100.0f, 100.0f, 100.0f};
    obj->speed = 250.0f;
    return obj;
}