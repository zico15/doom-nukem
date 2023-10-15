#include "Engine.h"

static void __render(t_scene *this, SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect rec1 = {100, 100, 40, 40};
    SDL_RenderDrawRect(renderer, &rec1);
    SDL_SetRenderDrawColor(renderer, 165, 42, 42, 255);
    SDL_Rect rec2 = {10, 10, 40, 40};
    SDL_RenderDrawRect(renderer, &rec2);
}

t_scene *new_login()
{
    t_scene *scene;

    scene = new_scene(NULL);
    scene->render = __render;
    return (scene);
}