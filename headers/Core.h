#ifndef CORE_H
#define CORE_H

#include "SDL2D.h"
#include "Objects.h"

typedef struct s_engine t_engine;

struct s_engine
{
    t_sdl *sdl;
    t_scene *scene;
    float delta_time;
    void (*init)(int argc, char **argv, int width, int height);
    void (*run)();
    void (*update)();
    void (*render)(SDL_Renderer *renderer);
    void (*destroy)(char *msg);
};

t_engine *engine();
#endif