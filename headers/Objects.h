#ifndef OBJECTS_H
#define OBJECTS_H

#include "Engine.h"

typedef struct s_object t_object;
typedef struct s_scene t_scene;

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
    int life;
    void (*move)(t_object *this, float x, float y);
    void (*render)(t_object *this, SDL_Renderer *renderer);
    void (*destroy)(t_object *this);
    void (*update)(t_object *this, t_sdl *sdl);
    void (*collision)(t_object *this, t_object *target, t_sdl *sdl);
    void (*key)(t_object *this, bool *key, SDL_EventType event);
    void (*mouse)(t_object *this, t_sdl *sdl, SDL_Event event);
    void (*damage)(t_object *this, int damage);
};

struct s_scene
{
    t_type type;
    SDL_Rect rect;
    t_image *image;
    float speed;
    int life;
    void (*move)(t_scene *this, float x, float y);
    void (*render)(t_scene *this, SDL_Renderer *renderer);
    void (*destroy)(t_scene *this);
    void (*update)(t_scene *this, t_sdl *sdl);
    void (*collision)(t_scene *this, t_object *target, t_sdl *sdl);
    void (*key)(t_scene *this, bool *key, SDL_EventType event);
    void (*mouse)(t_scene *this, t_sdl *sdl, SDL_Event event);
    void (*damage)(t_object *this, int damage);
    t_object *(*add)(t_scene *this, t_object *object);
    t_object *objects[2];
    t_object **event_key;
};

t_object *new_object(size_t size);
t_scene *new_scene(int width, int height);

#endif