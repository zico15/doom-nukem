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

static bool __save(t_map *map)
{
    int fd;

    if (!map->path)
        return (false);
    fd = open(map->path, O_WRONLY | O_CREAT, 0644);
    printf("Mapa salvo: %s fd: %i\n", map->path, fd);
    if (fd == -1)
        return (false);
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
static void __destroy(t_map *map)
{
    free(map->path);
    free(map);
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
        map->path = string().join(MAP_PATH, path);
        fd = open(map->path, O_RDONLY);
        printf("Mapa carregado: %s fd: %i\n", map->path, fd);
        if (fd >= 0 && read(fd, map, sizeof(struct s_map_data)) >= 0)
            close(fd);
    }
    map->destroy = __destroy;
    map->save = __save;
    return (map);
}