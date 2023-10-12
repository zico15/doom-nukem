#include <SDL2/SDL.h>
#include <DoomEngine.h>

struct DoomEngine
{
    char *wad_path;
}   t_DoomEngine;

int main(int argc, char *argv[])
{

    // test_binary_tree();

    // test_binary_tree();
    argv[1] = "resources/maps/DOOM1.WAD";

    WADData()->init(argv[1]);
    engine()->init(argc, argv, GLSW, GLSH);

    t_scene *scene = new_scene(0, 0);

    scene->add(scene, new_camera());

    // scene->add(scene, new_plane(1.0f, 0.0f, 0.0f, -200.0f));

    engine()->add(scene);
    engine()->run();
    engine()->destroy(NULL);

    // t_map *map = new_map("mapa.txt");
    // save(map, );
    // t_map *map_load = load("mapa.txt");
    // print_layout(map);
    // set_layout(map, 'd');
    // print_layout(map);

    // map->save(map);
    // map->destroy(map);
    return (0);
}