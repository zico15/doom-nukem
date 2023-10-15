
#include "Engine.h"

void key_handler(t_sdl *sdl);
void mouse_handler(t_sdl *sdl);

static void render_defaul(SDL_Renderer *renderer)
{
    // Desenhe a textura na tela
    engine()->scene->render(engine()->scene, renderer);
}

static void update_default(t_sdl *sdl)
{
    engine()->scene->update(engine()->scene, sdl);
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

// SDL_INIT_VIDEO linux mac SDL_INIT_EVERYTHING, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
t_sdl *new_sdl(int width, int height)
{
    t_sdl *sdl;

    if (SDL_Init(SDL_INIT_VIDEO) != 0 || IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
        engine()->destroy("Error initializing SDL");
    sdl = malloc(sizeof(t_sdl));
    if (!sdl)
        engine()->destroy("Error initializing SDL");
    sdl->width = width;
    sdl->height = height;
    engine()->render = render_defaul;
    engine()->update = update_default;
    if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &sdl->win, &sdl->renderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        engine()->destroy("Error initializing Window");
    }
    if (!sdl->renderer)
        engine()->destroy("Error creating renderer");
    sdl->surface = SDL_GetWindowSurface(sdl->win);
    return (sdl);
}

void sdl_loop(t_sdl *sdl)
{
    SDL_Event event;
    Uint32 prevTime;

    prevTime = SDL_GetTicks();
    sdl->running = true;
    int i = 0;
    while (sdl->running)
    {
        sdl->currentTime = SDL_GetTicks();
        engine()->delta_time = (sdl->currentTime - prevTime) / 1000.0f;
        prevTime = sdl->currentTime;
        even_handler(sdl);
        // engine()->update();
        SDL_RenderClear(sdl->renderer);
        engine()->render(sdl->renderer);
        // printf("render\n");
        /* Draw to window and loop */
        SDL_RenderPresent(sdl->renderer);
        SDL_Delay(1000 / FPS);
    }
    engine()->destroy("Exiting...");
}