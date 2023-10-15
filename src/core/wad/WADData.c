#include <Engine.h>

#pragma pack(1)

// static void extract_thing(t_wad_directory *directory)
// {

//     // t_wadd_thing *thing;

//     if (string().equals(directory->name, "THINGS"))
//     {
//         // thing = ft_calloc(sizeof(t_wadd_thing));

//         // thing->xPosition = directory->data[0];
//         // thing->yPosition = directory->data[2];
//         // thing->angle = directory->data[4];
//         // thing->type = directory->data[6];
//         // thing->flags = directory->data[8];
//         // array(directory->data)->add(thing);
//         // printf("x: %d y: %d angle: %d type: %d flags: %d\n", thing->xPosition, thing->yPosition, thing->angle, thing->type, thing->flags);
//         // printf("offset: %u length: %u name: %.8s data: { %d , %d, %d}\n", directory->offset, directory->length, directory->name, thing->xPosition, thing->yPosition, thing->angle);
//     }
// }

// static void extract_data(t_node *e, t_wadd_data *wad)
// {
//     t_wadd_directory *directory;

//     directory = (t_wadd_directory *)e->value;
//     directory->data = ft_calloc(directory->length + 1);
//     printf("name: %.8s\n", directory->name);
//     readDataFromFile(wad->file, directory->offset, directory->length, directory->data);
// }

static void extractDirectories(t_wadd_data *wad, t_wad_directory *directorys)
{
    size_t i;
    // t_wadd_directory *directory;

    i = -1;
    while (++i < wad->header.numLumps)
    {
        // fseek(wad->file, directorys[i].offset, SEEK_SET);
        // uint8_t *data = malloc(lumps[i].size);
        // if (fread(data, 1, directorys[i].size, wad->file) != directorys[i].size)
        // {
        //     perror("Erro ao ler dados do lump");
        //     free(data);
        //     continue;
        // }
        // directory = ft_calloc(sizeof(t_wadd_directory));
        // directory->offset = lumps[i].filePos;
        // directory->length = lumps[i].size;
        // // memcpy(directory->name, lumps[i].name, 8);
        // // directory->data = data;
        // // extract_thing(directory);
        // array(wad->directory)->add(directory);

        // "WADDirectory{" + "offset=" + offset + ", length=" + length   + ", name=" + name + ", data=" + data + '}';
        // convert para printf
        printf("length: %u offset: %u name: %.8s\n", directorys[i].size, directorys[i].offset, directorys[i].name);
    }
}

static void loadWad(t_wadd_data *wad, char *wad_path)
{
    long file_size;

    wad->file = fopen(wad_path, "rb");
    if (wad->file == NULL)
        return;
    fseek(wad->file, 0, SEEK_END);
    file_size = ftell(wad->file);
    fseek(wad->file, 0, SEEK_SET);
    wad->data = (uint8_t *)malloc(file_size);
    if (wad->data == NULL)
        return;
    fread(wad->data, 1, file_size, wad->file);
    fclose(wad->file);
    read_header(wad->data, 0, &wad->header);
    printf("name: %s numLumps: %i directoryOffset: %i\n", wad->header.identification, wad->header.numLumps, wad->header.directoryOffset);
    wad->directory = malloc(sizeof(t_wad_directory) * wad->header.numLumps);
    wad->directory = (t_wad_directory *)(wad->data + wad->header.directoryOffset);
    extractDirectories(wad, wad->directory);
    printf("map: %i\n", find_map_index(wad, "E1M1"));
}

t_wadd_data init_wad_data(char *wad_path)
{
    t_wadd_data e;

    e.file = NULL;
    e.is_valid = wad_path == NULL;
    e.things = new_array(OBJECT);
    if (wad_path != NULL)
        loadWad(&e, wad_path);
    return (e);
}