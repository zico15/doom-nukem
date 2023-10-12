#include <SDL2/SDL.h>
#include <DoomEngine.h>

struct DoomEngine
{
    char *wad_path;
}   t_DoomEngine;

int main(int argc, char *argv[])
{
    doomEngine()->init("src/wad/DOOM1.WAD");
    return (0);
}