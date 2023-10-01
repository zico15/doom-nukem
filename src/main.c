#include <stdio.h>
#include <stdbool.h>
#include <Engine.h>

void print_node(t_node *e, void *v)
{
    (void)v;
    printf("%s\n", (char *)e->value);
}

int main(int argc, char *argv[])
{

    // void *a;

    // a = new_array(STR);

    // array(a)->add(("Hello"))->destroy = NULL;
    // array(a)->add(strdup("World"));
    // array(a)->add(strdup("Hello"));
    // // array(a)->remove("World");

    // array(a)->for_each(print_node, NULL);
    // array(a)->set(0, " sdsd");
    // array(a)->for_each(print_node, NULL);

    // engine()->init(argc, argv, 640, 480);

    // t_scene *scene = new_scene(640, 480);

    // t_object *object = new_object(sizeof(t_object));
    // object->key = NULL;
    // scene->add(scene, object);
    // scene->add(scene, new_object(sizeof(t_object)))->rect.x = 300;

    // engine()->scene = scene;

    // engine()->run();
    // engine()->destroy(NULL);

    // t_map map;

    // map.numero = 10;
    // map.nome = strdup("Hello World");
    // save(&map, "mapa.txt");

    t_map *map = new_map("mapa.txt");
    // save(map, );
    // t_map *map_load = load("mapa.txt");
    print_layout(map);
    set_layout(map, 'd');
    map->save(map, "mapa.txt");
    return (0);
}