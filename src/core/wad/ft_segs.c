#include <Engine.h>

static t_wad_seg *read_seg_data(const uint8_t *data, int offset, t_map *map)
{
    t_wad_seg *seg;

    seg = ft_calloc(sizeof(t_wad_seg));
    seg->start_vertex_id = read_2_bytes(data, offset);
    seg->end_vertex_id = read_2_bytes(data, offset + 2);
    seg->angle = read_2_bytes(data, offset + 4);
    seg->linedef_id = read_2_bytes(data, offset + 6);
    seg->direction = read_2_bytes(data, offset + 8);
    seg->offset = read_2_bytes(data, offset + 10);
    return (seg);
}

void read_map_segs(t_wad_data *wad_data, t_map *map)
{
    int i;
    int index;
    int count_segs;
    t_wad_seg *seg;

    printf("read_map_segs\n");
    index = map->map_index + SEGS;
    if (index == SEGS || !string().equals_n(wad_data->directory[index].name, "SEGS", 4))
    {
        printf("Map %s not found\n", map->name);
        return;
    }
    printf("SEAGS: %s\n", wad_data->directory[index].name);
    count_segs = wad_data->directory[index].size / sizeof(t_wad_seg);
    i = 0;
    while (i < count_segs)
    {
        seg = (t_wad_seg *)array(map->segs)->add(read_seg_data(wad_data->data, wad_data->directory[index].offset + i * sizeof(t_wad_seg), map))->value;
        i++;
        printf("start_vertex_id: %i end_vertex_id: %i angle: %i linedef_id: %i direction: %i offset: %i\n",
               seg->start_vertex_id, seg->end_vertex_id, seg->angle, seg->linedef_id, seg->direction, seg->offset);
    }
}