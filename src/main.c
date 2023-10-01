#include <stdio.h>
#include <stdbool.h>
#include <Engine.h>

int main(int argc, char *argv[])
{
    engine()->init(argc, argv, 640, 480);

    engine()->scene = new_scene(640, 480);

    engine()->scene->add(engine()->scene, new_object(sizeof(t_object)));
    engine()->run();
    engine()->destroy(NULL);
    return (0);
}