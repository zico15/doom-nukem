#ifndef Map_H
#define Map_H

#include "Engine.h"
#include <fcntl.h>

#define MAP_PATH "resources/maps/"

typedef struct s_map t_map;

struct s_map
{
    int id;
    char layout[20][501][501];
    char *path;
    bool (*save)(t_map *map);
    void (*destroy)(t_map *map);
};

struct s_map_data
{
    int id;
    char layout[20][501][501];
};

t_map *new_map(char *path);
// test
void set_layout(t_map *map, char c);
void print_layout(t_map *map);

#endif