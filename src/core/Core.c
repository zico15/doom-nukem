#include "Core.h"

void *game_exit(t_sdl *sdl, char *msg)
{
    if (sdl->renderer)
        SDL_DestroyRenderer(sdl->renderer);
    if (sdl->win)
        SDL_DestroyWindow(sdl->win);
    if (sdl->surface)
        SDL_FreeSurface(sdl->surface);
    SDL_Quit();
    printf("%s\n", msg);
    free(sdl);
    return (NULL);
}