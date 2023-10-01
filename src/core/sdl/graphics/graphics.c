#include "Engine.h"

void graphics(t_sdl *sdl)
{
    SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
    SDL_RenderClear(sdl->renderer);
    SDL_SetRenderDrawColor(sdl->renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(sdl->renderer, 0, 0, 640, 480);
    SDL_RenderPresent(sdl->renderer);
}

void draw_image(t_sdl *sdl, SDL_Surface *image, int x, int y)
{
    static SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = image->w;
    rect.h = image->h;
    SDL_BlitSurface(image, NULL, sdl->surface, &rect);
}

void draw_rect(t_sdl *sdl, int x, int y, int width, int height, int color)
{
    static SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_SetRenderDrawColor(sdl->renderer, color, color, color, 255);
    SDL_RenderFillRect(sdl->renderer, &rect);
}

void draw_line(t_sdl *sdl, int x1, int y1, int x2, int y2, int color)
{
    SDL_SetRenderDrawColor(sdl->renderer, color, color, color, 255);
    SDL_RenderDrawLine(sdl->renderer, x1, y1, x2, y2);
}

void draw_pixel(t_sdl *sdl, int x, int y, int color)
{
    SDL_SetRenderDrawColor(sdl->renderer, color, color, color, 255);
    SDL_RenderDrawPoint(sdl->renderer, x, y);
}