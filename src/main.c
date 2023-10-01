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

    void *a;

    a = new_array(STR);

    array(a)->add("Hello");
    array(a)->add("World");
    array(a)->add("!");
    array(a)->remove("!");
    array(a)->for_each(print_node, NULL);

    // engine()->init(argc, argv, 640, 480);

    // t_scene *scene = new_scene(640, 480);

    // scene->add(scene, new_object(sizeof(t_object)));
    // scene->add(scene, new_object(sizeof(t_object)))->rect.x = 300;

    // engine()->scene = scene;

    // engine()->run();
    // engine()->destroy(NULL);
    return (0);
}