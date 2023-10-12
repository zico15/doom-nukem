#ifndef DOOMENGINE_H
#define DOOMENGINE_H

#include <ft_string.h>
#include <WADData.h>

typedef struct s_doomEngine t_doomEngine;

struct s_doomEngine
{
    char *wad_path;
    void (*init)(char *wad_path);
};

t_doomEngine *doomEngine();

#endif