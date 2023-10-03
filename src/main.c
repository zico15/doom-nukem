#include <stdio.h>
#include <stdbool.h>
#include <Engine.h>

t_scene *new_login();

void print_node(t_node *e, void *v)
{
    (void)v;
    printf("%s\n", (char *)e->value);
}

void __key(t_object *this, bool *key, SDL_EventType event)
{
    printf("key\n");
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
    // printf("================================\n");
    // // array(a)->set(0, " sdsd");
    // array(a)->remove(" World", true);
    // array(a)->for_each(print_node, NULL);

    // array(a)->destroy();
    engine()->init(argc, argv, 640, 480);

    t_scene *scene = new_scene(0, 0);

    t_object *object = new_camera();

    // object->key = NULL;

    scene->add(scene, object);
    scene->add(scene, new_object(sizeof(t_object)))->rect.x = 300;

    engine()->scene = scene;

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