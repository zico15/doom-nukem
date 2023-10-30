#include <WADData.h>
#include <ft_string.h>
#include <Map.h>



int find_map_index(t_wad_data *wad_data, char *map_name)
{
    int i;

    i = 0;
    while (i < wad_data->header.numLumps)
    {
        if (string().equals(wad_data->directory[i].name, map_name))
            return (i);
        i++;
    }
    return (0);
}