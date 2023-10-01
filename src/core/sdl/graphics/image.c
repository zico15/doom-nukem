#include "Engine.h"

t_image *new_image_file(char *path)
{
    t_image *image;

    image = malloc(sizeof(t_image));
    if (!image)
        return (NULL);
    image->buffer = IMG_Load(path);
    if (!image->buffer)
    {
        free(image);
        return (NULL);
    }
    image->textura = SDL_CreateTextureFromSurface(engine()->sdl->renderer, image->buffer);
    return (image);
}
SDL_Surface *new_image(int width, int height)
{
    SDL_Surface *image;

    image = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    if (!image)
        return (NULL);
    return (image);
}
