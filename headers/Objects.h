#ifndef OBJECTS_H
#define OBJECTS_H

#include "Core.h"

typedef struct s_object t_object;

typedef enum e_type
{
    NONE,
    PLAYER,
    ENEMY,
    WALL,
} t_type;

struct s_object
{
    t_type type;
    SDL_Rect rect;
    t_image *image;
    float speed;
    void (*move)(t_object *this, float x, float y);
    void (*render)(t_object *this, SDL_Renderer *renderer);
    void (*destroy)(t_object *this);
    void (*update)(t_object *this, t_sdl *sdl);
    void (*collision)(t_object *this, t_object *target, t_sdl *sdl);
    void (*key)(t_object *this, t_sdl *sdl, SDL_Event event);
    void (*mouse)(t_object *this, t_sdl *sdl, SDL_Event event);
};

t_object *object_new(size_t size);

#endif