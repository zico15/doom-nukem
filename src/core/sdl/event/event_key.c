#include "Core.h"

static void key_pressed(t_sdl *sdl)
{
}

static void key_released(t_sdl *sdl)
{
    (void)sdl;
}

static void key_down(t_sdl *sdl)
{
    if (sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        sdl->running = false;
}

void key_handler(t_sdl *sdl)
{
    if (sdl->event.type == SDL_QUIT)
        sdl->running = false;
    else if (sdl->event.type == SDL_KEYUP)
        key_released(sdl);
    else if (sdl->event.type == SDL_KEYDOWN)
    {
        key_pressed(sdl);
        key_down(sdl);
    }
}