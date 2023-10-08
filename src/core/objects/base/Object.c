
#include "Engine.h"

static void move(t_object *this, float x, float y)
{
    this->rect.x += x * this->speed * engine()->delta_time;
    this->rect.y += y * this->speed * engine()->delta_time;
}

static void destroy(t_object *this)
{
    printf("Destroy object\n");
    if (this->image)
    {
        SDL_DestroyTexture(this->image->textura);
        SDL_FreeSurface(this->image->buffer);
        free(this->image);
    }
    free(this);
}

t_object *new_object(size_t size)
{
    t_object *obj;

    obj = ft_calloc(size);
    if (!obj)
        return NULL;
    obj->move = move;
    obj->rect = (SDL_Rect){100.0f, 100.0f, 32.0f, 32.0f};
    obj->speed = 550.0f;
    obj->destroy = destroy;
    return obj;
}