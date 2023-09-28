#include "Core.h"

// SDL_Surface *new_image_file(char *path)
// {
//     SDL_Surface *image;

//     image = IMG_Load(path);
//     if (!image)
//         return (NULL);
//     return (image);
// }
SDL_Surface *new_image(int width, int height)
{
    SDL_Surface *image;

    image = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    if (!image)
        return (NULL);
    return (image);
}

// SDL_Surface *load_image_png(char *path)
// {
//     SDL_Surface *image;

//     image = IMG_Load(path);
//     if (!image)
//         return (NULL);
//     return (image);
// }