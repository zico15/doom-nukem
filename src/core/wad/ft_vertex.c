#include "Engine.h"

static t_wad_vertex *read_vertex_data(const uint8_t *pWADData, int offset)
{
    t_wad_vertex *vertex;

    vertex = ft_calloc(sizeof(t_wad_vertex));
    vertex->x_position = read_2_bytes(pWADData, offset);
    vertex->y_position = read_2_bytes(pWADData, offset + 2);
    return (vertex);
}

void normalize_vertex(t_map *map)
{
    size_t i;
    size_t size;
    t_node *node;

    node = array(map->vertexes)->array;
    i = -1;
    size = array(map->vertexes)->size;
    while (++i < size)
    {
        if (map->min_x > ((t_wad_vertex *)(node[i]).value)->x_position)
            map->min_x = ((t_wad_vertex *)(node[i]).value)->x_position;
        if (map->min_y > ((t_wad_vertex *)(node[i]).value)->y_position)
            map->min_y = ((t_wad_vertex *)(node[i]).value)->y_position;
    }
    i = -1;
    // while (++i < size)
    // {
    //     ((t_wad_vertex *)(node[i]).value)->x_position -= map->min_x;
    //     ((t_wad_vertex *)(node[i]).value)->y_position -= map->min_y;
    //     if (map->x_min > ((t_wad_vertex *)(node[i]).value)->x_position)
    //         map->x_min = ((t_wad_vertex *)(node[i]).value)->x_position;
    //     if (map->y_min > ((t_wad_vertex *)(node[i]).value)->y_position)
    //         map->y_min = ((t_wad_vertex *)(node[i]).value)->y_position;
    //     if (map->x_max < ((t_wad_vertex *)(node[i]).value)->x_position)
    //         map->x_max = ((t_wad_vertex *)(node[i]).value)->x_position;
    //     if (map->y_max < ((t_wad_vertex *)(node[i]).value)->y_position)
    //         map->y_max = ((t_wad_vertex *)(node[i]).value)->y_position;
    // }
}

void read_map_vertex(t_wad_data *wad_data, t_map *map)
{
    int i;
    int index;
    int count_vertex;
    t_wad_vertex *vertex;

    index = find_map_index(wad_data, map->name) + VERTEXES;
    if (index == VERTEXES || !string().equals_n(wad_data->directory[index].name, "VERTEXES", 8))
    {
        printf("Map %s not found\n", map->name);
        return;
    }
    count_vertex = wad_data->directory[index].size / sizeof(t_wad_vertex);
    i = 0;
    while (i < count_vertex)
    {
        vertex = (t_wad_vertex *)array(map->vertexes)->add(read_vertex_data(wad_data->data, wad_data->directory[index].offset + i * sizeof(t_wad_vertex)))->value;
        i++;
        printf("(%i,%i)\n", vertex->x_position, vertex->y_position);
    }
    // int size = array(map->vertexes)->size;
    // t_node *node = array(map->vertexes)->array;
    // i = -1;
    // while (++i < size)
    // {
    //     // vertex = node[i];
    //     // printf("(%i,%i)\n", vertex->x_position, vertex->y_position);
    //     printf("%p\n", node[i].value);
    // }
}