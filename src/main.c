#include <stdio.h>
#include <stdbool.h>
#include <Engine.h>

int main(int argc, char *argv[])
{
    engine()->init(argc, argv, 640, 480);

    t_scene *scene = new_scene(640, 480);
    
    scene->add(scene, new_object(sizeof(t_object)));
    scene->add(scene, new_object(sizeof(t_object)))->rect.x = 300;

    engine()->scene = scene;

    engine()->run();
    engine()->destroy(NULL);
    return (0);
}