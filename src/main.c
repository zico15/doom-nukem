#include <stdio.h>
#include <stdbool.h>
#include <Core.h>

int main(int argc, char *argv[])
{
    engine()->init(argc, argv, 640, 480);

    engine()->object = object_new(sizeof(t_object));

    engine()->run();
    engine()->destroy(NULL);
    return (0);
}