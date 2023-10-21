#include "Engine.h"

// static void key_pressed(bool *key)
// {

//     if (engine()->scene->key)
//         engine()->scene->key(engine()->scene, key, SDL_KEYDOWN);
//     // engine()->object->move(engine()->object,
//     //                        key[SDL_SCANCODE_D] - key[SDL_SCANCODE_A], key[SDL_SCANCODE_S] - key[SDL_SCANCODE_W]);
// }

// static void key_released(bool *key)
// {
//     if (engine()->scene->key)
//         engine()->scene->key(engine()->scene, key, SDL_KEYUP);
// }

// static void key_down(bool *key)
// {
//     if (key[SDL_SCANCODE_ESCAPE])
//         engine()->sdl->running = false;
// }

void key_handler(t_sdl *sdl)
{
    if (!engine()->scene->key)
        return;
    sdl->keys[sdl->event.key.keysym.scancode] = (sdl->event.type == SDL_KEYDOWN);
    if (sdl->keys[SDL_SCANCODE_ESCAPE])
    {
        sdl->running = false;
        return;
    }
    engine()->scene->key(engine()->scene, sdl->keys, &sdl->event);
}