#ifndef SDL2D_H
#define SDL2D_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>

#define RENDER_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
#define FPS 60

typedef struct s_sdl t_sdl;
typedef struct s_image t_image;
typedef SDL_Scancode t_key;

struct s_sdl
{
    SDL_Window *win;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Event event;
    t_image *image;
    bool running;
    bool fullscreen;
    int width;
    int height;
    float currentTime;
};

struct s_image
{
    SDL_Surface *buffer;
    SDL_Texture *textura;
    int width;
    int height;
};

void sdl_loop(t_sdl *sdl);
t_sdl *new_sdl(int width, int height);
SDL_Surface *new_image(int width, int height);
t_image *new_image_file(char *path);

#endif