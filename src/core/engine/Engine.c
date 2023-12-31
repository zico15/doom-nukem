#include "Engine.h"

t_scene *__add_scene(t_scene *scene);

static void init(int argc, char **argv, int width, int height)
{
    (void)argc;
    (void)argv;
    engine()->sdl = new_sdl(width, height);
    if (!engine()->sdl)
   {    
        printf("error\n");
     exit(-1);
     }
}

static void run()
{
    sdl_loop(engine()->sdl);
}

static void destroy(char *msg)
{
    printf("Destroy engine\n");
    engine()->scene->destroy(engine()->scene);
    if (msg)
        printf("%s\n", msg);
    if (engine()->sdl->renderer)
        SDL_DestroyRenderer(engine()->sdl->renderer);
    if (engine()->sdl->win)
        SDL_DestroyWindow(engine()->sdl->win);
    SDL_Quit();
    free(engine()->sdl);
    exit(0);
}

t_engine *engine()
{
    static t_engine e = {
        NULL,
        NULL,
        0,
        init,
        run,
        NULL,
        NULL,
        destroy,
        __add_scene,
    };

    return (&e);
}