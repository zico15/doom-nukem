#include "Map.h"

void print_layout(t_map *map)
{
    int i;
    int j;
    int k;

    i = -1;
    while (++i < 20)
    {
        j = -1;
        while (++j < 100)
        {
            k = -1;
            while (++k < 100)
                printf("%c", map->layout[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
}

static bool __save(t_map *map, char *path)
{
    int fd;

    fd = open(path, O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
        return (false);
    printf("Mapa salvo: %i\n", map->id);
    write(fd, map, sizeof(struct s_map_data));
    close(fd);
    return (true);
}

void set_layout(t_map *map, char c)
{
    int i;
    int j;
    int k;

    i = -1;
    while (++i < 20)
    {
        j = -1;
        while (++j < 100)
        {
            k = -1;
            while (++k < 100)
                map->layout[i][j][k] = c;
        }
    }
}

t_map *new_map(char *path)
{
    int fd;
    t_map *map;

    map = ft_calloc(sizeof(t_map));
    if (!map)
        return (NULL);
    if (path)
    {
        map->path = path;
        fd = open(path, O_RDONLY);
        if (fd == -1)
            return (NULL);
        read(fd, map, sizeof(struct s_map_data));
        close(fd);
    }
    map->save = __save;
    return (map);
}