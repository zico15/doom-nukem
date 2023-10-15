#include "Engine.h"

static t_linedef *read_linedef_data(const uint8_t *pWADData, int offset)
{
    t_linedef *linedef;

    linedef = ft_calloc(sizeof(t_linedef));
    linedef->start_vertex = read_2_bytes(pWADData, offset);
    linedef->end_vertex = read_2_bytes(pWADData, offset + 2);
    linedef->flags = read_2_bytes(pWADData, offset + 4);
    linedef->line_type = read_2_bytes(pWADData, offset + 6);
    linedef->sector_tag = read_2_bytes(pWADData, offset + 8);
    linedef->right_sidedef = read_2_bytes(pWADData, offset + 10);
    linedef->left_sidedef = read_2_bytes(pWADData, offset + 12);
    return (linedef);
}
void read_map_linedef(t_wadd_data *wad_data, t_map *map)
{
    int i;
    int index;
    int count_linedef;
    t_linedef *linedef;

    printf("read_map_linedef\n");
    index = map->map_index + LINEDEFS;
    if (index == LINEDEFS || !string().equals_n(wad_data->directory[index].name, "LINEDEFS", 8))
    {
        printf("Map %s not found\n", map->name);
        return;
    }
    printf("LINEDEFS: %s\n", wad_data->directory[index].name);
    count_linedef = wad_data->directory[index].size / sizeof(t_linedef);
    i = 0;
    while (i < count_linedef)
    {
        linedef = (t_linedef *)array(map->linedefs)->add(read_linedef_data(wad_data->data, wad_data->directory[index].offset + i * sizeof(t_linedef)))->value;
        i++;
        printf("start_vertex: %i, end_vertex: %i, flags: %i, line_type: %i, sector_tag: %i, right_sidedef: %i, left_sidedef: %i\n", linedef->start_vertex, linedef->end_vertex, linedef->flags, linedef->line_type, linedef->sector_tag, linedef->right_sidedef, linedef->left_sidedef);
    }
}