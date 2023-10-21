#include "Engine.h"

static t_wadd_thing *read_thing_data(const uint8_t *pWADData, int offset, t_map *map)
{
    t_wadd_thing *thing;

    thing = ft_calloc(sizeof(t_wadd_thing));
    thing->x_position = read_2_bytes(pWADData, offset);
    thing->y_position = read_2_bytes(pWADData, offset + 2);
    thing->angle = read_2_bytes(pWADData, offset + 4);
    thing->type = read_2_bytes(pWADData, offset + 6);
    thing->flags = read_2_bytes(pWADData, offset + 8);
    return (thing);
}

void read_map_things(t_wadd_data *wad_data, t_map *map)
{
    int i;
    int index;
    int count_things;
    t_wadd_thing *thing;

    printf("read_map_things\n");
    index = map->map_index + THINGS;
    if (index == THINGS || !string().equals_n(wad_data->directory[index].name, "THINGS", 6))
    {
        printf("Map %s not found\n", map->name);
        return;
    }
    printf("THINGS: %s\n", wad_data->directory[index].name);
    count_things = wad_data->directory[index].size / sizeof(t_wadd_thing);
    i = 0;
    while (i < count_things)
    {
        thing = (t_wadd_thing *)array(map->things)->add(read_thing_data(wad_data->data, wad_data->directory[index].offset + i * sizeof(t_wadd_thing), map))->value;
        i++;
        if (thing->type == 1)
        {
            map->player.x_position = thing->x_position;
            map->player.y_position = thing->y_position;
            map->player.angle = thing->angle;
            map->player.type = thing->type;
            map->player.flags = thing->flags;
        }
        printf("x_position: %i y_position: %i angle: %i type: %i flags: %i\n",
               map->player.x_position, map->player.y_position, (int)map->player.angle, map->player.type, map->player.flags);
    }
}