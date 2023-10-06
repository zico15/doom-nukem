#include <stdio.h>
#include <stdbool.h>
#include <Engine.h>

t_scene *new_login();

void print_node(t_node *e, void *v)
{
    printf((char *)v, _void_int_(e->value));
}

void __key(t_object *this, bool *key, SDL_EventType event)
{
    printf("key\n");
}

void test_array()
{
    void *a;
    a = new_array(STR);

    array(a)->add("Hello")->destroy = NULL;
    array(a)->add(strdup("World"));
    array(a)->add(strdup("Hello"));
    // array(a)->remove("World");
    array(a)->for_each(print_node, "%s\n");
    printf("================================\n");
    // // array(a)->set(0, " sdsd");
    // array(a)->remove("World", true);
    // array(a)->for_each(print_node, NULL);

    char **b = (char **)array(a)->to_array();

    printf("%p\n", *b);
    for (int i = 0; b[i]; i++)
    {
        printf("to_array: %s\n", b[i]);
    }
    array(a)->add(strdup("sdfsdf"));
    b = (char **)array(a)->to_array();

    printf("%p\n", *b);
    for (int i = 0; b[i]; i++)
    {
        printf("to_array: %s\n", b[i]);
    }

    array(a)->destroy();
}

void test_binary_tree()
{
    void *a;
    a = new_binary_tree(STR);

    array(a)->add(_int_void_(5));
    array(a)->add(_int_void_(3));
    array(a)->add(_int_void_(7));

    // array(a)->add(strdup("World"));
    // array(a)->add(strdup("Hello"));
    // // array(a)->remove("World");
    array(a)->for_each(print_node, "%i\n");
    // printf("================================\n");
    // // array(a)->set(0, " sdsd");
    // array(a)->remove(" World", true);
    // array(a)->for_each(print_node, NULL);

    // array(a)->destroy();
}

int main(int argc, char *argv[])
{

    // test_binary_tree();

    // test_binary_tree();
    engine()->init(argc, argv, 640, 480);

    t_scene *scene = new_scene(0, 0);

    t_object *object = new_object(sizeof(t_object));

    object->key = NULL;

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