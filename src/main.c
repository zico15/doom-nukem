#include <stdio.h>
#include <stdbool.h>
#include <Engine.h>
#include <BinaryTrees.h>

t_scene *new_login();

void print_node(t_node *e, void *v)
{
    printf((char *)v, e->value);
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
    array(a)->remove("World", true);
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

    binary(a)->insert(2, strdup("Hello"));
    binary(a)->insert(1, strdup("World"));
    binary(a)->insert(3, strdup("Hello"));
    printf_tree(binary(a)->root, 0);

    t_bnode *node = binary(a)->search(3);

    if (node)
        printf("search: %llu\n", node->id);
    else
        printf("search: NULL\n");
    binary(a)->destroy();

    // // array(a)->add(strdup("World"));
    // // array(a)->add(strdup("Hello"));
    // // // array(a)->remove("World");
    // array(a)->for_each(print_node, "%i\n");
    // // printf("================================\n");
    // // // array(a)->set(0, " sdsd");
    // // array(a)->remove(" World", true);
    // // array(a)->for_each(print_node, NULL);

    // array(a)->destroy();
}

int main(int argc, char *argv[])
{
    // test_array();

    // test_binary_tree();

    test_binary_tree();
    exit(0);
    // argv[1] = "resources/maps/DOOM.WAD";

    // // // WADData()->init(argv[1]);
    engine()->init(argc, argv, 320, 200);

    t_scene *scene = new_scene(argv[1]);

    // scene->add(scene, new_camera());

    // scene->add(scene, new_plane(1.0f, 0.0f, 0.0f, -200.0f));

    engine()->add(scene);
    engine()->run();
    engine()->destroy(NULL);

    // // test
    // //  t_map *map = new_map("mapa.txt");
    // //  save(map, );
    // //  t_map *map_load = load("mapa.txt");
    // //  print_layout(map);
    // //  set_layout(map, 'd');
    // //  print_layout(map);

    // // map->save(map);
    // // map->destroy(map);
    return (0);
}