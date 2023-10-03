#include "Engine.h"

static void mouse_pressed(t_sdl *sdl)
{
    printf("Mouse pressed: %d %d\n", sdl->event.button.x, sdl->event.button.y);
}

static void mouse_released(t_sdl *sdl)
{
    printf("Mouse released: %d %d\n", sdl->event.button.x, sdl->event.button.y);
}

static void mouse_down(t_sdl *sdl)
{
    printf("Mouse down: %d %d\n", sdl->event.button.x, sdl->event.button.y);
}

static void mouse_move(t_sdl *sdl)
{
    printf("Mouse moved: %d %d\n", sdl->event.motion.x, sdl->event.motion.y);
}

void mouse_handler(t_sdl *sdl)
{
    if (!engine()->scene->mouse)
        return;
    if (sdl->event.type == SDL_MOUSEBUTTONUP)
        mouse_released(sdl);
    else if (sdl->event.type == SDL_MOUSEBUTTONDOWN)
    {
        mouse_pressed(sdl);
        mouse_down(sdl);
    }
    else if (sdl->event.type == SDL_MOUSEMOTION)
        mouse_move(sdl);
}