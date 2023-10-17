#include "Engine.h"

static t_wad_subsector *read_subsector_data(const uint8_t *pWADData, int offset, t_map *map)
{
    t_wad_subsector *subsector;

    subsector = ft_calloc(sizeof(t_wad_subsector));
    subsector->seg_count = read_2_bytes(pWADData, offset);
    subsector->first_seg_id = read_2_bytes(pWADData, offset + 2);
    return (subsector);
}

void read_map_subsectors(t_wadd_data *wad_data, t_map *map)
{
    int i;
    int index;
    int count_subsectors;
    t_wad_subsector *subsector;

    printf("read_map_subsectors\n");
    index = map->map_index + SSECTORS;
    if (index == SSECTORS || !string().equals_n(wad_data->directory[index].name, "SSECTORS", 8))
    {
        printf("Map %s not found\n", map->name);
        return;
    }
    printf("SSECTORS: %s\n", wad_data->directory[index].name);
    count_subsectors = wad_data->directory[index].size / sizeof(t_wad_subsector);
    i = 0;
    while (i < count_subsectors)
    {
        subsector = (t_wad_subsector *)array(map->subsectors)->add(read_subsector_data(wad_data->data, wad_data->directory[index].offset + i * sizeof(t_wad_subsector), map))->value;
        i++;
        printf("seg_count: %i first_seg_id: %i\n",
               subsector->seg_count, subsector->first_seg_id);
    }
}