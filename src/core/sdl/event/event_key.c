#include "Core.h"

static void key_pressed(t_key key)
{
    // printf("Key pressed: %i\n", sdl->event.key.keysym.scancode);
    // if (sdl->event.key.keysym.scancode == SDL_SCANCODE_W)
    //     engine()->object->move(engine()->object, 0, -1);
    // if (sdl->event.key.keysym.scancode == SDL_SCANCODE_A)
    //     engine()->object->move(engine()->object, -1, 0);
    // if (sdl->event.key.keysym.scancode == SDL_SCANCODE_S)
    //     engine()->object->move(engine()->object, 0, 1);
    // if (sdl->event.key.keysym.scancode == SDL_SCANCODE_D)
    //     engine()->object->move(engine()->object, 1, 0);
}

static void key_released(t_key key)
{
    // printf("Key released: %i\n", sdl->event.key.keysym.scancode);
}

static void key_down(t_key key)
{
    if (key == SDL_SCANCODE_ESCAPE)
        engine()->sdl->running = false;
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