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
    // static bool keys[SDL_NUM_SCANCODES] = {0};

    if (!engine()->scene->key)
        return;
    // keys[sdl->event.key.keysym.scancode] = (sdl->event.type == SDL_KEYDOWN);
    if (sdl->event.type == SDL_QUIT)
        sdl->running = false;
    else if (sdl->event.type == SDL_KEYUP)
        engine()->scene->key(engine()->scene, NULL, &sdl->event);
    else if (sdl->event.type == SDL_KEYDOWN)
    {
        engine()->scene->key(engine()->scene, NULL, &sdl->event);
        // key_down(keys);
    }
}