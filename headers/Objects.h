#ifndef OBJECTS_H
#define OBJECTS_H

#include "Engine.h"

typedef struct s_object t_object;
typedef struct s_scene t_scene;
typedef struct s_plane t_plane;
typedef struct s_camera t_camera;

#define res 1
#define SW 160 * res
#define SH 120 * res
#define SW2 (SW / 2)
#define SH2 (SH / 2)
#define pixelScale 4 / res
#define GLSW (SW * pixelScale)
#define GLSH (SH * pixelScale)

typedef struct s_math
{
    float cos[360];
    float sin[360];
} t_math;

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
    t_vector2 position;
    t_vector2 direction;
    t_image *image;
    int life;
    void (*move)(t_object *this, float x, float y);
    void (*render)(t_object *this, SDL_Renderer *renderer);
    void (*destroy)(t_object *this);
    void (*update)(t_object *this, t_sdl *sdl);
    void (*collision)(t_object *this, t_object *target, t_sdl *sdl);
    void (*key)(t_object *this, bool *key, SDL_Event *event);
    void (*mouse)(t_object *this, t_sdl *sdl, SDL_Event *event);
    void (*damage)(t_object *this, int damage);
};

struct s_scene
{
    t_type type;
    SDL_Rect rect;
    t_vector2 position;
    t_vector2 direction;
    t_image *image;
    int life;
    void (*move)(t_scene *this, float x, float y);
    void (*render)(t_scene *this, SDL_Renderer *renderer);
    void (*destroy)(t_scene *this);
    void (*update)(t_scene *this, t_sdl *sdl);
    void (*collision)(t_scene *this, t_object *target, t_sdl *sdl);
    void (*key)(t_scene *this, bool *key, SDL_Event *event);
    void (*mouse)(t_scene *this, t_sdl *sdl, SDL_Event *event);
    void (*damage)(t_object *this, int damage);
    t_object *(*add)(t_scene *this, void *object);
    void *objects;
    void *event_render;
    void *event_update;
    void *event_key;
};

struct s_plane
{
    t_type type;
    SDL_Rect rect;
    t_vector2 position;
    t_vector2 direction;
    t_image *image;
    int life;
    void (*move)(t_plane *this, float x, float y);
    void (*render)(t_plane *this, SDL_Renderer *renderer);
    void (*destroy)(t_plane *this);
    void (*update)(t_plane *this, t_sdl *sdl);
    void (*collision)(t_plane *this, t_object *target, t_sdl *sdl);
    void (*key)(t_plane *this, bool *key, SDL_Event *event);
    void (*mouse)(t_plane *this, t_sdl *sdl, SDL_Event *event);
    void (*damage)(t_plane *this, int damage);
    float a;
    float b;
    float c;
    float d;
};

struct s_camera
{
    t_type type;
    SDL_Rect rect;
    t_vector2 position;
    t_vector2 direction;
    t_image *image;
    int life;
    void (*move)(t_camera *this, float x, float y);
    void (*render)(t_camera *this, SDL_Renderer *renderer);
    void (*destroy)(t_camera *this);
    void (*update)(t_camera *this, t_sdl *sdl);
    void (*collision)(t_camera *this, t_object *target, t_sdl *sdl);
    void (*key)(t_camera *this, bool *key, SDL_Event *event);
    void (*mouse)(t_camera *this, t_sdl *sdl, SDL_Event *event);
    void (*damage)(t_camera *this, int damage);
    double angSpeed;
    double speed;
    double angle;
    int look;
    t_math math;
};

t_object *new_object(size_t size);
t_scene *new_scene(int width, int height);
t_camera *new_camera();
t_plane *new_plane(float a, float b, float c, float d);

#endif