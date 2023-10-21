#include "Map.h"

void __render_map_wall(t_map *this, SDL_Renderer *renderer, int iXShift, int iYShift);
void __render_map_wall_player(t_map *this, SDL_Renderer *renderer, int iXShift, int iYShift);
void __render_auto_map_node(t_map *this, SDL_Renderer *renderer, int iXShift, int iYShift);
void __renderBSPNodes(t_map *map, SDL_Renderer *renderer);

static void __render(t_map *this, SDL_Renderer *renderer)
{
    __render_map_wall(this, renderer, -this->x_min, -this->y_min);
    __render_map_wall_player(this, renderer, -this->x_min, -this->y_min);
    __renderBSPNodes(this, renderer);
}

t_map *new_map(t_wadd_data *wad, char *name)
{
    int fd;
    t_map *map;

    map = ft_calloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->render = __render;
    map->linedefs = new_array(OBJECT);
    map->vertexes = new_array(OBJECT);
    map->things = new_array(OBJECT);
    map->nodes = new_array(OBJECT);
    map->subsectors = new_array(OBJECT);
    map->segs = new_array(OBJECT);
    map->name = name;
    map->x_min = INT_MAX;
    map->y_min = INT_MAX;
    map->x_max = INT_MIN;
    map->y_max = INT_MIN;
    map->min_x = __INT16_MAX__;
    map->min_y = __INT16_MAX__;
    map->scale = 15;
    map->map_index = find_map_index(wad, name);
    map->direction[0][0] = -1;
    map->direction[0][1] = -1;
    map->direction[1][0] = 0;
    map->direction[1][1] = -1;
    map->direction[2][0] = +1;
    map->direction[2][1] = -1;
    map->direction[3][0] = -1;
    map->direction[3][1] = 0;
    map->direction[4][0] = 0;
    map->direction[4][1] = 0;
    map->direction[5][0] = +1;
    map->direction[5][1] = 0;
    map->direction[6][0] = -1;
    map->direction[6][1] = +1;
    map->direction[7][0] = 0;
    map->direction[7][1] = +1;
    map->direction[8][0] = +1;
    map->direction[8][1] = +1;
    read_map_vertex(wad, map);
    normalize_vertex(map);
    read_map_linedef(wad, map);
    read_map_things(wad, map);
    read_map_nodes(wad, map);
    read_map_subsectors(wad, map);
    read_map_segs(wad, map);
    // exit(0);
    return (map);
}