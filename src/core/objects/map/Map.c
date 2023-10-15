#include "Map.h"

static void __render(t_map *this, SDL_Renderer *renderer)
{
    t_node *linedefs;
    t_node *vertexes;
    size_t size;
    size_t i;
    int iXShift = -this->x_min; // Invert the min X value
    int iYShift = -this->y_min; // Invert the min Y value

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    linedefs = array(this->linedefs)->array;
    vertexes = array(this->vertexes)->array;
    i = 0;
    size = array(this->linedefs)->size;
    while (i < size)
    {
        t_vertex *vStart = (t_vertex *)vertexes[((t_linedef *)linedefs[i].value)->start_vertex].value; // Read the first point
        t_vertex *vEnd = (t_vertex *)vertexes[((t_linedef *)linedefs[i].value)->end_vertex].value;     // Read the second point
        SDL_RenderDrawLine(renderer,
                           (vStart->x_position + iXShift) / this->scale,
                           (vStart->y_position + iYShift) / this->scale,
                           (vEnd->x_position + iXShift) / this->scale,
                           (vEnd->y_position + iYShift) / this->scale);
        i++;
    }
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
    map->name = name;
    map->x_min = INT_MAX;
    map->y_min = INT_MAX;
    map->x_max = INT_MIN;
    map->y_max = INT_MIN;
    map->scale = 15;
    map->map_index = find_map_index(wad, name);
    read_map_vertex(wad, map);
    normalize_vertex(map);
    read_map_linedef(wad, map);
    return (map);
}