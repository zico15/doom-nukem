
#include "Core.h"

void key_handler(t_sdl *sdl);
void mouse_handler(t_sdl *sdl);

static void render_defaul(SDL_Renderer *renderer, t_sdl *sdl)
{
    (void)renderer;
    (void)sdl;
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
}

static void update_default(t_sdl *sdl)
{
    (void)sdl;
}

static void even_handler(t_sdl *sdl)
{
    while (SDL_PollEvent(&sdl->event))
    {
        if (sdl->event.type == SDL_KEYDOWN || sdl->event.type == SDL_KEYUP)
            key_handler(sdl);
        else if (sdl->event.type == SDL_QUIT)
            sdl->running = false;
        else if (sdl->event.type == SDL_MOUSEBUTTONDOWN || sdl->event.type == SDL_MOUSEBUTTONUP || sdl->event.type == SDL_MOUSEMOTION)
            mouse_handler(sdl);
    }
}
t_sdl *new_sdl(int width, int height)
{
    t_sdl *sdl;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return (NULL);
    sdl = malloc(sizeof(t_sdl));
    if (!sdl)
        return (game_exit(sdl, "Error initializing SDL"));
    sdl->width = width;
    sdl->height = height;
    sdl->render = render_defaul;
    sdl->update = update_default;
    sdl->win = SDL_CreateWindow("Hello Platformer!",
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!sdl->win)
        return (game_exit(sdl, "Error creating window"));
    sdl->renderer = SDL_CreateRenderer(sdl->win, -1, RENDER_FLAGS);
    if (!sdl->renderer)
        return (game_exit(sdl, "Error creating renderer"));
    sdl->surface = SDL_GetWindowSurface(sdl->win);
    return (sdl);
}

void sdl_loop(t_sdl *sdl)
{
    SDL_Event event;

    sdl->running = true;
    while (sdl->running)
    {
        even_handler(sdl);
        sdl->update(sdl);
        sdl->render(sdl->renderer, sdl);
        /* Draw to window and loop */
        SDL_RenderPresent(sdl->renderer);
        SDL_Delay(1000 / FPS);
    }
    game_exit(sdl, "Exiting...");
}