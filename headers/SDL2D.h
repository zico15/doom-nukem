#ifndef SDL2D_H
#define SDL2D_H

#include <SDL.h>
#include <stdbool.h>

#define RENDER_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
#define FPS 60

typedef struct s_sdl t_sdl;

struct s_sdl
{
    SDL_Window *win;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool running;
    bool fullscreen;
    int width;
    int height;
    void (*update)(t_sdl *sdl);
    void (*render)(SDL_Renderer *renderer, t_sdl *sdl);
};

void sdl_loop(t_sdl *sdl);
t_sdl *new_sdl(int width, int height);

#endif