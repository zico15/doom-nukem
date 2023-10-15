#ifndef Map_H
#define Map_H

#include "Engine.h"
#include <fcntl.h>

#define MAP_PATH "resources/maps/"

typedef struct s_map t_map;

struct s_map
{
    int id;
    char *name;
    int map_index;
    int x_min;
    int y_min;
    int x_max;
    int y_max;
    int scale;
    void *vertexes;
    void *linedefs;
    bool (*save)(t_map *map);
    void (*destroy)(t_map *map);
    void (*render)(t_map *this, SDL_Renderer *renderer);
};

struct s_map_data
{
    int id;
    char layout[20][501][501];
};

t_map *new_map(t_wadd_data *wad, char *name);
// test
void set_layout(t_map *map, char c);
void print_layout(t_map *map);

#endif